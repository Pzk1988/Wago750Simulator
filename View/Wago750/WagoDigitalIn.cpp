#include "WagoDigitalIn.h"
#include "QPainter"
#include <QDebug>

int WagoDigitalIn::globalId = 0;

WagoDigitalIn::WagoDigitalIn(QWidget *parent) : QWidget(parent)
{
    this->id = globalId++;
    setFixedWidth(45);
    setFixedHeight(370);
    CreateGui();
}

void WagoDigitalIn::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap wago750_1504("C:/Users/PKnapik/Documents/QtProject/Wago750Simulator/Resources/750-1504.png");
    painter.drawPixmap(0, 0, 45, 369, wago750_1504);
}

void WagoDigitalIn::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "WagoDigitalIn::mousePressEvent " << id;
}

void WagoDigitalIn::CreateGui()
{
    int id = 1;

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this);
            inOut->move(4 + 19*k, 131 + j*26);
            inOutList.push_back(inOut);
            connect(inOut, SIGNAL(StateChanged(bool, int)), this, SLOT(InputStateChange(bool, int)));
        }
    }

    for(int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this);
            inOut->move(4 + 19*k, 220 + j*26);
            inOutList.push_back(inOut);
            connect(inOut, SIGNAL(StateChanged(bool, int)), this, SLOT(InputStateChange(bool, int)));
        }
    }

    for(int j = 0; j < 3; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            InOut* inOut = new InOut(id++, this);
            inOut->move(4 + 19*k, 288 + j*26);
            inOutList.push_back(inOut);
            connect(inOut, SIGNAL(StateChanged(bool, int)), this, SLOT(InputStateChange(bool, int)));
        }
    }
}

void WagoDigitalIn::InputStateChange(bool state, int id)
{
    qDebug() << "Input changed " << state << " = " << id;
}
