//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_SORT_H
#define SORT_ALGORITHM_VISUALIZATION_SORT_H

class MainWindow;

class Sort {
protected:
    int size;
    int* unsorted;
    MainWindow* mainWindow;

public:
    int* sorted;
    Sort(int size, MainWindow* mainWindow);
    ~Sort();
    virtual void sort() = 0;
    int pubSize;
};


#endif //SORT_ALGORITHM_VISUALIZATION_SORT_H
