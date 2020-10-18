//主窗口

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "QStack"
#include "QFile"
#include "dialog_help.h"
#include "dialog_fail.h"
#include "QTextCodec"
#include "qpainter.h"
#include "QTime"

#include <QDebug>

const double PI=3.141592654;
const double EX=2.718281828;

const QString stySheet1 = "QPushButton {background-color: rgba(38, 95, 152, 100);}";
const QString stySheet2 = "QPushButton {background-color: rgba(38, 95, 152, 100);border-width: 2px;border-style: outset;border-radius: 0px;border-color: rgba(170, 255, 255, 255);box-shadow: 0px 0px 19px rgba(0, 255, 255, 255);}";

//错误类型
const QString error[12]={"正常",            //0
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute((Qt::WA_TranslucentBackground));
    connect(this, SIGNAL(send_num(int)), SLOT(get_num(int)));
    connect(this, SIGNAL(send_sign(char)), SLOT(get_sign(char)));
    connect(this, SIGNAL(send_fun(QString)), SLOT(get_fun(QString)));
    connect(this, SIGNAL(send_hero(int)), SLOT(get_hero(int)));
    connect(this, SIGNAL(send_trank(int)), SLOT(get_trank(int)));
    ui->setupUi(this);
    MainWindow::ui->label_show_exp->setAlignment(Qt::AlignRight);
    MainWindow::ui->lineEdit_output->setAlignment(Qt::AlignRight);
    ui->label_vsheroname2->setAlignment(Qt::AlignRight);
    ui->label_vstype2->setAlignment(Qt::AlignRight);
    QVector<QPushButton *> hero_button, hero_button1, hero_button2, hero_button3, hero_button4, hero_button5, hero_button6, hero_button7;
    hero_initialize(hero_button, hero_button1, hero_button2, hero_button3, hero_button4, hero_button5, hero_button6);
    hero_Trank_init(hero_button7);

    QPixmap pixmap = QPixmap("D:/kCal/icon_pic/vs.png").scaled(ui->label_vsicon->size(),Qt::KeepAspectRatio);
    ui->label_vsicon->setPixmap(pixmap);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vstips_show()
{
    int type1 = hero_list[ui->comboBox1->currentIndex()][4].toInt();
    int type2 = hero_list[ui->comboBox2->currentIndex()][4].toInt();
    int arr[2] = {0, 0};

    for (int i=0; i<13; i++){
        if (hero_kz[ui->comboBox1->currentIndex()].size() == 1)break;
        if (hero_kz[ui->comboBox1->currentIndex()][i] == ui->label_vsheroname2->text()){
            arr[0] = 1;
            arr[1] = i;
            break;
        }
    }

    if (arr[0] == 0){
        for (int i=0; i<13; i++){
            if (hero_kz[ui->comboBox2->currentIndex()].size() == 1)break;
            if (hero_kz[ui->comboBox2->currentIndex()][i] == ui->label_vsheroname1->text()){
                arr[0] = 2;
                arr[1] = i;
                break;
            }
        }
    }

    if (arr[0] == 1){
        ui->label_vstip4_tip->setText("Tip 4");
        if (arr[1]<7){
            ui->label_vstip4->setText(ui->label_vsheroname2->text()+"较为克制"+ui->label_vsheroname1->text()+", 克制指数"+hero_kz[ui->comboBox1->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname1->text()+"时, 可选择"+ui->label_vsheroname2->text()+"。");
            ui->label_vstip5->setText(ui->label_vsheroname1->text()+"被"+ui->label_vsheroname2->text()+"克制, 被克制指数"+hero_kz[ui->comboBox1->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname2->text()+"时, 不要选择"+ui->label_vsheroname1->text()+"。");
        }
        else {
            ui->label_vstip4->setText(ui->label_vsheroname1->text()+"被"+ui->label_vsheroname2->text()+"克制, 克制指数"+hero_kz[ui->comboBox1->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname2->text()+"时, 不要选择"+ui->label_vsheroname1->text()+"。");
            ui->label_vstip5->setText(ui->label_vsheroname2->text()+"较为克制"+ui->label_vsheroname1->text()+", 被克制指数"+hero_kz[ui->comboBox1->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname1->text()+"时, 可选择"+ui->label_vsheroname2->text()+"。");
        }
    }

    if (arr[0] == 2){
        ui->label_vstip4_tip->setText("Tip 4");
        if (arr[1]<7){
            ui->label_vstip4->setText(ui->label_vsheroname1->text()+"较为克制"+ui->label_vsheroname2->text()+", 克制指数"+hero_kz[ui->comboBox2->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname2->text()+"时, 可选择"+ui->label_vsheroname1->text()+"。");
            ui->label_vstip5->setText(ui->label_vsheroname2->text()+"被"+ui->label_vsheroname1->text()+"克制, 被克制指数"+hero_kz[ui->comboBox2->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname1->text()+"时, 不要选择"+ui->label_vsheroname2->text()+"。");
        }
        else {
            ui->label_vstip4->setText(ui->label_vsheroname2->text()+"被"+ui->label_vsheroname1->text()+"克制, 克制指数"+hero_kz[ui->comboBox2->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname1->text()+"时, 不要选择"+ui->label_vsheroname2->text()+"。");
            ui->label_vstip5->setText(ui->label_vsheroname1->text()+"较为克制"+ui->label_vsheroname2->text()+", 被克制指数"+hero_kz[ui->comboBox2->currentIndex()][arr[1]-1]+", 当对面有"+ui->label_vsheroname2->text()+"时, 可选择"+ui->label_vsheroname1->text()+"。");
        }
    }

    if (arr[0] == 0){
        ui->label_vstip4_tip->setText("");
        ui->label_vstip4->setText("");
        ui->label_vstip5->setText("");
    }

    QString tmp="";

    if (ui->progressBar_vs1_4->value()>5 && ui->progressBar_vs2_4->value()>5){
        tmp = ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"上手难度都较大。";
    }

    if (ui->progressBar_vs1_4->value()<5 && ui->progressBar_vs2_4->value()<5){
        tmp = ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"上手难度都较小。";
    }

    if (ui->progressBar_vs1_4->value()>ui->progressBar_vs2_4->value()){
        tmp = tmp + ui->label_vsheroname1->text() +"更难上手。";
    }
    if (ui->progressBar_vs1_4->value()<ui->progressBar_vs2_4->value()){
        tmp = tmp + ui->label_vsheroname2->text() +"更难上手。";
    }
    if (ui->progressBar_vs1_4->value()==ui->progressBar_vs2_4->value()){
        tmp = tmp + ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"上手难度相当。";
    }
    ui->label_vstip3->setText(tmp);

    switch (type1) {
    case 1:
        switch (type2) {
        case 1:
            if (ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()>=-1 && ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"生存能力相当。");
            }
            else {
                if (ui->progressBar_vs1_1->value()>ui->progressBar_vs2_1->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname1->text()+"。");
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname2->text()+"。");
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname1->text()+"。");
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname2->text()+"。");
                }
            }
            break;
        case 2:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为战士, 在" + ui->label_vsheroname2->text() +"输出高时应尽早出法抗装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为法师, 后期在" + ui->label_vsheroname1->text() +"输出高时可适当出一些防御装备。");
            break;
        case 3:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为战士, 在" + ui->label_vsheroname2->text() +"坦度高时可以适当出一些输出装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为坦克, 在" + ui->label_vsheroname1->text() +"经济较高时不应与之正面对抗。");
            break;
        case 4:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为战士, 在" + ui->label_vsheroname2->text() +"输出高时可以适当出一些防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 在" + ui->label_vsheroname1->text() +"经济较高于自己时不应与之单独对抗。");
            break;
        case 5:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为战士, 在" + ui->label_vsheroname2->text() +"输出高时可以适当出一些防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为射手, 在" + ui->label_vsheroname1->text() +"经济接近或高于自己时不应与之单独对抗。");
            break;
        case 6:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为战士, 在" + ui->label_vsheroname2->text() +"坦度高时可以适当出一些输出装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为辅助, 在" + ui->label_vsheroname1->text() +"经济高于自己时不应与之单独对抗。");
            break;
        default:break;
        }break;
    case 2:
        switch (type2) {
        case 1:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为战士, 在" + ui->label_vsheroname1->text() +"输出高时应尽早出法抗装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为法师, 后期在" + ui->label_vsheroname2->text() +"输出高时可适当出一些防御装备。");
            break;
        case 2:
            if (ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"输出能力相当。");
            }
            else {
                if (ui->progressBar_vs1_2->value()>ui->progressBar_vs2_2->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"输出能力更强, 在对面射手、刺客生存能力高时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"输出能力更强, 在对面射手、刺客生存能力高时可选择"+ui->label_vsheroname2->text());
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname2->text());
                }
            }
            break;
        case 3:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为坦克, 在" + ui->label_vsheroname1->text() +"输出高时应尽早出法抗装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为法师, 后期在" + ui->label_vsheroname2->text() +"输出高时可适当出一些防御装备。");
            break;
        case 4:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为法师, 后期在" + ui->label_vsheroname2->text() +"输出高时可适当出一些防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 在" + ui->label_vsheroname1->text() +"输出高时可以出一些法抗装备。");
            break;
        case 5:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为法师, 后期尽量找机会先手秒掉" + ui->label_vsheroname2->text() +"。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为射手, 在" + ui->label_vsheroname1->text() +"输出高时可以出一些法抗装备。");
            break;
        case 6:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为法师, 后期在" + ui->label_vsheroname2->text() +"控制多时可出辉月等保命装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 在" + ui->label_vsheroname1->text() +"输出高时应当出一些法抗装备。");
            break;
        default:break;
        }break;
    case 3:
        switch (type2) {
        case 1:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为战士, 在" + ui->label_vsheroname1->text() +"坦度高时可以适当出一些输出装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为坦克, 在" + ui->label_vsheroname2->text() +"经济较高时不应与之正面对抗。");
            break;
        case 2:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为坦克, 在" + ui->label_vsheroname2->text() +"输出高时应尽早出法抗装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为法师, 后期在" + ui->label_vsheroname1->text() +"输出高时可适当出一些防御装备。");
            break;
        case 3:
            if (ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()>=-1 && ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"生存能力相当。");
            }
            else {
                if (ui->progressBar_vs1_1->value()>ui->progressBar_vs2_1->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname2->text());
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname2->text());
                }
            }
            break;
        case 4:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为坦克, 在" + ui->label_vsheroname2->text() +"输出高时应尽早出防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 后期在" + ui->label_vsheroname1->text() +"坦度高时可适当出一些穿透类装备。");
            break;
        case 5:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为坦克, 在" + ui->label_vsheroname2->text() +"输出高时应尽早出防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为射手, 后期在" + ui->label_vsheroname1->text() +"坦度高时可适当出一些穿透类装备。");
            break;
        case 6:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为坦克, 在" + ui->label_vsheroname2->text() +"有对友时不应与之纠缠。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为辅助, 后期在" + ui->label_vsheroname1->text() +"机动性高时可适当出一些减速装备, 与队友一起杀之。");
            break;
        default:break;
        }break;
    case 4:
        switch (type2) {
        case 1:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为战士, 在" + ui->label_vsheroname1->text() +"输出高时可以适当出一些防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 在" + ui->label_vsheroname2->text() +"经济较高于自己时不应与之单独对抗。");
            break;
        case 2:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为法师, 后期在" + ui->label_vsheroname1->text() +"输出高时可适当出一些防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 在" + ui->label_vsheroname2->text() +"输出高时可以出一些法抗装备。");
            break;
        case 3:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为坦克, 在" + ui->label_vsheroname1->text() +"输出高时应尽早出防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 后期在" + ui->label_vsheroname2->text() +"坦度高时可适当出一些穿透类装备。");
            break;
        case 4:
            if (ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"输出能力相当。");
            }
            else {
                if (ui->progressBar_vs1_2->value()>ui->progressBar_vs2_2->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"输出能力更强, 在对面射手、法师、刺客生存能力高时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"输出能力更强, 在对面射手、法师、刺客生存能力高时可选择"+ui->label_vsheroname2->text());
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname2->text());
                }
            }
            break;
        case 5:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 后期在" + ui->label_vsheroname2->text() +"输出高时可以出一些防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为射手, 后期在" + ui->label_vsheroname1->text() +"输出高时可适当出一些防御装备。");
            break;
        case 6:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 在" + ui->label_vsheroname2->text() +"不是单独的时候不应与之缠斗。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为辅助, 在" + ui->label_vsheroname1->text() +"输出高时可出防御装或救赎之翼保护我方输出。");
            break;
        default:break;
        }break;
    case 5:
        switch (type2) {
        case 1:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为战士, 在" + ui->label_vsheroname1->text() +"输出高时可以适当出一些防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为射手, 在" + ui->label_vsheroname2->text() +"经济接近或高于自己时不应与之单独对抗。");
            break;
        case 2:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为法师, 后期尽量找机会先手秒掉" + ui->label_vsheroname1->text() +"。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为射手, 在" + ui->label_vsheroname2->text() +"输出高时可以出一些法抗装备。");
            break;
        case 3:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为坦克, 在" + ui->label_vsheroname1->text() +"输出高时应尽早出防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为射手, 后期在" + ui->label_vsheroname2->text() +"坦度高时可适当出一些穿透类装备。");
            break;
        case 4:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 后期在" + ui->label_vsheroname1->text() +"输出高时可以出一些防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为射手, 后期在" + ui->label_vsheroname2->text() +"输出高时可适当出一些防御装备。");
            break;
        case 5:
            if (ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_2->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"输出能力相当。");
            }
            else {
                if (ui->progressBar_vs1_2->value()>ui->progressBar_vs2_2->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"输出能力更强, 在对面射手、刺客生存能力高时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"输出能力更强, 在对面射手、刺客生存能力高时可选择"+ui->label_vsheroname2->text());
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、我方缺乏控制时可选择"+ui->label_vsheroname2->text());
                }
            }
            break;
        case 6:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为辅助, 后期在" + ui->label_vsheroname1->text() +"输出高时可以出一些防御装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为射手, 在" + ui->label_vsheroname2->text() +"控制技能多时可适当出一些防御装备, 减少与其缠斗。");
            break;
        default:break;
        }break;
    case 6:
        switch (type2) {
        case 1:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为战士, 在" + ui->label_vsheroname1->text() +"坦度高时可以适当出一些输出装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为辅助, 在" + ui->label_vsheroname2->text() +"经济高于自己时不应与之单独对抗。");
            break;
        case 2:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为法师, 后期在" + ui->label_vsheroname1->text() +"控制多时可出辉月等保命装备。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为刺客, 在" + ui->label_vsheroname2->text() +"输出高时应当出一些法抗装备。");
            break;
        case 3:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为坦克, 在" + ui->label_vsheroname1->text() +"有对友时不应与之纠缠。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为辅助, 后期在" + ui->label_vsheroname2->text() +"机动性高时可适当出一些减速装备, 与队友一起杀之。");
            break;
        case 4:
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为刺客, 在" + ui->label_vsheroname1->text() +"不是单独的时候不应与之缠斗。");
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为辅助, 在" + ui->label_vsheroname2->text() +"输出高时可出防御装或救赎之翼保护我方输出。");
            break;
        case 5:
            ui->label_vstip1->setText(ui->label_vsheroname1->text()+"作为辅助, 后期在" + ui->label_vsheroname2->text() +"输出高时可以出一些防御装备。");
            ui->label_vstip2->setText(ui->label_vsheroname2->text()+"作为射手, 在" + ui->label_vsheroname1->text() +"控制技能多时可适当出一些防御装备, 减少与其缠斗。");
            break;
        case 6:
            if (ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()>=-1 && ui->progressBar_vs1_1->value()-ui->progressBar_vs2_1->value()<=1){
                ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"生存能力相当。");
            }
            else {
                if (ui->progressBar_vs1_1->value()>ui->progressBar_vs2_1->value()){
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip1->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"生存能力更强, 在对面射手、刺客输出较高时可选择"+ui->label_vsheroname2->text());
                }
            }

            if (ui->progressBar_vs1_3->value()-ui->progressBar_vs2_3->value()>=-1 && ui->progressBar_vs1_2->value()-ui->progressBar_vs2_3->value()<=1){
                ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"和"+ui->label_vsheroname2->text()+"技能效果相当。");
            }
            else {
                if (ui->progressBar_vs1_3->value()>ui->progressBar_vs2_3->value()){
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname1->text()+"比"+ui->label_vsheroname2->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname1->text());
                }
                else {
                    ui->label_vstip2->setText("同为"+ui->label_vstype1->text()+", "+ui->label_vsheroname2->text()+"比"+ui->label_vsheroname1->text()+"技能效果更好, 在对面机动性高、控制较多时可选择"+ui->label_vsheroname2->text());
                }
            }
            break;
        default:break;
        }break;
    default:break;
    }
}

