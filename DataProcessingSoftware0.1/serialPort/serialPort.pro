QT       += core gui widgets network
QT       += widgets
QT       += charts
QT       += serialport

TARGET = serialPort
TEMPLATE = app


SOURCES += main.cpp\
    dataprocess.cpp \
    filetrans.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    dataprocess.h \
    filetrans.h

FORMS    += mainwindow.ui

RESOURCES += \
    picture.qrc

