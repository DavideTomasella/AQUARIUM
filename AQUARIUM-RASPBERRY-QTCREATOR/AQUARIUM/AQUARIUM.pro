#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T14:52:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network sql

TARGET = AQUARIUM
TEMPLATE = app


SOURCES += main.cpp\
        home.cpp \
    globals.cpp \
    dbconnect.cpp \
    inoutconnection.cpp \
    datastate.cpp \
    dataparser.cpp \
    autocontrol.cpp \
    updater.cpp \
    log.cpp \
    params.cpp \
    file.cpp \
    calibrate.cpp

HEADERS  += home.h \
    globals.h \
    dbconnect.h \
    inoutconnection.h \
    datastate.h \
    dataparser.h \
    autocontrol.h \
    updater.h \
    log.h \
    params.h \
    file.h \
    calibrate.h

FORMS    += home.ui \
    log.ui \
    params.ui \
    calibrate.ui

DEFINES +="VERSION=\"3.3\""
