#ifndef PANTALLA_EVENTO_AGREGAR_H
#define PANTALLA_EVENTO_AGREGAR_H

#include <QMainWindow>

namespace Ui {
class pantalla_evento_agregar;
}

class pantalla_evento_agregar : public QMainWindow
{
    Q_OBJECT

public:
    explicit pantalla_evento_agregar(QWidget *parent = 0);
    ~pantalla_evento_agregar();

public slots:
    void on_Button_luz_3_2_pressed();

    void on_Button_luz_4_2_pressed();

    void on_Button_luz_5_2_pressed();

    void on_Button_luz_6_2_pressed();

    void on_Button_luz_7_2_pressed();

    void on_Slider_luz_8_2_valueChanged(int value);

    void on_pushButton_Aceptar_pressed();

    void on_pushButton_Cancelar_pressed();

private:
    Ui::pantalla_evento_agregar *ui;

signals:
    void ventana_cerrar();
};

#endif // PANTALLA_EVENTO_AGREGAR_H
