//
// Created by User on 29.10.2024.
//

#include "MainWindow.h"
#include <QVBoxLayout>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), algoChooser(new QComboBox(this)) {
    resize(600, 400);
    setWindowTitle("Sort Algorithm Visualization");

    auto *widget = new QWidget(this);
    auto *layout = new QVBoxLayout(widget);

    //Initialize and connect ComboBox algoChooser
    this->initAlgoChooser();
    connect(algoChooser, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxChanged);

    layout->addWidget(new QLabel("Choose an algorithm:"));
    layout->addWidget(algoChooser);

    setCentralWidget(widget);

}

void MainWindow::initAlgoChooser() {
    this->algoChooser->addItem("Insertion Sort", QVariant(0));
    this->algoChooser->addItem("Selection Sort", QVariant(1));
}

void MainWindow::onComboBoxChanged(int item) {
    switch (dynamic_cast<QComboBox*>(sender())->itemData(item).toInt()) {
        case 0:
            this->sort = new InsertionSort(5);
            std::cout << this->sort->pubSize << std::endl;
            break;
        case 1:
            this->sort = new SelectionSort(4);
            std::cout << this->sort->pubSize << std::endl;
            break;
    }
}

MainWindow::~MainWindow() = default;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}

