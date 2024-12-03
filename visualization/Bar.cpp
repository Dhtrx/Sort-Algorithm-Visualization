//
// Created by User on 26.11.2024.
//
#include <GL/gl.h>

#include "Bar.h"

Bar::Bar(float height, float pos) {
    this->height = height;
    this-> pos = pos;
    width = .01;
    glType = GL_QUADS;
    color.r = 1;
    color.g = 1;
    color.b = 1;
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

void Bar::toVertecies() const {
    glColor3f(color.r, color.g, color.b);
    glVertex2f(pos, 0);
    glVertex2f(pos + width, 0);
    glVertex2f(pos + width, height);
    glVertex2f(pos, height);
}

int Bar::getGLType() {
    return glType;
}

void Bar::setColor(float r, float g, float b) {
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
}

void Bar::setHeight(float height) {
    this->height = height;
}

void Bar::setWidth(float width) {
    this->width = width;
}
