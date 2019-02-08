#include "WagoDigitalIn.h"
#include <QDebug>

int WagoDigitalIn::globalId = 0;

WagoDigitalIn::WagoDigitalIn(QWidget *parent) : WagoSlot(INPUT, parent)
{
    slotPicPath = ":/WagoImg/Resources/750-1604.png";
    this->id = globalId++;
    setFixedWidth(45);
    setFixedHeight(370);
    foreach (InOut* slot, inOutVector) {
        connect(slot, SIGNAL(StateChanged(bool, int)), this, SLOT(InputStateChange(bool,int)));
    }
}

void WagoDigitalIn::InputStateChange(bool state, int id)
{
    if( state == true)
    {
        value |= (1 << id);
    }
    else
    {
        value &= ~(1 << id);
    }
    qDebug("Input changed %d, %d, 0x%04x", state, id, value);
    emit InputChanged(value);
}
