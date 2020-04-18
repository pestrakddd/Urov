QT       += core gui opengl
LIBS += -lopengl32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    oglwidget.cpp \
    widget.cpp

HEADERS += \
    oglwidget.h \
    widget.h

