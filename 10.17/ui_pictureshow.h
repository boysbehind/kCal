/********************************************************************************
** Form generated from reading UI file 'pictureshow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURESHOW_H
#define UI_PICTURESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_PictureShow
{
public:

    void setupUi(QDialog *PictureShow)
    {
        if (PictureShow->objectName().isEmpty())
            PictureShow->setObjectName(QStringLiteral("PictureShow"));
        PictureShow->resize(400, 300);

        retranslateUi(PictureShow);

        QMetaObject::connectSlotsByName(PictureShow);
    } // setupUi

    void retranslateUi(QDialog *PictureShow)
    {
        PictureShow->setWindowTitle(QApplication::translate("PictureShow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PictureShow: public Ui_PictureShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURESHOW_H
