/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *import_statics;
    QAction *export_statics;
    QAction *theme_black_white;
    QAction *theme_blue;
    QAction *background_heros;
    QAction *background_graph;
    QAction *file_quit;
    QAction *help_H;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QPushButton *kexue_Cal;
    QPushButton *king_Cal;
    QWidget *page_2;
    QGroupBox *groupBox1;
    QLabel *label_show_exp;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_output;
    QPushButton *pushButton_ce;
    QPushButton *pushButton_c;
    QPushButton *pushButton_cleft;
    QPushButton *pushButton_cright;
    QPushButton *pushButton_m_add;
    QPushButton *pushButton_m;
    QPushButton *button_m_inc;
    QPushButton *pushButton_add;
    QPushButton *button_sin;
    QPushButton *button_sinh;
    QPushButton *button_square;
    QPushButton *button_root2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_inc;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *button_root3;
    QPushButton *button_cube;
    QPushButton *button_cosh;
    QPushButton *button_cos;
    QPushButton *button_tan;
    QPushButton *button_tanh;
    QPushButton *button_power;
    QPushButton *button_log;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_div;
    QPushButton *button_cot;
    QPushButton *button_pi;
    QPushButton *button_exp;
    QPushButton *button_ln;
    QPushButton *pushButton_sign;
    QPushButton *pushButton_0;
    QPushButton *pushButton_point;
    QPushButton *pushbutton_equal;
    QLabel *label_Power;
    QLabel *label_M;
    QPushButton *pushButton;
    QPushButton *pushButton_kexue_return;
    QWidget *page_3;
    QPushButton *pushButton_kCal_return;
    QPushButton *pushButton_datachange;
    QPushButton *pushButton_ability;
    QPushButton *pushButton_vs;
    QPushButton *pushButton_525;
    QLabel *label_3;
    QWidget *page_5;
    QPushButton *pushButton_525_return;
    QLabel *label_4;
    QPushButton *pushButton_525c1;
    QPushButton *pushButton_525c2;
    QPushButton *pushButton_525c3;
    QPushButton *pushButton_525c4;
    QPushButton *pushButton_525c5;
    QWidget *gridWidget_525;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget_2;
    QWidget *page_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_525A;
    QWidget *page_10;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_5251;
    QWidget *page_11;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_5252;
    QWidget *page_12;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_5253;
    QWidget *page_13;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5254;
    QWidget *page_14;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_5255;
    QWidget *page_15;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_5256;
    QPushButton *pushButton_5250;
    QPushButton *pushButton_525A;
    QPushButton *pushButton_5252;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5253;
    QPushButton *pushButton_5251;
    QPushButton *pushButton_5254;
    QPushButton *pushButton_5255;
    QWidget *page_6;
    QPushButton *pushButton_525_return_2;
    QLabel *label_5;
    QWidget *page_7;
    QPushButton *pushButton_525_return_3;
    QLabel *label_6;
    QWidget *page_8;
    QPushButton *pushButton_525_return_4;
    QLabel *label_7;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *theme_change;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 551);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        import_statics = new QAction(MainWindow);
        import_statics->setObjectName(QStringLiteral("import_statics"));
        import_statics->setChecked(false);
        export_statics = new QAction(MainWindow);
        export_statics->setObjectName(QStringLiteral("export_statics"));
        theme_black_white = new QAction(MainWindow);
        theme_black_white->setObjectName(QStringLiteral("theme_black_white"));
        theme_blue = new QAction(MainWindow);
        theme_blue->setObjectName(QStringLiteral("theme_blue"));
        background_heros = new QAction(MainWindow);
        background_heros->setObjectName(QStringLiteral("background_heros"));
        background_graph = new QAction(MainWindow);
        background_graph->setObjectName(QStringLiteral("background_graph"));
        file_quit = new QAction(MainWindow);
        file_quit->setObjectName(QStringLiteral("file_quit"));
        help_H = new QAction(MainWindow);
        help_H->setObjectName(QStringLiteral("help_H"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, -40, 1211, 631));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        kexue_Cal = new QPushButton(page1);
        kexue_Cal->setObjectName(QStringLiteral("kexue_Cal"));
        kexue_Cal->setGeometry(QRect(302, 350, 141, 51));
        king_Cal = new QPushButton(page1);
        king_Cal->setObjectName(QStringLiteral("king_Cal"));
        king_Cal->setGeometry(QRect(820, 340, 141, 51));
        king_Cal->setCursor(QCursor(Qt::WhatsThisCursor));
        stackedWidget->addWidget(page1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        groupBox1 = new QGroupBox(page_2);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setGeometry(QRect(10, 20, 1201, 611));
        label_show_exp = new QLabel(groupBox1);
        label_show_exp->setObjectName(QStringLiteral("label_show_exp"));
        label_show_exp->setGeometry(QRect(340, 120, 321, 41));
        label = new QLabel(groupBox1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 130, 72, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(groupBox1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 180, 72, 21));
        label_2->setFont(font1);
        lineEdit_output = new QLineEdit(groupBox1);
        lineEdit_output->setObjectName(QStringLiteral("lineEdit_output"));
        lineEdit_output->setGeometry(QRect(340, 170, 321, 41));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_output->setFont(font2);
        pushButton_ce = new QPushButton(groupBox1);
        pushButton_ce->setObjectName(QStringLiteral("pushButton_ce"));
        pushButton_ce->setGeometry(QRect(280, 220, 41, 41));
        pushButton_c = new QPushButton(groupBox1);
        pushButton_c->setObjectName(QStringLiteral("pushButton_c"));
        pushButton_c->setGeometry(QRect(330, 220, 41, 41));
        pushButton_c->setStyleSheet(QStringLiteral(""));
        pushButton_cleft = new QPushButton(groupBox1);
        pushButton_cleft->setObjectName(QStringLiteral("pushButton_cleft"));
        pushButton_cleft->setGeometry(QRect(380, 220, 41, 41));
        pushButton_cright = new QPushButton(groupBox1);
        pushButton_cright->setObjectName(QStringLiteral("pushButton_cright"));
        pushButton_cright->setGeometry(QRect(430, 220, 41, 41));
        pushButton_m_add = new QPushButton(groupBox1);
        pushButton_m_add->setObjectName(QStringLiteral("pushButton_m_add"));
        pushButton_m_add->setGeometry(QRect(480, 220, 41, 41));
        pushButton_m = new QPushButton(groupBox1);
        pushButton_m->setObjectName(QStringLiteral("pushButton_m"));
        pushButton_m->setGeometry(QRect(530, 220, 41, 41));
        button_m_inc = new QPushButton(groupBox1);
        button_m_inc->setObjectName(QStringLiteral("button_m_inc"));
        button_m_inc->setGeometry(QRect(580, 220, 41, 41));
        pushButton_add = new QPushButton(groupBox1);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(630, 220, 41, 41));
        button_sin = new QPushButton(groupBox1);
        button_sin->setObjectName(QStringLiteral("button_sin"));
        button_sin->setGeometry(QRect(280, 270, 41, 41));
        QFont font3;
        font3.setItalic(true);
        button_sin->setFont(font3);
        button_sinh = new QPushButton(groupBox1);
        button_sinh->setObjectName(QStringLiteral("button_sinh"));
        button_sinh->setGeometry(QRect(330, 270, 41, 41));
        button_sinh->setFont(font3);
        button_square = new QPushButton(groupBox1);
        button_square->setObjectName(QStringLiteral("button_square"));
        button_square->setGeometry(QRect(380, 270, 41, 41));
        button_square->setFont(font3);
        button_root2 = new QPushButton(groupBox1);
        button_root2->setObjectName(QStringLiteral("button_root2"));
        button_root2->setGeometry(QRect(430, 270, 41, 41));
        button_root2->setFont(font3);
        pushButton_1 = new QPushButton(groupBox1);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(480, 270, 41, 41));
        pushButton_2 = new QPushButton(groupBox1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 270, 41, 41));
        pushButton_3 = new QPushButton(groupBox1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 270, 41, 41));
        pushButton_inc = new QPushButton(groupBox1);
        pushButton_inc->setObjectName(QStringLiteral("pushButton_inc"));
        pushButton_inc->setGeometry(QRect(630, 270, 41, 41));
        pushButton_mul = new QPushButton(groupBox1);
        pushButton_mul->setObjectName(QStringLiteral("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(630, 320, 41, 41));
        pushButton_6 = new QPushButton(groupBox1);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 320, 41, 41));
        pushButton_5 = new QPushButton(groupBox1);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(530, 320, 41, 41));
        pushButton_4 = new QPushButton(groupBox1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 320, 41, 41));
        button_root3 = new QPushButton(groupBox1);
        button_root3->setObjectName(QStringLiteral("button_root3"));
        button_root3->setGeometry(QRect(430, 320, 41, 41));
        button_root3->setFont(font3);
        button_cube = new QPushButton(groupBox1);
        button_cube->setObjectName(QStringLiteral("button_cube"));
        button_cube->setGeometry(QRect(380, 320, 41, 41));
        button_cube->setFont(font3);
        button_cosh = new QPushButton(groupBox1);
        button_cosh->setObjectName(QStringLiteral("button_cosh"));
        button_cosh->setGeometry(QRect(330, 320, 41, 41));
        button_cosh->setFont(font3);
        button_cos = new QPushButton(groupBox1);
        button_cos->setObjectName(QStringLiteral("button_cos"));
        button_cos->setGeometry(QRect(280, 320, 41, 41));
        button_cos->setFont(font3);
        button_tan = new QPushButton(groupBox1);
        button_tan->setObjectName(QStringLiteral("button_tan"));
        button_tan->setGeometry(QRect(280, 370, 41, 41));
        button_tan->setFont(font3);
        button_tanh = new QPushButton(groupBox1);
        button_tanh->setObjectName(QStringLiteral("button_tanh"));
        button_tanh->setGeometry(QRect(330, 370, 41, 41));
        button_tanh->setFont(font3);
        button_power = new QPushButton(groupBox1);
        button_power->setObjectName(QStringLiteral("button_power"));
        button_power->setGeometry(QRect(380, 370, 41, 41));
        button_power->setFont(font3);
        button_log = new QPushButton(groupBox1);
        button_log->setObjectName(QStringLiteral("button_log"));
        button_log->setGeometry(QRect(430, 370, 41, 41));
        button_log->setFont(font3);
        pushButton_7 = new QPushButton(groupBox1);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(480, 370, 41, 41));
        pushButton_8 = new QPushButton(groupBox1);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(530, 370, 41, 41));
        pushButton_9 = new QPushButton(groupBox1);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(580, 370, 41, 41));
        pushButton_div = new QPushButton(groupBox1);
        pushButton_div->setObjectName(QStringLiteral("pushButton_div"));
        pushButton_div->setGeometry(QRect(630, 370, 41, 41));
        button_cot = new QPushButton(groupBox1);
        button_cot->setObjectName(QStringLiteral("button_cot"));
        button_cot->setGeometry(QRect(280, 420, 41, 41));
        button_cot->setFont(font3);
        button_pi = new QPushButton(groupBox1);
        button_pi->setObjectName(QStringLiteral("button_pi"));
        button_pi->setGeometry(QRect(330, 420, 41, 41));
        button_pi->setFont(font3);
        button_exp = new QPushButton(groupBox1);
        button_exp->setObjectName(QStringLiteral("button_exp"));
        button_exp->setGeometry(QRect(380, 420, 41, 41));
        button_exp->setFont(font3);
        button_ln = new QPushButton(groupBox1);
        button_ln->setObjectName(QStringLiteral("button_ln"));
        button_ln->setGeometry(QRect(430, 420, 41, 41));
        button_ln->setFont(font3);
        pushButton_sign = new QPushButton(groupBox1);
        pushButton_sign->setObjectName(QStringLiteral("pushButton_sign"));
        pushButton_sign->setGeometry(QRect(480, 420, 41, 41));
        pushButton_0 = new QPushButton(groupBox1);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(530, 420, 41, 41));
        pushButton_point = new QPushButton(groupBox1);
        pushButton_point->setObjectName(QStringLiteral("pushButton_point"));
        pushButton_point->setGeometry(QRect(580, 420, 41, 41));
        pushbutton_equal = new QPushButton(groupBox1);
        pushbutton_equal->setObjectName(QStringLiteral("pushbutton_equal"));
        pushbutton_equal->setGeometry(QRect(630, 420, 41, 41));
        label_Power = new QLabel(groupBox1);
        label_Power->setObjectName(QStringLiteral("label_Power"));
        label_Power->setGeometry(QRect(670, 190, 41, 31));
        label_Power->setStyleSheet(QStringLiteral(""));
        label_M = new QLabel(groupBox1);
        label_M->setObjectName(QStringLiteral("label_M"));
        label_M->setGeometry(QRect(670, 160, 41, 31));
        pushButton = new QPushButton(groupBox1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(842, 20, 131, 51));
        pushButton_kexue_return = new QPushButton(groupBox1);
        pushButton_kexue_return->setObjectName(QStringLiteral("pushButton_kexue_return"));
        pushButton_kexue_return->setGeometry(QRect(-10, 20, 194, 59));
        pushButton_kexue_return->setStyleSheet(QLatin1String("QPushButton {\n"
"  min-width:194px;\n"
"  max-width:194px;\n"
"  min-height:59px;\n"
"  max-height:59px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 28px;\n"
"  border-radius: 0px;\n"
"  color: black;\n"
"  background-color: transparent;\n"
"  border-color: red;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"  image: url(C:/Users/zhangyun/Desktop/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        pushButton_kCal_return = new QPushButton(page_3);
        pushButton_kCal_return->setObjectName(QStringLiteral("pushButton_kCal_return"));
        pushButton_kCal_return->setGeometry(QRect(10, 40, 194, 59));
        pushButton_kCal_return->setStyleSheet(QLatin1String("QPushButton {\n"
"  min-width:194px;\n"
"  max-width:194px;\n"
"  min-height:59px;\n"
"  max-height:59px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 28px;\n"
"  border-radius: 0px;\n"
"  color: black;\n"
"  background-color: transparent;\n"
"  border-color: red;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"  image: url(C:/Users/zhangyun/Desktop/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"}"));
        pushButton_datachange = new QPushButton(page_3);
        pushButton_datachange->setObjectName(QStringLiteral("pushButton_datachange"));
        pushButton_datachange->setGeometry(QRect(890, 130, 181, 371));
        QFont font4;
        font4.setPointSize(20);
        pushButton_datachange->setFont(font4);
        pushButton_ability = new QPushButton(page_3);
        pushButton_ability->setObjectName(QStringLiteral("pushButton_ability"));
        pushButton_ability->setGeometry(QRect(640, 130, 181, 371));
        pushButton_ability->setFont(font4);
        pushButton_vs = new QPushButton(page_3);
        pushButton_vs->setObjectName(QStringLiteral("pushButton_vs"));
        pushButton_vs->setGeometry(QRect(390, 130, 181, 371));
        pushButton_vs->setFont(font4);
        pushButton_525 = new QPushButton(page_3);
        pushButton_525->setObjectName(QStringLiteral("pushButton_525"));
        pushButton_525->setGeometry(QRect(140, 130, 181, 371));
        pushButton_525->setFont(font4);
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 40, 221, 61));
        QFont font5;
        font5.setPointSize(17);
        label_3->setFont(font5);
        stackedWidget->addWidget(page_3);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        pushButton_525_return = new QPushButton(page_5);
        pushButton_525_return->setObjectName(QStringLiteral("pushButton_525_return"));
        pushButton_525_return->setGeometry(QRect(10, 40, 194, 59));
        pushButton_525_return->setStyleSheet(QLatin1String("QPushButton {\n"
"  min-width:194px;\n"
"  max-width:194px;\n"
"  min-height:59px;\n"
"  max-height:59px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 28px;\n"
"  border-radius: 0px;\n"
"  color: black;\n"
"  background-color: transparent;\n"
"  border-color: red;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"  image: url(C:/Users/zhangyun/Desktop/icon_pic/85923789d31e1c88f5cb6808dd1eb125_back.png);\n"
"}"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 40, 221, 61));
        label_4->setFont(font5);
        pushButton_525c1 = new QPushButton(page_5);
        pushButton_525c1->setObjectName(QStringLiteral("pushButton_525c1"));
        pushButton_525c1->setGeometry(QRect(30, 130, 51, 51));
        pushButton_525c2 = new QPushButton(page_5);
        pushButton_525c2->setObjectName(QStringLiteral("pushButton_525c2"));
        pushButton_525c2->setGeometry(QRect(30, 200, 51, 51));
        pushButton_525c3 = new QPushButton(page_5);
        pushButton_525c3->setObjectName(QStringLiteral("pushButton_525c3"));
        pushButton_525c3->setGeometry(QRect(30, 270, 51, 51));
        pushButton_525c4 = new QPushButton(page_5);
        pushButton_525c4->setObjectName(QStringLiteral("pushButton_525c4"));
        pushButton_525c4->setGeometry(QRect(30, 340, 51, 51));
        pushButton_525c5 = new QPushButton(page_5);
        pushButton_525c5->setObjectName(QStringLiteral("pushButton_525c5"));
        pushButton_525c5->setGeometry(QRect(30, 410, 51, 51));
        gridWidget_525 = new QWidget(page_5);
        gridWidget_525->setObjectName(QStringLiteral("gridWidget_525"));
        gridWidget_525->setGeometry(QRect(170, 90, 661, 381));
        gridWidget_525->setStyleSheet(QLatin1String("gridWidget_52 {\n"
"    background-color: rgba(33, 69, 105, 100);\n"
"}"));
        gridLayout = new QGridLayout(gridWidget_525);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget_2 = new QStackedWidget(gridWidget_525);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        scrollArea = new QScrollArea(page_9);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-10, -10, 661, 341));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_525A = new QWidget();
        scrollAreaWidgetContents_525A->setObjectName(QStringLiteral("scrollAreaWidgetContents_525A"));
        scrollAreaWidgetContents_525A->setGeometry(QRect(0, 0, 659, 339));
        scrollArea->setWidget(scrollAreaWidgetContents_525A);
        stackedWidget_2->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        scrollArea_2 = new QScrollArea(page_10);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_5251 = new QWidget();
        scrollAreaWidgetContents_5251->setObjectName(QStringLiteral("scrollAreaWidgetContents_5251"));
        scrollAreaWidgetContents_5251->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_2->setWidget(scrollAreaWidgetContents_5251);
        stackedWidget_2->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        scrollArea_3 = new QScrollArea(page_11);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_5252 = new QWidget();
        scrollAreaWidgetContents_5252->setObjectName(QStringLiteral("scrollAreaWidgetContents_5252"));
        scrollAreaWidgetContents_5252->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_3->setWidget(scrollAreaWidgetContents_5252);
        stackedWidget_2->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QStringLiteral("page_12"));
        scrollArea_4 = new QScrollArea(page_12);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_5253 = new QWidget();
        scrollAreaWidgetContents_5253->setObjectName(QStringLiteral("scrollAreaWidgetContents_5253"));
        scrollAreaWidgetContents_5253->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_4->setWidget(scrollAreaWidgetContents_5253);
        stackedWidget_2->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        scrollArea_5 = new QScrollArea(page_13);
        scrollArea_5->setObjectName(QStringLiteral("scrollArea_5"));
        scrollArea_5->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5254 = new QWidget();
        scrollAreaWidgetContents_5254->setObjectName(QStringLiteral("scrollAreaWidgetContents_5254"));
        scrollAreaWidgetContents_5254->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_5->setWidget(scrollAreaWidgetContents_5254);
        stackedWidget_2->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        scrollArea_6 = new QScrollArea(page_14);
        scrollArea_6->setObjectName(QStringLiteral("scrollArea_6"));
        scrollArea_6->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_5255 = new QWidget();
        scrollAreaWidgetContents_5255->setObjectName(QStringLiteral("scrollAreaWidgetContents_5255"));
        scrollAreaWidgetContents_5255->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_6->setWidget(scrollAreaWidgetContents_5255);
        stackedWidget_2->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName(QStringLiteral("page_15"));
        scrollArea_7 = new QScrollArea(page_15);
        scrollArea_7->setObjectName(QStringLiteral("scrollArea_7"));
        scrollArea_7->setGeometry(QRect(-10, -10, 611, 341));
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_5256 = new QWidget();
        scrollAreaWidgetContents_5256->setObjectName(QStringLiteral("scrollAreaWidgetContents_5256"));
        scrollAreaWidgetContents_5256->setGeometry(QRect(0, 0, 609, 339));
        scrollArea_7->setWidget(scrollAreaWidgetContents_5256);
        stackedWidget_2->addWidget(page_15);

        gridLayout->addWidget(stackedWidget_2, 2, 0, 1, 10);

        pushButton_5250 = new QPushButton(gridWidget_525);
        pushButton_5250->setObjectName(QStringLiteral("pushButton_5250"));
        pushButton_5250->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5250, 1, 1, 1, 1);

        pushButton_525A = new QPushButton(gridWidget_525);
        pushButton_525A->setObjectName(QStringLiteral("pushButton_525A"));
        pushButton_525A->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_525A, 1, 0, 1, 1);

        pushButton_5252 = new QPushButton(gridWidget_525);
        pushButton_5252->setObjectName(QStringLiteral("pushButton_5252"));
        pushButton_5252->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5252, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 8, 1, 1);

        pushButton_5253 = new QPushButton(gridWidget_525);
        pushButton_5253->setObjectName(QStringLiteral("pushButton_5253"));
        pushButton_5253->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5253, 1, 4, 1, 1);

        pushButton_5251 = new QPushButton(gridWidget_525);
        pushButton_5251->setObjectName(QStringLiteral("pushButton_5251"));
        pushButton_5251->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5251, 1, 2, 1, 1);

        pushButton_5254 = new QPushButton(gridWidget_525);
        pushButton_5254->setObjectName(QStringLiteral("pushButton_5254"));
        pushButton_5254->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5254, 1, 5, 1, 1);

        pushButton_5255 = new QPushButton(gridWidget_525);
        pushButton_5255->setObjectName(QStringLiteral("pushButton_5255"));
        pushButton_5255->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  font-family: \345\256\213\344\275\223;\n"
