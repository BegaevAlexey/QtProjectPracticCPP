#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T11:15:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QMAKE_CXXFLAGS += -std=gnu++11

TARGET = practic
TEMPLATE = app


SOURCES += main.cpp\
    qcustomplot.cpp \
    well.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    getdata.h \
    getvectorwell.h \
    well.h

FORMS    +=
