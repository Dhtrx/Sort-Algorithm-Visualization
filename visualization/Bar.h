//
// Created by User on 26.11.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_BAR_H
#define SORT_ALGORITHM_VISUALIZATION_BAR_H


class Bar {
private:
    float height;
    float width;
    float pos;
    int glType;
public:
    Bar(float height, float pos);
    float getHeight();
    float getWidth();
    float getPos();
    int getGLType();

    void setPos(float pos);
    void toVertecies();
};


#endif //SORT_ALGORITHM_VISUALIZATION_BAR_H
