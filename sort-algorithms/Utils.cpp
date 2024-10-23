//
// Created by Daniel Hinkelmann on 22.10.2024.
//

#include "Utils.h"
#include "random"

using namespace std;

void Utils::initArrRandom(int* arr, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(0, size);

    for (int i = 0; i < size; ++i) {
        arr[i] = distribution(gen);
    }
}

void Utils::copyArr(const int *from, int *to, unsigned int size) {
    for (int i = 0; i < size; ++i) {
        to[i] = from[i];
    }
}
