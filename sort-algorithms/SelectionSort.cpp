//
// Created by Daniel Hinkelmann on 23.10.2024.
//
#include "SelectionSort.h"
#include "MainWindow.h"
#include <thread>

SelectionSort::~SelectionSort() {
    delete[] unsorted;
    delete[] sorted;
}

void SelectionSort::sort() {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            minIndex = sorted[minIndex] >= sorted[j]? j : minIndex;
        }

        this->updateChart(minIndex);

        std::swap(sorted[i], sorted[minIndex]);

        this->updateChart(i
        );
    }
}
