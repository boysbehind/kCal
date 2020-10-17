/********************************************************************************
** Form generated from reading UI file 'dialog_fail.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FAIL_H
#define UI_DIALOG_FAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog_fail
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_error;

    void setupUi(QDialog *Dialog_fail)
    {
        if (Dialog_fail->objectName().isEmpty())
            Dialog_fail->setObjectName(QStringLiteral("Dialog_fail"));
        Dialog_fail->resize(568, 184);
        buttonBox = new QDialogButtonBox(Dialog_fail);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_error = new QLabel(Dialog_fail);
        label_error->setObjectName(QStringLiteral("label_error"));
        label_error->setGeometry(QRect(20, 40, 531, 51));
        label_error->setStyleSheet(QLatin1String("QLineEdit{\n"
"font-color::rgb(255, 0, 0);\n"
"}"));

        retranslateUi(Dialog_fail);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_fail, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_fail, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_fail);
    } // setupUi

    void retranslateUi(QDialog *Dialog_fail)
    {
        Dialog_fail->setWindowTitle(QApplication::translate("Dialog_fail", "Dialog", nullptr));
        label_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_fail: public Ui_Dialog_fail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FAIL_H
