#include "reportwindow.h"
#include "report.h"
#include "mainwindow.h"
#include <QComboBox>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <iostream>
#include <QWidget>
#include <QRectF>
#include <QBrush>
#include <QTextCodec>
#include <vector>


reportWindow::reportWindow(QWidget *parent, std::vector<item> *_expenseItems, std::vector<item>* _incomeItems,
                           std::vector<std::string>* _expenseLabels, std::vector<std::string>* _incomeLabels,
                           date _currDate) :
    QDialog(parent)
{
     expenseItems = _expenseItems;
     incomeItems = _incomeItems;
     expenseLabels = _expenseLabels;
     incomeLabels = _incomeLabels;
     currDate.day = _currDate.day;
     currDate.month = _currDate.month;
     currDate.year = _currDate.year;
//***************************Line Test Parameter****************************
//     std::pair<std::string, double> pair01("Jan.", 20);
//     std::pair<std::string, double> pair02("Feb.", 12);
//     std::pair<std::string, double> pair03("Mar.", 35);
//     std::pair<std::string, double> pair04("Apr.", 6);
//     std::pair<std::string, double> pair05("May.", 17);
//     std::pair<std::string, double> pair06("Jun.", 34);
//     std::pair<std::string, double> pair07("July.", 19);
//     std::vector<std::pair<std::string, double> > test0;
//     test0.push_back(pair01);
//     test0.push_back(pair02);
//     test0.push_back(pair03);
//     test0.push_back(pair04);
//     test0.push_back(pair05);
//     test0.push_back(pair06);
//     test0.push_back(pair07);
//    data = test0;

//***************************Pie Test Parameter****************************
//    std::pair<std::string, double> pair1("Jan.", 20);
//    std::pair<std::string, double> pair2("Feb.", 20);
//    std::pair<std::string, double> pair3("Mar.", 20);
//    std::pair<std::string, double> pair4("Apr.", 20);
//    std::pair<std::string, double> pair5("May.", 20);
//    std::pair<std::string, double> pair6("Jan.", 20);
//    std::pair<std::string, double> pair7("Feb.", 20);
//    std::pair<std::string, double> pair8("Mar.", 20);
//    std::pair<std::string, double> pair9("Apr.", 20);
//    std::pair<std::string, double> pair10("May.", 20);
//    std::pair<std::string, double> pair11("Jan.", 20);
//    std::pair<std::string, double> pair12("Feb.", 20);
//    std::pair<std::string, double> pair13("Mar.", 20);
//    std::pair<std::string, double> pair14("Apr.", 20);
//    std::pair<std::string, double> pair15("May.", 20);
//    std::vector<std::pair<std::string, double> > test;
//    test.push_back(pair1);
//    test.push_back(pair2);
//    test.push_back(pair3);
//    test.push_back(pair4);
//    test.push_back(pair5);
//    test.push_back(pair6);
//    test.push_back(pair7);
//    test.push_back(pair8);
//    test.push_back(pair9);
//    test.push_back(pair10);
//    test.push_back(pair11);
//    test.push_back(pair12);
//    test.push_back(pair13);
//    test.push_back(pair14);
//    test.push_back(pair15);
//    data2 = test;
    std::vector<std::string> _colorcode;
    _colorcode.push_back("#0000ff");//Blue
    _colorcode.push_back("#1e90ff");//DodgerBlue
    _colorcode.push_back("#00bfff");//DeepSkyblue
    _colorcode.push_back("#00ffff");//Cyan
    _colorcode.push_back("#008080");//Teal
    _colorcode.push_back("#006400");//darkGreen
    _colorcode.push_back("#00ff7f");//SpringGreen
    _colorcode.push_back("#daa520");//Goldenrod
    _colorcode.push_back("#bc8f8f");//RosyBrown
    _colorcode.push_back("#8a2be2");//BlueViolet
    _colorcode.push_back("#ff00ff");//Magenta
    _colorcode.push_back("#ee82ee");//Violet
    _colorcode.push_back("#e6e6fa");//Lavender
    _colorcode.push_back("#ff0000");//Red
    _colorcode.push_back("#fa8072");//Salmon
    _colorcode.push_back("#ff1493");//DeepPink
    _colorcode.push_back("#ff69b4");//Hotpink
    _colorcode.push_back("#ffb6c1");//LightPink
    _colorcode.push_back("#ff4500");//OrangeRed
    _colorcode.push_back("#ffa500");//Orange
    _colorcode.push_back("#ffff00");//Yellow
    _colorcode.push_back("#ffd700");//Gold
    _colorcode.push_back("#ffdab9");//PeachPuff
    _colorcode.push_back("#f0f8ff");//AliceBlue
    colorcode = _colorcode;


    QString newpath (":/image/images/3.jpg");
    QPixmap pixmap = QPixmap(newpath).scaled(850,650);
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);


