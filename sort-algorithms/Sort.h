//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_SORT_H
#define SORT_ALGORITHM_VISUALIZATION_SORT_H


class Sort {
protected:
    int size;
    int* unsorted;
    int* sorted;

public:
    Sort(int size);
    ~Sort();
    virtual void sort() = 0;
    int pubSize;
};


#endif //SORT_ALGORITHM_VISUALIZATION_SORT_H
