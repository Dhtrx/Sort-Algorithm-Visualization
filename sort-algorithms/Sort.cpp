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

void Sort::updateChart() {
    for (int k = 0; k < size; ++k) {
        (*this->mainWindow->getSet()).replace(k, sorted[k]);
    }

    QApplication::processEvents();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
