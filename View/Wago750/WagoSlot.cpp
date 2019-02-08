#include "WagoSlot.h"
#include <QPainter>

WagoSlot::WagoSlot(InOutType type, QWidget *parent) : QWidget(parent), value(0x0000), type(type)
{
    CreateGui();
}
void WagoSlot::CreateGui()
{
    int id = 0;

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, type, this);
            inOut->move(4 + 19*k, 131 + j*26);
            inOutVector.push_back(inOut);
        }
    }

    for(int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, type, this);
            inOut->move(4 + 19*k, 220 + j*26);
            inOutVector.push_back(inOut);
        }
    }

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, type, this);
            inOut->move(4 + 19*k, 288 + j*26);
            inOutVector.push_back(inOut);
        }
    }
}

void WagoSlot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap wago750_1604(slotPicPath);
    painter.drawPixmap(0, 0, 45, 369, wago750_1604);
}

int WagoSlot::GetId()
{
    return id;
}
