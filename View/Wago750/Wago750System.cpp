#include "Wago750System.h"
#include <QDebug>
#include "WagoDigitalIn.h"
#include "WagoDigitalOut.h"

Wago750System::Wago750System(QWidget *parent) : QWidget(parent)
{   
    //Logic
    wagoModule = new WagoModule();

    //GUI
    mainLayout = new QHBoxLayout();

    //Ethernet module
    customWidget = new CustomWidget(this);
    mainLayout->addWidget(customWidget);
    mainLayout->setAlignment(customWidget, Qt::AlignLeft);

    //Digital in
    for(int i = 0; i < DIGITAL_IN_NUMBER; i++)
    {
        WagoDigitalIn* digitalIn = new WagoDigitalIn(this);
        slotList.push_back(digitalIn);
        mainLayout->addWidget(digitalIn);
        mainLayout->setAlignment(digitalIn, Qt::AlignLeft);
        connect(digitalIn, SIGNAL(InputChanged(quint16)), wagoModule, SLOT(InputChanged(quint16)));
    }
    //Digital out
    for(int i = 0; i < DIGITAL_OUT_NUMBER; i++)
    {
        WagoDigitalOut* digitalOut = new WagoDigitalOut(this);
        slotList.push_back(digitalOut);
        mainLayout->addWidget(digitalOut);
        mainLayout->setAlignment(digitalOut, Qt::AlignLeft);
    }
    mainLayout->addStretch();

    connect(wagoModule, SIGNAL(OutputChanged(quint8, quint16)), this, SLOT(OutputChanged(quint8, quint16)));
    connect(wagoModule, SIGNAL(ConnectionStatus(bool)), customWidget, SLOT(ConnectionStatusChanged(bool)));

    setLayout(mainLayout);
    qDebug() << "New widget";
}

void Wago750System::OutputChanged(quint8 slotId, quint16 value)
{
    reinterpret_cast<WagoDigitalOut*>(slotList[slotId + DIGITAL_IN_NUMBER])->SetState(value);
}