void MainWindow::hero_ability_show()
{
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);

    count*=10;
    int index = ui->stackedWidget_2->currentIndex();
    rank = hero_list;
    for (int i=0; i<rank.length()-1; i++){
        for (int j=i; j<rank.length()-1; j++){
            int tmp1 = rank[j][5].toInt()/10;
            int tmp2 = rank[j+1][5].toInt()/10;
            int value1 = 0, value2 = 0;
            for (int cnt = 1; cnt < 4; cnt++){
                if (tmp1%10 == 0)value1 = value1 + ((count-ability[3-cnt])*10);
                else value1 = value1 + (count-ability[3-cnt])*(tmp1%10);
                tmp1 = tmp1/10;
            }
            for (int cnt = 1; cnt < 4; cnt++){
                if (tmp2%10 == 0)value2 = value2 + (count-ability[3-cnt]) * 10;
                else value2 = value2 + (count-ability[3-cnt])*(tmp2%10);
                tmp2 = tmp2/10;
            }
            if (value1>value2){
                QStringList tmplist = rank[j+1];
                rank[j+1] = rank[j];
                rank[j] = tmplist;
            }
        }
    }


    QVector<int> arr;
    count = 0;
    for (int i=0; i<rank.length()-1; i++){
        if (count == 6)break;
        if (rank[rank.length()-1-i][2] == ui->label_525c11->text()||rank[rank.length()-1-i][2] == ui->label_525c21->text()||rank[rank.length()-1-i][2] == ui->label_525c31->text()||rank[rank.length()-1-i][2] == ui->label_525c41->text()||rank[rank.length()-1-i][2] == ui->label_525c51->text()){
            continue;
        }
        switch (index) {
        case 0:
            arr.append(rank.length()-1-i);
            count++;break;
        case 1:
            if (rank[rank.length()-1-i][4] == "3"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        case 2:
            if (rank[rank.length()-1-i][4] == "1"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        case 3:
            if (rank[rank.length()-1-i][4] == "4"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        case 4:
            if (rank[rank.length()-1-i][4] == "2"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        case 5:
            if (rank[rank.length()-1-i][4] == "5"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        case 6:
            if (rank[rank.length()-1-i][4] == "6"){
                arr.append(rank.length()-1-i);
                count++;
            }break;
        default:break;
        }
    }

    ui->pushButton_525r1->setIconSize(ui->pushButton_525r1->size());
    ui->pushButton_525r2->setIconSize(ui->pushButton_525r2->size());
    ui->pushButton_525r3->setIconSize(ui->pushButton_525r3->size());
    ui->pushButton_525r4->setIconSize(ui->pushButton_525r4->size());
    ui->pushButton_525r5->setIconSize(ui->pushButton_525r5->size());
    ui->pushButton_525r6->setIconSize(ui->pushButton_525r6->size());

    for (int i=0; i<6; i++){
        hero_recomand[i] = arr[i];
    }

    ui->pushButton_525r1->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[0]][0].toInt()][1]+"-"+hero_list[rank[arr[0]][0].toInt()][2]).scaled(ui->pushButton_525r1->size(),Qt::KeepAspectRatio));
    ui->pushButton_525r1->setStyleSheet(stySheet2);

    ui->textBrowser_tips->setText(rank[hero_recomand[0]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[0]][0].toInt()][1]);

    ui->pushButton_525r2->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[1]][0].toInt()][1]+"-"+hero_list[rank[arr[1]][0].toInt()][2]).scaled(ui->pushButton_525r2->size(),Qt::KeepAspectRatio));
    ui->pushButton_525r3->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[2]][0].toInt()][1]+"-"+hero_list[rank[arr[2]][0].toInt()][2]).scaled(ui->pushButton_525r3->size(),Qt::KeepAspectRatio));
    ui->pushButton_525r4->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[3]][0].toInt()][1]+"-"+hero_list[rank[arr[3]][0].toInt()][2]).scaled(ui->pushButton_525r4->size(),Qt::KeepAspectRatio));
    ui->pushButton_525r5->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[4]][0].toInt()][1]+"-"+hero_list[rank[arr[4]][0].toInt()][2]).scaled(ui->pushButton_525r5->size(),Qt::KeepAspectRatio));
    ui->pushButton_525r6->setIcon(QPixmap("D:/kCal/data_processing/heropng/"+hero_list[rank[arr[5]][0].toInt()][1]+"-"+hero_list[rank[arr[5]][0].toInt()][2]).scaled(ui->pushButton_525r6->size(),Qt::KeepAspectRatio));
}