"  min-width:92px;\n"
"  max-width:92px;\n"
"  min-height:27px;\n"
"  max-height:27px;\n"
"  border-width: 0px;\n"
"  border-style: outset;\n"
"  font-size: 17px;\n"
"  border-radius: 6px;\n"
"  color: rgba(0, 255, 255, 255);\n"
"  background-color: rgba(255, 255, 255, 255);\n"
"  font-weight: bold;\n"
"  box-shadow: 0px 0px 0px rgba(0, 0, 127, 255);\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove.jpg);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  border-width: 0px;\n"
"  border-style: inset;\n"
"  border-radius: 0px;\n"
"  color: white;\n"
"  background-image: url(D:/kCal/icon_pic/b9f9255673ea80df9fae5b0020b0e49d_tab-hove11.jpg);\n"
"}"));

        gridLayout->addWidget(pushButton_5255, 1, 6, 1, 1);

        stackedWidget->addWidget(page_5);
        gridWidget_525->raise();
        pushButton_525_return->raise();
        label_4->raise();
        pushButton_525c1->raise();
        pushButton_525c2->raise();
        pushButton_525c3->raise();
        pushButton_525c4->raise();
        pushButton_525c5->raise();
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        pushButton_525_return_2 = new QPushButton(page_6);
        pushButton_525_return_2->setObjectName(QStringLiteral("pushButton_525_return_2"));
        pushButton_525_return_2->setGeometry(QRect(30, 40, 131, 51));
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 40, 221, 51));
        label_5->setFont(font5);
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        pushButton_525_return_3 = new QPushButton(page_7);
        pushButton_525_return_3->setObjectName(QStringLiteral("pushButton_525_return_3"));
        pushButton_525_return_3->setGeometry(QRect(30, 40, 131, 51));
        label_6 = new QLabel(page_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 40, 221, 51));
        label_6->setFont(font5);
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        pushButton_525_return_4 = new QPushButton(page_8);
        pushButton_525_return_4->setObjectName(QStringLiteral("pushButton_525_return_4"));
        pushButton_525_return_4->setGeometry(QRect(30, 40, 131, 51));
        label_7 = new QLabel(page_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 40, 221, 51));
        label_7->setFont(font5);
        stackedWidget->addWidget(page_8);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        theme_change = new QMenu(menu_2);
        theme_change->setObjectName(QStringLiteral("theme_change"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(import_statics);
        menu->addAction(export_statics);
        menu->addSeparator();
        menu->addAction(file_quit);
        menu_2->addAction(theme_change->menuAction());
        menu_2->addAction(menu_3->menuAction());
        theme_change->addAction(theme_black_white);
        theme_change->addAction(theme_blue);
        menu_3->addAction(background_heros);
        menu_3->addAction(background_graph);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "kCal", nullptr));
        import_statics->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245(I)", nullptr));
