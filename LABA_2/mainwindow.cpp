#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), v1(-100, 100, 0, this)
{
    ui->setupUi(this);

    v1.setNotation(QDoubleValidator::StandardNotation);

    ui->X1->setRange(-1000, 1000);
    ui->X1->setValue(-318);
    ui->Y1->setRange(-1000, 1000);
    ui->Y1->setValue(-48);

    ui->X2->setRange(-1000, 1000);
    ui->X2->setValue(0);
    ui->Y2->setRange(-1000, 1000);
    ui->Y2->setValue(-178);

    ui->X3->setRange(-1000, 1000);
    ui->X3->setValue(378);
    ui->Y3->setRange(-1000, 1000);
    ui->Y3->setValue(0);

    ui->X4->setRange(-1000, 1000);
    ui->X4->setValue(-57);
    ui->Y4->setRange(-1000, 1000);
    ui->Y4->setValue(200);

    ui->AC->setChecked(true);
    ui->AB->setChecked(false);
    ui->BC->setChecked(false);
    ui->CD->setChecked(false);
    ui->DA->setChecked(false);
    ui->DB->setChecked(false);

    ui->AB_2->setChecked(true);
    ui->BC_2->setChecked(true);
    ui->DB_2->setChecked(true);
    ui->AC_2->setChecked(true);
    ui->CD_2->setChecked(true);
    ui->DA_2->setChecked(true);

    PointPeek[0][0] = -318;
    PointPeek[0][1] =  -48;
    PointPeek[1][0] = 0;
    PointPeek[1][1] = -178;
    PointPeek[2][0] = 378;
    PointPeek[2][1] = 0;
    PointPeek[3][0] = -57;
    PointPeek[3][1] = 200;

    ui->Width->setReadOnly(true);
    ui->Height->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(ui->openGLWidget);
    drawFigure(paint);
}


void MainWindow::on_pushButton_clicked()
{
    PointPeek[0][0] = ui->X1->value();
    PointPeek[0][1] = ui->Y1->value();
    PointPeek[1][0] = ui->X2->value();
    PointPeek[1][1] = ui->Y2->value();
    PointPeek[2][0] = ui->X3->value();
    PointPeek[2][1] = ui->Y3->value();
    PointPeek[3][0] = ui->X4->value();
    PointPeek[3][1] = ui->Y4->value();

    ui->openGLWidget->update();
}

void MainWindow::drawFigure(QPainter &painter)
{
    ui->Width->setText(QString::number(ui->openGLWidget->width()));
    ui->Height->setText(QString::number(ui->openGLWidget->height()));

    int XCenter = ui->openGLWidget->width() / 2;
    int YCenter = ui->openGLWidget->height() / 2;

    QPen penOXY(Qt::gray);
    penOXY.setWidth(3);
    QPen penPoint(Qt::white);
    penPoint.setWidth(5);
    QPen penLine(Qt::green);
    penLine.setWidth(9);
    QPen penLine_DashLine(Qt::green);
    penLine_DashLine.setWidth(9);
    penLine_DashLine.setStyle(Qt::DashLine);
    QPen penText(Qt::white);
    painter. setFont (QFont ( "Tirnes", 25, QFont::Normal));

    OX0.setX(0);
    OX0.setY(ui->openGLWidget->height() / 2);
    OX1.setX(ui->openGLWidget->width());
    OX1.setY(ui->openGLWidget->height() / 2);
    OY0.setX(ui->openGLWidget->width() / 2);
    OY0.setY(0);
    OY1.setX(ui->openGLWidget->width() / 2);
    OY1.setY(ui->openGLWidget->height());


    painter.setPen(penOXY);

    painter.drawLine(OX0, OX1);
    painter.drawLine(OY0, OY1);

    if(ui->AB_2->isChecked()) {
        if(ui->AB->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(A, B);
        } else {
            painter.setPen(penLine);
            painter.drawLine(A, B);
        }
    }
    if(ui->BC_2->isChecked()) {
        if(ui->BC->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(B, C);
        } else {
            painter.setPen(penLine);
            painter.drawLine(B, C);
        }
    }
    if(ui->CD_2->isChecked()) {
        if(ui->CD->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(C, D);
        } else {
            painter.setPen(penLine);
            painter.drawLine(C, D);
        }
    }
    if(ui->DB_2->isChecked()) {
        if(ui->DB->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(D, B);
        } else {
            painter.setPen(penLine);
            painter.drawLine(D, B);
        }
    }
    if(ui->DA_2->isChecked()) {
        if(ui->DA->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(D, A);
        } else {
            painter.setPen(penLine);
            painter.drawLine(D, A);
        }
    }
    if(ui->AC_2->isChecked()) {
        if(ui->AC->isChecked()) {
            painter.setPen(penLine_DashLine);
            painter.drawLine(A, C);
        } else {
            painter.setPen(penLine);
            painter.drawLine(A, C);
        }
    }

    painter.setPen(penPoint);

    A.setX(XCenter + PointPeek[0][0]);
    A.setY(YCenter - PointPeek[0][1]);
    B.setX(XCenter + PointPeek[1][0]);
    B.setY(YCenter - PointPeek[1][1]);
    C.setX(XCenter + PointPeek[2][0]);
    C.setY(YCenter - PointPeek[2][1]);
    D.setX(XCenter + PointPeek[3][0]);
    D.setY(YCenter - PointPeek[3][1]);

    painter.drawPoint(A);
    painter.drawPoint(B);
    painter.drawPoint(C);
    painter.drawPoint(D);


    painter.setPen(penText);

    painter.drawText(A, "A");
    painter.drawText(B, "B");
    painter.drawText(C, "C");
    painter.drawText(D, "D");
}

void MainWindow::on_AB_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_BC_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_CD_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_DB_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_DA_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_AC_stateChanged(int) { ui->openGLWidget->update(); }

void MainWindow::on_AB_2_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_BC_2_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_CD_2_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_DA_2_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_DB_2_stateChanged(int) { ui->openGLWidget->update(); }
void MainWindow::on_AC_2_stateChanged(int) { ui->openGLWidget->update(); }
