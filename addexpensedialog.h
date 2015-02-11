#ifndef ADDEXPENSEDIALOG_H
#define ADDEXPENSEDIALOG_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDate>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QComboBox;
class QGroupBox;
QT_END_NAMESPACE

class addExpenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addExpenseDialog(QWidget *parent = 0);
    ~addExpenseDialog();
    double expenseamount;
    QString expensename;
    QString expenseLabel;
    QComboBox *categoryBox;

public slots:
    void categoryChanged(int);
    void save();
    void cancel();
    void addnew();
private:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLineEdit *nameLine;
    QLineEdit *moneyLine;
    bool newLabel;
    QLabel *itemCategory;
    QGroupBox *newBox1;
    QLineEdit *newCategoryLine;
};

#endif // ADDEXPENSEDIALOG_H
