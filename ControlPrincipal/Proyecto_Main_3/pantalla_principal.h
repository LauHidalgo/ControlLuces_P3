#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QSharedPointer>

namespace Ui {
class Pantalla_Principal;
}

class Pantalla_Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla_Principal(QWidget *parent = 0 );
    ~Pantalla_Principal();

    void inicializacion_pantalla_principal();

    Ui::Pantalla_Principal *ui;


public slots:

    //Cambio de estado en los botones/sliders que encienden/apagan las
    //luces en el modo mmanual
    void on_Button_luz_3_pressed();
    void on_Button_luz_4_pressed();
    void on_Button_luz_5_pressed();
    void on_Button_luz_6_pressed();
    void on_Button_luz_7_pressed();
    void on_Slider_luz_8_valueChanged(int value);

    void on_Button_evento_agregar_pressed();
    void on_Button_evento_eliminar_pressed();

    void agregar_evento_lista();
    void agregar_entrada_historial();
    void revision_eventos();
    //void guardado_eventos();

    QString string_estatus_dispositivo(bool historial);

    void Debug_Pruebas();




private slots:
    void on_Button_Guardar_Historial_clicked();
    void on_Button_Historial_clicked();
};

#endif // PANTALLA_PRINCIPAL_H
