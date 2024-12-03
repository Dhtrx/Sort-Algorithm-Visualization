//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#include "Sort.h"
#include "Utils.h"
#include "MainWindow.h"
#include <thread>

Sort::Sort(int size, MainWindow* mainWindow) {
    this->mainWindow = mainWindow;
    this->pubSize = size;
    this->size = size;
    this->unsorted = new int[size];
    this->sorted = new int[size];
    this->highlighted = 0;

    Utils::initArrRandom(unsorted, size);
    Utils::copyArr(unsorted, sorted, size);
}

Sort::~Sort() {
    delete[] unsorted;
    delete[] sorted;
}

int Sort::getSize() {
    return this->size;
}

void Sort::updateChart(int highlightedIndex) {
    for (int i = 0; i < mainWindow->getRenderer()->getBars().size(); ++i) {
        if (i == highlightedIndex) {
            mainWindow->getRenderer()->getBars().at(i)->setColor(1, 0, 0);
        } else {
            mainWindow->getRenderer()->getBars().at(i)->setColor(1, 1, 1);
        }
    }
    mainWindow->updateChart();

    QApplication::processEvents();
    QEventLoop loop;
    QTimer::singleShot(mainWindow->getSpeed(), &loop, &QEventLoop::quit);
    loop.exec();
}
