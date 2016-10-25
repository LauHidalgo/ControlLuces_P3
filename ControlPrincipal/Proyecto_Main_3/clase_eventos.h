#ifndef CLASE_EVENTOS_H
#define CLASE_EVENTOS_H

#include <QObject>

class clase_eventos
{
public:

    //Definicion de variables publicas pertenecientes a la clase evento

    clase_eventos();                                    //Creacion de la clase eventos
    QString meridiano;                                  //Hora se encuentra en "am" o "pm"
    int dia, mes, year, hora, minutos;                  //Variables de fecha y hora del evento
    int luz3, luz4, luz5, luz6, luz7, luz8;             //Estatus deseado para las luces en el momento del evento



};

#endif // CLASE_EVENTOS_H
