#ifndef QRWIDGET_H
#define QRWIDGET_H

//#include <QWidget>
#include <QDialog>
#include <QEvent>
#include <QPushButton>
#include <QScrollArea>
#include "qrcodegenerator.h"
#include <QLabel>

const static QString nameProgram = "QRCode Generator";

class Widget : public QDialog
{
    Q_OBJECT
public:
    explicit Widget(QDialog *parent, QString toEncode);
    QString encode_string;
    ~Widget();

private slots:
    void updateQRImage();
    void save();

private:
    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    QPushButton *savebutton;
    QScrollArea *scroll;
    QLabel *image_label;
    //QString encode_string;
protected:
    bool eventFilter( QObject * object, QEvent * event );
};

#endif // QRWIDGET_H
