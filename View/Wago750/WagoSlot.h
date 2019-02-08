#ifndef WAGOSLOT_H
#define WAGOSLOT_H

#include <QWidget>
#include "InOut.h"

class WagoSlot : public QWidget
{
    Q_OBJECT
public:
    explicit WagoSlot(InOutType type,  QWidget *parent = nullptr);
    int GetId();

protected:
    void paintEvent(QPaintEvent *event) override;
    QVector<InOut*> inOutVector;
    int id;
    QString slotPicPath;
    quint16 value;

private:
    void CreateGui();
    InOutType type;

signals:

public slots:
};

#endif // WAGOSLOT_H
