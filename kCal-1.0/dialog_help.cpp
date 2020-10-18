//帮助页面构造函数

#include "dialog_help.h"
#include "ui_dialog_help.h"

Dialog_help::Dialog_help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_help)
{
    ui->setupUi(this);
    ui->help_text->append("----Version 1.0----\n\n    kCal欢迎您的使用！\n\nQQ2752583070");
}

Dialog_help::~Dialog_help()
{
    delete ui;
}

