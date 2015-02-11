#include "mainwindow.h"
#include "dataRead.h"
#include "dataWrite.h"
#include <QDate>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
#include <QPalette>

//#include <addexpensedialog.h>
//#include <addincomedialog.h">

Tracker::Tracker(QWidget *parent)
    : QWidget(parent)
{
 //****************construct putton and widget************************//
    //Calendar Setting
    calendar = new QCalendarWidget;
    calendar->setGridVisible(true);

    QLabel *listname=new QLabel("                   Detail  Table");
    listname->setFont(QFont("Times", 16, QFont::Bold));

    listname->setStyleSheet("QLabel { background-color : rgb(255, 165, 0); color : black; }");
    detailList=new QListWidget;
    detailList->setStyleSheet( "QListWidget::item { background-color: white;border-bottom: 1px solid black; }"
                                  "QListWidget::item:selected{color: #333538;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #cdcdcd, stop: 1 #ababab); border-top: 1px solid;border-top-color: #a8abad;border-bottom: 1px solid;border-bottom-color: #bfc7ce;}");

    removeButton=new QPushButton(tr("&REMOVE"));
    removeButton->setFont(QFont("Cambria", 14, QFont::Bold));
    QVBoxLayout *LayoutRight=new QVBoxLayout;
    LayoutRight->addWidget(listname,1);
    LayoutRight->addWidget(detailList,12);
    LayoutRight->setSpacing(3);
    LayoutRight->addWidget(removeButton,2);

    QHBoxLayout *Layout1=new QHBoxLayout;
    Layout1->addWidget(calendar,3);
    Layout1->addLayout(LayoutRight,2);

//Background Setting

    QString newpath (":/image/images/2.jpg");
    QPixmap pixmap = QPixmap(newpath).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

//pushbutton declaration
    addExpenseButton = new QPushButton(tr("&Expense"));
    addExpenseButton->setFont(QFont("Cambria", 13, QFont::Bold));
    addIncomeButton= new QPushButton(tr("&Income"));
    addIncomeButton->setFont(QFont("Cambria", 13, QFont::Bold));
    shoppingListButton= new QPushButton(tr("&Shopping List"));
    shoppingListButton->setFont(QFont("Cambria", 13, QFont::Bold));
    reportButton = new QPushButton(tr("&Report"));
    reportButton->setFont(QFont("Cambria", 13, QFont::Bold));
    searchButton = new QPushButton(tr("&Search"));
    searchButton->setFont(QFont("Cambria", 13, QFont::Bold));
    searchLine = new QLineEdit;

    // Button horizontal layout
    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    buttonLayout1->addWidget(addExpenseButton,1);
    buttonLayout1->addWidget(addIncomeButton,1);
    buttonLayout1->addWidget(reportButton,1);
    buttonLayout1->addWidget(shoppingListButton,1);


    QHBoxLayout *searcharea = new QHBoxLayout;
    searcharea->addWidget(searchLine,3);
    searcharea->addWidget(searchButton,1);

    QVBoxLayout *left = new QVBoxLayout;
    left->addLayout(buttonLayout1);
    left->addLayout(searcharea);
   //right area

    settingbudget=new QPushButton(tr("Monthly Budget"));
    settingbudget->setFont(QFont("Times", 15, QFont::Bold));

    budget=new QLCDNumber;
    budget->setSegmentStyle(QLCDNumber::Filled);
    //budget->display(budgetAmount);

    QPushButton *ratiobar=new QPushButton(tr("Expense Ratio"));
    ratiobar->setFont(QFont("Times", 15, QFont::Bold));
    ratio=new QProgressBar;


   QGridLayout *showarea=new QGridLayout;
   showarea->setSpacing(20);
   showarea->addWidget(settingbudget,0,0);
   showarea->addWidget(budget,0,1);
   showarea->addWidget(ratiobar,1,0);
   showarea->addWidget(ratio,1,1);

   QHBoxLayout *Layout2=new QHBoxLayout;
   Layout2->addLayout(left,3);
   Layout2->addLayout(showarea,2);

   QVBoxLayout *mainLayout=new QVBoxLayout;
   mainLayout->addLayout(Layout1,10);
   mainLayout->addLayout(Layout2,3);
   setLayout(mainLayout);
   setWindowTitle("Basic Model");

//! [grid layout]
    setLayout(mainLayout);
    setWindowTitle(tr("Basic Model"));
    
//****************construct items and labels************************//
    
//        QDir currentDir;
//        QString path = currentDir.currentPath();
//    QString filePathE = path + "/../../../expense_data.csv";
//    QString filePathI = path + "/../../../income_data.csv";
//    QString filePathEL = path + "/../../../expense_labels.txt";
//    QString filePathIL = path + "/../../../income_labels.txt";
    QString homePath = QString(getenv("HOME"));
    //std::cout<<homePath.toStdString().c_str()<<std::endl;

    QDir *temp = new QDir;
    bool exist = temp->exists(homePath + "/.ExpenseTracker_withData");
    if(exist == 0)   temp->mkdir(homePath + "/.ExpenseTracker_withData");

    QString filePathE = homePath + "/.ExpenseTracker_withData/expense_data.csv";
    QString filePathI = homePath + "/.ExpenseTracker_withData/income_data.csv";
    QString filePathEL = homePath + "/.ExpenseTracker_withData/expense_labels.txt";
    QString filePathIL = homePath + "/.ExpenseTracker_withData/income_labels.txt";
    QString filePathB = homePath + "/.ExpenseTracker_withData/budget.txt";
    QString filePathSL = homePath + "/.ExpenseTracker_withData/shoppingList.csv";



    std::ifstream fin(filePathE.toStdString().c_str());
    if(!fin){

        QString dataPath (":/data/resource");
        QString filePathEd = dataPath + "/expense_data.csv";
        QString filePathId = dataPath + "/income_data.csv";
        QString filePathELd = dataPath + "/expense_labels.txt";
        QString filePathILd = dataPath + "/income_labels.txt";
        QString filePathBd = dataPath + "/budget.txt";
        QString filePathSLd = dataPath + "/shoppingList.csv";


        expenseItems = readData(filePathEd);
        incomeItems = readData(filePathId);
        expenseLabels = readLabel(filePathELd);
        incomeLabels = readLabel(filePathILd);
        budgetAmount = readBudget(filePathBd);
        shoppingItems = readShoppingList(filePathSLd);
        writeData(expenseItems, filePathE.toStdString().c_str());
        writeData(incomeItems, filePathI.toStdString().c_str());
        writeLabel(expenseLabels, filePathEL.toStdString().c_str());
        writeLabel(incomeLabels, filePathIL.toStdString().c_str());
        writeBudget(budgetAmount, filePathB.toStdString().c_str());
        writeShoppingList(shoppingItems, filePathSL.toStdString().c_str());


    }
    else{
        expenseItems = readData(filePathE.toStdString().c_str());
        incomeItems = readData(filePathI.toStdString().c_str());
        expenseLabels = readLabel(filePathEL.toStdString().c_str());
        incomeLabels = readLabel(filePathIL.toStdString().c_str());
        budgetAmount = readBudget(filePathB.toStdString().c_str());
        std::ifstream finSL(filePathSL.toStdString().c_str());
        if(finSL){
            shoppingItems = readShoppingList(filePathSL.toStdString().c_str());
        }
        else{
            shoppingItems = NULL;
        }
    }
    budget->display(budgetAmount);
    selectedDateChanged();
    double ratioValue = report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount;
    if(ratioValue < 1){
       ratio->setValue(100*ratioValue);
    }
    else ratio->setValue(100);
    searchFlag = 0;
//******************connecting signals and slots***************************//
    connect(addExpenseButton, SIGNAL(clicked()), this, SLOT(addexpensewindow()));
    connect(addIncomeButton, SIGNAL(clicked()), this, SLOT(addincomewindow()));
    connect(reportButton, SIGNAL(clicked()), this, SLOT(report()));
    connect(calendar, SIGNAL(selectionChanged()), this, SLOT(selectedDateChanged()));
    connect(settingbudget, SIGNAL(clicked()), this, SLOT(settingBudget()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeItem()));
    connect(shoppingListButton, SIGNAL(clicked()), this, SLOT(checkShoppingList()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchItem()));
    connect(searchLine, SIGNAL(returnPressed()), this, SLOT(searchItem()));
}

