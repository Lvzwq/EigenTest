//
// Created by zwenqiang on 15/11/26.
//

#ifndef EIGENTEST_POINT_H
#define EIGENTEST_POINT_H

#include "Eigen/Dense"

using namespace Eigen;

class Point {
private:
    double x, y;

public:
    Point();

    Point(double x, double y);

    void update(double x, double y);

    void print();

    void move(double x, double y);

    void rotate(double angle);

    void zoom(double zx, double zy);

    Vector2d pointByMatrix();

    void setByMatrix(Vector2d m);

    ~Point();
};


#endif //EIGENTEST_POINT_H
