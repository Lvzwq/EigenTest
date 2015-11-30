#include "tetrahedron.h"

Tetrahedron::Tetrahedron(QWidget *parent) : QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;

    faceColors[0] = Qt::red;
    faceColors[1] = Qt::green;
    faceColors[2] = Qt::blue;
    faceColors[3] = Qt::black;

//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(alwaysRotate()));
//    this->startTimer(70);
}

void Tetrahedron::initializeGL(){
    glClearColor(0.0, 0.2, 0.3, 1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH);
}

void Tetrahedron::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    drawTriangle();
    glPopMatrix();
}

void Tetrahedron::resizeGL(int w, int h){
    int side = qMin(w, h);
    glViewport((width() - side)/2, (height() - side)/ 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.2, 1.2, -1.2, 1.2, 5.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -40.0);
}

void Tetrahedron::mousePressEvent(QMouseEvent *event){
    lastPos = event->pos();
}

void Tetrahedron::mouseMoveEvent(QMouseEvent *event){
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if(event->buttons() & Qt::LeftButton){
       xRot += 4 * dy;
       yRot += 4 * dx;
       updateGL();
    }else if(event->buttons() & Qt::RightButton){
         xRot += 4 * dy;
         zRot += 4 * dx;
    }
    lastPos = event->pos();
}

void Tetrahedron::drawTriangle(){
    static const GLfloat P1[3] = { 0.0, -1.0, +2.0 };
    static const GLfloat P2[3] = { +1.73205081, -1.0, -1.0 };
    static const GLfloat P3[3] = { -1.73205081, -1.0, -1.0 };
    static const GLfloat P4[3] = { 0.0, +2.0, 0.0 };
    static const GLfloat * const coords[4][3] = {
        { P1, P2, P3 }, { P1, P3, P4 }, { P1, P2, P4 }, { P2, P4, P3 }
    };

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);
    for(int i = 0; i < 4; i++){
        glBegin(GL_TRIANGLES);
        qglColor(faceColors[i]);
        for (int j = 0; j < 3; ++j) {
             glVertex3f(coords[i][j][0], coords[i][j][1],  coords[i][j][2]);
        }
        glEnd();
    }
}

void Tetrahedron::normalizeAngle(int *angle){
    while(*angle < 0){
        angle += 360 * 16;
    }
    while(*angle > 360 * 16){
        angle -= 360 * 16;
    }
}

void Tetrahedron::setXRotation(int angle){
    normalizeAngle(&angle);
    if(angle != xRot){
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}


void Tetrahedron::setYRotation(int angle){
    normalizeAngle(&angle);
    if(angle != yRot){
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void Tetrahedron::setZRotation(int angle){
    normalizeAngle(&angle);
    if(angle != zRot){
        xRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void Tetrahedron::alwaysRotate(){
    zRot += 2;
    emit zRotationChanged(zRot);
    updateGL();
}