double Tracker::report_sum_M(const int month,const int year, std::vector<item> * v){
    double ans = 0;
    for (unsigned i=0; i < v->size(); i++) {
      if((*v)[i].getDate().month == month && (*v)[i].getDate().year == year) {
        ans += (*v)[i].getAmount();
      }
    }
    return ans;
}

//Maindow destructor
Tracker::~Tracker()
{
//   QDir currentDir;
//   QString path = currentDir.currentPath();
//    QString filePathE = path + "/../../../expense_data.csv";
//    QString filePathI = path + "/../../../income_data.csv";
//    QString filePathEL = path + "/../../../expense_labels.txt";
//    QString filePathIL = path + "/../../../income_labels.txt";

//    QString filePathE = path + "/expense_data.csv";
//    QString filePathI = path + "/income_data.csv";
//    QString filePathEL = path + "/expense_labels.txt";
//    QString filePathIL = path + "/income_labels.txt";
//    QString filePathB = path + "/budget.txt";
//    QString filePathSL = path + "/shoppingList.csv";

    QString homePath = QString(getenv("HOME"));
    //std::cout<<homePath.toStdString().c_str()<<std::endl;
    QString filePathE = homePath + "/.ExpenseTracker_withData/expense_data.csv";
    QString filePathI = homePath + "/.ExpenseTracker_withData/income_data.csv";
    QString filePathEL = homePath + "/.ExpenseTracker_withData/expense_labels.txt";
    QString filePathIL = homePath + "/.ExpenseTracker_withData/income_labels.txt";
    QString filePathB = homePath + "/.ExpenseTracker_withData/budget.txt";
    QString filePathSL = homePath + "/.ExpenseTracker_withData/shoppingList.csv";

    writeData(expenseItems, filePathE.toStdString().c_str());
    writeData(incomeItems, filePathI.toStdString().c_str());
    writeLabel(expenseLabels, filePathEL.toStdString().c_str());
    writeLabel(incomeLabels, filePathIL.toStdString().c_str());
    writeBudget(budgetAmount, filePathB.toStdString().c_str());

    if(shoppingItems != NULL){
        writeShoppingList(shoppingItems, filePathSL.toStdString().c_str());
    }

    delete expenseItems;
    delete incomeItems;
    delete expenseLabels;
    delete incomeLabels;
    delete shoppingItems;
}