void MainWindow::hero_Trank_init(QVector<QPushButton *> &hero_button)
{
    QString data_dir = QCoreApplication::applicationDirPath() + "/data_processing";
    QFile *data_file = new QFile(data_dir+"/hero-trank.txt");
    QFile *filekz = new QFile(data_dir+"/hero-kz.txt");

    QTextCodec *codec = QTextCodec::codecForName("GBK");

    if(!filekz->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/hero-kz.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    while (!filekz->atEnd()){
        QByteArray line = filekz->readLine();
        QString data = codec->toUnicode(line);
        data = data.left(data.size()-1);
        QStringList hero = data.split(",");
        if (hero.size()==1){
        }
        hero_kz.append(hero);
    }

    if(!data_file->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/hero-trank.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    int cnt = 0;
    while (!data_file->atEnd()){
        QByteArray line = data_file->readLine();
        QString data = codec->toUnicode(line);
        QStringList hero = data.split(",");
        hero_trank.append(hero);

        QPushButton *button = new QPushButton();
        button->setMinimumSize(QSize(51,51));
        QString ename;
        for (int i = 0; i<hero_list.length(); i++){
            if (hero_list[i][2] == hero[0]){
                ename = hero_list[i][1];
                break;
            }
        }
        QString pngname = ename+"-"+hero[0];
        QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(button->size(),Qt::KeepAspectRatio);
        button->setIconSize(QSize(61,61));
        button->setIcon(pixmap);
        button->setStyleSheet("background-color:rgba(0,0,0,0);");
        connect(button, &QPushButton::clicked, [=](){
            emit send_trank(cnt);
        });
        cnt++;
        hero_button.append(button);
    }

    ui->scrollAreaWidgetContents_trank->setMinimumSize(321, 73*hero_button.length());
    ui->scrollAreaWidgetContents_trank->setMaximumSize(321, 73*hero_button.length());

    ui->scrollArea_trank->setWidget(ui->scrollAreaWidgetContents_trank);
    QGridLayout *pLayout = new QGridLayout();

    cnt = 0;
    for (int i=0; i<hero_trank.length(); i++){
        QLabel *label1 = new QLabel;
        label1->setText("   "+hero_trank[i][1]+"   "+hero_trank[i][2]+" "+hero_trank[i][3]+" "+hero_trank[i][4]);
        pLayout->addWidget(hero_button[i],cnt,0);
        pLayout->addWidget(label1,cnt,1);
        cnt++;
    }

    ui->scrollArea_trank->widget()->setLayout(pLayout);
    ui->scrollArea_trank->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_trank->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_trank->setStyleSheet("background-color:transparent;");
}

void MainWindow::hero_initialize(QVector<QPushButton *> &hero_button, QVector<QPushButton *> &hero_button1, QVector<QPushButton *> &hero_button2, QVector<QPushButton *> &hero_button3, QVector<QPushButton *> &hero_button4, QVector<QPushButton *> &hero_button5, QVector<QPushButton *> &hero_button6)
{
    QString cwd = QCoreApplication::applicationDirPath();
    QString data_dir = cwd + "/data_processing";
    QFile *data_file = new QFile(data_dir+"/qtmessage.txt");
    QFile *sugg_file = new QFile(data_dir+"/hero-sugg.txt");
    QFile *df_file = new QFile(data_dir+"/hero-df.txt");
    QFile *skin_listfile = new QFile(data_dir +"/hero-skin.txt");

    QTextCodec *codec = QTextCodec::codecForName("GBK");

    if(!data_file->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/qtmessage.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    while (!data_file->atEnd()){
        QByteArray line = data_file->readLine();
        QString data = codec->toUnicode(line);
        QStringList hero = data.split(",");
        hero_list.append(hero);

        ui->comboBox1->addItem(hero[2]);
        ui->comboBox2->addItem(hero[2]);

        QPushButton *button = new QPushButton();
        button->setMinimumSize(QSize(61,61));
        QString pngname = hero[1]+"-"+hero[2];
        QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(button->size(),Qt::KeepAspectRatio);
        button->setIconSize(QSize(61,61));
        button->setIcon(pixmap);
        connect(button, &QPushButton::clicked, [=](){
            emit send_hero(hero[0].toInt());
        });
        hero_button.append(button);
    }

    if(!sugg_file->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/hero-sugg.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    while (!sugg_file->atEnd()){
        QByteArray line = sugg_file->readLine();
        QString data = codec->toUnicode(line);
        QStringList sugg = data.split("|");
        hero_sugg.append(sugg);
    }

    if(!df_file->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/hero-df.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    while (!df_file->atEnd()){
        QByteArray line = df_file->readLine();
        QString data = codec->toUnicode(line);
        QStringList df = data.split(",");
        hero_df.append(df);
    }

    if(!skin_listfile->open(QIODevice::ReadOnly|QIODevice::Text)){
       Dialog_fail *fail = new Dialog_fail();
       fail->setText("文件"+data_dir+"/skin-list.txt" + '\n' + "       不存在。");
       fail->show();
       return;
    }

    while (!skin_listfile->atEnd()){
        QByteArray line = skin_listfile->readLine();
        QString data = codec->toUnicode(line);
        QStringList skin = data.split("|");
        skin_list.append(skin);
    }

    for (int i = 0; i < hero_list.length(); i++){
        QPushButton *button = new QPushButton();
        connect(button, &QPushButton::clicked, [=](){
            emit send_hero(hero_list[i][0].toInt());
        });
        QString pngname = hero_list[i][1]+"-"+hero_list[i][2];
        QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(button->size(),Qt::KeepAspectRatio);
        button->setIconSize(QSize(61,61));
        button->setIcon(pixmap);
        int type = hero_list[i][4].toInt();
        switch (type) {
        case 1:
            button->setMinimumSize(QSize(61,61));
            hero_button2.append(button);break;
        case 2:
            button->setMinimumSize(QSize(61,61));
            hero_button4.append(button);break;
        case 3:
            button->setMinimumSize(QSize(61,61));
            hero_button1.append(button);break;
        case 4:
            button->setMinimumSize(QSize(61,61));
            hero_button3.append(button);break;
        case 5:
            button->setMinimumSize(QSize(61,61));
            hero_button5.append(button);break;
        case 6:
            button->setMinimumSize(QSize(61,61));
            hero_button6.append(button);break;
        default:break;
        }
    }

    MainWindow::ui->scrollAreaWidgetContents_525A->setMinimumSize(590,73*hero_button.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_525A->setMaximumSize(590,90*hero_button.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5251->setMinimumSize(590,73*hero_button1.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5251->setMaximumSize(590,90*hero_button1.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5252->setMinimumSize(590,73*hero_button2.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5252->setMaximumSize(590,76*hero_button2.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5253->setMinimumSize(590,73*hero_button3.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5253->setMaximumSize(590,97*hero_button3.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5254->setMinimumSize(590,73*hero_button4.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5254->setMaximumSize(590,89*hero_button4.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5255->setMinimumSize(590,73*hero_button5.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5255->setMaximumSize(590,97*hero_button5.length()/8+1);

    MainWindow::ui->scrollAreaWidgetContents_5256->setMinimumSize(590,73*hero_button6.length()/8+1);
    MainWindow::ui->scrollAreaWidgetContents_5256->setMaximumSize(590,115*hero_button6.length()/8+1);

    MainWindow::ui->scrollArea->setWidget(MainWindow::ui->scrollAreaWidgetContents_525A);
    MainWindow::ui->scrollArea_2->setWidget(MainWindow::ui->scrollAreaWidgetContents_5251);
    MainWindow::ui->scrollArea_3->setWidget(MainWindow::ui->scrollAreaWidgetContents_5252);
    MainWindow::ui->scrollArea_4->setWidget(MainWindow::ui->scrollAreaWidgetContents_5253);
    MainWindow::ui->scrollArea_5->setWidget(MainWindow::ui->scrollAreaWidgetContents_5254);
    MainWindow::ui->scrollArea_6->setWidget(MainWindow::ui->scrollAreaWidgetContents_5255);
    MainWindow::ui->scrollArea_7->setWidget(MainWindow::ui->scrollAreaWidgetContents_5256);
    QGridLayout *pLayoutA = new QGridLayout();
    QGridLayout *pLayout1 = new QGridLayout();
    QGridLayout *pLayout2 = new QGridLayout();
    QGridLayout *pLayout3 = new QGridLayout();
    QGridLayout *pLayout4 = new QGridLayout();
    QGridLayout *pLayout5 = new QGridLayout();
    QGridLayout *pLayout6 = new QGridLayout();

    int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0;
    for (int i = 0; i < hero_list.length(); i++){
        pLayoutA->addWidget(hero_button[i], i/8, i%8);
    }

    for (int i = 0; i < hero_button1.length(); i++){
        pLayout1->addWidget(hero_button1[i], count1/8, count1%8);
        count1++;
    }
    for (int i = 0; i < hero_button2.length(); i++){
        pLayout2->addWidget(hero_button2[i], count2/8, count2%8);
        count2++;
    }
    for (int i = 0; i < hero_button3.length(); i++){
        pLayout3->addWidget(hero_button3[i], count3/8, count3%8);
        count3++;
    }
    for (int i = 0; i < hero_button4.length(); i++){
        pLayout4->addWidget(hero_button4[i], count4/8, count4%8);
        count4++;
    }
    for (int i = 0; i < hero_button5.length(); i++){
        pLayout5->addWidget(hero_button5[i], count5/8, count5%8);
        count5++;
    }
    for (int i = 0; i < hero_button6.length(); i++){
        pLayout6->addWidget(hero_button6[i], count6/8, count6%8);
        count6++;
    }

    MainWindow::ui->scrollArea->widget()->setLayout(pLayoutA);
    MainWindow::ui->scrollArea_2->widget()->setLayout(pLayout1);
    MainWindow::ui->scrollArea_3->widget()->setLayout(pLayout2);
    MainWindow::ui->scrollArea_4->widget()->setLayout(pLayout3);
    MainWindow::ui->scrollArea_5->widget()->setLayout(pLayout4);
    MainWindow::ui->scrollArea_6->widget()->setLayout(pLayout5);
    MainWindow::ui->scrollArea_7->widget()->setLayout(pLayout6);
}

void MainWindow::kz_init()
{
    QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_kz1->size());
    ui->pushButton_kz1->setIconSize(ui->pushButton_kz1->size());
    ui->pushButton_kz2->setIconSize(ui->pushButton_kz2->size());
    ui->pushButton_kz3->setIconSize(ui->pushButton_kz3->size());
    ui->pushButton_kz4->setIconSize(ui->pushButton_kz4->size());
    ui->pushButton_kz5->setIconSize(ui->pushButton_kz5->size());
    ui->pushButton_kz6->setIconSize(ui->pushButton_kz6->size());

    ui->pushButton_kz1->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz2->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz3->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz4->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz5->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz6->setStyleSheet("background-color:transparent;");

    ui->pushButton_kz1->setIcon(pixmap);
    ui->pushButton_kz2->setIcon(pixmap);
    ui->pushButton_kz3->setIcon(pixmap);
    ui->pushButton_kz4->setIcon(pixmap);
    ui->pushButton_kz5->setIcon(pixmap);
    ui->pushButton_kz6->setIcon(pixmap);

    pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_kz->size());
    ui->pushButton_kz->setIconSize(ui->pushButton_kz->size());
    ui->pushButton_kz->setStyleSheet("background-color:transparent;");
    ui->pushButton_kz->setIcon(pixmap);

    ui->label_kz11->setText("");
    ui->label_kz21->setText("");
    ui->label_kz31->setText("");
    ui->label_kz41->setText("");
    ui->label_kz51->setText("");
    ui->label_kz61->setText("");
    ui->label_kz12->setText("???");
    ui->label_kz22->setText("???");
    ui->label_kz32->setText("???");
    ui->label_kz42->setText("???");
    ui->label_kz52->setText("???");
    ui->label_kz62->setText("???");
    ui->label_kzname->setText("");
    ui->label_kztype->setText("");

    if (ui->label_winrate1->text() == ""){
        ui->pushButton_df11->setIconSize(ui->pushButton_df11->size());
        ui->pushButton_df12->setIconSize(ui->pushButton_df11->size());
        ui->pushButton_df13->setIconSize(ui->pushButton_df11->size());
        ui->pushButton_df14->setIconSize(ui->pushButton_df11->size());
        ui->pushButton_df15->setIconSize(ui->pushButton_df11->size());
        ui->pushButton_df16->setIconSize(ui->pushButton_df11->size());

        ui->pushButton_df11->setStyleSheet("background-color:transparent;");
        ui->pushButton_df12->setStyleSheet("background-color:transparent;");
        ui->pushButton_df13->setStyleSheet("background-color:transparent;");
        ui->pushButton_df14->setStyleSheet("background-color:transparent;");
        ui->pushButton_df15->setStyleSheet("background-color:transparent;");
        ui->pushButton_df16->setStyleSheet("background-color:transparent;");


        ui->pushButton_df11->setIcon(pixmap);
        ui->pushButton_df12->setIcon(pixmap);
        ui->pushButton_df13->setIcon(pixmap);
        ui->pushButton_df14->setIcon(pixmap);
        ui->pushButton_df15->setIcon(pixmap);
        ui->pushButton_df16->setIcon(pixmap);

        ui->progressBar_winrate1->setValue(0);
        ui->progressBar_winrate2->setValue(0);
        ui->progressBar_winrate3->setValue(0);
    }
}

//help按钮
void MainWindow::on_pushButton_clicked()
{
    Dialog_help *help=new Dialog_help(this);
    help->show();
}

void MainWindow::get_trank(int i)
{
    for (int cnt=0; cnt<hero_list.length(); cnt++){
        if (hero_list[cnt][2]==hero_trank[i][0]){
            QPixmap heropixmap = QPixmap("D:/kCal/data_processing/heropng/"+hero_list[cnt][1]+"-"+hero_list[cnt][2]);
            ui->pushButton_kz->setIconSize(ui->pushButton_kz->size());
            ui->pushButton_kz->setIcon(heropixmap);
            ui->label_kzname->setText(hero_list[cnt][2]);
            QString type="";
            switch (hero_list[cnt][4].toInt()) {
            case 1: type = "战士";break;
            case 2: type = "法师";break;
            case 3: type = "坦克";break;
            case 4: type = "刺客";break;
            case 5: type = "射手";break;
            case 6: type = "辅助";break;
            default: break;
            }
            ui->label_kztype->setText(type);

            QString winrate = "";
            QString dfpng = hero_df[hero_list[cnt][0].toInt()][2]+"-"+get_cname(hero_df[hero_list[cnt][0].toInt()][2]);
            QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+dfpng).scaled(ui->pushButton_df12->size(),Qt::KeepAspectRatio);
            ui->pushButton_df12->setIconSize(ui->pushButton_df12->size());
            ui->pushButton_df12->setIcon(pixmap);
            ui->label_winrate1->setText(hero_df[hero_list[cnt][0].toInt()][1]);
            ui->progressBar_winrate1->setTextVisible(false);
            winrate = hero_df[hero_list[cnt][0].toInt()][1];
            ui->progressBar_winrate1->setValue(winrate.remove('.').remove('%').toInt());

            dfpng = hero_df[hero_list[cnt][0].toInt()][4]+"-"+get_cname(hero_df[hero_list[cnt][0].toInt()][4]);
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+dfpng).scaled(ui->pushButton_df14->size(),Qt::KeepAspectRatio);
            ui->pushButton_df14->setIconSize(ui->pushButton_df14->size());
            ui->pushButton_df14->setIcon(pixmap);
            ui->label_winrate2->setText(hero_df[hero_list[cnt][0].toInt()][3]);
            ui->progressBar_winrate2->setTextVisible(false);
            winrate = hero_df[hero_list[cnt][0].toInt()][3];
            ui->progressBar_winrate2->setValue(winrate.remove('.').remove('%').toInt());

            dfpng = hero_df[hero_list[cnt][0].toInt()][6]+"-"+get_cname(hero_df[hero_list[cnt][0].toInt()][6].remove('\n'));
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+dfpng).scaled(ui->pushButton_df16->size(),Qt::KeepAspectRatio);
            ui->pushButton_df16->setIconSize(ui->pushButton_df16->size());
            ui->pushButton_df16->setIcon(pixmap);
            ui->label_winrate3->setText(hero_df[hero_list[cnt][0].toInt()][5]);
            ui->progressBar_winrate3->setTextVisible(false);
            winrate = hero_df[hero_list[cnt][0].toInt()][5];
            ui->progressBar_winrate3->setValue(winrate.remove('.').remove('%').toInt());

            dfpng = hero_df[hero_list[cnt][0].toInt()][0]+"-"+get_cname(hero_df[hero_list[cnt][0].toInt()][0]);
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+dfpng).scaled(ui->pushButton_df11->size(),Qt::KeepAspectRatio);
            ui->pushButton_df11->setIconSize(ui->pushButton_df16->size());
            ui->pushButton_df13->setIconSize(ui->pushButton_df16->size());
            ui->pushButton_df15->setIconSize(ui->pushButton_df16->size());
            ui->pushButton_df11->setIcon(pixmap);
            ui->pushButton_df13->setIcon(pixmap);
            ui->pushButton_df15->setIcon(pixmap);

            if (hero_kz[hero_list[cnt][0].toInt()].size()==1){
                kz_init();
                return;
            }
            QString pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][2])+"-"+hero_kz[hero_list[cnt][0].toInt()][2];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz1->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz1->setIconSize(ui->pushButton_kz1->size());
            ui->pushButton_kz1->setIcon(pixmap);
            ui->label_kz11->setText(hero_kz[hero_list[cnt][0].toInt()][2]);
            ui->label_kz12->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][1].toDouble()*100));

            pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][4])+"-"+hero_kz[hero_list[cnt][0].toInt()][4];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz2->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz2->setIconSize(ui->pushButton_kz2->size());
            ui->pushButton_kz2->setIcon(pixmap);
            ui->label_kz21->setText(hero_kz[hero_list[cnt][0].toInt()][4]);
            ui->label_kz22->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][3].toDouble()*100));

            pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][6])+"-"+hero_kz[hero_list[cnt][0].toInt()][6];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz3->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz3->setIconSize(ui->pushButton_kz3->size());
            ui->pushButton_kz3->setIcon(pixmap);
            ui->label_kz31->setText(hero_kz[hero_list[cnt][0].toInt()][6]);
            ui->label_kz32->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][5].toDouble()*100));

            pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][8])+"-"+hero_kz[hero_list[cnt][0].toInt()][8];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz4->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz4->setIconSize(ui->pushButton_kz4->size());
            ui->pushButton_kz4->setIcon(pixmap);
            ui->label_kz41->setText(hero_kz[hero_list[cnt][0].toInt()][8]);
            ui->label_kz42->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][7].toDouble()*100));

            pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][10])+"-"+hero_kz[hero_list[cnt][0].toInt()][10];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz5->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz5->setIconSize(ui->pushButton_kz5->size());
            ui->pushButton_kz5->setIcon(pixmap);
            ui->label_kz51->setText(hero_kz[hero_list[cnt][0].toInt()][10]);
            ui->label_kz52->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][9].toDouble()*100));

            pngname = get_ename(hero_kz[hero_list[cnt][0].toInt()][12])+"-"+hero_kz[hero_list[cnt][0].toInt()][12];
            pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->pushButton_kz6->size(),Qt::KeepAspectRatio);
            ui->pushButton_kz6->setIconSize(ui->pushButton_kz6->size());
            ui->pushButton_kz6->setIcon(pixmap);
            ui->label_kz61->setText(hero_kz[hero_list[cnt][0].toInt()][12]);
            ui->label_kz62->setText(QString::number(hero_kz[hero_list[cnt][0].toInt()][11].toDouble()*100));

            break;
        }
    }
}

