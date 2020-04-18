#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), v1(-100, 100, 2, this), v2(0.1, 50, 1, this)
{
    ui->setupUi(this);
    v1.setNotation(QDoubleValidator::StandardNotation);
    v2.setNotation(QDoubleValidator::StandardNotation);
    ui->startX->setValidator(&v1);
    ui->endX->setValidator(&v1);
    ui->step->setValidator(&v2);

    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->startX->text() == nullptr || ui->endX->text() == nullptr || ui->step->text() == nullptr) {
        QMessageBox::critical(this, "ошибка", "не заданы значиния диапазона и\\или шага");
    } else {
        int pos = ui->step->text().indexOf(",");
        int pos_1 = ui->startX->text().indexOf(",");
        int pos_2 = ui->endX->text().indexOf(",");
        if(pos != -1) {
            QString step = ui->step->text();
            step[pos] = '.';
            ui->step->setText(step);
        }
        if(pos_1 != -1) {
            QString startX = ui->startX->text();
            startX[pos_1] = '.';
            ui->startX->setText(startX);
        }
        if(pos_2 != -1) {
            QString endX = ui->endX->text();
            endX[pos_2] = '.';
            ui->endX->setText(endX);
        }
        calculate(ui->startX->text().toDouble(), ui->endX->text().toDouble(),  ui->step->text().toDouble());
    }
}

void MainWindow::calculate(double start, double end, double step)
{
    for(double x = start; x <= end; x += step) {
        QString line = "x: " + QString::number(x) + "  y: " + QString::number(sin(x));
        ui->textEdit->append(line + "\n");
    }
}

