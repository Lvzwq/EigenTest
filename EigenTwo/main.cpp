#include "mainwindow.h"
#include <QApplication>
#include<QTextEdit>
#include<QtGui>
#include<QBoxLayout>
#include<QPushButton>

#include<iostream>
#include<trianglewindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSurfaceFormat format;

    format.setSamples(16);
    TriangleWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();
    return a.exec();
}
