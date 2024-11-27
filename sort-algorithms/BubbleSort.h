//
// Created by Anwender on 27.11.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_BUBBLESORT_H
#define SORT_ALGORITHM_VISUALIZATION_BUBBLESORT_H


#include "Sort.h"

class BubbleSort : public Sort {

public:
    explicit BubbleSort(int size, MainWindow* mainWindow) : Sort(size, mainWindow){}
    void sort() override;
};


#endif //SORT_ALGORITHM_VISUALIZATION_BUBBLESORT_H
