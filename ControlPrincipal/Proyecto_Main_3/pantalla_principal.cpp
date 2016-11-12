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

//=======================================================================//
//      Librerias a utilizar
//=======================================================================//
//Clase local
#include "pantalla_principal.h"
#include "ui_pantalla_principal.h"
//Clases externas
#include "pantalla_evento_agregar.h"
#include "pantalla_historial.h"
#include "myTCPServer.h"
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
#include <QTcpServer>
#include <QTcpSocket>
//Librerias de funcionalidades wiringPi
#include <wiringPi.h>
#include <softPwm.h>



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
QTimer *entradas_salidas;

//Creando el servidor TCP
MyTCPServer *server;




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
    timer_historial->start(30000);   //Periodos en milisegundos para actualizar

    //Conexion de la senal de revision de eventos y actualizacion del reloj
    //de la pantalla principal al timer correspondiente
    ejecucion_eventos = new QTimer();
    connect(ejecucion_eventos,SIGNAL(timeout()),this,SLOT(revision_eventos()));
    connect(ejecucion_eventos,SIGNAL(timeout()),this,SLOT(actualizar_reloj()));
    ejecucion_eventos->start(1000);

    //Conexion de la senal de entradas y salidas con la interaccion externa
    entradas_salidas = new QTimer();
    connect(entradas_salidas,SIGNAL(timeout()),this,SLOT(interaccion_entradas_salidas()));
    entradas_salidas->start(250);

    //Raspberry WiringPi>
    //Configurando los pines de salida de las luces
    wiringPiSetup();
    pinMode(2,OUTPUT);  //BCM: 27 - GPIOwPi  - Luz 8 PWM
    pinMode(25,OUTPUT); //BCM: 26 - GPIOwPi  - Luz 7 LED
    pinMode(6,OUTPUT);  //BCM: 25 - GPIOwPi  - Luz 6 LED
    pinMode(5,OUTPUT);  //BCM: 24 - GPIOwPi  - Luz 5 LED
    pinMode(4,OUTPUT);  //BCM: 23 - GPIOwPi  - Luz 4 LED
    pinMode(3,OUTPUT);  //BCM: 22 - GPIOwPi  - Luz 3 LED
    pinMode(29,INPUT);  //BCM: 21 - GPIOwPi  - Luz 1/2 Fotoresistencia
    softPwmCreate(2,0,100); //Declaracion del pin 16 BCM (GPIO 27) como pin PWM para la Luz 8



    //Creacion del objeto server
    server = new MyTCPServer();

    //Se esperan request desde cualquier direccion IP de la red, al puerto 9500
    if(!server->listen(QHostAddress::Any,9500))
    {
      QMessageBox::warning(NULL,"Error","Error Listening Port 9500!");
    }

    //Se conectan las señales emitidas por el servidor (class myTCPserver) a las funciones de encender o apagar   
    connect(server,SIGNAL(luz_3_off()),this,SLOT(tcp_cambio_luz_3_off()));
    connect(server,SIGNAL(luz_3_on()),this,SLOT(tcp_cambio_luz_3_on()));
    connect(server,SIGNAL(luz_4_off()),this,SLOT(tcp_cambio_luz_4_off()));
    connect(server,SIGNAL(luz_4_on()),this,SLOT(tcp_cambio_luz_4_on()));
    connect(server,SIGNAL(luz_5_off()),this,SLOT(tcp_cambio_luz_5_off()));
    connect(server,SIGNAL(luz_5_on()),this,SLOT(tcp_cambio_luz_5_on()));
    connect(server,SIGNAL(luz_6_off()),this,SLOT(tcp_cambio_luz_6_off()));
    connect(server,SIGNAL(luz_6_on()),this,SLOT(tcp_cambio_luz_6_on()));
    connect(server,SIGNAL(luz_7_off()),this,SLOT(tcp_cambio_luz_7_off()));
    connect(server,SIGNAL(luz_7_on()),this,SLOT(tcp_cambio_luz_7_on()));

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
//Estas funciones cambian el estado de los botones, segun las señales emitidas por el socket de red
void Pantalla_Principal::tcp_cambio_luz_3_off(){
    ui->Button_luz_3->setChecked(false);
    ui->Button_luz_3->setText("OFF");   //cambia a OFF
}
void Pantalla_Principal::tcp_cambio_luz_3_on(){
    ui->Button_luz_3->setChecked(true);
    ui->Button_luz_3->setText("ON");    //cambia a ON
}
void Pantalla_Principal::tcp_cambio_luz_4_off(){
    ui->Button_luz_4->setChecked(false);
    ui->Button_luz_4->setText("OFF");   //cambia a OFF
}
void Pantalla_Principal::tcp_cambio_luz_4_on(){
    ui->Button_luz_4->setChecked(true);
    ui->Button_luz_4->setText("ON");    //cambia a ON
}
void Pantalla_Principal::tcp_cambio_luz_5_off(){
    ui->Button_luz_5->setChecked(false);
    ui->Button_luz_5->setText("OFF");   //cambia a OFF
}
void Pantalla_Principal::tcp_cambio_luz_5_on(){
    ui->Button_luz_5->setChecked(true);
    ui->Button_luz_5->setText("ON");    //cambia a ON
}
void Pantalla_Principal::tcp_cambio_luz_6_off(){
    ui->Button_luz_6->setChecked(false);
    ui->Button_luz_6->setText("OFF");   //cambia a OFF
}
void Pantalla_Principal::tcp_cambio_luz_6_on(){
    ui->Button_luz_6->setChecked(true);
    ui->Button_luz_6->setText("ON");    //cambia a ON
}
void Pantalla_Principal::tcp_cambio_luz_7_off(){
    ui->Button_luz_7->setChecked(false);
    ui->Button_luz_7->setText("OFF");   //cambia a OFF
}
void Pantalla_Principal::tcp_cambio_luz_7_on(){
    ui->Button_luz_7->setChecked(true);
    ui->Button_luz_7->setText("ON");    //cambia a ON
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

    //Declaracion de la variable del String para agregar los eventos a la lista del GUI
    QString listWidget_String;

    //Llamado a la funcion que convierte los eventos programados en un String
    listWidget_String = string_estatus_dispositivo(false);

    //El evento se agrega a la lista que se encuentra en la interfaz de usuario
    ui->listWidget->addItem(listWidget_String);

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

    //Eliminacion del item de la lista del GUI
    ui->listWidget->currentItem()->~QListWidgetItem();

    }
}


