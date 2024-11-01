//
// Created by User on 29.10.2024.
//

#include "MainWindow.h"
#include "Sort.h"
#include <QVBoxLayout>
#include <iostream>
#include <QtCharts>
#include "QChartView"
#include "QChart"
#include "MergeSort.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), algoChooser(new QComboBox(this)), sort(new InsertionSort(50, this)) {
    resize(600, 400);
    setWindowTitle("Sort Algorithm Visualization");

    auto *widget = new QWidget(this);
    auto *layout = new QVBoxLayout(widget);

    //Initialize and connect ComboBox algoChooser
    this->initAlgoChooser();
    connect(algoChooser, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxChanged);

    //Init Standard bar diagram with values from standard sort algorithm insertion sort
    set = new QBarSet("");
    highlighted = new QBarSet("");
    highlighted->setColor(QColor("red"));
    for (int i = 0; i < sort->getSize(); ++i) {
        *set << sort->sorted[i];
        *highlighted << 0;
    }

    //Init Chart
    auto* series = new QBarSeries();
    series->append(set);
    series->append(highlighted);

    chart = new QChart();
    chart->addSeries(series);

    auto* yAxis = new QValueAxis();
    yAxis->setRange(0, 10);
    chart->addAxis(yAxis, Qt::AlignLeft);

    //Init chart view of chart
    view = new QChartView(chart);

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
    this->algoChooser->addItem("Merge Sort", QVariant(2));
}

void MainWindow::onComboBoxChanged(int item) {
    switch (dynamic_cast<QComboBox*>(sender())->itemData(item).toInt()) {
        case 0:
            this->sort = new InsertionSort(50, this);
            updateChart();
            break;
        case 1:
            this->sort = new SelectionSort(50, this);
            updateChart();
            break;
        case 2:
            this->sort = new MergeSort(50, this);
            updateChart();
            break;
    }
}

void MainWindow::startSorting() {
    sort->sort();
}

QBarSet *MainWindow::getSet() {
    return this->set;
}

QChart *MainWindow::getChart() {
    return this->chart;
}

void MainWindow::updateChart() {
    for (int i = 0; i < sort->getSize(); ++i) {
        (*this->set).replace(i, sort->sorted[i]);
        (*this->highlighted).replace(i, 0);
    }
}

QChartView *MainWindow::getView() {
    return this->view;
}

QBarSet *MainWindow::getHighlighted() {
    return this->highlighted;
}

MainWindow::~MainWindow() = default;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}

