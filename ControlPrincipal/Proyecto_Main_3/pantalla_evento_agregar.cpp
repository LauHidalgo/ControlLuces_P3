#include "pantalla_evento_agregar.h"
#include "ui_pantalla_evento_agregar.h"

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
