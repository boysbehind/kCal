//主窗口

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "dialog_help.h"

const double PI=3.141592654;
const double EX=2.718281828;
const QString m_warning("No memory!");
QString text1="";
QString text2="";
QString Memory=NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(this, SIGNAL(send_num(int)), SLOT(get_num(int)));
    connect(this, SIGNAL(send_sign(char)), SLOT(get_sign(char)));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_num(int x)
{
    MainWindow::ui->lineEdit_output->clear();
    if (x>=0 && x<=9)
        text1=text1+QString::number(x);
        MainWindow::ui->label_show_exp->setText(text1);

}

void MainWindow::get_sign(char ch)
{
    MainWindow::ui->lineEdit_output->clear();
    switch (ch) {
    case 'i': text1="";break;
    case 'd': text1=text1.remove(text1.length()-1,text1.length());break;
    case 'm':
        if (Memory==NULL)
        {
            if(text1.end()==QChar('+')||text1.end()==QChar('-')||text1.end()==QChar('*')||text1.end()==QChar('/')||text1.end()==QChar('(')||text1.end()==QChar(')'))
            {
                MainWindow::ui->lineEdit_output->insert(m_warning);
            }
            else {

            }
        }
        else if(text1.end()==QChar('+')||text1.end()==QChar('-')||text1.end()==QChar('*')||text1.end()==QChar('/')||text1.end()==QChar('(')||text1.end()==QChar(')'))
        {
            text1=text1+Memory;
        }
        else{
            Memory=text2;
            text1=QString("M= ")+text2;
        }break;
    case '+': case '-': case '*': case '/': case '(': case ')': case '.':
        text1=text1+QChar(ch);break;
    default:break;
    }
    MainWindow::ui->label_show_exp->setText(text1);
}

//计算并返回n！(阶乘)
int Factorial(int n)
{
    if (n==1)return 1;
    return n*Factorial(n-1);
}

//三角函数
//计算并返回sin(x)的值
double Sin(double x)
{
    return sin(x);
}

//计算并返回cos(x)的值
double Cos(double x)
{
    return cos(x);
}

//计算并返回tan(x)的值
double Tan(double x)
{
    return tan(x);
}

//计算并返回cot(x)的值
double Cot(double x)
{
    double y=(180*x/PI+90)*PI/180;
    return tan(y);
}

//对数指数

//计算并返回ln(x)的值
double Ln(double x)
{
    return log(x)/log(EX);
}

//计算并返回log(a, b)=ln(b)/ln(a)的值
double Ln(double a, double b)
{
    return log(b)/log(a);
}

//计算并返回e^x的值
double Exp(double x)
{
    return pow(EX, x);
}

//计算并返回x^y的值
double Exp(double x, double y)
{
    return pow(x, y);
}

//排列组合
//计算并返回A(a, b)的值
int Arrange(int a, int b)
{
    return Factorial(b)/Factorial(b-a);
}

//计算并返回C(a, b)的值
int Compose(int a, int b)
{
    return Arrange(a, b)/Factorial(a);
}


void MainWindow::on_pushButton_ce_clicked()
{
    emit send_sign('i');
}

void MainWindow::on_pushButton_c_clicked()
{
    emit send_sign('d');
}

void MainWindow::on_pushButton_m_clicked()
{
    emit send_sign('m');
}

void MainWindow::on_pushButton_1_clicked()
{
    emit send_num(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    emit send_num(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    emit send_num(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    emit send_num(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    emit send_num(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    emit send_num(6);
}


void MainWindow::on_pushButton_7_clicked()
{
    emit send_num(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    emit send_num(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    emit send_num(9);
}

void MainWindow::on_pushButton_0_clicked()
{
    emit send_num(0);
}

void MainWindow::on_pushButton_add_clicked()
{
    emit send_sign('+');
}


void MainWindow::on_pushButton_inc_clicked()
{
    emit send_sign('-');
}

void MainWindow::on_pushButton_mul_clicked()
{
    emit send_sign('*');
}

void MainWindow::on_pushButton_div_clicked()
{
    emit send_sign('/');
}

void MainWindow::on_pushButton_cleft_clicked()
{
    emit send_sign('(');
}

void MainWindow::on_pushButton_cright_clicked()
{
    emit send_sign(')');
}