//Throw the dialog to input the expense information
void Tracker::addexpensewindow()
{ 
    addExpenseWindow = new addExpenseDialog(); // Be sure to destroy you window somewhere
    addExpenseWindow->setMaximumSize(300,250);
    addExpenseWindow->setMinimumSize(300,250);
    addExpenseWindow->setWindowTitle("Add Expense Item on This Day");
    //******Add labels******//
    for(unsigned i = 0; i < expenseLabels->size(); i++){
        addExpenseWindow->categoryBox->addItem(tr((*expenseLabels)[i].c_str()));
    }
    //addExpenseWindow->categoryBox->addItem(tr("Add new label..."));
    //***if save***//
    if(addExpenseWindow->exec() == QDialog::Accepted){
        //***check if new label***//
        unsigned i;
        for(i = 0; i < expenseLabels->size(); i++){
            if(addExpenseWindow->expenseLabel.toStdString() == (*expenseLabels)[i]){
                break;
            }
        }
        if(i == expenseLabels->size()){
            expenseLabels->push_back(addExpenseWindow->expenseLabel.toStdString());
        }
        //*************************//
        date testDate(calendar->selectedDate().year(),calendar->selectedDate().month(),calendar->selectedDate().day());
        item toAdd(addExpenseWindow->expensename.toStdString(), addExpenseWindow->expenseamount, testDate, addExpenseWindow->expenseLabel.toStdString());
        //std::cout<<toAdd.getName().c_str()<<" "<<toAdd.getAmount()<<" "<<toAdd.getLabel().c_str()<<" "<<toAdd.getDate().month<<"/"<<toAdd.getDate().day<<"/"<<toAdd.getDate().year<<std::endl;
        expenseItems->push_back(toAdd);
        //std::cout<<"clicked SAVE"<<std::endl;
        selectedDateChanged();
    }
    //***if not save***//
    else{
        //std::cout<<"clicked CANCLE"<<std::endl;
    }
    double ratioValue = report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount;
    if(ratioValue < 1){
       ratio->setValue(100*ratioValue);
    }
    else ratio->setValue(100);
}

