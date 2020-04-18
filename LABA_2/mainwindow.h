#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include <QPainter>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE 

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_AB_stateChanged(int arg1);
    void on_BC_stateChanged(int arg1);
    void on_CD_stateChanged(int arg1);
    void on_DA_stateChanged(int arg1);
    void on_DB_stateChanged(int arg1);
    void on_AC_stateChanged(int arg1);
    void on_AB_2_stateChanged(int arg1);
    void on_BC_2_stateChanged(int arg1);
    void on_CD_2_stateChanged(int arg1);
    void on_DA_2_stateChanged(int arg1);
    void on_DB_2_stateChanged(int arg1);
    void on_AC_2_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void drawFigure(QPainter &painter);
    int PointPeek [4][2];
    QPoint A, B, C, D;
    QPoint OX0, OX1, OY0, OY1;
    QDoubleValidator v1;
};
#endif // MAINWINDOW_H
