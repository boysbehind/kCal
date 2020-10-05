#include "mainwindow.h"
#include <QApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    py_hello();
    QApplication a(argc, argv);
    MainWindow w;
    Dialog_help h;
    w.show();
    return a.exec();
}
