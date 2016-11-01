//=======================================================================//
//      Librerias a utilizar
//=======================================================================//
//Clase local
#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
//Clases externas
#include "pantalla_evento_agregar.h"
#include "pantalla_historial.h"
//Librerias de funcionalidades de Qt
#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QListData>
#include <QtCore>
#include <QCoreApplication>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>


//=======================================================================//
//      Declaracion de variables y objetos
//=======================================================================//

//Variables/Objetos para que la ventana secundaria use como extern (interaccion entre ventanas)
QDateTime pantalla_agregar_fecha_hora;
int pantalla_agregar_luz_8;
bool pantalla_agregar_luz_3,pantalla_agregar_luz_4,pantalla_agregar_luz_5,pantalla_agregar_luz_6,pantalla_agregar_luz_7;

//Array de eventos y sus respectivos estatus por fecha/hora y numero de luz.
QList <QDateTime> Lista_Eventos_Fecha_Hora;  //Esta sera la lista de eventos futuros tipo QDateTime indexados de manera correspondiente
QList <bool> Lista_Eventos_Luz_3;            //Listas de estatus de las luces, cada elemento esta conectado por el indice a una fecha y hora respectiva
QList <bool> Lista_Eventos_Luz_4;
QList <bool> Lista_Eventos_Luz_5;
QList <bool> Lista_Eventos_Luz_6;
QList <bool> Lista_Eventos_Luz_7;
QList <int> Lista_Eventos_Luz_8;
QList <bool> Lista_Eventos_Ejecutado;

//Estados de las luces L1 y L2, que al no tener boton se establecen manualmente
bool Status_Luz_1 = false;
bool Status_Luz_2 = false;

//Declaracion de la ventana secundaria (para ser mostrada)
pantalla_evento_agregar *agregarevento;

//Declaracion de la ventana secundaria de historial (para ser mostrada)
pantalla_historial *pantallahistorial;

//Objeto que guardara la fecha y hora actuales
QDateTime fecha_hora_actuales;

//Objetos QTimer que se encargaran de actualizar diversas funciones del codigo principal
QTimer *timer_historial;
QTimer *ejecucion_eventos;



//=======================================================================//
//      Funciones principales
//=======================================================================//

//---------------------------------
//Declaracion de la ventana "Pantalla Principal" como un QWidget
Pantalla_Principal::Pantalla_Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pantalla_Principal)
{

    //Procesos que se quieren inicializar cuando se crea la ventana
    ui->setupUi(this);  //*Setup de la UI

    inicializacion_pantalla_principal();    //*Eventos que se quieren inicializar para
                                            //lograr la funcionalidad deseada    
}

//---------------------------------
//Metodo para destruir la Pantalla Principal
Pantalla_Principal::~Pantalla_Principal()
{
    delete ui;

}

//---------------------------------
//Funcion de inicializacion para los procesos principales
void Pantalla_Principal::inicializacion_pantalla_principal(){

    //Creacion de un nuevo elemento/Pantalla para agregar eventos
    agregarevento = new pantalla_evento_agregar();

    //Creacion de un nuevo elemento/Pantalla para ver el historial
    pantallahistorial = new pantalla_historial();

    //Conexion de la senal de cerrar ventana agregar eventos a la senal agregar evento lista de la pantalla principal
    connect(agregarevento,SIGNAL(ventana_cerrar()),this,SLOT(agregar_evento_lista()));

    //Conexion de la senal de guardar elementos en el historial al timer correspondiente
    timer_historial = new QTimer();
    connect(timer_historial,SIGNAL(timeout()),this,SLOT(agregar_entrada_historial()));
    timer_historial->start(5000);   //Periodos en milisegundos para actualizar

    //Conexion de la senal de revision de eventos al timer correspondiente
    ejecucion_eventos = new QTimer();
    connect(ejecucion_eventos,SIGNAL(timeout()),this,SLOT(revision_eventos()));
    ejecucion_eventos->start(1000);

}


//---------------------------------
//Nota: el estado de las luces se manejara con la lectura constante
//del estado en el que se encuentren estos botones, por lo tanto, se ahorrara
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


//---------------------------------
//Este evento corresponde a agregar un nuevo evento para determinar que luces
//se encenderan o apagaran y en que fecha determinada
void Pantalla_Principal::on_Button_evento_agregar_pressed()
{
    agregarevento->show();
}


