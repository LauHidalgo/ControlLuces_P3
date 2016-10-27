#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include <QDateTime>
#include <QDebug>
#include "pantalla_evento_agregar.h"
#include "pantalla_principal.h"
#include <QList>
#include <QListData>


//Variables para que la ventana secundaria use como extern (interaccion entre ventanas)
QDateTime pantalla_agregar_fecha_hora;
int pantalla_agregar_luz_8;
bool pantalla_agregar_luz_3,pantalla_agregar_luz_4,pantalla_agregar_luz_5,pantalla_agregar_luz_6,pantalla_agregar_luz_7;


//Array de eventos y sus respectivos estatus por fechaa/hora y numero de luz.
QList <QDateTime> Lista_Eventos_Fecha_Hora;  //Esta sera la lista de eventos futuros tipo QDateTime indexados de manera correspondiente
QList <bool> Lista_Eventos_Luz_3;
QList <bool> Lista_Eventos_Luz_4;
QList <bool> Lista_Eventos_Luz_5;
QList <bool> Lista_Eventos_Luz_6;
QList <bool> Lista_Eventos_Luz_7;
QList <int> Lista_Eventos_Luz_8;


//Declaracion de la ventana secundaria (para ser mostrada)
pantalla_evento_agregar *agregarevento;


//Declaracion de la variable del String para agregar los eventos a la lista del GUI
QString listWidget_String;





Pantalla_Principal::Pantalla_Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla_Principal)
{
    ui->setupUi(this);

    inicializacion_pantalla_principal();
}

Pantalla_Principal::~Pantalla_Principal()
{
    delete ui;

}

void Pantalla_Principal::inicializacion_pantalla_principal(){

    agregarevento = new pantalla_evento_agregar();

    connect(agregarevento,SIGNAL(ventana_cerrar()),this,SLOT(agregar_evento_lista()));
}



//Nota: el estado de las luces se manejara con la lectura constante
//del estad en el que se encuentren estos botones, por lo tanto, se ahorrara
//espacio al no tener que declarar variables extra

void Pantalla_Principal::on_Button_luz_3_pressed() //cuando se presiona el boton de Encendido/Apagado de la luz 3
{
    if(ui->Button_luz_3->isChecked()){      //Verifica si el boton se encuentra en el estado ON
        ui->Button_luz_3->setText("OFF");   //Si es asi, lo cambia a OFF
    }
    else{
        ui->Button_luz_3->setText("ON");    //Si no es asi, lo cambia a ON
    }
}
void Pantalla_Principal::on_Button_luz_4_pressed() //cuando se presiona el boton de Encendido/Apagado de la luz 3
{
    if(ui->Button_luz_4->isChecked()){
        ui->Button_luz_4->setText("OFF");
    }
    else{
        ui->Button_luz_4->setText("ON");
    }
}
void Pantalla_Principal::on_Button_luz_5_pressed() //cuando se presiona el boton de Encendido/Apagado de la luz 3
{
    if(ui->Button_luz_5->isChecked()){
        ui->Button_luz_5->setText("OFF");
    }
    else{
        ui->Button_luz_5->setText("ON");
    }
}
void Pantalla_Principal::on_Button_luz_6_pressed() //cuando se presiona el boton de Encendido/Apagado de la luz 3
{
    if(ui->Button_luz_6->isChecked()){
        ui->Button_luz_6->setText("OFF");
    }
    else{
        ui->Button_luz_6->setText("ON");
    }
}
void Pantalla_Principal::on_Button_luz_7_pressed() //cuando se presiona el boton de Encendido/Apagado de la luz 3
{
    if(ui->Button_luz_7->isChecked()){
        ui->Button_luz_7->setText("OFF");
    }
    else{
        ui->Button_luz_7->setText("ON");
    }
}

void Pantalla_Principal::on_Slider_luz_8_valueChanged(int value)
{
    ui->label_luz_8_porcentaje->setText(QString::number(value)+"%");
}



