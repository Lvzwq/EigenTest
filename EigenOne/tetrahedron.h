#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <QGLWidget>
#include <math.h>
#include <QtGui>
#include <QtOpenGL>

class Tetrahedron : public QGLWidget
{
    Q_OBJECT

public:
    explicit Tetrahedron(QWidget *parent = 0);
    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void alwaysRotate();
    void drawTriangle();

private:
    int xRot;
    int yRot;
    int zRot;
    void normalizeAngle(int *angle);

    QColor faceColors[4];
    QPoint lastPos;
};

#endif // TETRAHEDRON_H
