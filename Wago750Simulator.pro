#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T20:04:41
#
#-------------------------------------------------

QT       += core gui
QT += network widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wago750Simulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11

SOURCES += \
    Main.cpp \
    MainWindow.cpp \
    Model/ModbusTcp.cpp \
    Model/WagoModule.cpp \
    Model/InternalMemory.cpp \
    View/Wago750/CustomWidget.cpp \
    View/Wago750/WagoDigitalIn.cpp \
    View/Wago750/InOut.cpp \
    View/Wago750/WagoDigitalOut.cpp \
    View/Wago750/Wago750System.cpp

HEADERS += \
    MainWindow.h \
    Model/ModbusTcp.h \
    Model/WagoModule.h \
    Model/InternalMemory.h \
    Utilities/HelperClass.h \
    View/Wago750/CustomWidget.h \
    View/Wago750/WagoDigitalIn.h \
    View/Wago750/InOut.h \
    View/Wago750/WagoDigitalOut.h \
    View/Wago750/Wago750System.h

FORMS +=

INCLUDEPATH += Model \
               Utilities \
               View\Wago750
