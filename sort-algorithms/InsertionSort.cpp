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
        int j = i - 1;

        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j = j - 1;
        }

        sorted[j + 1] = key;

        //Update barSet of chart in gui
        for (int k = 0; k < size; ++k) {
            *this->mainWindow->getSet() << sorted[k];
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

