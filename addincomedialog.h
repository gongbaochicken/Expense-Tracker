#ifndef ADDINCOMEDIALOG_H
#define ADDINCOMEDIALOG_H

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

class addIncomeDialog: public QDialog
{
    Q_OBJECT
public:
    explicit addIncomeDialog(QWidget *parent = 0);
    ~addIncomeDialog(); 
    double incomeamount;
    QString incomeLabel;
    QString incomename;
    QComboBox *categoryBox;

public slots:
    void categoryChanged(int);
    void save();
    void cancel();
    void newincomecategroy();

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

#endif // ADDINCOMEDIALOG_H

