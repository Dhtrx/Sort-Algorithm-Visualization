//
// Created by User on 24.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_TEST_H
#define SORT_ALGORITHM_VISUALIZATION_TEST_H

#include "Sort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

class Test {
private:
    int size;
    bool testInsertionSort();
    bool isSorted(int* arr);

public:
    Test(int size);

};


#endif //SORT_ALGORITHM_VISUALIZATION_TEST_H
