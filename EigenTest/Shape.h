//
// Created by zwenqiang on 15/11/26.
//


#include "Point.h"

class Shape {
private:
    const char *shapeName;
    int pointNum;
    Point *pointArr;
public:
    Shape(Point *arr, int num, const char *name);

    void printShape();

    void rotateShape(double angle);

    void moveShape(double x, double y);

    void zoomShape(double zx, double zy);

    ~Shape();
};

