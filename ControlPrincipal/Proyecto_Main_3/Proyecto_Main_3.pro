#-------------------------------------------------
#
# Project created by QtCreator 2016-10-06T09:27:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto_Main_3
TEMPLATE = app


SOURCES += main.cpp\
        pantalla_principal.cpp \
    pantalla_evento_agregar.cpp \
    clase_eventos.cpp

HEADERS  += pantalla_principal.h \
    pantalla_evento_agregar.h \
    clase_eventos.h

FORMS    += pantalla_principal.ui \
    pantalla_evento_agregar.ui
