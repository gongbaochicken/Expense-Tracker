#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <QPushButton>
#include <QListWidget>
#include "shoppingitem.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QPainter;
class QListWidget;
QT_END_NAMESPACE

class shoppinglist: public QDialog
{
    Q_OBJECT
public:
    explicit shoppinglist(QWidget *parent, std::vector<std::pair<std::string, double> > * _shoppingItems, double &_budget);
    ~shoppinglist();
    std::vector<std::pair<std::string, double> > * shoppingItems;
public slots:
    void addShoppingItem();
    void removeShoppingItem();

private:
    QPushButton *addButton;
    QPushButton *removeButton;
    QLineEdit *nameLine;
    QLineEdit *moneyLine;
    QListWidget *List;
    shoppingItem *shoppingitemwindow;
    //std::vector<std::pair<std::string, double> > * shoppingItems;
    void updateList();
    QString filingIn(QString tofiling, int charNum);
    double & budget;
    //std::vector<std::pair<std::string, double> > ** shoppingItems_tmp;
};

#endif // SHOPPINGLIST_H
