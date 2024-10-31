//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#include "Sort.h"
#include "Utils.h"
#include "MainWindow.h"

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