//英雄选择
void MainWindow::get_hero(int i){
    if (skin_change_type == 2){
        hero_id = i;
        skin_id = 1;

        emit ui->pushButton_next_skin->click();
    }

    QPushButton *button;
    QLabel *label1, *label2;
    switch (choose_id) {
    case 1:
        button = ui->pushButton_525c1;
        label1 = ui->label_525c11;
        label2 = ui->label_525c12;
        break;
    case 2:
        button = ui->pushButton_525c2;
        label1 = ui->label_525c21;
        label2 = ui->label_525c22;
        break;
    case 3:
        button = ui->pushButton_525c3;
        label1 = ui->label_525c31;
        label2 = ui->label_525c32;
        break;
    case 4:
        button = ui->pushButton_525c4;
        label1 = ui->label_525c41;
        label2 = ui->label_525c42;
        break;
    case 5:
        button = ui->pushButton_525c5;
        label1 = ui->label_525c51;
        label2 = ui->label_525c52;
        break;
    default:return;
    }

    QString pngname = hero_list[i][1]+"-"+hero_list[i][2];
    QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(button->size(),Qt::KeepAspectRatio);
    button->setIconSize(QSize(61,61));
    button->setIcon(pixmap);

    if (label1->text() == hero_list[i][2]){
        button->setStyleSheet(stySheet1);
        if (ui->label_525c11->text()==""){
            choose_id = 1;
        }
        else if(ui->label_525c21->text()==""){
            choose_id = 2;
        }
        else if(ui->label_525c31->text()==""){
            choose_id = 3;
        }
        else if(ui->label_525c41->text()==""){
            choose_id = 4;
        }
        else if(ui->label_525c51->text()==""){
            choose_id = 5;
        }
        else {
            choose_id = 6;
        }
        switch (choose_id) {
        case 2:
            ui->pushButton_525c2->setStyleSheet(stySheet2);
            break;
        case 3:
            ui->pushButton_525c3->setStyleSheet(stySheet2);
            break;
        case 4:
            ui->pushButton_525c4->setStyleSheet(stySheet2);
            break;
        case 5:
            ui->pushButton_525c5->setStyleSheet(stySheet2);
            break;
        default:break;
        }
    }
    else {
        label1->setText(hero_list[i][2]);
        QString type="";
        switch (hero_list[i][4].toInt()) {
        case 1: type = "战士";break;
        case 2: type = "法师";break;
        case 3: type = "坦克";break;
        case 4: type = "刺客";break;
        case 5: type = "射手";break;
        case 6: type = "辅助";break;
        default: break;
        }
        label2->setText(type);
    }
    hero_ability_show();
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
        return;
    }
    if (str=="exp"){
        if (MainWindow::ui->label_show_exp->text()==""){
            text1="e";
        }
        else {
            text1=text1+"e";
        }
        MainWindow::ui->label_show_exp->setText(text1);
        return;
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
        int err_num = word_analysis(word, Memory, text1);
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
int word_analysis(QVector<QPair<QString, int>>& word, const QString Memory, const QString expr)
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
                word.push_back(qMakePair('*', 3));
                word.push_back(qMakePair(Memory, 5));
                if (i<expr.length()-1){
                    if (expr[i+1]!='+'||expr[i+1]!='-'||expr[i+1]!='*'||expr[i+1]!='/'||expr[i+1]!=')')
                        word.push_back(qMakePair('*', 3));
                }
                continue;
            }

            if(expr[i].unicode() == 'e'){
                word.push_back(qMakePair(tmp, 5));
                word.push_back(qMakePair('*', 3));
                word.push_back(qMakePair(QString::number(EX), 5));
                if (i<expr.length()-1){
                    if (expr[i+1]!='+'||expr[i+1]!='-'||expr[i+1]!='*'||expr[i+1]!='/'||expr[i+1]!=')')
                        word.push_back(qMakePair('*', 3));
                }
                continue;
            }

            if(expr[i] == "π"){
                word.push_back(qMakePair(tmp, 5));
                word.push_back(qMakePair('*', 3));
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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(background).scaled(this->size());

    QPainter painter(this);

    painter.drawPixmap(this->rect(), pixmap);
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
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_king_Cal_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    kCal_clicked = true;
}

