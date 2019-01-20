#ifndef WAGODIGITALOUT_H
#define WAGODIGITALOUT_H

#include <QWidget>
#include "InOut.h"

class WagoDigitalOut : public QWidget
{
    Q_OBJECT
public:
    explicit WagoDigitalOut(QWidget *parent = nullptr);
    bool GetState(int id);
    void SetState(int id, bool state);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int id;
    static int globalId;
    QVector<InOut*> inOutList;

    void CreateGui();

signals:
public slots:
};

#endif // WAGODIGITALOUT_H
