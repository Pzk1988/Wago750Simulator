#ifndef WAGODIGITALIN_H
#define WAGODIGITALIN_H

#include <QWidget>
#include "InOut.h"

class WagoDigitalIn : public QWidget
{
    Q_OBJECT
public:
    explicit WagoDigitalIn(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int id;
    static int globalId;
    QVector<InOut*> inOutList;

    void CreateGui();

signals:
public slots:
    void InputStateChange(bool state, int id);
};

#endif // WAGODIGITALIN_H