void MainWindow::on_pushButton_kexue_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_kCal_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_525_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_525_clicked()
{
    ui->scrollArea->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_2->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_2->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea_3->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_3->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea_4->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_4->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea_5->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_5->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea_6->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_6->viewport()->setStyleSheet("background-color:transparent;");
    ui->scrollArea_7->setStyleSheet("QScrollArea{background-color:transparent;}");
    ui->scrollArea_7->viewport()->setStyleSheet("background-color:transparent;");

    QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());

    ui->pushButton_525c1->setStyleSheet(stySheet2);
    ui->pushButton_525c2->setStyleSheet(stySheet1);
    ui->pushButton_525c3->setStyleSheet(stySheet1);
    ui->pushButton_525c4->setStyleSheet(stySheet1);
    ui->pushButton_525c5->setStyleSheet(stySheet1);

    ui->pushButton_525c1->setIconSize(QSize(51,51));
    ui->pushButton_525c2->setIconSize(QSize(51,51));
    ui->pushButton_525c3->setIconSize(QSize(51,51));
    ui->pushButton_525c4->setIconSize(QSize(51,51));
    ui->pushButton_525c5->setIconSize(QSize(51,51));

    ui->pushButton_525c1->setIcon(pixmap);
    ui->pushButton_525c2->setIcon(pixmap);
    ui->pushButton_525c3->setIcon(pixmap);
    ui->pushButton_525c4->setIcon(pixmap);
    ui->pushButton_525c5->setIcon(pixmap);

    ui->label_525c11->setText("");
    ui->label_525c12->setText("");
    ui->label_525c21->setText("");
    ui->label_525c22->setText("");
    ui->label_525c31->setText("");
    ui->label_525c32->setText("");
    ui->label_525c41->setText("");
    ui->label_525c42->setText("");
    ui->label_525c51->setText("");
    ui->label_525c52->setText("");

    ui->progressBar_1->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->progressBar_3->setValue(0);
    ui->progressBar_4->setValue(0);

    ui->pushButton_525r1->setStyleSheet(stySheet2);
    ui->pushButton_525r2->setStyleSheet(stySheet1);
    ui->pushButton_525r3->setStyleSheet(stySheet1);
    ui->pushButton_525r4->setStyleSheet(stySheet1);
    ui->pushButton_525r5->setStyleSheet(stySheet1);
    ui->pushButton_525r6->setStyleSheet(stySheet1);

    ui->pushButton_525r1->setIconSize(QSize(51,51));
    ui->pushButton_525r2->setIconSize(QSize(51,51));
    ui->pushButton_525r3->setIconSize(QSize(51,51));
    ui->pushButton_525r4->setIconSize(QSize(51,51));
    ui->pushButton_525r5->setIconSize(QSize(51,51));
    ui->pushButton_525r5->setIconSize(QSize(51,51));
    ui->pushButton_525r6->setIconSize(QSize(51,51));

    ui->pushButton_525r1->setIcon(pixmap);
    ui->pushButton_525r2->setIcon(pixmap);
    ui->pushButton_525r3->setIcon(pixmap);
    ui->pushButton_525r4->setIcon(pixmap);
    ui->pushButton_525r5->setIcon(pixmap);
    ui->pushButton_525r5->setIcon(pixmap);
    ui->pushButton_525r6->setIcon(pixmap);

    choose_id = 1;

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_vs_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_ability_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    kz_init();
}

