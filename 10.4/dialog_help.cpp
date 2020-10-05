//帮助页面构造函数

#include "dialog_help.h"
#include "ui_dialog_help.h"

Dialog_help::Dialog_help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_help)
{
    ui->setupUi(this);
}

Dialog_help::~Dialog_help()
{
    delete ui;
}
