#include "InOut.h"
#include <QPainter>
#include <QDebug>

InOut::InOut(int id, InOutType type, QWidget *parent) : QWidget(parent), id(id), type(type)
{
    state = false;
    brush = Qt::gray;
    setFixedHeight(12);
    setFixedWidth(12);
}

void InOut::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setBrush(brush);
    painter.drawEllipse(0, 0, 12, 12);
}

void InOut::mousePressEvent(QMouseEvent* event)
{
    if(type == INPUT)
    {
        if( brush == Qt::gray)
        {
            brush = Qt::green;
            state = true;
        }
        else
        {
            brush = Qt::gray;
            state = false;
        }
        emit StateChanged(state, id);
        update();
    }
}

void InOut::SetState(bool state)
{
    if(this->state != state)
    {
        brush = (state == true ? Qt::green : Qt::gray);
        this->state = state;
        update();
    }
}
