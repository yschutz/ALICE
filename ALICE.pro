#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T11:32:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ALICE
TEMPLATE = app


SOURCES += main.cpp \
    alice.cpp \
    laboratoryview.cpp \
    particle.cpp \
    collision.cpp




include(cutegl/cutegl.pri)

HEADERS += \
    alice.h \
    laboratoryview.h \
    particle.h \
    collision.h

RESOURCES += \
    textures.qrc


