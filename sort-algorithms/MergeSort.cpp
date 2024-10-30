//
// Created by Anwender on 30.10.2024.
//

#include "MergeSort.h"
#include <vector>

using namespace std;

void MergeSort::merge(vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    //Split arr int left and right array at middle
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    //Merge left and right partial array together
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //Fill up arr with rest of left array if necessary
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    //Fill up arr with rest of right array if necessary
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort::sortRec(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    //Sort left part of array
    sortRec(arr, start, mid);
    //Sort right part of array
    sortRec(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void MergeSort::sort() {
    vector<int> arr(sorted, sorted + size);
    sortRec(arr, 0, static_cast<int>(arr.size()));
    sorted = new int[arr.size()];
    for (size_t i = 0; i < arr.size(); ++i) {
        sorted[i] = arr[i];
    }
}

