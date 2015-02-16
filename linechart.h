#ifndef LINECHART_H
#define LINECHART_H
#include <QWidget>
#include <QDialog>
#include <QPainter>
#include <QPen>
#include <vector>
//#include <QDebug>
#include <string>


class Linechart: public QDialog{
    Q_OBJECT
public:
    explicit Linechart(QWidget *parent = 0);
    Linechart(QWidget *parent, std::vector<std::pair<std::string, double> > _data);
    ~Linechart();
    void paintEvent(QPaintEvent *);
    //void setxaxis(std::string x);
   // void setyaxis(double y);
    int getXmax(std::vector<std::pair<std::string, double> > data);
    double getYmax (std::vector<std::pair<std::string, double> > data);
private:
    int size;
    std::vector<std::pair<std::string, double> > data;
    std::string x;
    double y;
    Linechart * linechart;

};



#endif // LINECHART_H