//***************************Group 1****************************
    groupBox1 = new QGroupBox(tr("Please choose report range:"));
    groupBox1->setCheckable(true);
    groupBox1->setChecked(true);

    chooseweek = new QRadioButton(tr("&Past 7 days"));
    choosemonth = new QRadioButton(tr("&Past 30 days"));
    chooseyear = new QRadioButton(tr("&Whole year"));
    chooseweek->setChecked(true);

    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(chooseweek);
    vbox1->addWidget(choosemonth);
    vbox1->addWidget(chooseyear);
    groupBox1->setLayout(vbox1);

//***************************Group 2****************************
    groupBox2 = new QGroupBox(tr("Define youself"));
    groupBox2->setCheckable(true);
    groupBox2->setChecked(false);

//    QLabel *line1=new QLabel("From");
//    QLabel *line2=new QLabel("To");
//    QLineEdit *Startdate=new QLineEdit;
//    QLineEdit *Enddate=new QLineEdit;

    YearBox=new QComboBox;
    for(unsigned year = QDate::currentDate().year(); year >= 2000; year--){
        YearBox->addItem(tr((QString::number(year)).toStdString().c_str()));
    }


    MonthBox=new QComboBox;
    MonthBox->addItem(tr("Jan"));
    MonthBox->addItem(tr("Feb"));
    MonthBox->addItem(tr("Mar"));
    MonthBox->addItem(tr("Apr"));
    MonthBox->addItem(tr("May"));
    MonthBox->addItem(tr("Jun"));
    MonthBox->addItem(tr("Jul"));
    MonthBox->addItem(tr("Aug"));
    MonthBox->addItem(tr("Sep"));
    MonthBox->addItem(tr("Oct"));
    MonthBox->addItem(tr("Nov"));
    MonthBox->addItem(tr("Dec"));
    MonthBox->addItem(tr("All-year"));

    QVBoxLayout *vbox2 = new QVBoxLayout;
    vbox2->addWidget(YearBox);
    vbox2->addWidget(MonthBox);
    groupBox2->setLayout(vbox2);

//    QPushButton *reportButton=new QPushButton("Report Now");
    QPushButton *QRcodeButton=new QPushButton("QR code report");

    QVBoxLayout *h2=new QVBoxLayout;
    h2->addWidget(groupBox1);
    h2->addWidget(groupBox2);
//    h2->addWidget(reportButton);
    h2->addWidget(QRcodeButton);

    QVBoxLayout *h3=new QVBoxLayout;
    Q1=new QLabel;
    Q2=new QLabel;
    h3->addWidget(Q1);
    h3->addWidget(Q2);

    QHBoxLayout *whole = new QHBoxLayout;
    whole->addLayout(h2,1);
    whole->addLayout(h3,3);
    setLayout(whole);
    reportweek();
    this->repaint();
//*****************************Connect********************************************//
    connect(chooseweek, SIGNAL(toggled(bool)),this, SLOT(reportweek()));
    connect(choosemonth, SIGNAL(toggled(bool)),this, SLOT(reportmonth()));
    connect(chooseyear, SIGNAL(toggled(bool)), this, SLOT(reportyear()));
    connect(YearBox, SIGNAL(activated(int)),this, SLOT(YearChanged(int)));
    connect(MonthBox, SIGNAL(activated(int)),this, SLOT(MonthChanged(int)));
