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

MainWindow::MainWindow(QWidget *parent) : QOpenGLWidget(parent), algoChooser(new QComboBox(this)), sort(new InsertionSort(20, this)), renderer(new Renderer()) {
    resize(600, 400);
    setWindowTitle("Sort Algorithm Visualization");

    auto *widget = new QWidget(this);
    auto *layout = new QVBoxLayout(widget);

    //Initialize and connect ComboBox algoChooser
    this->initAlgoChooser();
    connect(algoChooser, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxChanged);

    //Init Standard bar diagram with values from standard sort algorithm insertion sort
    for (int i = 0; i < 20; ++i) {
        float mappedVal = 2.0f * ((static_cast<float>(sort->sorted[i]) / 19.0f) - 1.0f);
        renderer->getBars().push_back(new Bar(mappedVal, (2.0f * (static_cast<float>(i) / 19.0f) - 1.0f)));
    }
}

void MainWindow::initAlgoChooser() {
    this->algoChooser->addItem("Insertion Sort", QVariant(0));
    this->algoChooser->addItem("Selection Sort", QVariant(1));
    this->algoChooser->addItem("Merge Sort", QVariant(2));
}

void MainWindow::onComboBoxChanged(int item) {
    switch (dynamic_cast<QComboBox*>(sender())->itemData(item).toInt()) {
        case 0:
            this->sort = new InsertionSort(20, this);
            updateChart();
            break;
        case 1:
            this->sort = new SelectionSort(20, this);
            updateChart();
            break;
        case 2:
            this->sort = new MergeSort(20, this);
            updateChart();
            break;
    }
}

void MainWindow::startSorting() {
    sort->sort();
}

void MainWindow::initializeGL() {
    renderer->init();
}

void MainWindow::paintGL() {
    renderer->display();
}

void MainWindow::resizeGL(int w, int h) {
    renderer->resize(w, h);
}


void MainWindow::updateChart() {

}

MainWindow::~MainWindow() = default;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}

