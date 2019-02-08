#include "WagoDigitalOut.h"
#include "QPainter"
#include <QDebug>

int WagoDigitalOut::globalId = 0;

WagoDigitalOut::WagoDigitalOut(QWidget *parent) : WagoSlot(OUTPUT, parent)
{
    slotPicPath = ":/WagoImg/Resources/750-1504.png";
    this->id = globalId++;
    setFixedWidth(45);
    setFixedHeight(370);
}

void WagoDigitalOut::SetState(int id, bool state)
{
    if(id < 16)
    {
        inOutVector[id]->SetState(state);
    }
}

void WagoDigitalOut::SetState(quint16 value)
{
    for(int i = 0; i < 16; i++)
    {
        inOutVector[i]->SetState((value >> i) & 1);
    }
}
