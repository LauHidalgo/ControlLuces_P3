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

#include "pantalla_historial.h"
#include "ui_pantalla_historial.h"

pantalla_historial::pantalla_historial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_historial)
{
    ui->setupUi(this);
}

pantalla_historial::~pantalla_historial()
{
    delete ui;
}

void pantalla_historial::desplegar_historial(QString datos){

    ui->textBrowser_Historial->setText(datos);
}

void pantalla_historial::on_pushButton_Historial_Aceptar_clicked()
{
    pantalla_historial::close();
}
