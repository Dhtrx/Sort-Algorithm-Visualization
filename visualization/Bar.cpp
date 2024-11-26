//
// Created by User on 26.11.2024.
//
#include <GL/gl.h>

#include "Bar.h"

Bar::Bar(float height, float pos) {
    this->height = height;
    this-> pos = pos;
    width = .05;
    glType = GL_QUADS;
}

float Bar::getHeight() {
    return height;
}

float Bar::getWidth() {
    return width;
}

float Bar::getPos() {
    return pos;
}

void Bar::setPos(float pos) {
    this->pos = pos;
}

void Bar::toVertecies() {
    glVertex2f(pos, 0);
    glVertex2f(pos + width, 0);
    glVertex2f(pos + width, height);
    glVertex2f(pos, height);
}

int Bar::getGLType() {
    return glType;
}
