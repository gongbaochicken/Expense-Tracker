#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    //Create mainwindow;
    Tracker w;
    w.setMinimumSize(700, 450);
    w.setMaximumSize(700, 450);
    w.show();
    w.setWindowTitle("Expense Tracker");

    return a.exec();

}

