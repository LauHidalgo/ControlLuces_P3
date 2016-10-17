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

private:
    Ui::pantalla_evento_agregar *ui;
};

#endif // PANTALLA_EVENTO_AGREGAR_H
