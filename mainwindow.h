#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wagomodule.h"
#include "ISlot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WagoModule* wagoModule;
    QVector<ISlot*> slotVector;

private slots:
    void DataChanged();
};

#endif // MAINWINDOW_H
