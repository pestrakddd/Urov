#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QGLWidget>
#include <QtOpenGL>

class MainWindow : public QOpenGLWidget
{
private:
    GLuint m_nPyrarnid;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;

protected:
    virtual void initializeGL();
    virtual void resizeGL (int nWidth, int nHeight);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    GLuint createPyrarnid();

public:
    MainWindow(QWidget* pwgt = 0);
};
#endif // MAINWINDOW_H