//Throw the dialog to input the income information
void Tracker::addincomewindow()
{
    addIncomeWindow = new addIncomeDialog(); // Be sure to destroy you window somewhere
    addIncomeWindow->setMaximumSize(300,250);
    addIncomeWindow->setMinimumSize(300,250);
    addIncomeWindow->setWindowTitle("Add Income Item on This Day");
    //******Add labels******//
    for(unsigned i = 0; i < incomeLabels->size(); i++){
        addIncomeWindow->categoryBox->addItem(tr((*incomeLabels)[i].c_str()));
    }
    //addIncomeWindow->categoryBox->addItem(tr("Add new label..."));
    //***if save***//
    if(addIncomeWindow->exec() == QDialog::Accepted){
        //***check if new label***//
        unsigned i;
        for(i = 0; i < incomeLabels->size(); i++){
            if(addIncomeWindow->incomeLabel.toStdString() == (*incomeLabels)[i]){
                break;
            }
        }
        if(i == incomeLabels->size()){
            incomeLabels->push_back(addIncomeWindow->incomeLabel.toStdString());
        }
        //*************************//
        date testDate(calendar->selectedDate().year(),calendar->selectedDate().month(),calendar->selectedDate().day());
        item toAdd(addIncomeWindow->incomename.toStdString(), addIncomeWindow->incomeamount, testDate, addIncomeWindow->incomeLabel.toStdString());
        //std::cout<<toAdd.getName().c_str()<<" "<<toAdd.getAmount()<<" "<<toAdd.getLabel().c_str()<<" "<<toAdd.getDate().month<<"/"<<toAdd.getDate().day<<"/"<<toAdd.getDate().year<<std::endl;
        incomeItems->push_back(toAdd);
        //std::cout<<"clicked SAVE"<<std::endl;
        selectedDateChanged();
    }
    //***if not save***//
    else{
        //std::cout<<"clicked CANCLE"<<std::endl;
    }
}

QString Tracker::filingIn(QString tofiling, int charNum){
  QString tmp = tofiling;
  for(int i = 0; i < (charNum - tofiling.length()); i++){
    tmp = tmp + " ";
  }
  return tmp;
}

void Tracker::updateTable(std::vector<item> * itemsToAdd, const int selectITEMS){

  for(unsigned i = 0; i < itemsToAdd->size(); i++){
    if((*itemsToAdd)[i].getDate().month == calendar->selectedDate().month() &&
       (*itemsToAdd)[i].getDate().day == calendar->selectedDate().day() &&
       (*itemsToAdd)[i].getDate().year == calendar->selectedDate().year()){

      QString nameToAdd = filingIn(QString::fromStdString((*itemsToAdd)[i].getName()), 17);
      QString cateToAdd = filingIn(QString::fromStdString((*itemsToAdd)[i].getLabel()), 14);
      QString amountToAdd = QString::number((*itemsToAdd)[i].getAmount());
      QString _itemToAdd;
      if(selectITEMS == 0){
        _itemToAdd = nameToAdd + cateToAdd + "-" + amountToAdd;
      }
      else{
        _itemToAdd = nameToAdd + cateToAdd + "+" + amountToAdd;
      }
      QListWidgetItem * itemToAdd = new QListWidgetItem;
      itemToAdd->setText(_itemToAdd);
      itemToAdd->setFont(QFont("Monaco", 10, QFont::Bold));
      //std::cout<<itemToAdd->text().toStdString().c_str()<<std::endl;
      detailList->addItem(itemToAdd);
    }
  }

}

