//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#include <thread>
#include "InsertionSort.h"
#include "MainWindow.h"
InsertionSort::~InsertionSort() {
    delete[] unsorted;
    delete[] sorted;
}

void InsertionSort::sort() {
    for (int i = 1; i < size; i++) {
        int key = sorted[i];
        this->updateChart(i);
        int j = i - 1;

        while (j >= 0 && sorted[j] > key) {
            //this->updateChart(j);
            sorted[j + 1] = sorted[j];
            //this->updateChart(j + 1);
            j--;
        }

        sorted[j + 1] = key;
        this->updateChart(j + 1);
    }
}

