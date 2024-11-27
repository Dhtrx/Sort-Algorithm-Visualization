//
// Created by User on 29.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H
#define SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QOpenGLWidget>
#include <QLabel>
#include <QComboBox>
#include <QMainWindow>
#include <Renderer.h>

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QtCharts"
#include "QBarSet"
#include "QChart"
#include "QBarSeries"
#include "QChartView"

class MainWindow : public QOpenGLWidget {

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateChart();
    Renderer *getRenderer();

private:
    QComboBox* algoChooser;
    QPushButton* sortButton;
    void initAlgoChooser();
    Sort* sort;
    Renderer* renderer;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private slots:
    void onComboBoxChanged(int item);
    void startSorting();
};

#endif //SORT_ALGORITHM_VISUALIZATION_MAINWINDOW_H
