#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    signals:
        void send_num(int x);
        void send_sign(char ch);

    public slots:
        void get_num(int x);
        void get_sign(char ch);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

        void on_pushButton_ce_clicked();

        void on_pushButton_c_clicked();

        void on_pushButton_m_clicked();

        void on_pushButton_1_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_9_clicked();

        void on_pushButton_0_clicked();

        void on_pushButton_add_clicked();

        void on_pushButton_inc_clicked();

        void on_pushButton_mul_clicked();

        void on_pushButton_div_clicked();

        void on_pushButton_cleft_clicked();

        void on_pushButton_cright_clicked();

private:
    Ui::MainWindow *ui;
};

//阶乘
int Factorial(int n);

//三角函数
double Sin(double x);
double Cos(double x);
double Tan(double x);
double Cot(double x);

//对数指数
double Ln(double x);
double Ln(double a, double b);
double Exp(double x);
double Exp(double x, double y);

//排列组合
int Arrange(int a, int b);
int Compose(int a, int b);



#endif // MAINWINDOW_H
