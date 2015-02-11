#include "addexpensedialog.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <iostream>
addExpenseDialog::addExpenseDialog(QWidget *parent) :
    QDialog(parent)
{
    expenseamount=0;
    expensename="";
    newLabel = 0;
    QLabel *itemName = new QLabel(tr("Name:"));
    nameLine=new QLineEdit;
    nameLine->setMaxLength(15);
    //expensename=nameLine->text();
    QHBoxLayout *namearea = new QHBoxLayout;
    namearea->addWidget(itemName);
    namearea->addWidget(nameLine);

    QLabel *itemMoney = new QLabel(tr("Cost:$"));
    moneyLine=new QLineEdit;
    moneyLine->setValidator(new QDoubleValidator(0, 1000000, 5, this));
    //expenseamount=moneyLine->text().toDouble();
    QHBoxLayout *moneyarea = new QHBoxLayout;
    moneyarea->addWidget(itemMoney);
    moneyarea->addWidget(moneyLine);

    itemCategory = new QLabel(tr("Category:"));
    categoryBox = new QComboBox;
    QHBoxLayout *boxarea = new QHBoxLayout;
    boxarea->addWidget(itemCategory,2);
    boxarea->addWidget(categoryBox,5);

    newBox1=new QGroupBox(tr("Add New Category"));
    newBox1->setCheckable(true);
    newBox1->setChecked(false);
    QLabel *newCate = new QLabel(tr("New Categroy:"));
    newCategoryLine=new QLineEdit;
    newCategoryLine->setMaxLength(14);

    QHBoxLayout *Hbox1 = new QHBoxLayout;
    Hbox1->addWidget(newCate);
    Hbox1->addWidget(newCategoryLine);
    newBox1->setLayout(Hbox1);

    QHBoxLayout *saveLayout = new QHBoxLayout;
    saveButton=new QPushButton(tr("Save"));
    cancelButton=new QPushButton(tr("Cancel"));
    saveLayout->addStretch();
    saveLayout->addWidget(saveButton);
    saveLayout->addWidget(cancelButton);

    QVBoxLayout *whole=new QVBoxLayout;
    whole->addLayout(namearea);
    whole->addLayout(moneyarea);
    whole->addLayout(boxarea);
    whole->addWidget(newBox1);
    whole->addLayout(saveLayout);
    setLayout(whole);
//**********************************************************************************//

    connect(categoryBox, SIGNAL(activated(int)),this, SLOT(categoryChanged(int)));
    connect(saveButton, SIGNAL(clicked()),this, SLOT(save()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(newBox1, SIGNAL(toggled(bool)), this, SLOT(addnew()));
}

addExpenseDialog::~addExpenseDialog()
{

}

void addExpenseDialog::categoryChanged(int)
{

//    if(index == categoryBox->count() - 1){
//        //TODO -- add a new dialog for new label
//        expenseLabel = QString("from a new Dialog");
//        newLabel = 1;
//    }
}

void addExpenseDialog::addnew()
{
    if(newBox1->isChecked()){
        itemCategory->setEnabled(false);
        categoryBox->setEnabled(false);
        newLabel = 1;
    }
    else{
        itemCategory->setEnabled(true);
        categoryBox->setEnabled(true);
        newLabel = 0;
    }
}

void addExpenseDialog::save()
{
    if(newLabel == 0){
        expenseLabel=categoryBox->currentText();
    }
    else{
        expenseLabel = newCategoryLine->text();
    }
    expensename=nameLine->text();
    expenseamount=moneyLine->text().toDouble();
    accept();
    //close();
}

void addExpenseDialog::cancel()
{
    reject();
    //close();
}