//---------------------------------
//Procedimiento para agregar eventos a las listas correspondientes de estados
void Pantalla_Principal::agregar_evento_lista()
{
    //Agregando datos a las listas correspondientes por evento
    Lista_Eventos_Fecha_Hora.append(pantalla_agregar_fecha_hora);
    Lista_Eventos_Luz_3.append(pantalla_agregar_luz_3);
    Lista_Eventos_Luz_4.append(pantalla_agregar_luz_4);
    Lista_Eventos_Luz_5.append(pantalla_agregar_luz_5);
    Lista_Eventos_Luz_6.append(pantalla_agregar_luz_6);
    Lista_Eventos_Luz_7.append(pantalla_agregar_luz_7);
    Lista_Eventos_Luz_8.append(pantalla_agregar_luz_8);
    Lista_Eventos_Ejecutado.append(false);

    //Declaracion de la variable del String para agregar los eventos a la lista del GUI
    QString listWidget_String;

    //Llamado a la funcion que convierte los eventos programados en un String
    listWidget_String = string_estatus_dispositivo(false);

    //El evento se agrega a la lista que se encuentra en la interfaz de usuario
    ui->listWidget->addItem(listWidget_String);

    /////////
    //Pruebas
    //fecha_hora_actuales = QDateTime::currentDateTime();
    //int tiempo_restante = Lista_Eventos_Fecha_Hora.last().secsTo(fecha_hora_actuales);
    //qDebug() << "Milisegundos hasta cumplirse: " << tiempo_restante;
    //Debug_Pruebas();
    //Pruebas
    /////////
}


//---------------------------------
//Procedimiento para eliminar eventos seleccionados en la lista
void Pantalla_Principal::on_Button_evento_eliminar_pressed()
{

    //Para evitar errores de ejecucion, este procedimiento unicamente se realiza
    //cuando la lista de eventos no esta vacia.

    if (!Lista_Eventos_Fecha_Hora.empty()){
    //Se elimina el elemento en la lista de fecha-hora de eventos
    Lista_Eventos_Fecha_Hora.removeAt(ui->listWidget->currentIndex().row());
    //Se eliminan los estados de las luces
    Lista_Eventos_Luz_3.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_4.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_5.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_6.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_7.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Luz_8.removeAt(ui->listWidget->currentIndex().row());
    Lista_Eventos_Ejecutado.removeAt(ui->listWidget->currentIndex().row());

    //Eliminacion del item de la lista del GUI
    ui->listWidget->currentItem()->~QListWidgetItem();

    /////////
    //Pruebas
    Debug_Pruebas();
    //Pruebas
    /////////
    }
}


//---------------------------------
//Codigo que permite guardar periodicamente el historial en la tarjeta SD
void Pantalla_Principal::agregar_entrada_historial(){

    QFile archivo;  //Creacion de un elemento QFile
    archivo.setFileName("/home/anthony/Desktop/historial.txt"); //Se configura el lugar del archivo y su nombre


    if(!archivo.exists())   //Si el archivo no existe...
    {
        archivo.open(QIODevice::WriteOnly | QIODevice::Text);  //Se abre un nuevo archivo
        QTextStream stream(&archivo);                          //Se conecta un stream a los a contener en el archivo
        stream << "Estatus del dispositivo durante las ultimas horas:\n\n"; //Se agrega un encabezado
        stream.flush();             //Se limpia la memoria utilizada por el stream
        archivo.close();            //Se cierra el archivo
    }

    else{                   //Si el archivo existe...

        archivo.open(QIODevice::ReadOnly | QIODevice::Text);//Se abre el archivo en modo lectura
        QTextStream stream(&archivo);                       //Se conecta el stream a los datos contenidos en el archivo
        QString string = stream.readAll(), string_estatus;  //Se crean dos strings: uno que obtiene los contenidos del archivo, otro que contiene el string de estatus actual
        string_estatus = string_estatus_dispositivo(true);  //Se obtiene es estado actual del dispositivo
        string = string + string_estatus + "\n";            //Se concatenan el string de los datos del archivo con los datos del nuevo estado
        stream.flush();                                     //Se limpia la memoria usada por el stream
        archivo.close();                                    //Se cierra el archivo
        archivo.open(QIODevice::WriteOnly | QIODevice::Text);//Se carga de nuevo el archivo pero esta vez en modo de escritura
        stream << string;                               //Se agregan los contenidos actualizados al archivo
        stream.flush();                                 //Se limpia de nuevo la memoria usada por el stream
        archivo.close();                                //Se cierra el archivo
    }
}


//---------------------------------
//Codigo de pruebas
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


