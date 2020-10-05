//主窗口

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "QStack"
#include "dialog_help.h"

#include <QDebug>

const double PI=3.141592654;
const double EX=2.718281828;

//错误类型
QString error[12]={"正常",            //0
                  "右括号多于左括号",   //1
                  "小数点无整数部分",   //2
                  "小数点无小数部分",   //3
                  "连续使用运算符",     //4
                  "*或/的左边无数字",   //5
                  "+、-、*或/的右边无数字",  //6
                  "M未定义",           //7
                  "负数没有平方根",     //8
                  "x^y的第二个参数不能为空",      //9
                  "log(a, b)中b不能为空",        //10
                  "M只能存储(有限的)数值"         //11
};
//输入
QString text1="";
//输出
QString text2="";
//M的值
QString Memory="";
//计算类型
QString M="";
QString P="";
QString Power="";
int caltype=0;   //0正常， 1 power， 2 log.

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(this, SIGNAL(send_num(int)), SLOT(get_num(int)));
    connect(this, SIGNAL(send_sign(char)), SLOT(get_sign(char)));
    connect(this, SIGNAL(send_fun(QString)), SLOT(get_fun(QString)));
    ui->setupUi(this);
    MainWindow::ui->label_show_exp->setAlignment(Qt::AlignRight);
    MainWindow::ui->lineEdit_output->setAlignment(Qt::AlignRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void py_hello()
{
    Py_Initialize();
    if (!Py_IsInitialized()){
        return;
    }

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('D:/kCal')");

    PyObject* pModule = PyImport_ImportModule("hero_py");
    if (!pModule) {
        qDebug()<<"Can not find 1";
        return;
    }

    PyObject* args;
    PyObject* arg1;
    arg1=PyBytes_FromString("hello world");
    args = PyTuple_New(1);
    PyTuple_SetItem(args, 0, arg1);

    PyObject* pFunhello= PyObject_GetAttrString(pModule, "hello");
    PyObject* f = PyObject_CallObject(pFunhello, args);

    if (pFunhello){
        QString result = PyBytes_AsString(f);
        qDebug()<<result;
    }

    Py_Finalize();
}


//help按钮
void MainWindow::on_pushButton_clicked()
{
    Dialog_help *help=new Dialog_help(this);
    help->show();
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
        if(Memory==""){
            emit send_fun("m");
        }
        else{
            if (MainWindow::ui->label_show_exp->text()==""){
                text1="M";
            }
            else {
                text1=text1+"M";
            }
        }
        break;
    case '+': case '-': case '*': case '/': case '(': case ')': case '.':
        text1=text1+QChar(ch);break;
    default:break;
    }
    MainWindow::ui->label_show_exp->setText(text1);
}

