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
    explicit MergeSort(int size) : Sort(size){}
    void sort() override;

private:
    void merge(vector<int>& arr, int start, int mid, int end);
    void sortRec(vector<int>& arr, int start, int end);
};


#endif //SORT_ALGORITHM_VISUALIZATION_MERGESORT_H