void Tracker::selectedDateChanged(){
    searchFlag = 0;
    detailList->clear();
      detailList->addItem("EXPENSE: ");
      updateTable(expenseItems, 0);
      detailList->addItem("INCOME: ");
      updateTable(incomeItems, 1);
}

void Tracker::report()
{

//    //std::cout<<"report here"<<std::endl;
    date currDate(calendar->selectedDate().year(), calendar->selectedDate().month(), calendar->selectedDate().day());
    reportWindow1 = new reportWindow(0, expenseItems, incomeItems,
                                     expenseLabels, incomeLabels, currDate);
    reportWindow1->setMaximumSize(850,650);
    reportWindow1->setMinimumSize(850,650);
    reportWindow1->setWindowTitle("Report Window");
    reportWindow1->exec();
}

void Tracker::settingBudget()
{
        addBudgetWindow = new budgetWindow();
        addBudgetWindow->setMaximumSize(300,100);
        addBudgetWindow->setMinimumSize(300,100);
        addBudgetWindow->setWindowTitle("Set New Budget of this month");

        if(addBudgetWindow->exec() == QDialog::Accepted){

            budgetAmount = addBudgetWindow->newBudget;
            budget->display(budgetAmount);
            //std::cout<<report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount<<"***"<<std::endl;
            double ratioValue = report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount;
            if(ratioValue < 1){
               ratio->setValue(100*ratioValue);
            }
            else ratio->setValue(100);
        }
        else{
            //std::cout<<"clicked CANCLE"<<std::endl;
        }
}


void Tracker::searchToRemove(std::vector<item> * itemsToRemove, std::string Rname, std::string Rlabel, double RVamount){

    for(unsigned i = 0; i < itemsToRemove->size(); i++){
        if((*itemsToRemove)[i].getDate().month == calendar->selectedDate().month() &&
           (*itemsToRemove)[i].getDate().day == calendar->selectedDate().day() &&
           (*itemsToRemove)[i].getDate().year == calendar->selectedDate().year()){

            std::string nameFromItem = filingIn(QString::fromStdString((*itemsToRemove)[i].getName()), 17).toStdString();
            std::string labelFromItem = filingIn(QString::fromStdString((*itemsToRemove)[i].getLabel()), 14).toStdString();

            if(nameFromItem.compare(Rname) == 0 && labelFromItem.compare(Rlabel) == 0 && RVamount == (*itemsToRemove)[i].getAmount()){

                (*itemsToRemove)[i].erase();
                return;
            }
        }

    }

}

void Tracker::removeItem()
{
    if(detailList->currentItem() == NULL) return;
    QString toRemove = detailList->currentItem()->text();
    if(searchFlag == 0){
        if(toRemove.toStdString().compare("EXPENSE: ") != 0 && toRemove.toStdString().compare("INCOME: ") != 0){
            std::string Rname(toRemove.toStdString(), 0 ,17);
            std::string Rlabel(toRemove.toStdString(), 17, 14);
            std::string sign(toRemove.toStdString(),31 ,1);
            std::string Ramount(toRemove.toStdString(), 32, 15);
            double RVamount = atof(Ramount.c_str());
//    std::cout<<toRemove.toStdString().c_str()<<"\n";
//    std::cout<<Rname<<"  |"<<RLabel<<"  |"<<Ramount<<"  |"<<RVamount<<std::endl;
            if(sign == "-") searchToRemove(expenseItems, Rname, Rlabel, RVamount);
            else searchToRemove(incomeItems, Rname, Rlabel, RVamount);
            selectedDateChanged();
        }
    }
    else detailList->addItem("Remove in search is not allowed!");
    double ratioValue = report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount;
    if(ratioValue < 1){
       ratio->setValue(100*ratioValue);
    }
    else ratio->setValue(100);
}

