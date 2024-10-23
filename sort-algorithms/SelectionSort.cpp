//
// Created by Daniel Hinkelmann on 23.10.2024.
//
#include "SelectionSort.h"

SelectionSort::~SelectionSort() {
    delete[] unsorted;
    delete[] sorted;
}

void SelectionSort::sort() {
    int minIndex = 0;
    for (int i = 1; i < size && minIndex < size; ++i) {
        for (int j = 0; j < size; ++j) {
            minIndex = sorted[minIndex] >= sorted[j]? sorted[j] : minIndex;
        }
        int tmp = sorted[i];
        sorted[i] = sorted[minIndex];
        sorted[i] = tmp;
        minIndex = i + 1;
    }
}
