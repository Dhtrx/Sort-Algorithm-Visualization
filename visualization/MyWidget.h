//
// Created by User on 28.10.2024.
//

#ifndef SORT_ALGORITHM_VISUALIZATION_MYWIDGET_H
#define SORT_ALGORITHM_VISUALIZATION_MYWIDGET_H

#include <QLabel>
#include <QApplication>
#include <QWidget>

class MyWidget : public QWidget{
public:
    explicit MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        this->resize(320, 240);
        this->setWindowTitle("HelloGUI with Qt");
        QLabel* label = new QLabel("Hello World", this); // create a label
    }
};
/*
int main (int argc, char* argv[]) {
    // create a QApplication object that handles initialization,
    // finalization, and the main event loop
    QApplication appl(argc, argv);
    MyWidget widget;  // create a widget
    widget.show(); //show the widget and its children
    return appl.exec(); // execute the application
}
 */


#endif //SORT_ALGORITHM_VISUALIZATION_MYWIDGET_H
