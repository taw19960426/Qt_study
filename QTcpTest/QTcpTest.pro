#-------------------------------------------------
#
# Project created by QtCreator 2022-01-06T19:10:52
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTcpTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    clienttcp.cpp

HEADERS  += widget.h \
    clienttcp.h

FORMS    += widget.ui \
    clienttcp.ui

CONFIG +=C++11
