#ifndef WAGO750SYSTEM_H
#define WAGO750SYSTEM_H

#include <QWidget>
#include <QHBoxLayout>
#include "CustomWidget.h"
#include "WagoSlot.h"
#include "WagoModule.h"

class Wago750System : public QWidget
{
    Q_OBJECT
public:
    explicit Wago750System(QWidget *parent = nullptr);

private:
    QHBoxLayout* mainLayout;
    CustomWidget* customWidget;
    QVector<WagoSlot*> slotList;
    WagoModule* wagoModule;

    static const int DIGITAL_IN_NUMBER = 5;
    static const int DIGITAL_OUT_NUMBER = 5;

private slots:
    void OutputChanged(quint8 slotId, quint16 value);
};

#endif // WAGO750SYSTEM_H
