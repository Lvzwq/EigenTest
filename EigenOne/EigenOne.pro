#-------------------------------------------------
#
# Project created by QtCreator 2015-11-25T12:31:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EigenOne
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shape.cpp

HEADERS  += mainwindow.h \
    shape.h


FORMS    += mainwindow.ui

LIBS += -LEigen
