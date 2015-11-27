#ifndef SHAPE_H
#define SHAPE_H

#include<QtGUi>
#include<QWidget>

class Shape:public QWidget
{
public:
    Shape(QWidget *parent = 0);
    void paintEvent(QPaintEvent *pe);
    ~Shape();
};

#endif // SHAPE_H