//Este evento corresponde a agregar un nuevo evento para determinar que luces
//se encenderan o apagaran y en que fecha determinada

void Pantalla_Principal::on_Button_evento_agregar_pressed()
{
    agregarevento->show();
}

void Pantalla_Principal::agregar_evento_lista()
{
    //Agregando datos a las listas correspondientes de eventos
    Lista_Eventos_Fecha_Hora.append(pantalla_agregar_fecha_hora);
    Lista_Eventos_Luz_3.append(pantalla_agregar_luz_3);
    Lista_Eventos_Luz_4.append(pantalla_agregar_luz_4);
    Lista_Eventos_Luz_5.append(pantalla_agregar_luz_5);
    Lista_Eventos_Luz_6.append(pantalla_agregar_luz_6);
    Lista_Eventos_Luz_7.append(pantalla_agregar_luz_7);
    Lista_Eventos_Luz_8.append(pantalla_agregar_luz_8);

    //Construccion del String que se agregará en la lista del GUI
    listWidget_String = "Fecha: " + pantalla_agregar_fecha_hora.toString("dd/MM/yyyy") + " || Hora: "
                     + pantalla_agregar_fecha_hora.toString("hh:mm AP");

    //String del estatus de la luz 3
    if (pantalla_agregar_luz_3){
        listWidget_String = listWidget_String + " || Luz3: ON";}
    else {
        listWidget_String = listWidget_String + " || Luz3: OFF";}

    //String del estatus de la luz 4
    if (pantalla_agregar_luz_4){
        listWidget_String = listWidget_String + " || Luz4: ON";}
    else {
        listWidget_String = listWidget_String + " || Luz4: OFF";}

    //String del estatus de la luz 5
    if (pantalla_agregar_luz_5){
        listWidget_String = listWidget_String + " || Luz5: ON";}
    else {
        listWidget_String = listWidget_String + " || Luz5: OFF";}

    //String del estatus de la luz 6
    if (pantalla_agregar_luz_6){
        listWidget_String = listWidget_String + " || Luz6: ON";}
    else {
        listWidget_String = listWidget_String + " || Luz6: OFF";}

    //String del estatus de la luz 7
    if (pantalla_agregar_luz_7){
        listWidget_String = listWidget_String + " || Luz7: ON";}
    else {
        listWidget_String = listWidget_String + " || Luz7: OFF";}

    //String del estatus de la luz 3
    listWidget_String = listWidget_String + " || Luz8: " + QString::number(pantalla_agregar_luz_8) + "%";

    //El evento se agrega a la lista que se encuentra en la interfaz de usuario
    ui->listWidget->addItem(listWidget_String);

    /////////
    //Pruebas
    Debug_Pruebas();
    //Pruebas
    /////////
}


void Pantalla_Principal::on_Button_evento_eliminar_pressed()
{
    Lista_Eventos_Fecha_Hora.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_3.removeAt(ui->listWidget->currentIndex().row());

    ui->listWidget->currentItem()->~QListWidgetItem();

    /////////
    //Pruebas
    Debug_Pruebas();
    //Pruebas
    /////////
}

void Pantalla_Principal::Debug_Pruebas(){

    //// Pruebas ////

    //QString fechahoraSTR = pantalla_agregar_fecha_hora.toString("dd/MM/yyyy hh:mm AP");

    //qDebug() << "Elemento Agregado: " << fechahoraSTR;
    qDebug() << "Elementos en Fecha/Hora: ";

    for (int i=0; i<Lista_Eventos_Fecha_Hora.count(); i++){
        qDebug() << Lista_Eventos_Fecha_Hora.value(i).toString("dd/MM/yyyy hh:mm AP");
    }
    qDebug() << "Elementos en Luz 3: ";
    for (int i=0; i<Lista_Eventos_Luz_3.count(); i++){
        qDebug() << Lista_Eventos_Luz_3.value(i);
    }
    qDebug() << "===================================";

    //// Pruebas ////
}
