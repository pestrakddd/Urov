#include "mainwindow.h"
#include <QOpenGLFunctions>

MainWindow::MainWindow(QWidget* pwgt) : QOpenGLWidget(pwgt)
    , m_xRotate(0)
    , m_yRotate(0)
{

}


void MainWindow::initializeGL() {
    QOpenGLFunctions *pFunc =
    QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nPyrarnid = createPyrarnid();
}


void MainWindow::resizeGL(int nWidth, int nHeight) {
    glViewport(0, 0, (GLint) nWidth, (GLint) nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

void MainWindow::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);
    glCallList(m_nPyrarnid);
}

void MainWindow::mousePressEvent(QMouseEvent* pe) {
    m_ptPosition = pe->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* pe) {
    m_xRotate += 180 * (GLfloat) (pe->y() - m_ptPosition.y()) / height ();
    m_yRotate += 180 * (GLfloat) (pe->x() - m_ptPosition.x()) / width();
    update();
    m_ptPosition - pe->pos();
}

GLuint MainWindow::createPyrarnid() {
    GLuint n = glGenLists(1);
//    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    glBegin(GL_QUADS);

    QFile file("./AllPoints.txt");
    QFile file2("./Colors.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || !file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug() << "can't open account list";
     } else {
       QString line;
       QString line2;
       QTextStream accIn(&file), lineIn(&line);
       QTextStream accIn2(&file2), lineIn2(&line2);

       int Zoom = 3;
       int countGr = 0;
       while (!accIn.atEnd()) {
           line2 = accIn2.readLine();
           lineIn2.flush();
           QStringList colors = line2.split(" ");
           qDebug() << colors;
           glColor4f(colors[0].toFloat(), colors[1].toFloat(), colors[2].toFloat(), colors[3].toFloat());

           for(int i = 0; i < 4; i++) {
               line = accIn.readLine();
               lineIn.flush();
               QStringList points = line.split(" ");
               glVertex3f(points[0].toFloat() * Zoom, points[1].toFloat() * Zoom, points[2].toFloat() * Zoom);
           }
           countGr++;
           if(countGr == 6) {
               line = accIn.readLine();
               lineIn.flush();
               line2 = accIn2.readLine();
               lineIn2.flush();
               countGr = 0;
           }
       }
    }
    glEnd();
    glEndList () ;
    return n;
}




