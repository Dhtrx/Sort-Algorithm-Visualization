//
// Created by Daniel Hinkelmann on 23.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_SELECTIONSORT_H
#define SORT_ALGORITHM_VISUALIZATION_SELECTIONSORT_H

#include "Sort.h"


class SelectionSort : public Sort {
public:
    explicit SelectionSort(int size, MainWindow* mainWindow) : Sort(size, mainWindow){}
    ~SelectionSort();
    void sort() override;
};


#endif //SORT_ALGORITHM_VISUALIZATION_SELECTIONSORT_H