void MainWindow::on_pushButton_datachange_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_525_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_525_return_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_525_return_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_525A_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    hero_ability_show();
}

void MainWindow::on_pushButton_5250_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    hero_ability_show();
}

void MainWindow::on_pushButton_5251_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    hero_ability_show();
}

void MainWindow::on_pushButton_5252_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
    hero_ability_show();
}

void MainWindow::on_pushButton_5253_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
    hero_ability_show();
}

void MainWindow::on_pushButton_5254_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
    hero_ability_show();
}

void MainWindow::on_pushButton_5255_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
    hero_ability_show();
}

void MainWindow::on_pushButton_525c1_clicked()
{
    if (choose_id == 1){
        QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());
        ui->pushButton_525c1->setIcon(pixmap);
        ui->label_525c11->setText("");
        ui->label_525c12->setText("");
    }
    switch (choose_id) {
    case 1:
        ui->pushButton_525c1->setStyleSheet(stySheet1);
        break;
    case 2:
        ui->pushButton_525c2->setStyleSheet(stySheet1);
        break;
    case 3:
        ui->pushButton_525c3->setStyleSheet(stySheet1);
        break;
    case 4:
        ui->pushButton_525c4->setStyleSheet(stySheet1);
        break;
    case 5:
        ui->pushButton_525c5->setStyleSheet(stySheet1);
        break;
    default:break;
    }
    choose_id = 1;
    ui->pushButton_525c1->setStyleSheet(stySheet2);
    hero_ability_show();
}