void Tracker::checkShoppingList()
{
    shoplist = new shoppinglist(0, shoppingItems, budgetAmount);
    shoplist->setMaximumSize(300,600);
    shoplist->setMinimumSize(300,600);
    shoplist->setWindowTitle("Shopping List");
    shoplist->exec();
    budget->display(budgetAmount);
    shoppingItems = shoplist->shoppingItems;
    double ratioValue = report_sum_M(QDate::currentDate().month(),QDate::currentDate().year(),expenseItems)/budgetAmount;
    if(ratioValue < 1){
       ratio->setValue(100*ratioValue);
    }
    else ratio->setValue(100);}

//Searching for the transaction items

bool Tracker::searchFromItems(std::vector<item> * itemsToSearch, const int selectITEMS){
    bool found = 0;
    for(unsigned i = 0; i < itemsToSearch->size(); i++){
        if(searchLine->text().toStdString().compare((*itemsToSearch)[i].getName()) == 0){
            QString nameToAdd = filingIn(QString::fromStdString((*itemsToSearch)[i].getName()), 17);
            QString cateToAdd = filingIn(QString::fromStdString((*itemsToSearch)[i].getLabel()), 14);
            QString amountToAdd = QString::number((*itemsToSearch)[i].getAmount());
            QString _itemToAdd;

        if(selectITEMS == 0){
           _itemToAdd = nameToAdd + cateToAdd + "-" + amountToAdd;
        }
        else{
            _itemToAdd = nameToAdd + cateToAdd + "+" + amountToAdd;
        }
        QListWidgetItem * itemToAdd = new QListWidgetItem;
        itemToAdd->setText(_itemToAdd);
        itemToAdd->setFont(QFont("Monaco", 10, QFont::Bold));
        //std::cout<<itemToAdd->text().toStdString().c_str()<<std::endl;
        detailList->addItem(itemToAdd);

        QString _dateToAdd;
        _dateToAdd = QString::number((*itemsToSearch)[i].getDate().month) + "/" + QString::number((*itemsToSearch)[i].getDate().day) + "/" +QString::number((*itemsToSearch)[i].getDate().year);
        QListWidgetItem * dateToAdd = new QListWidgetItem;
        dateToAdd->setText(_dateToAdd);
        dateToAdd->setFont(QFont("Monaco", 10, QFont::Bold));
        //std::cout<<dateToAdd->text().toStdString().c_str()<<std::endl;
        detailList->addItem(dateToAdd);

        found = 1;
    }
 }
    return found;

}

void Tracker::searchItem()
{
    searchFlag = 1;
    if(searchLine->text().isEmpty()){
        detailList->clear();
        detailList->addItem("Please enter what you want to search");
    }
    else{
        //std::cout<<searchLine->text().toStdString().c_str()<<std::endl;
        detailList->clear();
        detailList->addItem("SEARCH RESULTS: ");
        detailList->addItem("EXPENSE: ");
        bool expenseFound = 0;
        bool incomeFound = 0;
        if((expenseFound = searchFromItems(expenseItems, 0)) == 0){
            detailList->addItem("         NO MATCH");
        }
        detailList->addItem("INCOME: ");
        if((incomeFound = searchFromItems(incomeItems, 1)) == 0){
            detailList->addItem("         NO MATCH");
        }

        if(expenseFound == 0 && incomeFound == 0){
            detailList->clear();
            detailList->addItem("No match items");
        }
    }


}

