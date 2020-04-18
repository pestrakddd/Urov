#include "widget.h"
#include <QtOpenGL>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ogl = new OGLWidget(this);
    ogl->resize(800,600);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    ogl->resize(width(),height());
}

