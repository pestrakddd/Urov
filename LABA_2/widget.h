#pragma once
#include <QWidget>
#include "oglwidget.h"


class Widget : public QWidget
{
    Q_OBJECT
    OGLWidget *ogl;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event);
};

