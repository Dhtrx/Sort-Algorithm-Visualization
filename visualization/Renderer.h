//
// Created by User on 26.11.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_RENDERER_H
#define SORT_ALGORITHM_VISUALIZATION_RENDERER_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_1>
#include <QQuickOpenGLUtils>
#include "Bar.h"

using namespace std;

class Renderer : protected QOpenGLFunctions_3_1{
private:
    vector<Bar*> bars;

public:
    void init();
    void resize(int w, int h);
    void display();
    void dispose();
    vector<Bar*>& getBars();
};


#endif //SORT_ALGORITHM_VISUALIZATION_RENDERER_H