//    connect(reportButton, SIGNAL(clicked()), this, SLOT(reportNow()));
    connect(QRcodeButton, SIGNAL(clicked()), this, SLOT(QRgenerate()));
    connect(groupBox1,SIGNAL(clicked(bool)), this, SLOT(checkgroup1()));
    connect(groupBox2,SIGNAL(clicked(bool)), this, SLOT(checkgroup2()));
}

reportWindow::~reportWindow()
{

}

void reportWindow::paintEvent(QPaintEvent *)
{
//****************Let's draw line chart.*********************************//
    int xsize = getXmax(data);
    double ymax = getYmax(data) + 20;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    //============paint the frame===============
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawRect(300, 40, 500, 260);
    QBrush brush(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(300,40,500,260));


    QPen pen2;
    pen2.setWidth(0);
    pen2.setBrush(QColor("#0e5a77"));
    painter.setPen(pen2);
//  painter.drawText( rect(), Qt::AlignTop, title );
    //============paint the curve=========
    QPen pen3;
    pen3.setWidth(2);
    pen3.setBrush(QColor("#00e0fc"));
    QPen pend;
    pend.setWidth(0);
    pend.setBrush(Qt::black);
    painter.setPen(Qt::DotLine);
   //get the value
    double xstep = 500/xsize;

    double ymin = 0;


    for(int i = 1; i < xsize; i++){
        if(data[i].second < ymin) ymin = data[i].second;
    }
    double yrange = ymax - ymin;
    double ratio = yrange/260;

    //===================draw the plot========================

    std::vector<double> xplot;
    std::vector<double> yplot;
    for(int j = 0; j < xsize -1; j++) {
        xplot.push_back(800 - xstep * (j + 1));
        //std::cout<<j<<"***"<<"***"<<420 - xstep * (j + 1) <<std::endl;
        yplot.push_back(300 - data[xsize - 2 - j].second/ratio);
        //std::cout<<j<<"***"<<data[xsize - 2 - j].second<<"***"<<320 - data[xsize-1-j].second/ratio<<std::endl;
    }
    //xplot.push_back(20);
   // yplot.push_back(320);
    for(int k = 0 ; k < xsize -1; k++){
        if(k<xsize-2){
            painter.setPen(pen3);
            painter.drawLine(xplot[k], yplot[k], xplot[k+1], yplot[k+1]);
        }
        painter.setPen(pend);

        painter.setFont(QFont("Times", 10));
        if(data.size() == 7){

            painter.drawText(QPoint(xplot[k]-15, 313), QString::fromStdString(data[xsize - 2 - k].first));
        }
        else if(data.size() == 12){
            painter.drawText(QPoint(xplot[k]- 4, 313), QString::fromStdString(data[xsize - 2 - k].first));
        }
        else{
            if(k % 5 == 4){
                painter.drawText(QPoint(xplot[k]-15, 313), QString::fromStdString(data[xsize -2 -k].first));
            }
//            for(unsigned k1 = 0;(k+k1+1) < data.size(); k1 += 5){
//                painter.drawText(QPoint(xplot[k+k1]-15, 293), QString::fromStdString(data[xsize -2 -k -k1].first));
//            }
        }

        //painter.drawText(QPoint(0,yplot[k]), QString::number(data[k].second));
    }
    int n = 0;
    if(ymax == 0) n = ymax;
    else if(ymax >= 0 && ymax <=100) n = 10;
    else if(ymax > 100 && ymax <= 250) n = 25;
    else if(ymax > 250 && ymax <= 500) n = 50;
    else if(ymax > 500 && ymax <= 1000) n = 100;
    else if(ymax > 1000 && ymax <= 2000) n = 200;
    else if(ymax > 2000 && ymax <= 5000) n = 500;
    else if(ymax > 5000 && ymax <= 10000) n = 1000;
    else if(ymax > 10000 && ymax <= 100000) n = 10000;
    else n = 20000;

    for(int m = n;m <= ymax; m += n){
        painter.setPen(pend);
        painter.drawText(QPoint(275,305 - m/ratio), QString::number(m));

//        painter.setPen(pend);

        painter.drawLine(QPoint(300, 300-m/ratio), QPoint(800, 300-m/ratio));
     }
    painter.drawText(QPoint(280, 300), "0");
    painter.drawText(QPoint(270, 35), "Amount($)");
    painter.drawText(QPoint(790, 310),"Date");
    if(data.size() == 12){
        painter.drawText(QPoint(783, 320),"(Month)");
        //painter.drawText(QPoint(775, 313),"Date(Month)");
    }
    else{
        //painter.drawText(QPoint(790, 310),"Date");
        painter.drawText(QPoint(770, 320),"(MM/DD/YYYY)");
    }

//****************Let's draw pie chart.*********************************//
    //int sz = getNum(data2);
    double total = getTotal(data2);
    QPainter painter2(this);
//===================draw the frame of width 2===============//
    QPen penpiel;
    penpiel.setStyle(Qt::SolidLine);
    penpiel.setWidth(2);
    penpiel.setBrush(Qt::black);
    painter2.setPen(penpiel);
    painter2.drawRect(300, 330, 500, 260);

    painter2.setRenderHint(QPainter::Antialiasing, true);
    QBrush brush1(Qt::SolidPattern);
    painter2.setBrush(brush1);
    painter2.setBrush(QColor("#ffffff"));
    painter2.drawRect(QRect(300,330,500,260));

    QRectF size = QRectF(325, 355, 200, 200);

    double firstEdge = 0;
    double secondEdge = 0;
    if(total == 0){
        painter.drawPie(size,0, 360 * 16);
    }
    else{
        //=================set another piepen of width 1==============//
            QPen piepen;
            piepen.setStyle(Qt::SolidLine);
            piepen.setWidth(1);
            piepen.setBrush(Qt::black);
            piepen.setCapStyle(Qt::RoundCap);
            painter2.setPen(piepen);
            painter2.setRenderHint(QPainter::Antialiasing, true);
            QBrush brush2(Qt::SolidPattern);

            painter2.setBrush(brush2);

//            for(unsigned i = 0; i < data2.size(); i++){
//             if(data2[i].second == 0){
//                 data2.erase(data2.begin()+i);
//             }
//            }
      std::vector<std::pair<std::string, double> > datapie;
   for(unsigned i = 0; i < data2.size(); i++){
    if(data2[i].second != 0){
    datapie.push_back(data2[i]);
    }
   }

    //std::cout<<" inside paintevent "<<std::endl;
    for(unsigned i = 0; i < datapie.size(); i++){
        firstEdge = firstEdge + secondEdge;
        secondEdge = datapie[i].second/total * 360*16 ;
        //std::cout<<" inside paintevent "<<<<std::endl;
        //std::cout<<firstEdge<<"  "<<secondEdge<<std::endl;
        //second = (data[i].second/total+ (data[i].second)%total)*360*16;
        painter2.setBrush(brush1);
        painter2.setBrush(QColor(QString::fromStdString(colorcode[i])));
        painter2.drawPie(size,firstEdge,secondEdge);
   }



    for(unsigned i = 0; i < datapie.size(); i++){

     painter2.setBrush(brush2);
     painter2.setBrush(QColor(QString::fromStdString(colorcode[i])));


    painter2.setPen(piepen);
    painter2.setFont(QFont("Times", 11));

      if(i<10){
        painter2.drawText(QPoint(583, 395 + i * 15), QString::fromStdString(datapie[i].first));
        painter2.drawRect(QRect(553, 390 + i * 15, 15, 5));

      }
      else{
        painter2.drawText(QPoint(710, 395 + (i-10) * 15), QString::fromStdString(datapie[i].first));
        painter2.drawRect(QRect(680, 390 + (i-10) * 15, 15, 5));

    }
    }
    painter2.setFont(QFont("Lobster", 14));
    painter2.drawText(QPoint(573, 570),"Total Amount($):");
    painter2.drawText(QPoint(700,570),QString::number(total));
}
}

