//
// Created by zwenqiang on 15/11/26.
//

#include "Point.h"
#include <iostream>

Point::Point() {
    this->x = 0;
    this->y = 0;
}

void Point::update(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::print() {
    std::cout << "(" << this->x << ", " << this->y << ")";
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::~Point() {
    std::cout << "调用Point析构函数" << std::endl;
}

/**
 * 平移
 */
void Point::move(double x, double y) {
    this->x += x;
    this->y += y;
}

/**
 * 旋转变换,angle为角度, 逆时针为正, 顺时针为负
 */
void Point::rotate(double angle) {
    MatrixXd T(2, 2);
    angle = angle / 180 * M_PI;
    T(0, 0) = cos(angle);
    T(0, 1) = sin(angle);
    T(1, 0) = -sin(angle);
    T(1, 1) = cos(angle);
    std::cout << "旋转矩阵T = " << std::endl << T << std::endl;
    Vector2d m = this->pointByMatrix();
    m = T * m;  //貌似只能T * m
    this->setByMatrix(m);
}

/**
 * 缩放(比例变换), zx分别表示x轴缩放比例,zy表示y轴缩放比例
 */
void Point::zoom(double zx, double zy) {
    Matrix2d T;
    T << zx, 0, 0, zy;
    Vector2d result = T * this->pointByMatrix();
    this->setByMatrix(result);
}

Vector2d Point::pointByMatrix() {
    Vector2d a(this->x, this->y);
    return a;
}

void Point::setByMatrix(Vector2d m) {
    this->x = m(0);
    this->y = m(1);
}








