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

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QtCharts"
#include "QBarSet"
#include "QChart"
#include "QBarSeries"
#include "QChartView"

class MainWindow : public QMainWindow {

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    QBarSet* getSet();
    QChart* getChart();

private:
    QComboBox* algoChooser;
    void initAlgoChooser();
    Sort* sort;
    QBarSet* set;
    QChart* chart;
    void updateChart();


private slots:
    void onComboBoxChanged(int item);
    void startSorting();
};

#endif //SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H
