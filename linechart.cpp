#include "linechart.h"
#include <QWidget>
#include <iostream>

Linechart::Linechart(QWidget *parent):
    QDialog(parent)
{
    std::pair<std::string, double> pair1("Jan.", 20);
    std::pair<std::string, double> pair2("Feb.", 12);
    std::pair<std::string, double> pair3("Mar.", 35);
    std::pair<std::string, double> pair4("Apr.", 6);
    std::pair<std::string, double> pair5("May.", 17);
    std::vector<std::pair<std::string, double> > test;
    test.push_back(pair1);
    test.push_back(pair2);
    test.push_back(pair3);
    test.push_back(pair4);
    test.push_back(pair5);
    data = test;
}
Linechart::Linechart(QWidget *parent, std::vector<std::pair<std::string, double> > _data):
    QDialog(parent)
{
    data = _data;

}

Linechart::~Linechart()
{

}

void Linechart::paintEvent(QPaintEvent *)
{
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
    painter.drawRect(20, 20, 400, 300);
    QBrush brush(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(20,20,400,300));


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
    double xstep = 400/xsize;

    double ymin = 0;


    for(int i = 1; i < xsize; i++){
        if(data[i].second < ymin) ymin = data[i].second;
    }
    double yrange = ymax - ymin;
    double ratio = yrange/300;

    //===================draw the plot========================

    std::vector<double> xplot;
    std::vector<double> yplot;
    for(int j = 0; j < xsize -1; j++) {
        xplot.push_back(420 - xstep * (j + 1));
        //std::cout<<j<<"***"<<"***"<<420 - xstep * (j + 1) <<std::endl;
        yplot.push_back(320 - data[xsize - 2 - j].second/ratio);
        //std::cout<<j<<"***"<<data[xsize - 2 - j].second<<"***"<<320 - data[xsize-1-j].second/ratio<<std::endl;
    }
    //xplot.push_back(20);
   // yplot.push_back(320);
    for(int k = 0 ; k < xsize -1; k++){
        if(k<xsize-2){
            painter.setPen(pen3);
            painter.drawLine(xplot[k], yplot[k], xplot[k+1], yplot[k+1]);
        }
        painter.setPen(pen2);

        painter.setFont(QFont("Monaco", 8));
        painter.drawText(QPoint(xplot[k]-30, 330), QString::fromStdString(data[xsize - 2 - k].first));
        painter.drawText(QPoint(7,325),"0");
        for(int m = 50;m <= 320/ratio;m +=50){
            painter.setPen(pen2);
            int n = m*ratio/10;
            painter.drawText(QPoint(2,(325-m)),QString::number(n*10+10));
            if(m < 320/ratio){
                painter.setPen(pend);
                painter.drawLine(QPoint(20,320-n*10),QPoint(420,320-n*10));
            }
        }
        //painter.drawText(QPoint(0,yplot[k]), QString::number(data[k].second));
    }

}


int Linechart::getXmax(std::vector<std::pair<std::string, double> > data)
{
   return data.size()+1;
}

double Linechart::getYmax(std::vector<std::pair<std::string, double> > data)
{
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
   // std::cout<<ymax<<std::endl;
    return ymax;
}



