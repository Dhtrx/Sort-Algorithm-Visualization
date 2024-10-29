//
// Created by User on 29.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H
#define SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QMainWindow>

#include "Sort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

class MainWindow : public QMainWindow {

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    QComboBox* algoChooser;
    void initAlgoChooser();
    Sort* sort;

private slots:
    void onComboBoxChanged(int item);
};

#endif //SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H