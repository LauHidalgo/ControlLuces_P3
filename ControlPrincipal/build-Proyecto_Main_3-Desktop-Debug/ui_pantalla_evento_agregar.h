/********************************************************************************
** Form generated from reading UI file 'pantalla_evento_agregar.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
    QLabel *label_ventana2_Fecha_2;
    QPushButton *pushButton_Aceptar;
    QPushButton *pushButton_Cancelar;
    QLabel *label_luz_8_porcentaje_2;
    QLabel *label_luz_8;
    QSlider *Slider_luz_8_2;
    QLabel *label_luz_3;
    QPushButton *Button_luz_3_2;
    QLabel *label_luz_4;
    QPushButton *Button_luz_4_2;
    QLabel *label_luz_6;
    QLabel *label_luz_7;
    QPushButton *Button_luz_6_2;
    QPushButton *Button_luz_7_2;
    QPushButton *Button_luz_5_2;
    QLabel *label_luz_9;
    QTimeEdit *timeEdit;
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
        dateEdit_Fecha->setGeometry(QRect(39, 120, 121, 26));
        dateEdit_Fecha->setMaximumDateTime(QDateTime(QDate(7999, 1, 28), QTime(23, 59, 59)));
        dateEdit_Fecha->setMinimumDateTime(QDateTime(QDate(1816, 9, 30), QTime(0, 0, 0)));
        dateEdit_Fecha->setCalendarPopup(true);
        dateEdit_Fecha->setDate(QDate(2016, 10, 12));
        label_ventana2_Fecha = new QLabel(centralwidget);
        label_ventana2_Fecha->setObjectName(QStringLiteral("label_ventana2_Fecha"));
        label_ventana2_Fecha->setGeometry(QRect(46, 70, 111, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_ventana2_Fecha->setFont(font);
        label_ventana2_Fecha->setAlignment(Qt::AlignCenter);
        label_ventana2_Fecha_2 = new QLabel(centralwidget);
        label_ventana2_Fecha_2->setObjectName(QStringLiteral("label_ventana2_Fecha_2"));
        label_ventana2_Fecha_2->setGeometry(QRect(210, 70, 131, 20));
        label_ventana2_Fecha_2->setFont(font);
        label_ventana2_Fecha_2->setAlignment(Qt::AlignCenter);
        pushButton_Aceptar = new QPushButton(centralwidget);
        pushButton_Aceptar->setObjectName(QStringLiteral("pushButton_Aceptar"));
        pushButton_Aceptar->setGeometry(QRect(20, 420, 180, 25));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_Aceptar->setFont(font1);
        pushButton_Cancelar = new QPushButton(centralwidget);
        pushButton_Cancelar->setObjectName(QStringLiteral("pushButton_Cancelar"));
        pushButton_Cancelar->setGeometry(QRect(210, 420, 180, 25));
        pushButton_Cancelar->setFont(font1);
        label_luz_8_porcentaje_2 = new QLabel(centralwidget);
        label_luz_8_porcentaje_2->setObjectName(QStringLiteral("label_luz_8_porcentaje_2"));
        label_luz_8_porcentaje_2->setGeometry(QRect(320, 350, 51, 31));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_luz_8_porcentaje_2->setFont(font2);
        label_luz_8_porcentaje_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_luz_8 = new QLabel(centralwidget);
        label_luz_8->setObjectName(QStringLiteral("label_luz_8"));
        label_luz_8->setGeometry(QRect(30, 350, 111, 31));
        label_luz_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Slider_luz_8_2 = new QSlider(centralwidget);
        Slider_luz_8_2->setObjectName(QStringLiteral("Slider_luz_8_2"));
        Slider_luz_8_2->setGeometry(QRect(150, 360, 161, 16));
        Slider_luz_8_2->setMaximum(100);
        Slider_luz_8_2->setOrientation(Qt::Horizontal);
        label_luz_3 = new QLabel(centralwidget);
        label_luz_3->setObjectName(QStringLiteral("label_luz_3"));
        label_luz_3->setGeometry(QRect(20, 210, 51, 31));
        label_luz_3->setAlignment(Qt::AlignCenter);
        Button_luz_3_2 = new QPushButton(centralwidget);
        Button_luz_3_2->setObjectName(QStringLiteral("Button_luz_3_2"));
        Button_luz_3_2->setGeometry(QRect(20, 250, 51, 61));
        Button_luz_3_2->setFont(font1);
        Button_luz_3_2->setCheckable(true);
        Button_luz_3_2->setChecked(false);
        label_luz_4 = new QLabel(centralwidget);
        label_luz_4->setObjectName(QStringLiteral("label_luz_4"));
        label_luz_4->setGeometry(QRect(100, 210, 51, 31));
        label_luz_4->setAlignment(Qt::AlignCenter);
        Button_luz_4_2 = new QPushButton(centralwidget);
        Button_luz_4_2->setObjectName(QStringLiteral("Button_luz_4_2"));
        Button_luz_4_2->setGeometry(QRect(100, 250, 51, 61));
        Button_luz_4_2->setFont(font1);
        Button_luz_4_2->setCheckable(true);
        Button_luz_4_2->setChecked(false);
        label_luz_6 = new QLabel(centralwidget);
        label_luz_6->setObjectName(QStringLiteral("label_luz_6"));
        label_luz_6->setGeometry(QRect(260, 210, 51, 31));
        label_luz_6->setAlignment(Qt::AlignCenter);
        label_luz_7 = new QLabel(centralwidget);
        label_luz_7->setObjectName(QStringLiteral("label_luz_7"));
        label_luz_7->setGeometry(QRect(340, 210, 51, 31));
        label_luz_7->setAlignment(Qt::AlignCenter);
        Button_luz_6_2 = new QPushButton(centralwidget);
        Button_luz_6_2->setObjectName(QStringLiteral("Button_luz_6_2"));
        Button_luz_6_2->setGeometry(QRect(260, 250, 51, 61));
        Button_luz_6_2->setFont(font1);
        Button_luz_6_2->setCheckable(true);
        Button_luz_6_2->setChecked(false);
        Button_luz_7_2 = new QPushButton(centralwidget);
        Button_luz_7_2->setObjectName(QStringLiteral("Button_luz_7_2"));
        Button_luz_7_2->setGeometry(QRect(340, 250, 51, 61));
        Button_luz_7_2->setFont(font1);
        Button_luz_7_2->setCheckable(true);
        Button_luz_7_2->setChecked(false);
        Button_luz_5_2 = new QPushButton(centralwidget);
        Button_luz_5_2->setObjectName(QStringLiteral("Button_luz_5_2"));
        Button_luz_5_2->setGeometry(QRect(180, 250, 51, 61));
        Button_luz_5_2->setFont(font1);
        Button_luz_5_2->setCheckable(true);
        Button_luz_5_2->setChecked(false);
        label_luz_9 = new QLabel(centralwidget);
        label_luz_9->setObjectName(QStringLiteral("label_luz_9"));
        label_luz_9->setGeometry(QRect(180, 210, 51, 31));
        label_luz_9->setAlignment(Qt::AlignCenter);
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(210, 120, 131, 26));
        pantalla_evento_agregar->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(pantalla_evento_agregar);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        pantalla_evento_agregar->setStatusBar(statusbar);

        retranslateUi(pantalla_evento_agregar);

        QMetaObject::connectSlotsByName(pantalla_evento_agregar);
    } // setupUi

    void retranslateUi(QMainWindow *pantalla_evento_agregar)
    {
        pantalla_evento_agregar->setWindowTitle(QApplication::translate("pantalla_evento_agregar", "Nuevo Evento", 0));
        dateEdit_Fecha->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "dd/MM/yyyy", 0));
        label_ventana2_Fecha->setText(QApplication::translate("pantalla_evento_agregar", "Fecha", 0));
        label_ventana2_Fecha_2->setText(QApplication::translate("pantalla_evento_agregar", "Hora", 0));
        pushButton_Aceptar->setText(QApplication::translate("pantalla_evento_agregar", "ACEPTAR", 0));
        pushButton_Cancelar->setText(QApplication::translate("pantalla_evento_agregar", "CANCELAR", 0));
        label_luz_8_porcentaje_2->setText(QApplication::translate("pantalla_evento_agregar", "0%", 0));
        label_luz_8->setText(QApplication::translate("pantalla_evento_agregar", "Luz 8", 0));
        label_luz_3->setText(QApplication::translate("pantalla_evento_agregar", "Luz 3", 0));
        Button_luz_3_2->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_4->setText(QApplication::translate("pantalla_evento_agregar", "Luz 4", 0));
        Button_luz_4_2->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_6->setText(QApplication::translate("pantalla_evento_agregar", "Luz 6", 0));
        label_luz_7->setText(QApplication::translate("pantalla_evento_agregar", "Luz 7", 0));
        Button_luz_6_2->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        Button_luz_7_2->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        Button_luz_5_2->setText(QApplication::translate("pantalla_evento_agregar", "OFF", 0));
        label_luz_9->setText(QApplication::translate("pantalla_evento_agregar", "Luz 5", 0));
        timeEdit->setDisplayFormat(QApplication::translate("pantalla_evento_agregar", "hh:mm AP", 0));
    } // retranslateUi

};

namespace Ui {
    class pantalla_evento_agregar: public Ui_pantalla_evento_agregar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_EVENTO_AGREGAR_H
