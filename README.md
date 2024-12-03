## Sorting Algorithms Visualization
This project is a GUI-based application for visualizing various sorting algorithms. It displays the sorting process in real-time and allows users to adjust the animation speed and the size of the dataset being sorted.

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Sorting Algorithms](#supported-sorting-algorithms)
- [Future Improvements](#future-improvements)
- [License](#license)
- [QT Framework](#qt-framework)
- [Contact](#contact)

## About the Project
The goal of this project is to provide a visual representation of different sorting algorithms to help users understand their working principles. The application uses bar charts to illustrate the sorting steps and highlights the elements being compared during each iteration.

## Features
- Real-time visualization of the sorting process.
- Selection of different sorting algorithms.
- Adjustable animation speed for step-by-step or fast execution.
- Dynamic resizing of the array to sort (not yet implemented).
- Highlights the currently moved elements during sorting.
- Responsive GUI that remains interactive during the sorting process.

## Technologies Used
- **C++**: The core programming language used for the project.
- **Qt Framework**: For GUI development and event handling.
- **CMake**: Build system for project configuration and compilation.
- **Multithreading**: To ensure smooth animations without blocking the GUI.

## Installation
Follow these steps to set up and run the project on your local machine.

### Prerequisites
- C++ Compiler (e.g., GCC, Clang, MSVC)
- Qt Framework (version 5 or higher)
- CMake (version 3.10 or higher)

### Build Instructions
1. Clone the repository:
   git clone https://github.com/Dhtrx/sort-algorithm-visualization.git
2. Navigate to the project directory
    cd sort-algorithm-visualization
3. Build the Project using CMake
    mkdir build
    cd build
    cmake ..
    cmake --build .
4. Launch sort-algorithm-visualization.exe from the cmake-build-debug folder


- Start sort-algorithm.visualization.exe in sort-algorithm-visualizer/cmake-build-debug

## Usage
1. **Launch the application**: Open the compiled executable.
2. **Select a sorting algorithm**: From the dropdown menu, choose the algorithm you want to visualize.
3. **Adjust the animation speed**: Use the slider to control how fast the sorting process runs. You can set it for step-by-step execution or a fast visualization.
4. **Set the array size**: (Feature not yet implemented, will be available soon).
5. **Start the visualization**: Click the "Sort" button to begin the sorting process. The bars representing elements will change color as swaps are made.
6. **Observe the sorting process**: Watch the algorithm sort the array in real-time, with elements being highlighted as they are swapped.


## Supported Sorting Algorithms
- **Bubble Sort**: A simple sorting algorithm that compares adjacent elements and swaps them if they are in the wrong order.
- **Selection Sort**: Selects the smallest (or largest) element from the unsorted part of the array and swaps it with the first unsorted element.
- **Insertion Sort**: Builds the sorted array one element at a time by repeatedly inserting the current element into the sorted portion of the array.


## Future Improvements
- Add more sorting algorithms (e.g., Merge Sort, Quick Sort).
- Implement adjustable Array Size.
- Implement step-by-step control for better learning.

## License
This project is licensed under the MIT License.
Feel free to use, modify, and distribute it as per the license terms.

## Qt Framework
This project uses the Qt Framework, which is licensed under the **LGPL (Lesser General Public License)**.  
When dynamically linking to Qt libraries, the project complies with the LGPL requirements.  
For more information on Qt's licensing, visit [Qt Licensing](https://www.qt.io/licensing).


## Contact
If you have any questions or suggestions, feel free to reach out:

GitHub: [Dhtrx](https://github.com/Dhtrx)
