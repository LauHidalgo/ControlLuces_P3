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
