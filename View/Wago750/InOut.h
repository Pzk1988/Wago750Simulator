#ifndef INOUT_H
#define INOUT_H

#include <QWidget>

enum InOutType
{
    INPUT,
    OUTPUT
};

class InOut : public QWidget
{
    Q_OBJECT
public:
    explicit InOut(int id, QWidget *parent = nullptr, InOutType type = INPUT);
    void SetState(bool state);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    int id;
    bool state;
    QBrush brush;
    InOutType type;

signals:
    void StateChanged(bool, int);

public slots:


};

#endif // INOUT_H
