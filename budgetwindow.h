#ifndef BUDGETWINDOW_H
#define BUDGETWINDOW_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDate>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE


class budgetWindow:public QDialog
{
    Q_OBJECT
public:
    explicit budgetWindow(QWidget *parent = 0);
    double newBudget;
    ~budgetWindow();

public slots:
    void saveBudget();
    void cancelBudget();

private:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLineEdit *budgetInputLine;

};

#endif // BUDGETWINDOW_H
