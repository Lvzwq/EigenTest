//
// Created by zwenqiang on 15/11/26.
//

#include "Shape.h"


Shape::Shape(Point *arr, int num, const char *name) {
    this->pointArr = arr;
    this->pointNum = num;
    this->shapeName = name;
}

void Shape::moveShape(double x, double y) {
    printf("你输入的指令为 move, 移动距离: (%lf, %lf)\n", x, y);
    for (int i = 0; i < this->pointNum; ++i) {
        this->pointArr[i].move(x, y);
    }
}

void Shape::rotateShape(double angle) {
    printf("你输入的指令为 rotate, 旋转角度: %lf\n", angle);
    for (int i = 0; i < this->pointNum; ++i) {
        this->pointArr[i].rotate(angle);
    }
}

void Shape::zoomShape(double zx, double zy) {
    printf("你输入的指令为 zoom, 缩放比例为: (%lf, %lf)\n", zx, zy);
    for (int i = 0; i < this->pointNum; ++i) {
        this->pointArr[i].zoom(zx, zy);
    }
}

void Shape::printShape() {
    printf("图形%s的%d个点坐标分别为", this->shapeName, this->pointNum);
    for (int i = 0; i < this->pointNum - 1; ++i) {
        this->pointArr[i].print();
        printf(",");
    }
    this->pointArr[(this->pointNum - 1)].print();
    printf("\n");
}

Shape::~Shape() {
    printf("调用Helper析构函数\n");
}

