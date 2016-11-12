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

//Nota: Código tomado de la página web oficial del entorno de desarrollo
//Qt. este código fue modificado para adaptarlo a los requerimientos de
//la solución planteada.

#include <QtNetwork>
#include <QtWidgets>
#include "pantalla_principal.h"
#include <QDebug>


class MyTCPServer:public QTcpServer
{
  Q_OBJECT
public:
  QString recibido;


  //---------------------------------
  //Codigo que se ejecuta cuando se crea un objeto nuevo MyTCPServer
  MyTCPServer()
  {
    //Se inicializa esta clase, conectando la señal de nuevas conexiones a la funci{on que
    //registrara y manejara estas nuevas conexiones
    connect(this,SIGNAL(newConnection()),SLOT(slotNewConnection()));    
  }
  
public slots:

  //---------------------------------
  //Funcion que maneja las nuevas conexiones
  void slotNewConnection()
  {
    //Está en espera de nuevas conexiones en el socket de red
    connection = nextPendingConnection();
    //Conecta la señal de los datos recien llegados a la funcion de manejo de los datos recibidos
    connect(connection,SIGNAL(readyRead()),SLOT(readData()));
   }
  

  //---------------------------------
  //Funcion que analiza los datos recibidos
  void readData()
  {
      //Se cargan los caracteres recibidos al string
      recibido = QString(connection->readAll());


      //Las acciones que se deben realizar en el programa principal
      //(Pantalla Principal) segun la letra recibida, emiten a la clase principal
      //una señal para que se ejecute la accion deseada
      if(recibido =="a"){emit luz_3_off();}
      else if(recibido == "A"){emit luz_3_on();}
      else if(recibido == "b"){emit luz_4_off();}
      else if(recibido == "B"){emit luz_4_on();}
      else if(recibido == "c"){emit luz_5_off();}
      else if(recibido == "C"){emit luz_5_on();}
      else if(recibido == "d"){emit luz_6_off();}
      else if(recibido == "D"){emit luz_6_on();}
      else if(recibido == "e"){emit luz_7_off();}
      else if(recibido == "E"){emit luz_7_on();}
      //Si no coincide la letra con alguna accion especifica, se limpia el buffer de datos recibidos
      else{connection->flush();}
  }

private:
  QTcpSocket* connection;

//Señales que se emitirán hacia la ventana principal para
//las acciones deseadas
signals:
    void luz_3_on();
    void luz_3_off();
    void luz_4_on();
    void luz_4_off();
    void luz_5_on();
    void luz_5_off();
    void luz_6_on();
    void luz_6_off();
    void luz_7_on();
    void luz_7_off();
};
