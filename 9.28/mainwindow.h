#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_kexue_clicked();

private:
    Ui::MainWindow *ui;
};

//阶乘
int Factorial(int n);

//三角函数
double sin(double x);
double cos(double x);
double tan(double x);
double cot(double x);

//对数指数
double ln(double x);
double ln(double a, double b);
double exp(double x);
double exp(double x, double y);

//排列组合
int arrange(int a, int b);
int compose(int a, int b);



#endif // MAINWINDOW_H
