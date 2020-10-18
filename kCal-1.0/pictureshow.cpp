#include "pictureshow.h"
#include "ui_pictureshow.h"

PictureShow::PictureShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PictureShow)
{
    ui->setupUi(this);
}

PictureShow::~PictureShow()
{
    delete ui;
}
