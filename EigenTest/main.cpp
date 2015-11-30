#include <iostream>
#include <string>
#include "Eigen/Dense"
#include "Point.h"
#include "Shape.h"
#include <map>
#include "func.h"

using namespace Eigen;

enum Motion {
    Rotate = 1,
    Move,
    Zoom,
};

std::map<std::string, Motion> motion = {
        {"rotate", Motion::Rotate},
        {"move",   Motion::Move},
        {"zoom",   Motion::Zoom},
};

Motion resolveCommand(std::string command) {
    return motion[command];
}

int main() {
    std::string name, pointNum;
    printf("请输入图形的名字:");
    getline(std::cin, name);
    if (name.empty()) {
        name = "T";
        printf("你的输入为空,因此为你的图形命名(T)\n");
    }
    printf("请输入图形的端点数量:");
    getline(std::cin, pointNum);
    if (is_number(pointNum)) {
        std::cout << "你输入的是整数\n";
    } else {
        std::cout << "你输入的不是整数\n";
    }
    int num = atoi(pointNum.c_str());
    Point *shapePoints = new Point[num];

    for (int i = 0; i < num; ++i) {
        double x, y;
        printf("请输入第%d个点横坐标x = ", i + 1);
        scanf("%lf", &x);
        printf("请输入第%d个点纵坐标y = ", i + 1);
        scanf("%lf", &y);
        shapePoints[i].update(x, y);
    }
    std::cout << "你输入图形的名字为:" << name << " " << "你输入的端点数量为:" << pointNum << std::endl;
    Shape *shape = new Shape(shapePoints, num, name.c_str());
    shape->printShape();
    std::string command;
    bool flag = true;
    while (flag) {
        printf("\n请输入对图形的操作指令:");
        std::cin.ignore();
        getline(std::cin, command);
        std::vector<std::string> v;
        split_str(command, v);
        for (int i = 0; i < v.size(); i++) {
            std::cout << "v = " << v[i] << std::endl;
        }
        switch (resolveCommand(command)) {
            case Motion::Rotate:
                double angle;
                printf("请输入旋转角度,逆时针为正:");
                scanf("%lf", &angle);
                shape->rotateShape(angle);
                break;
            case Motion::Move:
                double mx, my;
                printf("输入X方向移动距离:");
                scanf("%lf", &mx);
                printf("输入Y方向移动距离:");
                scanf("%lf", &my);
                shape->moveShape(mx, my);
                break;
            case Motion::Zoom:
                double zx, zy;
                printf("输入X方向缩放大小:");
                scanf("%lf", &zx);
                printf("输入Y方向缩放大小:");
                scanf("%lf", &zy);
                shape->zoomShape(zx, zy);
                break;
            default:
                flag = false;
        }
        shape->printShape();
    }
    printf("Error!!!你输入的命令有误,已经退出指令模式退出\n");

    delete shape;
    delete[] shapePoints;
    shapePoints = NULL;
}