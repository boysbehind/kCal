#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#undef slots

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <Python.h>
#include <dialog_help.h>
#define slots Q_SLOTS

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int skin_change_type =0;    //0 不改变  1 随机改变  2 随英雄选择改变

    QVector<QStringList> hero_list;
    QVector<QStringList> rank;
    QVector<QStringList> skin_list;
    QVector<QStringList> hero_sugg;
    QVector<QStringList> hero_trank;
    QVector<QStringList> hero_kz;
    QVector<QStringList> hero_df;
    int hero_recomand[6];
    int choose_id=1;
    int hero_id = 49, skin_id = 1;
    bool kCal_clicked = false;


    QString last_background = "D:/kCal/data_processing/test/7";
    QString background = "D:/kCal/data_processing/test/7";


    //输入
    QString text1= "";
    //输出
    QString text2= "";
    //M的值
    QString Memory = "";
    //计算类型
    QString M = "";
    QString P = "";
    QString Power = "";
    int caltype=0;   //0正常， 1 power， 2 log.

    signals:
        void send_num(int x);
        void send_sign(char ch);
        void send_fun(QString str);
        void send_hero(int i);
        void send_trank(int i);

    public slots:
        void get_num(int x);
        void get_sign(char ch);
        void get_fun(QString str);
        void get_hero(int i);
        void get_trank(int i);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString get_ename(QString cname){
        QString ename = "";
        for (int i=0; i<hero_list.length(); i++){
            if (cname == hero_list[i][2]){
                ename = hero_list[i][1];
            }
        }
        return ename;
    }

    QString get_cname(QString ename){
        QString cname = "";
        for (int i=0; i<hero_list.length(); i++){
            if (ename == hero_list[i][1]){
                cname = hero_list[i][2];
            }
        }
        return cname;
    }

    void kz_init();
    void vstips_show();
    void hero_ability_show();
    void hero_Trank_init(QVector<QPushButton *> &hero_button);
    void hero_initialize(QVector<QPushButton *> &hero_button, QVector<QPushButton *> &hero_button1, QVector<QPushButton *> &hero_button2, QVector<QPushButton *> &hero_button3, QVector<QPushButton *> &hero_button4, QVector<QPushButton *> &hero_button5, QVector<QPushButton *> &hero_button6);

private slots:

        void paintEvent(QPaintEvent *);

        void on_pushButton_ce_clicked();

        void on_pushButton_c_clicked();

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

        void on_pushButton_sign_clicked();

        void on_pushButton_point_clicked();

        void on_pushButton_m_add_clicked();

        void on_button_m_inc_clicked();

        void on_button_sin_clicked();

        void on_button_sinh_clicked();

        void on_button_square_clicked();

        void on_button_root2_clicked();

        void on_button_cos_clicked();

        void on_button_cosh_clicked();

        void on_button_cube_clicked();

        void on_button_root3_clicked();

        void on_button_tan_clicked();

        void on_button_tanh_clicked();

        void on_button_power_clicked();

        void on_button_log_clicked();

        void on_button_cot_clicked();

        void on_button_pi_clicked();

        void on_button_exp_clicked();

        void on_button_ln_clicked();

        void on_pushButton_m_clicked();

        void on_pushbutton_equal_clicked();

        void on_pushButton_clicked();

        void on_kexue_Cal_clicked();

        void on_king_Cal_clicked();

        void on_pushButton_kexue_return_clicked();

        void on_pushButton_kCal_return_clicked();

        void on_pushButton_525_return_clicked();

        void on_pushButton_525_clicked();

        void on_pushButton_vs_clicked();

        void on_pushButton_ability_clicked();

        void on_pushButton_datachange_clicked();

        void on_pushButton_525_return_2_clicked();

        void on_pushButton_525_return_3_clicked();

        void on_pushButton_525_return_4_clicked();

        void on_pushButton_525A_clicked();

        void on_pushButton_5250_clicked();

        void on_pushButton_5251_clicked();

        void on_pushButton_5252_clicked();

        void on_pushButton_5253_clicked();

        void on_pushButton_5254_clicked();

        void on_pushButton_5255_clicked();

        void on_pushButton_525c1_clicked();

        void on_pushButton_525c2_clicked();

        void on_pushButton_525c3_clicked();

        void on_pushButton_525c4_clicked();

        void on_pushButton_525c5_clicked();

        void on_comboBox1_currentIndexChanged(int index);

        void on_comboBox2_currentIndexChanged(int index);

        void on_pushButton_525r1_pressed();

        void on_pushButton_525r2_pressed();

        void on_pushButton_525r3_pressed();

        void on_pushButton_525r4_pressed();

        void on_pushButton_525r5_pressed();

        void on_pushButton_525r6_pressed();

        void on_pushButton_525r1_released();

        void on_pushButton_525r2_released();

        void on_pushButton_525r3_released();

        void on_pushButton_525r4_released();

        void on_pushButton_525r5_released();

        void on_pushButton_525r6_released();

        void on_pushButton_next_skin_pressed();

        void on_pushButton_last_skin_pressed();

        void on_checkBox_clicked();

        void on_checkBox_2_clicked();

        void on_checkBox_3_clicked();

        void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
};

int word_analysis(QVector<QPair<QString, int>>& word,  const QString Memory, const QString expr);

// 获取运算符的优先级
int prior(int sym);

// 通过 种别编码 判定是否是运算符
bool isOperator(int sym);

// 中缀转后缀
QVector<QPair<QString, int>> getPostfix(const QVector<QPair<QString, int>>& expr);

// 从栈中连续弹出两个操作数
void popTwoNumbers(QStack<double>& s, double& first, double& second);

// 计算后缀表达式的值
double expCalculate(const QVector<QPair<QString, int>>& postfix);

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

void py_hello();
void py_hero_num();

#endif // MAINWINDOW_H