#ifndef QT_NO_SHORTCUT
        import_statics->setShortcut(QApplication::translate("MainWindow", "I", nullptr));
#endif // QT_NO_SHORTCUT
        export_statics->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272(O)", nullptr));
#ifndef QT_NO_SHORTCUT
        export_statics->setShortcut(QApplication::translate("MainWindow", "O", nullptr));
#endif // QT_NO_SHORTCUT
        theme_black_white->setText(QApplication::translate("MainWindow", "\351\273\221\347\231\275(W)", nullptr));
#ifndef QT_NO_SHORTCUT
        theme_black_white->setShortcut(QApplication::translate("MainWindow", "W", nullptr));
#endif // QT_NO_SHORTCUT
        theme_blue->setText(QApplication::translate("MainWindow", "\350\224\232\350\223\235(B)", nullptr));
#ifndef QT_NO_SHORTCUT
        theme_blue->setShortcut(QApplication::translate("MainWindow", "B", nullptr));
#endif // QT_NO_SHORTCUT
        background_heros->setText(QApplication::translate("MainWindow", "\350\213\261\351\233\204\346\265\267\346\212\245(H)", nullptr));
#ifndef QT_NO_SHORTCUT
        background_heros->setShortcut(QApplication::translate("MainWindow", "H", nullptr));
