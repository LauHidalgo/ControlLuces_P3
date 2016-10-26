#include "pantalla_evento_agregar.h"
#include "ui_pantalla_evento_agregar.h"
#include "pantalla_principal.h"
#include <QDateTime>
#include <QDate>
#include <QTime>


extern int numero_prueba;
extern QDateTime pantalla_agregar_fecha_hora;
extern int pantalla_agregar_luz_3,pantalla_agregar_luz_4,pantalla_agregar_luz_5,pantalla_agregar_luz_6,pantalla_agregar_luz_7,pantalla_agregar_luz_8;


pantalla_evento_agregar::pantalla_evento_agregar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pantalla_evento_agregar)
{
    ui->setupUi(this);
}

pantalla_evento_agregar::~pantalla_evento_agregar()
{
    delete ui;
}


void pantalla_evento_agregar::on_Button_luz_3_2_pressed()
{
    if(ui->Button_luz_3_2->isChecked()){
        ui->Button_luz_3_2->setText("OFF");
    }
    else{
        ui->Button_luz_3_2->setText("ON");
    }
}

void pantalla_evento_agregar::on_Button_luz_4_2_pressed()
{
    if(ui->Button_luz_4_2->isChecked()){
        ui->Button_luz_4_2->setText("OFF");
    }
    else{
        ui->Button_luz_4_2->setText("ON");
    }
}

void pantalla_evento_agregar::on_Button_luz_5_2_pressed()
{
    if(ui->Button_luz_5_2->isChecked()){
        ui->Button_luz_5_2->setText("OFF");
    }
    else{
        ui->Button_luz_5_2->setText("ON");
    }
}

void pantalla_evento_agregar::on_Button_luz_6_2_pressed()
{
    if(ui->Button_luz_6_2->isChecked()){
        ui->Button_luz_6_2->setText("OFF");
    }
    else{
        ui->Button_luz_6_2->setText("ON");
    }
}

void pantalla_evento_agregar::on_Button_luz_7_2_pressed()
{
    if(ui->Button_luz_7_2->isChecked()){
        ui->Button_luz_7_2->setText("OFF");
    }
    else{
        ui->Button_luz_7_2->setText("ON");
    }
}

void pantalla_evento_agregar::on_Slider_luz_8_2_valueChanged(int value2)
{
    ui->label_luz_8_porcentaje_2->setText(QString::number(value2)+"%");
}

void pantalla_evento_agregar::on_pushButton_Aceptar_pressed()
{

    //// Pruebas ////

    pantalla_agregar_fecha_hora.setDate(ui->dateEdit_Fecha->date());
    pantalla_agregar_fecha_hora.setTime(ui->timeEdit->time());

    emit ventana_cerrar();

    //// Pruebas ////


    pantalla_evento_agregar::close();
}

void pantalla_evento_agregar::on_pushButton_Cancelar_pressed()
{
    pantalla_evento_agregar::close();
}


