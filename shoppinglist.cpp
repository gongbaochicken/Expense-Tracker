#include "shoppinglist.h"
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <iostream>

shoppinglist::shoppinglist(QWidget *parent, std::vector<std::pair<std::string, double> > *_shoppingItems, double & _budget) :
    QDialog(parent), budget(_budget)
{
    List=new QListWidget;
    List->setStyleSheet( "QListWidget::item { background-color: white;border-bottom: 1px solid black; }"
                                  "QListWidget::item:selected{color: #333538;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #cdcdcd, stop: 1 #ababab); border-top: 1px solid;border-top-color: #a8abad;border-bottom: 1px solid;border-bottom-color: #bfc7ce;}");

    shoppingItems = _shoppingItems;
    //shoppingItems_tmp = &_shoppingItems;
    addButton=new QPushButton(tr("Add"));
    addButton->setFont(QFont("Times", 14, QFont::Bold));
    removeButton=new QPushButton(tr("REMOVE"));
    removeButton->setFont(QFont("Times", 14, QFont::Bold));
    QHBoxLayout *operationLay=new QHBoxLayout;
    operationLay->addStretch(1);
    operationLay->addWidget(addButton,1);
    operationLay->addWidget(removeButton,1);
   // budget = _budget;
    QVBoxLayout *layshopping=new QVBoxLayout;
    layshopping->addWidget(List,12);
    layshopping->addLayout(operationLay,1);
    setLayout(layshopping);
    updateList();

    QDir currentDir;
    QString newpath (":/image/images/2.jpg");
    QPixmap pixmap = QPixmap(newpath).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

//*****************************************************************************
    connect(addButton, SIGNAL(clicked()),this, SLOT(addShoppingItem()));
    connect(removeButton, SIGNAL(clicked()),this, SLOT(removeShoppingItem()));
}

shoppinglist::~shoppinglist()
{
    //shoppingItems_tmp = &shoppingItems;
}

QString shoppinglist::filingIn(QString tofiling, int charNum){
  QString tmp = tofiling;
  for(int i = 0; i < (charNum - tofiling.length()); i++){
    tmp = tmp + " ";
  }
  return tmp;
}

void shoppinglist::updateList(){

    List->clear();
    if(shoppingItems != NULL){
        //std::cout<<"updateshoppinglist"<<std::endl;
        for(unsigned i = 0; i < shoppingItems->size(); i++){
         QString nameToAdd = filingIn(QString::fromStdString((*shoppingItems)[i].first), 20);
         QString amountToAdd = QString::number((*shoppingItems)[i].second);
         QString _itemToAdd = nameToAdd + "    " + amountToAdd;
         QListWidgetItem * itemToAdd = new QListWidgetItem;
         itemToAdd->setText(_itemToAdd);
         itemToAdd->setFont(QFont("Monaco", 10, QFont::Bold));
         //std::cout<<itemToAdd->text().toStdString().c_str()<<std::endl;
         List->addItem(itemToAdd);
        }
    }

}


void shoppinglist::addShoppingItem()
{
    shoppingitemwindow = new shoppingItem();
    shoppingitemwindow->setMaximumSize(300,200);
    shoppingitemwindow->setMinimumSize(300,200);
    shoppingitemwindow->setWindowTitle("Add shopping list");

    if(shoppingitemwindow->exec() == QDialog::Accepted){

        std::pair<std::string, double> toAdd(shoppingitemwindow->itemName.toStdString(), shoppingitemwindow->itemAmount);
        //std::cout<<toAdd.first<<" "<<toAdd.second<<std::endl;
        if(shoppingItems == NULL){
            shoppingItems = new std::vector<std::pair<std::string, double> >;
        }
        shoppingItems->push_back(toAdd);
        budget += shoppingitemwindow->addToBudget;

        //std::cout<<"clicked SAVE"<<std::endl;
        updateList();
    }
}

void shoppinglist::removeShoppingItem()
{
    if(List->currentItem() == NULL) return;
    QString toRemove = List->currentItem()->text();
    std::string Rname(toRemove.toStdString(), 0 ,17);
    std::string Ramount(toRemove.toStdString(), 17, 15);
    double RVamount = atof(Ramount.c_str());
    for(unsigned i = 0; i < shoppingItems->size(); i++){
        std::string nameFromItem = filingIn(QString::fromStdString((*shoppingItems)[i].first), 17).toStdString();
        if(nameFromItem.compare(Rname) == 0 && RVamount == (*shoppingItems)[i].second){
            shoppingItems->erase((*shoppingItems).begin() + i);
            updateList();
            return;
       }
    }

}

