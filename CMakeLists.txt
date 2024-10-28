cmake_minimum_required(VERSION 3.27)
project(sort_algorithm_visualization)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/mingw_64/lib/cmake/Qt6")
set(QML_IMPORT_PATH "${CMAKE_PREFIX_PATH}/qml")
set(SOURCES main.cpp visualization/SortAlgorithmGui/SortAlgorithmGuiContent/resources.qrc)

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
        sort-algorithms/SelectionSort.h
        Test.h
        Test.cpp
        visualization/MyWidget.h
        visualization/MyWidget.cpp
)

set(Qt6_DIR "C:/Qt/6.8.0/mingw_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS Core Gui Qml Quick Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

target_link_libraries(sort_algorithm_visualization
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::Widgets
)
