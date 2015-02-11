#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QVector>
#include <QDate>
#include <QLabel>
#include <QCalendarWidget>
#include <QListWidget>
#include <QStatusBar>
#include <QLCDNumber>
#include <iostream>
#include <string>
#include <QProgressBar>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "addexpensedialog.h"
#include "addincomedialog.h"
#include "basicModel.h"
#include "budgetwindow.h"
#include "linechart.h"
#include "reportwindow.h"
#include "shoppinglist.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QCalendarWidget;
class QStatusBar;
class QProgressBar;
class QLCDNumber;
QT_END_NAMESPACE

class Tracker: public QWidget
 {
     Q_OBJECT

 public:
     Tracker(QWidget *parent = 0);
     ~Tracker();
 private slots:
    void addexpensewindow();
    void addincomewindow();
    void selectedDateChanged();
    void report();
   //void remove();
    void settingBudget();
    void removeItem();
    void checkShoppingList();
    void searchItem();
 private:
    void updateTable(std::vector<item> * itemsToAdd, const int selectITEMS);
    QString filingIn(QString tofiling, int charNum);
    void searchToRemove(std::vector<item> * itemsToRemove, std::string Rname, std::string Rlabel, double RVamount);
    bool searchFromItems(std::vector<item> * itemsToSearch, const int selectITEMS);
    double report_sum_M(const int month,const int year, std::vector<item> * v);
    //! [pushbutton declaration]
     QPushButton *addExpenseButton;
     QPushButton *addIncomeButton;
     QPushButton *removeButton;
     QPushButton *reportButton;
     QPushButton *searchButton;
     QPushButton *settingbudget;
     QPushButton *shoppingListButton;
     QLineEdit *searchLine;
     QLineEdit *money;
     QLCDNumber *cost;
     QLCDNumber *budget;
     QProgressBar *ratio;

     QCalendarWidget *calendar;

     QListWidget *detailList;

     shoppinglist *shoplist;
     addIncomeDialog *addIncomeWindow;
     addExpenseDialog *addExpenseWindow;
     budgetWindow *addBudgetWindow;
//   Linechart * reportWindow;
     reportWindow *reportWindow1;
     double budgetAmount;
private:
     bool searchFlag;
     QString itemName;
     QString Category;
     double moneyAccount;
     std::vector<item> * expenseItems;
     std::vector<item> * incomeItems;
     std::vector<std::string> * expenseLabels;
     std::vector<std::string> * incomeLabels;
     std::vector<std::pair<std::string, double> > * shoppingItems;
};
#endif // MAINWINDOW_H
