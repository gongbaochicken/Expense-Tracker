#include "budgetwindow.h"
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

budgetWindow::budgetWindow(QWidget *parent):
    QDialog(parent)
{

    QLabel *budgetLabel=new QLabel(tr("New Budget: $"));
    budgetInputLine=new QLineEdit;
    budgetInputLine->setValidator(new QDoubleValidator(0, 1000000000, 9, this));
    QHBoxLayout *filay=new QHBoxLayout;
    filay->addWidget(budgetLabel);
    filay->addWidget(budgetInputLine);


    saveButton=new QPushButton(tr("Save"));
    cancelButton=new QPushButton(tr("Cancel"));
    QHBoxLayout *secondlay=new QHBoxLayout;
    secondlay->addStretch(20);
    secondlay->addWidget(saveButton,1);
    secondlay->addWidget(cancelButton,1);

    QVBoxLayout *wholelay=new QVBoxLayout;
    wholelay->addLayout(filay);
    wholelay->addLayout(secondlay);
    setLayout(wholelay);

/***************************************************************/
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveBudget()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancelBudget()));

}

budgetWindow::~budgetWindow()
{

}

void budgetWindow::saveBudget()
{
    newBudget = budgetInputLine->text().toDouble();

    accept();
}

void budgetWindow::cancelBudget()
{
    reject();
}

