#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

const double PI=3.141592654;
const double EX=2.718281828;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_kexue_clicked()
{

}

//计算并返回n！(阶乘)
int Factorial(int n)
{
    if (n==1)return 1;
    return n*Factorial(n-1);
}

//三角函数
//计算并返回sin(x)的值
double sin(double x)
{

}

//计算并返回cos(x)的值
double cos(double x)
{

}

//计算并返回tan(x)的值
double tan(double x)
{

}

//计算并返回cot(x)的值
double cot(double x)
{

}

//对数指数

//计算并返回ln(x)的值
double ln(double x)
{

}

//计算并返回log(a, b)=ln(b)/ln(a)的值
double ln(double a, double b)
{

}

//计算并返回e^x的值
double exp(double x)
{

}

//计算并返回x^y的值
double exp(double x, double y)
{

}

//排列组合
//计算并返回A(a, b)的值
int arrange(int a, int b)
{
    return Factorial(b)/Factorial(b-a);
}

//计算并返回C(a, b)的值
int compose(int a, int b)
{

}