//---------------------------------
//Codigo que permite guardar periodicamente el historial en la tarjeta SD
void Pantalla_Principal::agregar_entrada_historial(){

    QFile archivo;  //Creacion de un elemento QFile
    archivo.setFileName("/home/pi/Desktop/historial.txt"); //Se configura el lugar del archivo y su nombre


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
//Codigo del boton que permite exportar una copia del historial a un dispositivo externo
//u otra locacion
void Pantalla_Principal::on_Button_Guardar_Historial_clicked()
{    

    QFile archivo, archivo_copia; //Se crean dos elementos: archivo y la copia del archivo
    archivo.setFileName("/home/pi/Desktop/historial.txt");//Se configura el nombre del archivo original

    if(!archivo.exists())   //Si el historial no se encuentra o no existe...
    {
        //Se desplega un mensaje de informacion acerca del problema
        QMessageBox::information(this, "Precaucion", "No existen registros de historial para exportar");

    }
    else{                   //En caso de que exista historial...

        QString directorio_copia = QFileDialog::getExistingDirectory(
                    this, tr(""), "/media/pi");                  //Se configura un cuadro de captura de directorios

        if (directorio_copia == ""){    //Si no se detecta ninguna direccion seleccionada, se procede a salir de la funcion
            return;
        }

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
    archivo.setFileName("/home/pi/Desktop/historial.txt");//Se configura el nombre del archivo original

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

    //Este procedimiento unicamente se realiza cuando la lista de eventos no esta vacia.
    if (!Lista_Eventos_Fecha_Hora.empty()){

        for (int i=0; i <= Lista_Eventos_Fecha_Hora.count()-1 ;i++){

            fecha_hora_actuales = QDateTime::currentDateTime();

            int tiempo_restante = Lista_Eventos_Fecha_Hora.value(i).secsTo(fecha_hora_actuales);

            if(tiempo_restante > 0){

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
                ui->Slider_luz_8->setValue(100-Lista_Eventos_Luz_8.value(i));

                //Se elige la columna del evento para eliminarlo
                ui->listWidget->setCurrentRow(i);

                //Se elimina el elemento de la lista
                on_Button_evento_eliminar_pressed();

            }
        }
    }
}



//---------------------------------
//Funcion que permite actualizar el reloj que se encuentra en la pantalla principal
void Pantalla_Principal::actualizar_reloj(){

    //Captura de la fecha y hora actuales
    fecha_hora_actuales = QDateTime::currentDateTime();

    //Construccion del String que se agregará en la lista del GUI de la pantalla principal
    QString texto = fecha_hora_actuales.toString("dd/MM/yyyy") + " -- "
                     + fecha_hora_actuales.toString("hh:mm:ss ap");

    //Cambio del texto a la etiqueta correspondiente a la hora
    ui->label_hora_actual->setText(texto);
}


//---------------------------------
//Funcion que permite interactuar con las entradas/salidas del sistema embebido raspberry (no disponible)
void Pantalla_Principal::interaccion_entradas_salidas(){

    //Lectura del estado de la fotoresistencia
    if(digitalRead(29)==1){ui->label_luz_11->setText("Encendido");}
    else{ui->label_luz_11->setText("Apagado");}

    //Encendido Luz 3
    if(ui->Button_luz_3->isChecked()){digitalWrite(3,1);}
    //Apagado Luz 3
    else{digitalWrite(3,0);}

    //Encendido Luz 4
    if(ui->Button_luz_4->isChecked()){digitalWrite(4,1);}
    //Apagado Luz 4
    else{digitalWrite(4,0);}

    //Encendido Luz 5
    if(ui->Button_luz_5->isChecked()){digitalWrite(5,1);}
    //Apagado Luz 5
    else{digitalWrite(5,0);}

    //Encendido Luz 6
    if(ui->Button_luz_6->isChecked()){digitalWrite(6,1);}
    //Apagado Luz 6
    else{digitalWrite(6,0);}

    //Encendido Luz 7
    if(ui->Button_luz_7->isChecked()){digitalWrite(25,1);}
    //Apagado Luz 7
    else{digitalWrite(25,0);}

    //Asignando valor al PWM Luz 8
    softPwmWrite(2, 100-ui->Slider_luz_8->value());
}







