//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_INSERTIONSORT_H
#define SORT_ALGORITHM_VISUALIZATION_INSERTIONSORT_H

#include "Sort.h"

class InsertionSort : public Sort {
public:
    explicit InsertionSort(int size) : Sort(size) {}
    ~InsertionSort();
    void sort() override;
};


#endif //SORT_ALGORITHM_VISUALIZATION_INSERTIONSORT_H