void MainWindow::on_pushButton_525c2_clicked()
{
    if (choose_id == 2){
        QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());
        ui->pushButton_525c2->setIcon(pixmap);
        ui->label_525c21->setText("");
        ui->label_525c22->setText("");
    }
    switch (choose_id) {
    case 1:
        ui->pushButton_525c1->setStyleSheet(stySheet1);
        break;
    case 2:
        ui->pushButton_525c2->setStyleSheet(stySheet1);
        break;
    case 3:
        ui->pushButton_525c3->setStyleSheet(stySheet1);
        break;
    case 4:
        ui->pushButton_525c4->setStyleSheet(stySheet1);
        break;
    case 5:
        ui->pushButton_525c5->setStyleSheet(stySheet1);
        break;
    default:break;
    }
    choose_id = 2;
    ui->pushButton_525c2->setStyleSheet(stySheet2);
    hero_ability_show();
}

void MainWindow::on_pushButton_525c3_clicked()
{
    if (choose_id == 3){
        QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());
        ui->pushButton_525c3->setIcon(pixmap);
        ui->label_525c31->setText("");
        ui->label_525c32->setText("");
    }
    switch (choose_id) {
    case 1:
        ui->pushButton_525c1->setStyleSheet(stySheet1);
        break;
    case 2:
        ui->pushButton_525c2->setStyleSheet(stySheet1);
        break;
    case 3:
        ui->pushButton_525c3->setStyleSheet(stySheet1);
        break;
    case 4:
        ui->pushButton_525c4->setStyleSheet(stySheet1);
        break;
    case 5:
        ui->pushButton_525c5->setStyleSheet(stySheet1);
        break;
    default:break;
    }
    choose_id = 3;
    ui->pushButton_525c3->setStyleSheet(stySheet2);
    hero_ability_show();
}

void MainWindow::on_pushButton_525c4_clicked()
{
    if (choose_id == 4){
        QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());
        ui->pushButton_525c4->setIcon(pixmap);
        ui->label_525c41->setText("");
        ui->label_525c42->setText("");
    }
    switch (choose_id) {
    case 1:
        ui->pushButton_525c1->setStyleSheet(stySheet1);
        break;
    case 2:
        ui->pushButton_525c2->setStyleSheet(stySheet1);
        break;
    case 3:
        ui->pushButton_525c3->setStyleSheet(stySheet1);
        break;
    case 4:
        ui->pushButton_525c4->setStyleSheet(stySheet1);
        break;
    case 5:
        ui->pushButton_525c5->setStyleSheet(stySheet1);
        break;
    default:break;
    }
    choose_id = 4;
    ui->pushButton_525c4->setStyleSheet(stySheet2);
    hero_ability_show();
}

