#ifndef PICTURESHOW_H
#define PICTURESHOW_H

#include <QDialog>

namespace Ui {
class PictureShow;
}

class PictureShow : public QDialog
{
    Q_OBJECT

public:
    explicit PictureShow(QWidget *parent = nullptr);
    ~PictureShow();

private:
    Ui::PictureShow *ui;
};

#endif // PICTURESHOW_H
