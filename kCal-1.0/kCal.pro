#-------------------------------------------------
#
# Project created by QtCreator 2020-09-22T19:16:18
#
#-------------------------------------------------

INCLUDEPATH += C:\Users\zhangyun\AppData\Local\Programs\Python\Python38-32\include
LIBS += -LC:\Users\zhangyun\AppData\Local\Programs\Python\Python38-32\libs\
-l_tkinter\
-lpython3\
-lpython38

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kCal
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog_help.cpp \
    dialog_fail.cpp \
    pictureshow.cpp

HEADERS += \
        mainwindow.h \
    dialog_help.h \
    dialog_fail.h \
    pictureshow.h

FORMS += \
        mainwindow.ui \
    dialog_help.ui \
    dialog_fail.ui \
    pictureshow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    hero_py.py
