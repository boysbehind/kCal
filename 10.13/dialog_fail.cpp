#include "dialog_fail.h"
#include "ui_dialog_fail.h"

Dialog_fail::Dialog_fail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fail)
{
    ui->setupUi(this);
}

void Dialog_fail::setText(QString error)
{
    ui->label_error->setText("ERROR: "+error);
}

Dialog_fail::~Dialog_fail()
{
    delete ui;
}
