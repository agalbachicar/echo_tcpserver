#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T14:20:33
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = QTTCPServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    athread.cpp \
    atcpserver.cpp

HEADERS += \
    athread.h \
    atcpserver.h
