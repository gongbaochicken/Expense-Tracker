#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QVector>
#include <QDate>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPainter>
#include <QGroupBox>
#include <string>
#include <QRadioButton>
#include "basicModel.h"
#include "qrwidget.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QComboBox;
class QPainter;
class QGroupBox;
class QRadioButton;
QT_END_NAMESPACE

class reportWindow: public QDialog
{
    Q_OBJECT
public:
    explicit reportWindow(QWidget *parent, std::vector<item> *_expenseItems, std::vector<item> *_incomeItems,
                          std::vector<std::string> *_expenseLabels, std::vector<std::string> *_incomeLabels,
                          date _currDate);
    ~reportWindow();
    QComboBox *YearBox;
    QComboBox *MonthBox;

public slots:
    void reportweek();
    void reportmonth();
    void reportyear();
    void YearChanged(int);
    void MonthChanged(int);
    //void reportNow();
    void QRgenerate();
    void checkgroup1();
    void checkgroup2();
//************Line Chart************
    void paintEvent(QPaintEvent *);
    int getXmax(std::vector<std::pair<std::string, double> > data);
    double getYmax(std::vector<std::pair<std::string, double> > data);
//************Pie Chart************
    int getNum(std::vector<std::pair<std::string, double> > data2);
    double getTotal(std::vector<std::pair<std::string, double> > data2);
//**************repaint*************
    //void toRepaint();
private:
//    QPushButton *reportButton;
    QPushButton *QRcodeButton;
    QPainter *lineChart;
    QPainter *pieChart;
    bool newLabel;
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QLabel *Q1;
    QLabel *Q2;

    QRadioButton *chooseweek;
    QRadioButton *choosemonth;
    QRadioButton *chooseyear;

    std::vector<item> *expenseItems;
    std::vector<item> *incomeItems;
    std::vector<std::string>* expenseLabels;
    std::vector<std::string>* incomeLabels;
    date currDate;
    std::vector<std::pair<std::string, double> > dataForLine;
    std::vector<std::pair<std::string, double> > dataForPi;
//************Line Chart***********************
    int size;
    std::vector<std::pair<std::string, double> > data;
    std::string x;
    double y;
//************Pie Chart**********************
    std::vector<std::pair<std::string, double> > data2;
    std::vector<std::string> colorcode;

//************QR code**********************
    Widget *w;
};

#endif // REPORTWINDOW_H