//---------------------------------
//Codigo del boton que permite exportar una copia del historial a un dispositivo externo
//u otra locacion
void Pantalla_Principal::on_Button_Guardar_Historial_clicked()
{    

    QFile archivo, archivo_copia; //Se crean dos elementos: archivo y la copia del archivo
    archivo.setFileName("/home/anthony/Desktop/historial.txt");//Se configura el nombre del archivo original

    if(!archivo.exists())   //Si el historial no se encuentra o no existe...
    {
        //Se desplega un mensaje de informacion acerca del problema
        QMessageBox::information(this, "Precaucion", "No existen registros de historial para exportar");

    }
    else{                   //En caso de que exista historial...

        QString directorio_copia = QFileDialog::getExistingDirectory(
                    this, tr(""), "/mnt");                  //Se configura un cuadro de captura de directorios

        if (directorio_copia == ""){    //Si no se detecta ninguna direccion seleccionada, se procede a salir de la funcion
            return;
        }

        qDebug() << "Directorio Obtenido: " << directorio_copia;
        directorio_copia = directorio_copia + "/Copia_del_historial.txt"; //Se le agrega el nombre del archivo copia a la direccion obtenida

        //Se abre el archivo original para obtener los datos de historial
        archivo.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&archivo);
        QString string = stream.readAll();
        stream.flush();
        archivo.close();

        //Se escriben los datos del historial en el archivo copia
        archivo_copia.setFileName(directorio_copia);
        archivo_copia.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream_copia(&archivo_copia);
        stream_copia << string;
        stream_copia.flush();
        archivo_copia.close();
        //Se desplega un mensaje de informacion acerca de la copia exitosa del historial
        QMessageBox::information(this, "Mensaje", "Registro exportado exitosamente!");
        qDebug() << "Archivo Copiado!";

    }

}


//---------------------------------
//Funcion que devuelve un string de estatus para el historial o para la lista de eventos
//de la ventana principal
QString Pantalla_Principal::string_estatus_dispositivo(bool historial){

    //Si el modo historial se encuentra habilitado:
    if(historial){

            //Captura de la fecha y hora actuales
            fecha_hora_actuales = QDateTime::currentDateTime();

            //Construccion del String que se agregará en la lista del GUI de la pantalla principal
            QString out = "[Fecha: " + fecha_hora_actuales.toString("dd/MM/yyyy") + " -- Hora: "
                             + fecha_hora_actuales.toString("hh:mm:ss AP") + "]:\n";

            //Modo Historial, se toman en cuenta en el string los valores de las luces L1 y L2

            //String del estatus de la luz 1
            if (Status_Luz_1){
                    out = out + "\tLuz1: ON ";}
            else {
                    out = out + "\tLuz1: OFF";}

            //String del estatus de la luz 2
            if (Status_Luz_2){
                    out = out + " / Luz2: ON ";}
            else {
                    out = out + " / Luz2: OFF";}

            //String del estatus de la luz 3
            if (ui->Button_luz_3->isChecked()){
                out = out + " / Luz3: ON ";}
            else {
                out = out + " / Luz3: OFF";}

            //String del estatus de la luz 4
            if (ui->Button_luz_4->isChecked()){
                out = out + " / Luz4: ON ";}
            else {
                out = out + " / Luz4: OFF";}

            //String del estatus de la luz 5
            if (ui->Button_luz_5->isChecked()){
                out = out + " / Luz5: ON ";}
            else {
                out = out + " / Luz5: OFF";}

            //String del estatus de la luz 6
            if (ui->Button_luz_6->isChecked()){
                out = out + " / Luz6: ON ";}
            else {
                out = out + " / Luz6: OFF";}

            //String del estatus de la luz 7
            if (ui->Button_luz_7->isChecked()){
                out = out + " / Luz7: ON ";}
            else {
                out = out + " / Luz7: OFF";}

            //String del estatus de la luz 8
            out = out + " / Luz8: " + QString::number(ui->Slider_luz_8->value()) + "%";

            //Retorno del String resultante
            return out;
    }
    //Si el modo historial se encuentra deshabilitado (modo lista eventos):
    else{

            //Construccion del String que se agregará en la lista del GUI de la pantalla principal
            QString out = "Fecha: " + pantalla_agregar_fecha_hora.toString("dd/MM/yyyy") + " || Hora: "
                             + pantalla_agregar_fecha_hora.toString("hh:mm AP");

            //Modo Lista Eventos, NO se toman en cuenta en el string los valores de las luces L1 y L2

            //String del estatus de la luz 3
            if (pantalla_agregar_luz_3){
                out = out + " || Luz3: ON";}
            else {
                out = out + " || Luz3: OFF";}

            //String del estatus de la luz 4
            if (pantalla_agregar_luz_4){
                out = out + " || Luz4: ON";}
            else {
                out = out + " || Luz4: OFF";}

            //String del estatus de la luz 5
            if (pantalla_agregar_luz_5){
                out = out + " || Luz5: ON";}
            else {
                out = out + " || Luz5: OFF";}

            //String del estatus de la luz 6
            if (pantalla_agregar_luz_6){
                out = out + " || Luz6: ON";}
            else {
                out = out + " || Luz6: OFF";}

            //String del estatus de la luz 7
            if (pantalla_agregar_luz_7){
                out = out + " || Luz7: ON";}
            else {
                out = out + " || Luz7: OFF";}

            //String del estatus de la luz 8
            out = out + " || Luz8: " + QString::number(pantalla_agregar_luz_8) + "%";

            //Retorno del String resultante
            return out;
    }

}


