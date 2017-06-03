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
    swc_processcommunicator.cpp \
    swc_morphology.cpp \
    swc_matrixinput.cpp \
    swc_structuringelementinput.cpp \
    swc_kernelprocess.cpp \
    swc_settwothresholds.cpp \
    swc_structure.cpp \
    swc_interestpoints.cpp \
    swc_camcalib.cpp \
    swc_stereogeometry.cpp

HEADERS  += mainwindow.h \
    processespane.h \
    swc_addlogo.h \
    swc_addnoisesaltandpepper.h \
    swc_computehistogram.h \
    swc_controller.h \
    swc_processmanager.h \
    swc_processcommunicator.h \
    swc_morphology.h \
    swc_matrixinput.h \
    swc_structuringelementinput.h \
    swc_kernelprocess.h \
    swc_settwothresholds.h \
    swc_structure.h \
    swc_interestpoints.h \
    swc_camcalib.h \
    swc_stereogeometry.h

FORMS    += mainwindow.ui \
    processespane.ui \
    swc_matrixinput.ui \
    swc_structuringelementinput.ui \
    swc_settwothresholds.ui

#-------------------------------------------------
#OPEN-CV3.2:
#-------------------------------------------------

INCLUDEPATH += "/usr/local/include/"
LIBS += `pkg-config --libs opencv`
