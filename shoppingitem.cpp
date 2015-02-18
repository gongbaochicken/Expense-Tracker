#include "shoppingitem.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <iostream>

shoppingItem::shoppingItem()
{

    shoppingName=new QLabel(tr("Item Name:"));
    nameLine=new QLineEdit;
    nameLine->setMaxLength(15);
    QHBoxLayout *h1 = new QHBoxLayout;
    h1->addWidget(shoppingName);
    h1->addWidget(nameLine);
    addToBudget = 0;

    expectMoney=new QLabel(tr("Expected Expenditure $:"));
    moneyLine=new QLineEdit;
    QHBoxLayout *h2 = new QHBoxLayout;
    h2->addWidget(expectMoney);
    h2->addWidget(moneyLine);

    checkBoxxx=new QCheckBox(tr("Increase your budget?"));
    checkBoxxx->setChecked(false);

    saveButton=new QPushButton(tr("Save"));
    cancelButton=new QPushButton(tr("Cancel"));
    QHBoxLayout *h3 = new QHBoxLayout;
    h3->addStretch();
    h3->addWidget(saveButton);
    h3->addWidget(cancelButton);

    QVBoxLayout *addItemLayout = new QVBoxLayout;
    addItemLayout->addLayout(h1);
    addItemLayout->addLayout(h2);
    addItemLayout->addWidget(checkBoxxx);
    addItemLayout->addLayout(h3);
    setLayout(addItemLayout);

    connect(saveButton, SIGNAL(clicked()),this, SLOT(save()));
    connect(cancelButton, SIGNAL(clicked()),this, SLOT(cancel()));
}

shoppingItem::~shoppingItem()
{

}

void shoppingItem::save()
{
    itemName=nameLine->text();
    itemAmount=moneyLine->text().toDouble();

    if(checkBoxxx->isChecked()){
        addToBudget = itemAmount;
    }
    accept();
    //close();

}

void shoppingItem::cancel()
{
    reject();
}
