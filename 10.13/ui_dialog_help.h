/********************************************************************************
** Form generated from reading UI file 'dialog_help.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_HELP_H
#define UI_DIALOG_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_help
{
public:
    QDialogButtonBox *button_ok;
    QTextEdit *help_text;

    void setupUi(QDialog *Dialog_help)
    {
        if (Dialog_help->objectName().isEmpty())
            Dialog_help->setObjectName(QStringLiteral("Dialog_help"));
        Dialog_help->resize(400, 300);
        button_ok = new QDialogButtonBox(Dialog_help);
        button_ok->setObjectName(QStringLiteral("button_ok"));
        button_ok->setGeometry(QRect(30, 240, 341, 32));
        button_ok->setOrientation(Qt::Horizontal);
        button_ok->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        help_text = new QTextEdit(Dialog_help);
        help_text->setObjectName(QStringLiteral("help_text"));
        help_text->setGeometry(QRect(30, 20, 341, 211));

        retranslateUi(Dialog_help);
        QObject::connect(button_ok, SIGNAL(accepted()), Dialog_help, SLOT(close()));
        QObject::connect(button_ok, SIGNAL(rejected()), Dialog_help, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog_help);
    } // setupUi

    void retranslateUi(QDialog *Dialog_help)
    {
        Dialog_help->setWindowTitle(QApplication::translate("Dialog_help", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_help: public Ui_Dialog_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_HELP_H
