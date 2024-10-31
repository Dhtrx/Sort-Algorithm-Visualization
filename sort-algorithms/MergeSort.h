//
// Created by Anwender on 30.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_MERGESORT_H
#define SORT_ALGORITHM_VISUALIZATION_MERGESORT_H


#include "Sort.h"
#include <vector>

using namespace std;

class MergeSort : public Sort {
public:
    explicit MergeSort(int size, MainWindow* mainWindow) : Sort(size, mainWindow){}
    void sort() override;

private:
    void merge(int* arr, int left, int mid, int right);
    void sortRec(int* arr, int left, int right);
};


#endif //SORT_ALGORITHM_VISUALIZATION_MERGESORT_H
