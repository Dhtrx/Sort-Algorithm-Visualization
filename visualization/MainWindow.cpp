//
// Created by User on 29.10.2024.
//

#include "MainWindow.h"
#include <QVBoxLayout>
#include <iostream>
#include <QtCharts>
#include "QChartView"
#include "QChart"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), algoChooser(new QComboBox(this)), sort(new InsertionSort(20)) {
    resize(600, 400);
    setWindowTitle("Sort Algorithm Visualization");

    auto *widget = new QWidget(this);
    auto *layout = new QVBoxLayout(widget);

    //Initialize and connect ComboBox algoChooser
    this->initAlgoChooser();
    connect(algoChooser, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxChanged);

    //Init Standard bar diagram with values from standard sort algorithm insertion sort
    set = new QBarSet("Values");
    for (int i = 0; i < sort->pubSize; ++i) {
        *set << sort->sorted[i];
    }

    //Init Chart
    auto* series = new QBarSeries();
    series->append(set);

    auto* chart = new QChart();
    chart->addSeries(series);

    auto* yAxis = new QValueAxis();
    yAxis->setRange(0, 10);
    chart->addAxis(yAxis, Qt::AlignLeft);

    //Init chart view of chart
    auto* view = new QChartView(chart);

    //Init button for starting the sorting algorithm
    auto* button = new QPushButton("Sort");
    connect(button, &QPushButton::clicked, this, &MainWindow::startSorting);

    layout->addWidget(algoChooser);
    layout->addWidget(view);
    layout->addWidget(button);

    setCentralWidget(widget);

}

void MainWindow::initAlgoChooser() {
    this->algoChooser->addItem("Insertion Sort", QVariant(0));
    this->algoChooser->addItem("Selection Sort", QVariant(1));
}

void MainWindow::onComboBoxChanged(int item) {
    switch (dynamic_cast<QComboBox*>(sender())->itemData(item).toInt()) {
        case 0:
            this->sort = new InsertionSort(20, this);
            break;
        case 1:
            this->sort = new SelectionSort(20, this);
            break;
    }
}

void MainWindow::startSorting() {
    sort->sort();
}

MainWindow::~MainWindow() = default;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}

