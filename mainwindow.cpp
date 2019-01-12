#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wagoModule = new WagoModule(&slotVector);
    connect(wagoModule, SIGNAL(DataChanged()), this, SLOT(DataChanged()));

}

void MainWindow::DataChanged()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
