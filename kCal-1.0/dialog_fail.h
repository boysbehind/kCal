#ifndef DIALOG_FAIL_H
#define DIALOG_FAIL_H

#include <QDialog>

namespace Ui {
class Dialog_fail;
}

class Dialog_fail : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_fail(QWidget *parent = nullptr);
    void setText(QString error);
    ~Dialog_fail();

private:
    Ui::Dialog_fail *ui;
};

#endif // DIALOG_FAIL_H
