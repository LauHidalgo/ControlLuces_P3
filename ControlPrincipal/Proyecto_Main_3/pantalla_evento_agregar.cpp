#include "pantalla_evento_agregar.h"
#include "ui_pantalla_evento_agregar.h"
#include "pantalla_principal.h"
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QDebug>


QDateTime fecha_hora_sistema;
extern QDateTime pantalla_agregar_fecha_hora;
extern int pantalla_agregar_luz_8;
extern bool pantalla_agregar_luz_3,pantalla_agregar_luz_4,pantalla_agregar_luz_5,pantalla_agregar_luz_6,pantalla_agregar_luz_7;


pantalla_evento_agregar::pantalla_evento_agregar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pantalla_evento_agregar)
{
    ui->setupUi(this);

    fecha_hora_sistema = QDateTime::currentDateTime();
    ui->dateEdit_Fecha->setDate(fecha_hora_sistema.date());
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

    QDateTime *test = new QDateTime();

    test->setDate(ui->dateEdit_Fecha->date());
    test->setTime(ui->timeEdit->time());

    fecha_hora_sistema = QDateTime::currentDateTime();
    int segundos_restantes = test->secsTo(fecha_hora_sistema);

    //Pruebas
    qDebug() << "Segundos restantes evento programado: " << segundos_restantes;
    //Pruebas

    if(segundos_restantes >= 0){
        QMessageBox::information(this, "Error", "La fecha del evento programado es anterior a la fecha actual");
    }
    else{
        pantalla_agregar_fecha_hora.setDate(ui->dateEdit_Fecha->date());
        pantalla_agregar_fecha_hora.setTime(ui->timeEdit->time());

        pantalla_agregar_luz_3 = ui->Button_luz_3_2->isChecked();
        pantalla_agregar_luz_4 = ui->Button_luz_4_2->isChecked();
        pantalla_agregar_luz_5 = ui->Button_luz_5_2->isChecked();
        pantalla_agregar_luz_6 = ui->Button_luz_6_2->isChecked();
        pantalla_agregar_luz_7 = ui->Button_luz_7_2->isChecked();
        pantalla_agregar_luz_8 = ui->Slider_luz_8_2->value();

        emit ventana_cerrar();
    }


    pantalla_evento_agregar::close();
}

void pantalla_evento_agregar::on_pushButton_Cancelar_pressed()
{
    pantalla_evento_agregar::close();
}


