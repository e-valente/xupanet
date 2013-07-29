#-------------------------------------------------
#
# Project created by QtCreator 2013-07-24T19:45:37
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xupanet
TEMPLATE = app


SOURCES += main.cpp\
        xupanet.cpp \
    youtubeurlhandler.cpp \
    videorender.cpp

HEADERS  += xupanet.h \
    youtubeurlhandler.h \
    videorender.h

FORMS    += xupanet.ui