void MainWindow::get_fun(QString str)
{
    if (str=="pi"){
        if (MainWindow::ui->label_show_exp->text()==""){
            text1="π";
        }
        else {
            text1=text1+"π";
        }
        MainWindow::ui->label_show_exp->setText(text1);
    }
    if (str=="exp"){
        if (MainWindow::ui->label_show_exp->text()==""){
            text1="e";
        }
        else {
            text1=text1+"e";
        }
        MainWindow::ui->label_show_exp->setText(text1);
    }
    if (str=="sign"){
        if(text1==""){
            text1="-";
        }
        else if(text1=="-"){
            text1="";
        }
        else{
            text1="-("+text1+")";
        }
        MainWindow::ui->label_show_exp->setText(text1);
    }
    else if(text1==""&&text2==""){
        MainWindow::ui->lineEdit_output->setText("Error: 请先输入！");return;
    }
    else if (text1==""){
        if (caltype==0){
            text1=text2;
        }
        else {
            MainWindow::ui->lineEdit_output->setText("Error: "+error[caltype+8]);return;
        }
    }
    if (str=="madd"){
        emit send_fun("equal");
        if (text2[0]>='0'&&text2[0]<='9'){
            Memory=text2;
            M="M";
            text1="M";
            MainWindow::ui->label_show_exp->setText(text1+"=");
        }
        else {
            MainWindow::ui->lineEdit_output->setText("Error: "+error[11]+"!");return;
        }
    }
    if (str=="m"){
        text2="Error: "+error[7]+"!";
    }
    if (str=="minc"){
        Memory=text2="";
        M="";
    }
    if (str=="sin"){
        emit send_fun("equal");
        text2=QString::number(Sin(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("sin("+text1+")=");
        text1=text2;
    }
    if (str=="sinh"){
        emit send_fun("equal");
        text2=QString::number(sinh(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("sinh("+text1+")=");
        text1=text2;
    }
    if (str=="square"){
        emit send_fun("equal");
        text2=QString::number(Exp(text2.toDouble(),2));
        MainWindow::ui->label_show_exp->setText("("+text1+")^2=");
        text1=text2;
    }
    if (str=="root2"){
        emit send_fun("equal");
        if (text1.toDouble()<0) text2=error[8];
        else{
            text2=QString::number(Exp(text2.toDouble(), 0.5));
            MainWindow::ui->label_show_exp->setText("("+text1+")^(1/2)=");
            text1=text2;
        }
    }
    if (str=="cos"){
        emit send_fun("equal");
        text2=QString::number(Cos(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("cos("+text1+")=");
        text1=text2;
    }
    if (str=="cosh"){
        emit send_fun("equal");
        text2=QString::number(cosh(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("cosh("+text1+")=");
        text1=text2;
    }
    if (str=="cube"){
        emit send_fun("equal");
        text2=QString::number(Exp(text2.toDouble(),3));
        MainWindow::ui->label_show_exp->setText("("+text1+")^3=");
        text1=text2;
    }
    if (str=="root3"){
        emit send_fun("equal");
        text2=QString::number(Exp(text2.toDouble(), 0.333333333));
        MainWindow::ui->label_show_exp->setText("("+text1+")^(1/3)=");
        text1=text2;
    }
    if (str=="tan"){
        emit send_fun("equal");
        text2=QString::number(Tan(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("tan("+text1+")=");
        text1=text2;
    }
    if (str=="tanh"){
        emit send_fun("equal");
        text2=QString::number(tanh(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("tanh("+text1+")=");
        text1=text2;
    }
    if (str=="power"){
        if (Power==""){
            if (text1==""&&text2==""){
                emit send_fun("equal");return;
            }
            else if (text1==""&&text2!=""){
                text1=text2;
            }
        }
        emit send_fun("equal");
        Power=text2;
        text2=text2+"^(_)";
        MainWindow::ui->label_show_exp->setText(text2);
        caltype=1;
        text1="";
        P="P";
    }
    if (str=="log"){
        if (Power==""){
            if (text1==""&&text2==""){
                emit send_fun("equal");return;
            }
            else if (text1==""&&text2!=""){
                text1=text2;
            }
        }
        emit send_fun("equal");
        Power=text2;
        text2="log("+text2+", (_))";
        MainWindow::ui->label_show_exp->setText(text2);
        caltype=2;
        text1="";
        P="P";
    }
    if (str=="cot"){
        emit send_fun("equal");
        text2=QString::number(Cot(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("cot("+text1+")=");
        text1=text2;
    }

    if (str=="ln"){
        emit send_fun("equal");
        text2=QString::number(Ln(text2.toDouble()));
        MainWindow::ui->label_show_exp->setText("ln("+text1+")=");
        text1=text2;
    }

    if (str=="equal"){
        QVector<QPair<QString, int>> word;
        int err_num = word_analysis(word, text1);
        if (err_num==0){
            double result=expCalculate(getPostfix(word));
            if(caltype==0){
                text2=QString::number(result);
            }
            else if (caltype==1) {
                text2=QString::number(Exp(Power.toDouble(), result));
            }
            else {
                text2=QString::number(Ln(Power.toDouble(), result));
            }
        }
        else {
            text2="Error: "+error[err_num]+"!";
        }
        QString label_s="";
        if (caltype==0)label_s=text1+"=";
        if (caltype==1)label_s=Power+"^("+text1+")=";
        if (caltype==2)label_s="log("+Power+", "+text1+")=";
        MainWindow::ui->label_show_exp->setText(label_s);
        caltype=0;
        P="";
    }
    MainWindow::ui->label_M->setText(M);
    MainWindow::ui->label_Power->setText(P);
    MainWindow::ui->lineEdit_output->setText(text2);
}

//中缀表达式情况分析
int word_analysis(QVector<QPair<QString, int>>& word, const QString expr)
{
    int cleft=0;  //cleft=左括号数量-右括号数量
    for(int i=0; i<expr.length(); ++i)
    {
        if(expr[i].unicode() =='M'){
            if (Memory=="")return 7;
            word.push_back(qMakePair(Memory, 5));
            if (i<expr.length()-1){
                if((expr[i+1]>='0' && expr[i+1]<='9')||expr[i+1]=='M'||expr[i+1]=='e'||expr[i+1]=="π"){
                    word.push_back(qMakePair('*', 3));
                }
            }
        }

        else if(expr[i].unicode() =='e'){
            word.push_back(qMakePair(QString::number(EX), 5));
            if (i<expr.length()-1){
                if((expr[i+1]>='0' && expr[i+1]<='9')||expr[i+1]=='M'||expr[i+1]=='e'||expr[i+1]=="π"){
                    word.push_back(qMakePair('*', 3));
                }
            }
        }

        else if(expr[i] == "π"){
            word.push_back(qMakePair(QString::number(PI), 5));
            if (i<expr.length()-1){
                if((expr[i+1]>='0' && expr[i+1]<='9')||expr[i+1]=='M'||expr[i+1]=='e'||expr[i+1]=="π"){
                    word.push_back(qMakePair('*', 3));
                }
            }
        }

        // 如果是 + - * / ( )
        else if(expr[i] == '(' || expr[i] == ')' || expr[i] == '+'
            || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            QString tmp;
            tmp.push_back(expr[i]);
            switch (expr[i].unicode())
            {
            case '+':
                word.push_back(qMakePair(tmp, 1));
                break;
            case '-':
                word.push_back(qMakePair(tmp, 2));
                break;
            case '*':
                word.push_back(qMakePair(tmp, 3));
                break;
            case '/':
                word.push_back(qMakePair(tmp, 4));
                break;
            case '(':
                cleft=cleft+1;
                word.push_back(qMakePair(tmp, 6));
                break;
            case ')':
                word.push_back(qMakePair(tmp, 7));
                cleft=cleft-1;
                if (cleft<0)return 1;  //右括号多于左括号
                break;
            }
        }

        // 如果是数字开头
        else if(expr[i]>='0' && expr[i]<='9')
        {
            QString tmp;
            while(expr[i]>='0' && expr[i]<='9')
            {
                tmp.push_back(expr[i]);
                ++i;
                if(i==expr.length())break;
            }

            if(i==expr.length()){
                word.push_back(qMakePair(tmp, 5));
                break;
            }

            if(expr[i].unicode() == 'M'){
                word.push_back(qMakePair(tmp, 5));
                word.push_back(qMakePair('^', 3));
                word.push_back(qMakePair(Memory, 5));
                if (i<expr.length()-1){
                    if (expr[i+1]!='+'||expr[i+1]!='-'||expr[i+1]!='*'||expr[i+1]!='/'||expr[i+1]!=')')
                        word.push_back(qMakePair('*', 3));
                }
                continue;
            }

            if(expr[i].unicode() == 'e'){
                word.push_back(qMakePair(tmp, 5));
                word.push_back(qMakePair('^', 3));
                word.push_back(qMakePair(QString::number(EX), 5));
                if (i<expr.length()-1){
                    if (expr[i+1]!='+'||expr[i+1]!='-'||expr[i+1]!='*'||expr[i+1]!='/'||expr[i+1]!=')')
                        word.push_back(qMakePair('*', 3));
                }
                continue;
            }

            if(expr[i] == "π"){
                word.push_back(qMakePair(tmp, 5));
                word.push_back(qMakePair('^', 3));
                word.push_back(qMakePair(QString::number(PI), 5));
                if (i<expr.length()-1){
                    if (expr[i+1]!='+'||expr[i+1]!='-'||expr[i+1]!='*'||expr[i+1]!='/'||expr[i+1]!=')')
                        word.push_back(qMakePair('*', 3));
                }
                continue;
            }

            if(expr[i] == '.')
            {
                ++i;
                if(i==expr.length())return 3;    //.在最右边
                if(expr[i]>='0' && expr[i]<='9')
                {
                    tmp.push_back('.');
                    while(expr[i]>='0' && expr[i]<='9')
                    {
                        tmp.push_back(expr[i]);
                        ++i;
                        if (i==expr.length())break;
                    }
                }
                else
                {
                    return 3;  // .后面直接跟运算符
                }
            }
            word.push_back(qMakePair(tmp, 5));
            if (i==expr.length())break;
            i--;
        }

        // 如果以.开头
        else
        {
            return 2;  // 以.开头
        }
    }

    // 左括号更多时在右边添加相应数量的右括号
    if (cleft>0){
        for (int c=0; c<cleft; c++){
            word.push_back(qMakePair(')', 7));
        }
    }

    for (int i=0; i<word.length(); i++){
        int tmp=word[i].second;
        if (tmp==1||tmp==2){
            if(i==0){
                word.insert(i, qMakePair('0', 5));  //左边加0
                i++;
            }
            if(i>0){
                if(word[i-1].second==1||word[i-1].second==2||word[i-1].second==3||word[i-1].second==4)
                    return 4;         // -或+的前面为运算符
                if(word[i-1].second==6){
                    word.insert(i-1, qMakePair('0', 5));  //左边加0
                    i++;
                }
            }
            if(i==word.length()-1)return 6;
        }
        if (tmp==3||tmp==4){
            if(i==0)return 5;     //*或/在最前面
            if(i>0){
                if(word[i-1].second==1||word[i-1].second==2||word[i-1].second==3||word[i-1].second==4)
                    return 4;     //*或/的前面为运算符
                if(word[i-1].second==6)
                    return 5;    //*或/的前面为（
            }
            if(i==word.length()-1)return 6;
        }
        if (tmp==5){
            if (i>0){
                if (word[i-1].second==5){
                    word.insert(i, qMakePair('*', 3));   // 数字前加缺失的*
                    i++;
                }
            }
        }
        if (tmp==6){
            if (i>0){
                if (word[i-1].second==5){
                    word.insert(i, qMakePair('*', 3));   // (前加缺失的*
                    i++;
                }
            }
        }
        if (tmp==7){
            if(i<word.length()-1){
                if (word[i+1].second==5||word[i+1].second==6){
                    word.insert(i+1, qMakePair('*', 3));    // )后加上缺失的*
                }
                if(word[i-1].second==1||word[i-1].second==2){
                    word.insert(i, qMakePair('0', 5));    //-)或+)中间加缺省的0
                }
                if(word[i-1].second==6){
                    word.insert(i, qMakePair('1', 5));    //()中加缺省的1
                }
            }
            if (word[i-1].second==3||word[i-1].second==4)
                return 6;     // *或/的后面为）
        }
    }
    return 0;   //运算符正常
}


// 获取运算符的优先级
int prior(int sym)
{
    switch (sym)
    {
        case 1:
        case 2:
            return 1;
        case 3:
        case 4:
            return 2;
        default:
            return 0;
    }
}

// 通过 种别编码 判定是否是运算符
bool isOperator(int sym)
{
    switch (sym)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            return true;
        default:
            return false;
    }
}

// 中缀转后缀
QVector<QPair<QString, int>> getPostfix(const QVector<QPair<QString, int>>& expr)
{
    QVector<QPair<QString, int>> output;  // 输出
    QStack<QPair<QString, int>> s;  // 操作符栈
    for(int i=0; i<expr.size(); ++i)
    {
        QPair<QString, int> p = expr[i];
        if(isOperator(p.second))
        {
            while(!s.empty() && isOperator(s.top().second) && prior(s.top().second)>=prior(p.second))
            {
                output.push_back(s.top());
                s.pop();
            }
            s.push(p);
        }
        else if(p.second == 6)
        {
            s.push(p);
        }
        else if(p.second == 7)
        {
            while(s.top().second != 6)
            {
                output.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            output.push_back(p);
        }
    }
    while (!s.empty())
    {
        output.push_back(s.top());
        s.pop();
    }
    return output;
}

// 从栈中连续弹出两个操作数
void popTwoNumbers(QStack<double>& s, double& first, double& second)
{
    first = s.top();
    s.pop();
    second = s.top();
    s.pop();
}

// 计算后缀表达式的值
double expCalculate(const QVector<QPair<QString, int>>& postfix)
{
    double first, second;
    QStack<double> s;
    for(int i=0; i<postfix.size(); ++i)
    {
        QPair<QString,int> p = postfix[i];
        switch (p.second)
        {
        case 1:
            popTwoNumbers(s, first, second);
            s.push(second+first);
            break;
        case 2:
            popTwoNumbers(s, first, second);
            s.push(second-first);
            break;
        case 3:
            popTwoNumbers(s, first, second);
            s.push(second*first);
            break;
        case 4:
            popTwoNumbers(s, first, second);
            s.push(second/first);
            break;
        default:
            s.push(p.first.toDouble());
            break;
        }
    }
    double result= s.top();
    s.pop();
    return result;
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

void MainWindow::on_pushButton_ce_clicked()
{
    emit send_sign('i');
}

void MainWindow::on_pushButton_c_clicked()
{
    emit send_sign('d');
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


void MainWindow::on_pushButton_sign_clicked()
{
    emit send_fun("sign");
}

void MainWindow::on_pushButton_point_clicked()
{
    emit send_sign('.');
}

void MainWindow::on_pushButton_m_add_clicked()
{
    emit send_fun("madd");
}

void MainWindow::on_button_m_inc_clicked()
{
    emit send_fun("minc");
}

void MainWindow::on_button_sin_clicked()
{
    emit send_fun("sin");
}

void MainWindow::on_button_sinh_clicked()
{
    emit send_fun("sinh");
}


void MainWindow::on_button_square_clicked()
{
    emit send_fun("square");
}

void MainWindow::on_button_root2_clicked()
{
    emit send_fun("root2");
}

void MainWindow::on_button_cos_clicked()
{
    emit send_fun("cos");
}

void MainWindow::on_button_cosh_clicked()
{
    emit send_fun("cosh");
}

void MainWindow::on_button_cube_clicked()
{
    emit send_fun("cube");
}

void MainWindow::on_button_root3_clicked()
{
    emit send_fun("root3");
}


void MainWindow::on_button_tan_clicked()
{
    emit send_fun("tan");
}

void MainWindow::on_button_tanh_clicked()
{
    emit send_fun("tanh");
}


void MainWindow::on_button_power_clicked()
{
    emit send_fun("power");
}

void MainWindow::on_button_log_clicked()
{
    emit send_fun("log");
}

void MainWindow::on_button_cot_clicked()
{
    emit send_fun("cot");
}

void MainWindow::on_button_pi_clicked()
{
    emit send_fun("pi");
}

void MainWindow::on_button_exp_clicked()
{
    emit send_fun("exp");
}

void MainWindow::on_button_ln_clicked()
{
    emit send_fun("ln");
}

void MainWindow::on_pushButton_m_clicked()
{
    emit send_sign('m');
}

void MainWindow::on_pushbutton_equal_clicked()
{
    emit send_fun("equal");
}

void MainWindow::on_kexue_Cal_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_king_Cal_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_kexue_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_kCal_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
