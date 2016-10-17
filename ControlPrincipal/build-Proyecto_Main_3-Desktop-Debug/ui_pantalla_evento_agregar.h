/********************************************************************************
** Form generated from reading UI file 'pantalla_evento_agregar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_EVENTO_AGREGAR_H
#define UI_PANTALLA_EVENTO_AGREGAR_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pantalla_evento_agregar
{
public:
    QWidget *centralwidget;
    QDateEdit *dateEdit_Fecha;
    QLabel *label_ventana2_Fecha;
    QTimeEdit *timeEdit_horas;
    QTimeEdit *timeEdit_minutos;
    QTimeEdit *timeEdit_AMPM;
    QLabel *label_ventana2_Fecha_2;
    QLabel *label_ventana2_Fecha_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox_Dias;
    QSpinBox *spinBox_Horas;
    QSpinBox *spinBox_Minutos;
    QPushButton *pushButton_Aceptar;
    QPushButton *pushButton_Cancelar;
    QLabel *label_luz_8_porcentaje;
    QLabel *label_luz_8;
    QSlider *Slider_luz_8;
    QLabel *label_luz_3;
    QPushButton *Button_luz_3;
    QLabel *label_luz_4;
    QPushButton *Button_luz_4;
    QLabel *label_luz_6;
    QLabel *label_luz_7;
    QPushButton *Button_luz_8;
    QPushButton *Button_luz_9;
    QPushButton *Button_luz_10;
    QLabel *label_luz_9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pantalla_evento_agregar)
    {
        if (pantalla_evento_agregar->objectName().isEmpty())
            pantalla_evento_agregar->setObjectName(QStringLiteral("pantalla_evento_agregar"));
        pantalla_evento_agregar->resize(410, 500);
        centralwidget = new QWidget(pantalla_evento_agregar);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        dateEdit_Fecha = new QDateEdit(centralwidget);
        dateEdit_Fecha->setObjectName(QStringLiteral("dateEdit_Fecha"));
        dateEdit_Fecha->setGeometry(QRect(39, 130, 121, 26));
        dateEdit_Fecha->setMaximumDateTime(QDateTime(QDate(7999, 1, 28), QTime(23, 59, 59)));
        dateEdit_Fecha->setMinimumDateTime(QDateTime(QDate(1816, 9, 30), QTime(0, 0, 0)));
        dateEdit_Fecha->setCalendarPopup(true);
        dateEdit_Fecha->setDate(QDate(2016, 10, 12));
        label_ventana2_Fecha = new QLabel(centralwidget);
        label_ventana2_Fecha->setObjectName(QStringLiteral("label_ventana2_Fecha"));
        label_ventana2_Fecha->setGeometry(QRect(46, 100, 111, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ventana2_Fecha->setFont(font);
        label_ventana2_Fecha->setAlignment(Qt::AlignCenter);
        timeEdit_horas = new QTimeEdit(centralwidget);
        timeEdit_horas->setObjectName(QStringLiteral("timeEdit_horas"));
        timeEdit_horas->setGeometry(QRect(180, 70, 51, 26));
        timeEdit_minutos = new QTimeEdit(centralwidget);
        timeEdit_minutos->setObjectName(QStringLiteral("timeEdit_minutos"));
        timeEdit_minutos->setGeometry(QRect(230, 70, 51, 26));
        timeEdit_AMPM = new QTimeEdit(centralwidget);
        timeEdit_AMPM->setObjectName(QStringLiteral("timeEdit_AMPM"));
        timeEdit_AMPM->setGeometry(QRect(280, 70, 71, 26));
        label_ventana2_Fecha_2 = new QLabel(centralwidget);
        label_ventana2_Fecha_2->setObjectName(QStringLiteral("label_ventana2_Fecha_2"));
        label_ventana2_Fecha_2->setGeometry(QRect(190, 40, 161, 20));
        label_ventana2_Fecha_2->setFont(font);
        label_ventana2_Fecha_2->setAlignment(Qt::AlignCenter);
        label_ventana2_Fecha_3 = new QLabel(centralwidget);
        label_ventana2_Fecha_3->setObjectName(QStringLiteral("label_ventana2_Fecha_3"));
        label_ventana2_Fecha_3->setGeometry(QRect(190, 110, 161, 20));
        label_ventana2_Fecha_3->setFont(font);
        label_ventana2_Fecha_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 140, 71, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 170, 71, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 200, 71, 17));
        spinBox_Dias = new QSpinBox(centralwidget);
        spinBox_Dias->setObjectName(QStringLiteral("spinBox_Dias"));
        spinBox_Dias->setGeometry(QRect(270, 140, 48, 26));
        spinBox_Dias->setMaximum(31);
        spinBox_Horas = new QSpinBox(centralwidget);
        spinBox_Horas->setObjectName(QStringLiteral("spinBox_Horas"));
        spinBox_Horas->setGeometry(QRect(270, 170, 48, 26));
        spinBox_Horas->setMaximum(23);
        spinBox_Minutos = new QSpinBox(centralwidget);
        spinBox_Minutos->setObjectName(QStringLiteral("spinBox_Minutos"));
        spinBox_Minutos->setGeometry(QRect(270, 200, 48, 26));
        spinBox_Minutos->setMaximum(59);
        pushButton_Aceptar = new QPushButton(centralwidget);
        pushButton_Aceptar->setObjectName(QStringLiteral("pushButton_Aceptar"));
        pushButton_Aceptar->setGeometry(QRect(20, 440, 180, 25));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_Aceptar->setFont(font1);
        pushButton_Cancelar = new QPushButton(centralwidget);
        pushButton_Cancelar->setObjectName(QStringLiteral("pushButton_Cancelar"));
        pushButton_Cancelar->setGeometry(QRect(210, 440, 180, 25));
        pushButton_Cancelar->setFont(font1);
        label_luz_8_porcentaje = new QLabel(centralwidget);
        label_luz_8_porcentaje->setObjectName(QStringLiteral("label_luz_8_porcentaje"));
        label_luz_8_porcentaje->setGeometry(QRect(320, 370, 51, 31));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_luz_8_porcentaje->setFont(font2);
        label_luz_8_porcentaje->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_luz_8 = new QLabel(centralwidget);
        label_luz_8->setObjectName(QStringLiteral("label_luz_8"));
        label_luz_8->setGeometry(QRect(30, 370, 111, 31));
        label_luz_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Slider_luz_8 = new QSlider(centralwidget);
        Slider_luz_8->setObjectName(QStringLiteral("Slider_luz_8"));
        Slider_luz_8->setGeometry(QRect(150, 380, 161, 16));
        Slider_luz_8->setMaximum(100);
        Slider_luz_8->setOrientation(Qt::Horizontal);
        label_luz_3 = new QLabel(centralwidget);
        label_luz_3->setObjectName(QStringLiteral("label_luz_3"));
        label_luz_3->setGeometry(QRect(20, 260, 51, 31));
        label_luz_3->setAlignment(Qt::AlignCenter);
        Button_luz_3 = new QPushButton(centralwidget);
        Button_luz_3->setObjectName(QStringLiteral("Button_luz_3"));
        Button_luz_3->setGeometry(QRect(20, 290, 51, 61));
        Button_luz_3->setFont(font1);
        Button_luz_3->setCheckable(true);
        Button_luz_3->setChecked(false);
        label_luz_4 = new QLabel(centralwidget);
        label_luz_4->setObjectName(QStringLiteral("label_luz_4"));
        label_luz_4->setGeometry(QRect(100, 260, 51, 31));
        label_luz_4->setAlignment(Qt::AlignCenter);
        Button_luz_4 = new QPushButton(centralwidget);
        Button_luz_4->setObjectName(QStringLiteral("Button_luz_4"));
        Button_luz_4->setGeometry(QRect(100, 290, 51, 61));
        Button_luz_4->setFont(font1);
        Button_luz_4->setCheckable(true);
        Button_luz_4->setChecked(false);
        label_luz_6 = new QLabel(centralwidget);
        label_luz_6->setObjectName(QStringLiteral("label_luz_6"));
        label_luz_6->setGeometry(QRect(260, 260, 51, 31));
        label_luz_6->setAlignment(Qt::AlignCenter);
        label_luz_7 = new QLabel(centralwidget);
        label_luz_7->setObjectName(QStringLiteral("label_luz_7"));
        label_luz_7->setGeometry(QRect(340, 260, 51, 31));
        label_luz_7->setAlignment(Qt::AlignCenter);
        Button_luz_8 = new QPushButton(centralwidget);
        Button_luz_8->setObjectName(QStringLiteral("Button_luz_8"));
        Button_luz_8->setGeometry(QRect(260, 290, 51, 61));
        Button_luz_8->setFont(font1);
        Button_luz_8->setCheckable(true);
        Button_luz_8->setChecked(false);
        Button_luz_9 = new QPushButton(centralwidget);
        Button_luz_9->setObjectName(QStringLiteral("Button_luz_9"));
        Button_luz_9->setGeometry(QRect(340, 290, 51, 61));
        Button_luz_9->setFont(font1);
        Button_luz_9->setCheckable(true);
        Button_luz_9->setChecked(false);
        Button_luz_10 = new QPushButton(centralwidget);
        Button_luz_10->setObjectName(QStringLiteral("Button_luz_10"));
        Button_luz_10->setGeometry(QRect(180, 290, 51, 61));
        Button_luz_10->setFont(font1);
        Button_luz_10->setCheckable(true);
        Button_luz_10->setChecked(false);
        label_luz_9 = new QLabel(centralwidget);
        label_luz_9->setObjectName(QStringLiteral("label_luz_9"));
        label_luz_9->setGeometry(QRect(180, 260, 51, 31));
        label_luz_9->setAlignment(Qt::AlignCenter);
        pantalla_evento_agregar->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(pantalla_evento_agregar);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        pantalla_evento_agregar->setStatusBar(statusbar);

        retranslateUi(pantalla_evento_agregar);

        QMetaObject::connectSlotsByName(pantalla_evento_agregar);
    } // setupUi

    void retranslateUi(QMainWindow *pantalla_evento_agregar)
    {
        pantalla_evento_agregar->setWindowTitle(QApplication::translate("pantalla_evento_agregar", "MainWindow", 0));
        dateEdit_Fecha->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "dd/MM/yyyy", 0));
        label_ventana2_Fecha->setText(QApplication::translate("pantalla_evento_agregar", "Fecha", 0));
        timeEdit_horas->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "hh", 0));
        timeEdit_minutos->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "mm", 0));
        timeEdit_AMPM->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "AP", 0));
        label_ventana2_Fecha_2->setText(QApplication::translate("pantalla_evento_agregar", "Hora", 0));
        label_ventana2_Fecha_3->setText(QApplication::translate("pantalla_evento_agregar", "Duracion", 0));
        label->setText(QApplication::translate("pantalla_evento_agregar", "Dias:", 0));
        label_2->setText(QApplication::translate("pantalla_evento_agregar", "Horas:", 0));
        label_3->setText(QApplication::translate("pantalla_evento_agregar", "Minutos:", 0));
        pushButton_Aceptar->setText(QApplication::translate("pantalla_evento_agregar", "ACEPTAR", 0));
        pushButton_Cancelar->setText(QApplication::translate("pantalla_evento_agregar", "CANCELAR", 0));
        label_luz_8_porcentaje->setText(QApplication::translate("pantalla_evento_agregar", "0%", 0));
        label_luz_8->setText(QApplication::translate("pantalla_evento_agregar", "Luz 8", 0));
        label_luz_3->setText(QApplication::translate("pantalla_evento_agregar", "Luz 3", 0));
        Button_luz_3->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_4->setText(QApplication::translate("pantalla_evento_agregar", "Luz 4", 0));
        Button_luz_4->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_6->setText(QApplication::translate("pantalla_evento_agregar", "Luz 6", 0));
        label_luz_7->setText(QApplication::translate("pantalla_evento_agregar", "Luz 7", 0));
        Button_luz_8->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        Button_luz_9->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        Button_luz_10->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_9->setText(QApplication::translate("pantalla_evento_agregar", "Luz 5", 0));
    } // retranslateUi

};

namespace Ui {
    class pantalla_evento_agregar: public Ui_pantalla_evento_agregar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_EVENTO_AGREGAR_H
