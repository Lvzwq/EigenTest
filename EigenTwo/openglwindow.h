#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include<QWindow>
#include<QOpenGLFunctions>
#include<QEvent>
#include<QOpenGLPaintDevice>

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();
    virtual void render(QPainter *painter);
    virtual void render();
    virtual void initialize();
    void setAnimating(bool animating);

signals:

public slots:
    void renderLater();
    void renderNow();
    
protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;
    
private:
    bool m_update_pending;
    bool m_animating;
    
    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif // OPENGLWINDOW_H