//*************************LINE Chart Out-functions*************************
int reportWindow::getXmax(std::vector<std::pair<std::string, double> > data){
   return data.size()+1;
}

double reportWindow::getYmax(std::vector<std::pair<std::string, double> > data){
    double ymax = 0;
//    for(std::vector<std::pair<std::string, int> >::iterator it = data.begin();
//        it != data.end(); ++it){
//        if((*data).second > ymax)
//        ymax = (*data).second;

//    }
    for(unsigned i = 0; i< data.size(); i++){
        if(data[i].second > ymax)
            ymax = data[i].second;
    }
    //std::cout<<ymax<<std::endl;
    return ymax;
}

//*************************PIE Chart Out-functions*************************
int reportWindow::getNum(std::vector<std::pair<std::string, double> > data2)
{
    return data2.size();
}

double reportWindow::getTotal(std::vector<std::pair<std::string, double> > data2)
{
    double total = 0;
    for(unsigned i = 0; i< data2.size(); i++){
        total += data2[i].second;
    }
    return total;
}

//*****************Switch group 1 or 2*************************
void reportWindow::checkgroup1()
{
    groupBox2->setChecked(false);
    if(chooseweek->isChecked()){
        reportweek();
    }
    else if(choosemonth->isChecked()){
        reportmonth();
    }
    else reportyear();
    this->update();

}

