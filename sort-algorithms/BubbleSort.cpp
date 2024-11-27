//
// Created by Anwender on 27.11.2024.
//

#include "BubbleSort.h"

void BubbleSort::sort() {
    for (int i = size; i > 1; --i) {
        for (int j = 0; j < i - 1; ++j) {
            this->updateChart(j);
            if (sorted[j] > sorted[j + 1]) {
                int tmp = sorted[j + 1];
                sorted[j + 1] = sorted[j];
                sorted[j] = tmp;
            }
            this->updateChart(j + 1);
        }
    }
}
