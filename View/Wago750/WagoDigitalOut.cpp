#include "WagoDigitalOut.h"
#include "QPainter"
#include <QDebug>

int WagoDigitalOut::globalId = 0;

WagoDigitalOut::WagoDigitalOut(QWidget *parent) : QWidget(parent)
{
    this->id = globalId++;
    setFixedWidth(45);
    setFixedHeight(370);
    CreateGui();
}

void WagoDigitalOut::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap wago750_1604("C:/Users/PKnapik/Documents/QtProject/Wago750Simulator/Resources/750-1604.png");
    painter.drawPixmap(0, 0, 45, 369, wago750_1604);
}

void WagoDigitalOut::CreateGui()
{
    int id = 1;

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this, OUTPUT);
            inOut->move(4 + 19*k, 131 + j*26);
            inOutList.push_back(inOut);
        }
    }

    for(int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this, OUTPUT);
            inOut->move(4 + 19*k, 220 + j*26);
            inOutList.push_back(inOut);
        }
    }

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this, OUTPUT);
            inOut->move(4 + 19*k, 288 + j*26);
            inOutList.push_back(inOut);
        }
    }
}

void WagoDigitalOut::SetState(int id, bool state)
{
    if(id < 16)
    {
        inOutList[id]->SetState(state);
    }
}