void reportWindow::checkgroup2()
{
    groupBox1->setChecked(false);
    YearChanged(1);
    this->update();

}

//**********************************************************
void reportWindow::reportweek()
{
    //std::cout<<"reportweek"<<std::endl;
    data = report_sum_Din7(currDate, expenseItems);
    data2 = report_sum_Label_Din7(currDate, expenseItems, expenseLabels);
    this->update();

}

void reportWindow::reportmonth()
{
    //std::cout<<"reportmonth"<<std::endl;
    data = report_sum_Din30(currDate, expenseItems);
    data2 = report_sum_Label_Din30(currDate, expenseItems, expenseLabels);
    this->update();

}

void reportWindow::reportyear()
{
    //std::cout<<"reportyear"<<std::endl;
    data = report_sum_MinY(currDate.year, expenseItems);
    data2 = report_SLY(expenseItems, expenseLabels, currDate.year);
    this->update();

}

void reportWindow::YearChanged(int)
{
    //std::cout<<"yearChanged"<<std::endl;
    MonthChanged(MonthBox->currentIndex());

}

void reportWindow::MonthChanged(int)
{
    //std::cout<<"MonthChanged"<<std::endl;
    //std::cout<<index<<std::endl;
    if(MonthBox->currentIndex() == 12){
         //std::cout<<"all-year"<<std::endl;
        data = report_sum_MinY(YearBox->currentText().toInt(), expenseItems);
        //std::cout<<YearBox->currentText().toInt()<<std::endl;
        data2 = report_SLY(expenseItems, expenseLabels, YearBox->currentText().toInt());
    }
    else{
        //std::cout<<YearBox->currentText().toInt()<<std::endl;
        //std::cout<<MonthBox->currentIndex()+1<<std::endl;
        data = report_sum_DinM(MonthBox->currentIndex()+1, YearBox->currentText().toInt(), expenseItems);
        data2 = report_SLM(expenseItems, expenseLabels, YearBox->currentText().toInt(), MonthBox->currentIndex() + 1);
        YearBox->currentIndex();
    }
    this->update();

}

void reportWindow::QRgenerate()
{
    double sum = 0;
    for(unsigned i = 0; i < data.size(); i++){
        sum += data[i].second;
    }
    QString toEncode("Sum in this period:   " + QString::number(sum) + "\n");

    for(unsigned i = 0; i < data2.size(); i++){
        toEncode += (QString::fromStdString(data2[i].first) + ":   " + QString::number(data2[i].second) + "\n");
    }
    w=new Widget(0, toEncode);
    w->setMinimumSize(550, 500);
    w->setMaximumSize(750, 700);
    w->setWindowTitle("QR code report (Adjust size as needed)");
    //w->encode_string = "November 2014: $2070.";
    w->exec();
}




