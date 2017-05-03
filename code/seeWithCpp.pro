#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T13:49:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = seeWithCpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processespane.cpp \
    swc_addlogo.cpp \
    swc_addnoisesaltandpepper.cpp \
    swc_computehistogram.cpp \
    swc_controller.cpp \
    swc_processmanager.cpp \
    swc_processcommunicator.cpp

HEADERS  += mainwindow.h \
    processespane.h \
    swc_addlogo.h \
    swc_addnoisesaltandpepper.h \
    swc_computehistogram.h \
    swc_controller.h \
    swc_processmanager.h \
    swc_processcommunicator.h

FORMS    += mainwindow.ui \
    processespane.ui

#-------------------------------------------------
#OPEN-CV3.2:
#-------------------------------------------------

#INCLUDEPATH += "/usr/local/include/"
#LIBS += `pkg-config --libs opencv`

# Qmake instructions for Unix platforms only
unix{
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
