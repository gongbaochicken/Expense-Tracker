#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QCheckBox;
QT_END_NAMESPACE

class shoppingItem: public QDialog
{
    Q_OBJECT
public:
    explicit shoppingItem();
    ~shoppingItem();
    QString itemName;
    double itemAmount;
    double addToBudget;
public slots:
    void save();
    void cancel();
private:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLabel *shoppingName;
    QLineEdit *nameLine;
    QLabel *expectMoney;
    QLineEdit *moneyLine;
    QCheckBox *checkBoxxx;

};

#endif // SHOPPINGITEM_H
