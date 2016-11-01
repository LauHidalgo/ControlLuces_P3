#ifndef PANTALLA_HISTORIAL_H
#define PANTALLA_HISTORIAL_H

#include <QDialog>

namespace Ui {
class pantalla_historial;
}

class pantalla_historial : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_historial(QWidget *parent = 0);
    ~pantalla_historial();
    Ui::pantalla_historial *ui;
    void desplegar_historial(QString datos);
private slots:
    void on_pushButton_Historial_Aceptar_clicked();
};

#endif // PANTALLA_HISTORIAL_H
