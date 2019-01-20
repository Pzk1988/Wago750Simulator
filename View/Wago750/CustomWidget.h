#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QBrush>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);

signals:

public slots:
    void ConnectionStatusChanged(bool status);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QBrush statusBrush;
};

#endif // CUSTOMWIDGET_H
