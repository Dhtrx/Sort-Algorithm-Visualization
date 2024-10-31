//
// Created by Anwender on 30.10.2024.
//

#include "MergeSort.h"
#include "MainWindow.h"
#include <vector>

using namespace std;

void MergeSort::merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    //Split arr in left and right half
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

    // Merge of temporary arrays
    int i = 0, j = 0, k = left;
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

    // Copy remaining elements of leftArr if necessary
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    //Copy remaining elements of rightArr if necessary
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
        this->updateChart();
    }

    delete[] leftArr;
    delete[] rightArr;

    this->updateChart();
}

void MergeSort::sortRec(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        //Sort left and Right halfs
        sortRec(arr, left, mid);
        sortRec(arr, mid + 1, right);

        // Merges sorted halfs
        merge(arr, left, mid, right);
    }
}

void MergeSort::sort() {
    sortRec(sorted, 0, size);
}



