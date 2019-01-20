#include "CustomWidget.h"
#include "QDebug"
#include "QPainter"
#include "QPixmap"
#include "QRect"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(186);
    setFixedHeight(370);
    statusBrush = Qt::red;
}

void CustomWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap wago750_352("C:/Users/PKnapik/Documents/QtProject/Wago750Simulator/Resources/750-352.png");

    painter.drawPixmap(0, 0, 186, 366, wago750_352);

    QRect rect(131, 36, 12, 12);
    painter.fillRect(rect, statusBrush);
    painter.drawRect(rect);
}

void CustomWidget::ConnectionStatusChanged(bool status)
{
    QBrush newStatus = (status == true ? Qt::green : Qt::red);
    if( newStatus != statusBrush)
    {
        statusBrush = newStatus;
        update();
    }
}
