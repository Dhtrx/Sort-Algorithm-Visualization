//
// Created by User on 26.11.2024.
//
#include <GL/glu.h>

#include "Renderer.h"
#include "Bar.h"

void Renderer::init() {
    QOpenGLFunctions_3_1::initializeOpenGLFunctions();
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Renderer::display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    for (Bar* bar: bars) {
        glLoadIdentity();
        glTranslatef(0, -.5, 0);
        glRotatef(180, 0, 0 , 1);
        glBegin(bar->getGLType());
        bar->toVertecies();
        glEnd();
    }
}

void Renderer::dispose() {}

vector<Bar*>& Renderer::getBars() {
    return bars;
}
