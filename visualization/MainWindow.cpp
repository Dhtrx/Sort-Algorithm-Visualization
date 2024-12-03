//
// Created by User on 29.10.2024.
//
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QtCharts>
#include <iostream>
#include "QChartView"
#include "QChart"
#include "MergeSort.h"
#include "BubbleSort.h"

MainWindow::MainWindow(QWidget *parent) : QOpenGLWidget(parent),
algoChooser(new QComboBox(this)),
sort(new InsertionSort(100, this)),
renderer(new Renderer()),
sortButton(new QPushButton(this)),
speed(new QSlider(Qt::Horizontal)) {

    resize(600, 400);
    setWindowTitle("Sort Algorithm Visualization");

    auto *widget = new QWidget(this);
    auto *layout = new QHBoxLayout(widget);

    //Initialize and connect ComboBox algoChooser and Button sortButton
    this->initAlgoChooser();
    connect(algoChooser, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxChanged);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::startSorting);
    connect(speed, &QSlider::valueChanged, this, &MainWindow::changeSpeed);

    sortButton->setText("Sort");
    speed->setValue(50);

    layout->addWidget(algoChooser);
    layout->addWidget(sortButton);
    layout->addWidget(speed);
    //Init Standard bar diagram with values from standard sort algorithm insertion sort
    for (int i = 0; i < sort->getSize(); ++i) {
        auto j = static_cast<float>(i);
        auto size = static_cast<float>(sort->getSize());
        auto val = static_cast<float>(sort->sorted[i]);
        float mappedVal = (val / (size - 1.0f)) + 1e-6f;
        float p = -1.0f + (j * (0.95f - -1)) / size;
        renderer->getBars().push_back(new Bar(mappedVal, p));
    }
}

void MainWindow::initAlgoChooser() {
    this->algoChooser->addItem("Insertion Sort", QVariant(0));
    this->algoChooser->addItem("Selection Sort", QVariant(1));
    //this->algoChooser->addItem("Merge Sort", QVariant(2));
    this->algoChooser->addItem("Bubble Sort", QVariant(3));
}

void MainWindow::onComboBoxChanged(int item) {
    switch (dynamic_cast<QComboBox*>(sender())->itemData(item).toInt()) {
        case 0:
            this->sort = new InsertionSort(100, this);
            updateChart();
            break;
        case 1:
            this->sort = new SelectionSort(100, this);
            updateChart();
            break;
        case 2:
            this->sort = new MergeSort(100, this);
            updateChart();
            break;
        case 3:
            this->sort = new BubbleSort(100, this);
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
    for (int i = 0; i < sort->getSize(); ++i) {
        auto j = static_cast<float>(i);
        auto size = static_cast<float>(sort->getSize());
        auto val = static_cast<float>(sort->sorted[i]);

        float mappedVal = ((val / (size - 1.0f)) + 1e-6f);
        float p = -1.0f + (j * (0.95f - -1)) / size;

        renderer->getBars().at(i)->setPos(p);
        renderer->getBars().at(i)->setHeight(mappedVal);
    }

    update();
}

Renderer* MainWindow::getRenderer() {
    return renderer;
}

void MainWindow::changeSpeed(int value) {
    waitTime = (100 - value) * 10;
}

int MainWindow::getSpeed() {
    return waitTime;
}

MainWindow::~MainWindow() = default;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}

