#pragma once
#include <QOpenGLWidget>

class OGLWidget : public QOpenGLWidget
{
public:
    OGLWidget(QWidget* pwgt = nullptr);
protected:
    void initializeGL( );
    void resizeGL (int nWidth, int nHeight);
    void paintGL ( );
};


