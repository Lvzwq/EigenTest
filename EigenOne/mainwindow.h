#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtGui>
#include <QGLWidget>

class QAction;
class QLabel;
class QMenu;
class QSlider;
class QScrollArea;
class QWidget;

class Tetrahedron;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createMenu();
    void createActions();
    QSlider *createSlider(const char *changedSignal, const char *setterSlot);
    void setPixmap(const QPixmap &pixmap);
    QSize getSize();

    QWidget *centralWidget;
    QScrollArea *glWidgetArea;
    QScrollArea *pixmapLabelArea;
    Tetrahedron *tetrahedron;
    QLabel *pixmapLabel;

    QSlider *xSlider, *ySlider, *zSlider;

    QMenu *fileMenu, *helpMenu;

    QAction *renderIntoPixmapAction;
    QAction *grabFrameBufferAction;
    QAction *clearPixmapAction;
    QAction *exitAction;
    QAction *aboutAction;
    QAction *aboutQtAction;

signals:



private slots:
    void renderIntoPixmap();
    void grabFrameBuffer();
    void clearPixmap();
    void about();



};

#endif // MAINWINDOW_H
