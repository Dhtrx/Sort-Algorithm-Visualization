cmake_minimum_required(VERSION 3.27)
project(sort_algorithm_visualization)

set(CMAKE_CXX_STANDARD 14)

include_directories(sort-algorithms)
include_directories(visualization)

add_executable(sort_algorithm_visualization
        sort-algorithms/InsertionSort.cpp
        sort-algorithms/InsertionSort.h
        sort-algorithms/InsertionSort.h
        sort-algorithms/InsertionSort.cpp
        sort-algorithms/Utils.h
        sort-algorithms/Utils.cpp
        sort-algorithms/Sort.h
        sort-algorithms/Sort.cpp
        sort-algorithms/SelectionSort.cpp
        sort-algorithms/SelectionSort.h)
