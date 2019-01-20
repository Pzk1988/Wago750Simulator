#ifndef WAGO750SYSTEM_H
#define WAGO750SYSTEM_H

#include <QWidget>
#include <QHBoxLayout>
#include "CustomWidget.h"
#include "WagoDigitalIn.h"
#include "WagoDigitalOut.h"
#include "WagoModule.h"

class Wago750System : public QWidget
{
    Q_OBJECT
public:
    explicit Wago750System(QWidget *parent = nullptr);

private:
    QHBoxLayout* mainLayout;
    CustomWidget* customWidget;
    QVector<WagoDigitalIn*> inList;
    QVector<WagoDigitalOut*> outList;
    WagoModule* wagoModule;
};

#endif // WAGO750SYSTEM_H
