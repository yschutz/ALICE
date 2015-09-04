#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T11:32:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ALICE
TEMPLATE = app


SOURCES += main.cpp
#    view.cpp \
#    scene.cpp \
#    mesh.cpp \
#    vertex.cpp \
#    sphere.cpp \
#    laboratoryview.cpp \
#    alice.cpp \
#    annulus.cpp \
#    polygon.cpp \
#    tube.cpp \
#    cylinder.cpp \
#    collision.cpp \
#    particle.cpp

#HEADERS  += \
#    view.h \
#    scene.h \
#    mesh.h \
#    vertex.h \
#    sphere.h \
#    laboratoryview.h \
#    alice.h \
#    annulus.h \
#    polygon.h \
#    tube.h \
#    cylinder.h \
#    collision.h \
#    particle.h



#RESOURCES += \
#    shaders.qrc \
#    textures.qrc

#DISTFILES +=

include(cutegl/cutegl.pri)

