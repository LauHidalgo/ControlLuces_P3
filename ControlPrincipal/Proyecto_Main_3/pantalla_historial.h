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

#ifndef PANTALLA_HISTORIAL_H
#define PANTALLA_HISTORIAL_H

#include <QDialog>

namespace Ui {
class pantalla_historial;
}

class pantalla_historial : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_historial(QWidget *parent = 0);
    ~pantalla_historial();
    Ui::pantalla_historial *ui;
    void desplegar_historial(QString datos);
private slots:
    void on_pushButton_Historial_Aceptar_clicked();
};

#endif // PANTALLA_HISTORIAL_H
