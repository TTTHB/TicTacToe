#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T15:24:38
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TTT_Arduinoconnection
TEMPLATE = app


SOURCES += main.cpp\
        connection.cpp \
    new_game.cpp

HEADERS  += connection.h \
    new_game.h

FORMS    += connection.ui \
    new_game.ui
