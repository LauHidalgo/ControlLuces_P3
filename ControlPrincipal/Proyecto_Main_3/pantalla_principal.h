#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class Pantalla_Principal;
}

class Pantalla_Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pantalla_Principal(QWidget *parent = 0);
    ~Pantalla_Principal();

private slots:

    //Cambio de estado en los botones/sliders que encienden/apagan las
    //luces en el modo mmanual
    void on_Button_luz_3_pressed();
    void on_Button_luz_4_pressed();
    void on_Button_luz_5_pressed();
    void on_Button_luz_6_pressed();
    void on_Button_luz_7_pressed();
    void on_Slider_luz_8_valueChanged(int value);


    void on_Button_evento_agregar_pressed();

private:
    Ui::Pantalla_Principal *ui;
};

#endif // PANTALLA_PRINCIPAL_H