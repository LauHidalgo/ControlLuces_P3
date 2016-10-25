#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
#include <QDateTime>
#include <QDebug>
#include "pantalla_evento_agregar.h"
#include "pantalla_principal.h"
#include "clase_eventos.h"
#include <QList>
#include <QListData>

int numero_prueba = 0;

Pantalla_Principal::Pantalla_Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla_Principal)
{
    ui->setupUi(this);




    //QDateTime fechahora = QDateTime::currentDateTime();

    //QString fechahoraSTR = fechahora.toString("dd/MM/yyyy hh:mm:ss");

    //qDebug() << "Hora Actual: " << fechahoraSTR;

    //ui->horaactual->setText(fechahoraSTR);

}

Pantalla_Principal::~Pantalla_Principal()
{
    delete ui;

}

/*void Pantalla_Principal::on_PushButton_clicked()
{
    QDateTime cambiofechahora;

    cambiofechahora.setDate(ui->dateEdit->date());

    cambiofechahora.setTime(ui->dateTimeEdit_2->time());

    QString cambiofechahoraSTR = cambiofechahora.toString("dd/MM/yyyy hh:mm:ss AP");

    ui->horaactual->setText(cambiofechahoraSTR);

}



void Pantalla_Principal::on_verticalSlider_sliderReleased()
{
    ui->lcdNumber->display(ui->verticalSlider->value());
}

void Pantalla_Principal::on_verticalSlider_valueChanged(int value)
{
    ui->lcdNumber->display(value);
    ui->label2->setText(QString::number(value));
}*/



/*void Pantalla_Principal::on_luz3Button_pressed()
{
    if(ui->luz3Button->isChecked()){
        ui->luz3Button->setText("OFF");
    }
    else{
        ui->luz3Button->settext("ON");
    }
}*/


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
    //// Pruebas ////

    nuevo_evento = new clase_eventos;

    //// Pruebas ////

    pantalla_evento_agregar *agregarevento = new pantalla_evento_agregar();
    qDebug() << "Hora evento: "<<QString::number(numero_prueba);
    agregarevento->show();
}

void Pantalla_Principal::agregar_evento_lista()
{
    //// Pruebas ////

    //Lista_Eventos.push_back(*nuevo_evento);



    qDebug() << "Hora evento: "<<QString::number(numero_prueba);

    //// Pruebas ////
}