//---------------------------------
//Boton que muestra la ventana del historial guardado en el equipo
void Pantalla_Principal::on_Button_Historial_clicked()
{
    QFile archivo; //Se crean el elemento archivo
    archivo.setFileName("/home/anthony/Desktop/historial.txt");//Se configura el nombre del archivo original

    if(!archivo.exists())   //Si el historial no se encuentra o no existe...
    {
        //Se desplega un mensaje de informacion acerca del problema
        QMessageBox::information(this, "Precaucion", "No existen registros de historial para observar");

    }
    else{                   //En caso de que exista historial...


        //Se abre el archivo original para obtener los datos de historial
        archivo.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&archivo);
        QString string = stream.readAll();
        stream.flush();
        archivo.close();

        //Se cargan los datos en la ventana y luego se muestra
        pantallahistorial->desplegar_historial(string);
        pantallahistorial->setWindowTitle("Historial");
        pantallahistorial->show();
    }
}


//---------------------------------
//Funcion que permite verificar y/o modificar el estado cuando es la hora de un evento
void Pantalla_Principal::revision_eventos(){

    /////////
    //Pruebas
    //int tiempo_restante = Lista_Eventos_Fecha_Hora.value(i).secsTo(fecha_hora_actuales);
    qDebug() << "-Metodo Revision-";
    //qDebug() << "Segundos Restantes: " << tiempo_restante;
    //Pruebas
    /////////


    //Este procedimiento unicamente se realiza cuando la lista de eventos no esta vacia.
    if (!Lista_Eventos_Fecha_Hora.empty()){

        for (int i=0; i <= Lista_Eventos_Fecha_Hora.count()-1 ;i++){

            fecha_hora_actuales = QDateTime::currentDateTime();

            int tiempo_restante = Lista_Eventos_Fecha_Hora.value(i).secsTo(fecha_hora_actuales);

            /////////
            //Pruebas
            qDebug() << "Segundos Restantes: " << tiempo_restante;
            qDebug() << "Index del evento: " << i;
            qDebug() << "Ejecutado?: " << Lista_Eventos_Ejecutado.value(i);
            //Pruebas
            /////////

            if((tiempo_restante > 0)&&(!Lista_Eventos_Ejecutado.value(i))){

                //Modificacion valor Luz 3
                if(Lista_Eventos_Luz_3.value(i)){
                   ui->Button_luz_3->setChecked(true);
                   ui->Button_luz_3->setText("ON");}
                else{
                    ui->Button_luz_3->setChecked(false);
                    ui->Button_luz_3->setText("OFF");}

                //Modificacion valor Luz 4
                if(Lista_Eventos_Luz_4.value(i)){
                   ui->Button_luz_4->setChecked(true);
                   ui->Button_luz_4->setText("ON");}
                else{
                    ui->Button_luz_4->setChecked(false);
                    ui->Button_luz_4->setText("OFF");}

                //Modificacion valor Luz 5
                if(Lista_Eventos_Luz_5.value(i)){
                   ui->Button_luz_5->setChecked(true);
                   ui->Button_luz_5->setText("ON");}
                else{
                    ui->Button_luz_5->setChecked(false);
                    ui->Button_luz_5->setText("OFF");}

                //Modificacion valor Luz 6
                if(Lista_Eventos_Luz_6.value(i)){
                   ui->Button_luz_6->setChecked(true);
                   ui->Button_luz_6->setText("ON");}
                else{
                    ui->Button_luz_6->setChecked(false);
                    ui->Button_luz_6->setText("OFF");}

                //Modificacion valor Luz 7
                if(Lista_Eventos_Luz_7.value(i)){
                   ui->Button_luz_7->setChecked(true);
                   ui->Button_luz_7->setText("ON");}
                else{
                    ui->Button_luz_7->setChecked(false);
                    ui->Button_luz_7->setText("OFF");}

                //Modificacion valor Luz 8
                ui->Slider_luz_8->setValue(Lista_Eventos_Luz_8.value(i));

                //Modificacion del valor de ejecutado del Elemento
                ui->listWidget->setCurrentRow(i);

                //Se elimina el elemento de la lista
                on_Button_evento_eliminar_pressed();

            }

        }


    }



}

