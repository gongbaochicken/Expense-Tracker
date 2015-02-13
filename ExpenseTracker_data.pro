#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T23:53:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpenseTracker_data
TEMPLATE = app


SOURCES += \
    addexpensedialog.cpp \
    addincomedialog.cpp \
    basicModel.cpp \
    budgetwindow.cpp \
    linechart.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcodegenerator.cpp \
    qrwidget.cpp \
    reportwindow.cpp \
    shoppingitem.cpp \
    shoppinglist.cpp

HEADERS  += \
    addexpensedialog.h \
    addincomedialog.h \
    basicModel.h \
    budgetwindow.h \
    dataRead.h \
    dataWrite.h \
    linechart.h \
    mainwindow.h \
    operation.h \
    qrcodegenerator.h \
    qrwidget.h \
    report.h \
    reportwindow.h \
    shoppingitem.h \
    shoppinglist.h

RESOURCES += \
    expenseTrackerData.qrc
