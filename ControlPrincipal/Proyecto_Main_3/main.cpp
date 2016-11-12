////////////////////////////////////////////////////
//Tecnológico de Costa Rica - Tecnológico de Costa Rica
//Escuela de Ingeniería Electrónica - Curso Laboratorio de Estructura de Microprocesadores
//Proyecto #3 - sistema de control de luces para un hogar
//Integrantes del grupo 3:
//  - Anthony Chaves Vásquez
//  - Laura Hidalgo Soto
//  - Carlos Murillo Soto
//  - Irene Rivera Arrieta
//Fecha de entrega: 7 de noviembre de 2017

#include "pantalla_principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pantalla_Principal w;
    w.show();

    return a.exec();
}
