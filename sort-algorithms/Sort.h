//
// Created by User on 22.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_SORT_H
#define SORT_ALGORITHM_VISUALIZATION_SORT_H


class Sort {
protected:
    unsigned size;
    int* unsorted;
    int* sorted;

public:
    Sort(unsigned size);
    ~Sort();
    virtual void sort() = 0;
};


#endif //SORT_ALGORITHM_VISUALIZATION_SORT_H
