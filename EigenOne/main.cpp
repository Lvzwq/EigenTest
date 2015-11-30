#include "mainwindow.h"
#include<iostream>
#include <QApplication>
#include <Eigen/Dense>
#include "shape.h"

using Eigen::MatrixXd;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shape *s = new Shape();
    s->show();

    MainWindow w;
    w.show();
    return a.exec();
}
