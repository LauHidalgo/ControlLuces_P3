#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include <QDateTime>
#include <QDebug>
#include "pantalla_evento_agregar.h"
#include "pantalla_principal.h"
#include <QList>
#include <QListData>


QDateTime pantalla_agregar_fecha_hora;
int pantalla_agregar_luz_3,pantalla_agregar_luz_4,pantalla_agregar_luz_5,pantalla_agregar_luz_6,pantalla_agregar_luz_7,pantalla_agregar_luz_8;


QList <QDateTime> Lista_Eventos;  //Esta sera la lista de eventos futuros tipo QDateTime indexados de manera correspondiente

pantalla_evento_agregar *agregarevento;


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
    Lista_Eventos.append(pantalla_agregar_fecha_hora);

    //// Pruebas ////

    QString fechahoraSTR = pantalla_agregar_fecha_hora.toString("dd/MM/yyyy hh:mm AP");

    qDebug() << "Elemento Agregado: " << fechahoraSTR;
    qDebug() << "Elementos en Lista: ";

    for (int i=0; i<Lista_Eventos.count(); i++){
        qDebug() << Lista_Eventos.value(i).toString("dd/MM/yyyy hh:mm AP");
    }
    qDebug() << "===================================";

    ui->listWidget->addItem(pantalla_agregar_fecha_hora.toString("dd/MM/yyyy hh:mm AP"));

    //// Pruebas ////
}

void Pantalla_Principal::inicializacion_pantalla_principal(){

    agregarevento = new pantalla_evento_agregar();

    connect(agregarevento,SIGNAL(ventana_cerrar()),this,SLOT(agregar_evento_lista()));
}
