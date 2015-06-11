#include "qrwidget.h"
#include <QtGui>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollArea>
#include <QImageWriter>
#include <QScrollBar>
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>
#include <iostream>
/// PUBLIC
Widget::Widget(QDialog *parent, QString toEncode) :
    QDialog(parent),
    successfulEncoding(false)
{
    setWindowTitle( nameProgram );
    image_label=new QLabel;
    savebutton=new QPushButton(tr("Save"));
    encode_string = toEncode;
    QVBoxLayout *lay=new QVBoxLayout;
    lay->addWidget(image_label);
    lay->addWidget(savebutton);
    setLayout(lay);

    connect( savebutton, SIGNAL( clicked() ), SLOT( save() ) );

    updateQRImage();
}

Widget::~Widget()
{

}

/// PRIVATE SLOTS
void Widget::updateQRImage()
{
    int level_index = 1;
    int version_index = 0;
    bool bExtent = true;
    int mask_index = -1;

 //***********************String!**********************************
    //encode_string = "November 2014: $2070.";
    //std::cout<<encode_string.toStdString().c_str()<<std::endl;
    successfulEncoding = qrEncode.EncodeData(level_index,
                                             version_index,
                                             bExtent,
                                             mask_index,
                                             encode_string.toLatin1().data());

    if (!successfulEncoding)
    {
        image_label->clear();
        image_label->setText( "Generating..." );
       // ui->labelSize->clear();
        savebutton->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encode_image( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encode_image.fill( 1 );

    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encode_image.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    image_label->setPixmap( QPixmap::fromImage( encode_image ) );

    const QPixmap & scale_image = image_label->pixmap()->scaled( encodeImageSize*8, encodeImageSize*8 );
    image_label->setPixmap( scale_image );
    savebutton->setEnabled( successfulEncoding );
}

void Widget::save()
{
    QString suffix;
    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
        suffix += QString( "%1 ( *.%2 )\n" )
                .arg( QString( format ).toUpper() )
                .arg( QString( format ) );

    const QString & path = QFileDialog::getSaveFileName( this,
                                                         tr("save file"),
                                                         QString( "qr_code" ),
                                                         suffix );
    if ( path.isNull() )
        return;

    image_label->pixmap()->save( path );
}

/// PROTECTED
bool Widget::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = new QScrollArea;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible()
                        || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}