void MainWindow::on_pushButton_525c5_clicked()
{
    if (choose_id == 5){
        QPixmap pixmap = QPixmap("D:/kCal/icon_pic/LBSBangzhu.png").scaled(ui->pushButton_525c1->size());
        ui->pushButton_525c5->setIcon(pixmap);
        ui->label_525c51->setText("");
        ui->label_525c52->setText("");
    }
    switch (choose_id) {
    case 1:
        ui->pushButton_525c1->setStyleSheet(stySheet1);
        break;
    case 2:
        ui->pushButton_525c2->setStyleSheet(stySheet1);
        break;
    case 3:
        ui->pushButton_525c3->setStyleSheet(stySheet1);
        break;
    case 4:
        ui->pushButton_525c4->setStyleSheet(stySheet1);
        break;
    case 5:
        ui->pushButton_525c5->setStyleSheet(stySheet1);
        break;
    default:break;
    }
    choose_id = 5;
    ui->pushButton_525c5->setStyleSheet(stySheet2);
    hero_ability_show();
}

void MainWindow::on_comboBox1_currentIndexChanged(int index)
{
    int tmp = hero_list[index][5].toInt();
    int ability[4] = {0};
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    QString pngname = hero_list[index][1]+"-"+hero_list[index][2];
    QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->label_vsjpg1->size(),Qt::KeepAspectRatio);

    ui->label_vsjpg1->setPixmap(pixmap);
    ui->label_vstype1->setText(hero_list[index][4]);
    QString type="";
    switch (hero_list[index][4].toInt()) {
    case 1: type = "战士";break;
    case 2: type = "法师";break;
    case 3: type = "坦克";break;
    case 4: type = "刺客";break;
    case 5: type = "射手";break;
    case 6: type = "辅助";break;
    default: break;
    }
    ui->label_vstype1->setText(type);
    ui->label_vsheroname1->setText(hero_list[index][2]);
    for (int i=100; i>=1; i--){
        ui->progressBar_vs1_1->setValue(ability[0]/i);
        ui->progressBar_vs1_2->setValue(ability[1]/i);
        ui->progressBar_vs1_3->setValue(ability[2]/i);
        ui->progressBar_vs1_4->setValue(ability[3]/i);
    }
    if (kCal_clicked){
        vstips_show();
    }
}

void MainWindow::on_comboBox2_currentIndexChanged(int index)
{
    int tmp = hero_list[index][5].toInt();
    int ability[4] = {0};
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    QString pngname = hero_list[index][1]+"-"+hero_list[index][2];
    QPixmap pixmap = QPixmap("D:/kCal/data_processing/heropng/"+pngname).scaled(ui->label_vsjpg1->size(),Qt::KeepAspectRatio);

    ui->label_vsjpg2->setPixmap(pixmap);
    ui->label_vstype2->setText(hero_list[index][4]);
    QString type="";
    switch (hero_list[index][4].toInt()) {
    case 1: type = "战士";break;
    case 2: type = "法师";break;
    case 3: type = "坦克";break;
    case 4: type = "刺客";break;
    case 5: type = "射手";break;
    case 6: type = "辅助";break;
    default: break;
    }
    ui->label_vstype2->setText(type);
    ui->label_vsheroname2->setText(hero_list[index][2]);
    ui->progressBar_vs2_1->setInvertedAppearance(true);
    ui->progressBar_vs2_2->setInvertedAppearance(true);
    ui->progressBar_vs2_3->setInvertedAppearance(true);
    ui->progressBar_vs2_4->setInvertedAppearance(true);
    for (int i=100; i>=1; i--){
        ui->progressBar_vs2_1->setValue(ability[0]/i);
        ui->progressBar_vs2_2->setValue(ability[1]/i);
        ui->progressBar_vs2_3->setValue(ability[2]/i);
        ui->progressBar_vs2_4->setValue(ability[3]/i);
    }
    if (kCal_clicked){
        vstips_show();
    }
}

void MainWindow::on_pushButton_525r1_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[0]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[0]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[0]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r2_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[1]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[1]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[1]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r3_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[2]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[2]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[2]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r4_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[3]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[3]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[3]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r5_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[4]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[4]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[4]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r6_pressed()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    int tmp = rank[hero_recomand[5]][5].toInt();
    for (int cnt=0; cnt < 4; cnt++){
        if (tmp%10 == 0)ability[3-cnt] += 10;
        else ability[3-cnt] += tmp%10;
        tmp = tmp/10;
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
    ui->textBrowser_tips->setText(rank[hero_recomand[5]][2]+":"+'\n'+"    "+hero_sugg[rank[hero_recomand[5]][0].toInt()][1]);
}

void MainWindow::on_pushButton_525r1_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_525r2_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_525r3_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_525r4_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_525r5_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_525r6_released()
{
    if (rank.length() == 0){
        return;
    }
    int ability[4] = {0};
    int count = 1;
    if (ui->label_525c11->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c11->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c21->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c21->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c31->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c31->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c41->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c41->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }
    if (ui->label_525c51->text() != ""){
        count++;
        for (int i=0; i<hero_list.length(); i++){
            if (hero_list[i][2] == ui->label_525c51->text()){
                int tmp = hero_list[i][5].toInt();
                for (int cnt=0; cnt < 4; cnt++){
                    if (tmp%10 == 0)ability[3-cnt] += 10;
                    else ability[3-cnt] += tmp%10;
                    tmp = tmp/10;
                }
                break;
            }
        }
    }

    ui->progressBar_1->setValue(ability[0]);
    ui->progressBar_2->setValue(ability[1]);
    ui->progressBar_3->setValue(ability[2]);
    ui->progressBar_4->setValue(ability[3]);
}

void MainWindow::on_pushButton_next_skin_pressed()
{
    if (skin_change_type == 0){
        return;
    }

    QString cwd = QCoreApplication::applicationDirPath()+"/data_processing/heroskin/";
    if (skin_change_type == 1){
        int count = 0;
        for(int i = 0; i<skin_list.length(); i++){
            count += skin_list[i].length()-1;
        }

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int random = qrand()%count;

        int tmp = 0;
        for (int i = 0; i<skin_list.length(); i++){
            if(tmp + skin_list[i].length() > random){
                if (background == cwd + skin_list[i][0] + '-'+ get_cname(skin_list[i][0]) +'-'+ skin_list[i][random-tmp].remove('\n'))return;
                else {
                    last_background = background;
                    background = cwd + skin_list[i][0] + '-'+ get_cname(skin_list[i][0]) +'-'+ skin_list[i][random-tmp].remove('\n');
                }
                return;
            }
            else {
                tmp += skin_list[i].length()-1;
            }
        }
    }

    if (skin_change_type == 2){
        skin_id++;
        if (skin_id >= skin_list[hero_id].length()){
            skin_id = 1;
        }
        background = cwd + skin_list[hero_id][0] + '-'+ get_cname(skin_list[hero_id][0]) +'-'+ skin_list[hero_id][skin_id].remove('\n');
    }
}

void MainWindow::on_pushButton_last_skin_pressed()
{
    if (skin_change_type == 0){
        return;
    }

    if (skin_change_type == 1){
       background = last_background;
       return;
    }

    if (skin_change_type == 2){
        skin_id--;
        if (skin_id == 0){
            skin_id = skin_list[hero_id].length()-1;
        }
        background = QCoreApplication::applicationDirPath()+"/data_processing/heroskin/" + skin_list[hero_id][0] + '-'+ get_cname(skin_list[hero_id][0]) +'-'+ skin_list[hero_id][skin_id].remove('\n');
    }
}

void MainWindow::on_checkBox_clicked()
{
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    skin_change_type = 0;
}

void MainWindow::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(false);
    skin_change_type = 1;
}

void MainWindow::on_checkBox_3_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(true);
    skin_change_type = 2;
}

void MainWindow::on_commandLinkButton_clicked()
{
    Dialog_help *help=new Dialog_help(this);
    help->show();
}