#endif // QT_NO_SHORTCUT
        background_graph->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211...(I)", nullptr));
#ifndef QT_NO_SHORTCUT
        background_graph->setShortcut(QApplication::translate("MainWindow", "I", nullptr));
#endif // QT_NO_SHORTCUT
        file_quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(Q)", nullptr));
#ifndef QT_NO_SHORTCUT
        file_quit->setShortcut(QApplication::translate("MainWindow", "Q", nullptr));
#endif // QT_NO_SHORTCUT
        help_H->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", nullptr));
#ifndef QT_NO_SHORTCUT
        help_H->setShortcut(QApplication::translate("MainWindow", "H", nullptr));
#endif // QT_NO_SHORTCUT
        kexue_Cal->setText(QApplication::translate("MainWindow", "\347\247\221\345\255\246\350\256\241\347\256\227\345\231\250", nullptr));
        king_Cal->setText(QApplication::translate("MainWindow", "kCal", nullptr));
        groupBox1->setTitle(QApplication::translate("MainWindow", "GroupBox1", nullptr));
        label_show_exp->setText(QApplication::translate("MainWindow", "0", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272:", nullptr));
        lineEdit_output->setText(QApplication::translate("MainWindow", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_ce->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\345\210\240\351\231\244\346\211\200\346\234\211\350\276\223\345\205\245\357\274\210\357\274\211<br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_ce->setText(QApplication::translate("MainWindow", "ce", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_c->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_c->setText(QApplication::translate("MainWindow", "del", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_cleft->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_cleft->setText(QApplication::translate("MainWindow", "(", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_cright->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_cright->setText(QApplication::translate("MainWindow", ")", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_m_add->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_m_add->setText(QApplication::translate("MainWindow", "M+", nullptr));
        pushButton_m->setText(QApplication::translate("MainWindow", "M", nullptr));
        button_m_inc->setText(QApplication::translate("MainWindow", "M-", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_add->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_add->setText(QApplication::translate("MainWindow", "+", nullptr));
        button_sin->setText(QApplication::translate("MainWindow", "sin", nullptr));
        button_sinh->setText(QApplication::translate("MainWindow", "sinh", nullptr));
        button_square->setText(QApplication::translate("MainWindow", "x\302\262", nullptr));
        button_root2->setText(QApplication::translate("MainWindow", "x^1/2", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_1->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_inc->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_inc->setText(QApplication::translate("MainWindow", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_mul->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_mul->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        button_root3->setText(QApplication::translate("MainWindow", "x^1/3", nullptr));
        button_cube->setText(QApplication::translate("MainWindow", "x\302\263", nullptr));
        button_cosh->setText(QApplication::translate("MainWindow", "cosh", nullptr));
        button_cos->setText(QApplication::translate("MainWindow", "cos", nullptr));
        button_tan->setText(QApplication::translate("MainWindow", "tan", nullptr));
        button_tanh->setText(QApplication::translate("MainWindow", "tanh", nullptr));
        button_power->setText(QApplication::translate("MainWindow", "x^y", nullptr));
        button_log->setText(QApplication::translate("MainWindow", "log", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_div->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_div->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        button_cot->setText(QApplication::translate("MainWindow", "cot", nullptr));
        button_pi->setText(QApplication::translate("MainWindow", "\317\200", nullptr));
        button_exp->setText(QApplication::translate("MainWindow", "e", nullptr));
        button_ln->setText(QApplication::translate("MainWindow", "ln", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_sign->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_sign->setText(QApplication::translate("MainWindow", "\302\261", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_0->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_point->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_point->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushbutton_equal->setText(QApplication::translate("MainWindow", "=", nullptr));
#ifndef QT_NO_TOOLTIP
        label_Power->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>p</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_Power->setText(QString());
        label_M->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "help", nullptr));
        pushButton_kexue_return->setText(QString());
        pushButton_kCal_return->setText(QString());
        pushButton_datachange->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\277\256\346\224\271", nullptr));
        pushButton_ability->setText(QApplication::translate("MainWindow", "\350\213\261\351\233\204\345\261\236\346\200\247", nullptr));
        pushButton_vs->setText(QApplication::translate("MainWindow", "\350\213\261\351\233\204\345\257\271\346\257\224", nullptr));
        pushButton_525->setText(QApplication::translate("MainWindow", "5v5", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "kCal", nullptr));
        pushButton_525_return->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "5v5\350\256\241\347\256\227", nullptr));
        pushButton_525c1->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_525c2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_525c3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_525c4->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_525c5->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5250->setText(QApplication::translate("MainWindow", "\345\235\246\345\205\213", nullptr));
        pushButton_525A->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250", nullptr));
        pushButton_5252->setText(QApplication::translate("MainWindow", "\345\210\272\345\256\242", nullptr));
        pushButton_5253->setText(QApplication::translate("MainWindow", "\346\263\225\345\270\210", nullptr));
        pushButton_5251->setText(QApplication::translate("MainWindow", "\346\210\230\345\243\253", nullptr));
        pushButton_5254->setText(QApplication::translate("MainWindow", "\345\260\204\346\211\213", nullptr));
        pushButton_5255->setText(QApplication::translate("MainWindow", "\350\276\205\345\212\251", nullptr));
        pushButton_525_return_2->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\213\261\351\233\204\345\257\271\346\257\224", nullptr));
        pushButton_525_return_3->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\350\213\261\351\233\204\345\261\236\346\200\247", nullptr));
        pushButton_525_return_4->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\277\256\346\224\271", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(S)", nullptr));
        theme_change->setTitle(QApplication::translate("MainWindow", "\344\270\273\351\242\230(T)", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\203\214\346\231\257\345\233\276\347\211\207(B)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
