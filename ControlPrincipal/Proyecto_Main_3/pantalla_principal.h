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


#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QSharedPointer>

namespace Ui {
class Pantalla_Principal;
}

class Pantalla_Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla_Principal(QWidget *parent = 0 );
    ~Pantalla_Principal();

    void inicializacion_pantalla_principal();

    Ui::Pantalla_Principal *ui;


public slots:

    //Cambio de estado en los botones/sliders que encienden/apagan las
    //luces en el modo mmanual
    void on_Button_luz_3_pressed();
    void on_Button_luz_4_pressed();
    void on_Button_luz_5_pressed();
    void on_Button_luz_6_pressed();
    void on_Button_luz_7_pressed();
    void on_Slider_luz_8_valueChanged(int value);

    //Funciones que manejan el cambio de estado de las luces segun los datos
    //recibidos por la aplicación extrerna
    void tcp_cambio_luz_3_off();
    void tcp_cambio_luz_3_on();
    void tcp_cambio_luz_4_off();
    void tcp_cambio_luz_4_on();
    void tcp_cambio_luz_5_off();
    void tcp_cambio_luz_5_on();
    void tcp_cambio_luz_6_off();
    void tcp_cambio_luz_6_on();
    void tcp_cambio_luz_7_off();
    void tcp_cambio_luz_7_on();

    //Funciones que activan las funciones de agregar eventos y eliminar eventos
    void on_Button_evento_agregar_pressed();
    void on_Button_evento_eliminar_pressed();

    //Funciones  internas que procesan el agregar un eveento a la lista, entradas
    //de historial, revision y activación de eventos, interacción de las entradas
    //y salidas y la actualización del reloj
    void agregar_evento_lista();
    void agregar_entrada_historial();
    void revision_eventos();
    void interaccion_entradas_salidas();
    void actualizar_reloj();

    //Funcion que devuelve un String que se usa para guardar el historial
    //o para mostrar en la tabla de eventos programados
    QString string_estatus_dispositivo(bool historial);




private slots:
    void on_Button_Guardar_Historial_clicked();
    void on_Button_Historial_clicked();
};

#endif // PANTALLA_PRINCIPAL_H
