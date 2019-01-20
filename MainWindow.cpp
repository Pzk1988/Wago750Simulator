#include "MainWindow.h"
#include "QPushButton"
#include "Wago750System.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    wago750System = new Wago750System();
    setCentralWidget(wago750System);
}

MainWindow::~MainWindow()
{
    delete wago750System;
}
