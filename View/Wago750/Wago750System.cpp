#include "Wago750System.h"
#include <QDebug>

Wago750System::Wago750System(QWidget *parent) : QWidget(parent)
{
    //GUI
    mainLayout = new QHBoxLayout();

    //Ethernet module
    customWidget = new CustomWidget(this);
    mainLayout->addWidget(customWidget);
    mainLayout->setAlignment(customWidget, Qt::AlignLeft);

    //Digital in
    for(int i = 0; i < 3; i++)
    {
        WagoDigitalIn* digitalIn = new WagoDigitalIn(this);
        inList.push_back(digitalIn);
        mainLayout->addWidget(digitalIn);
        mainLayout->setAlignment(digitalIn, Qt::AlignLeft);
    }
    //Digital out
    for(int i = 0; i < 4; i++)
    {
        WagoDigitalOut* digitalOut = new WagoDigitalOut(this);
        outList.push_back(digitalOut);
        mainLayout->addWidget(digitalOut);
        mainLayout->setAlignment(digitalOut, Qt::AlignLeft);
    }
    mainLayout->addStretch();

    //Logic
    wagoModule = new WagoModule();
    connect(wagoModule, SIGNAL(ConnectionStatus(bool)), customWidget, SLOT(ConnectionStatusChanged(bool)));

    outList[0]->SetState(0, true);
    outList[1]->SetState(15, true);
    setLayout(mainLayout);
    qDebug() << "New widget";
}
