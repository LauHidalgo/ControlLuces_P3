/********************************************************************************
** Form generated from reading UI file 'pantalla_principal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_PRINCIPAL_H
#define UI_PANTALLA_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pantalla_Principal
{
public:
    QWidget *centralWidget;
    QPushButton *Button_luz_3;
    QLabel *label_luz_3;
    QLabel *label_luz_4;
    QPushButton *Button_luz_4;
    QLabel *label_luz_5;
    QPushButton *Button_luz_5;
    QLabel *label_luz_6;
    QPushButton *Button_luz_6;
    QLabel *label_luz_7;
    QPushButton *Button_luz_7;
    QLabel *label_luz_8;
    QSlider *Slider_luz_8;
    QLabel *label_luz_8_porcentaje;
    QLabel *label_luz_10;
    QLabel *label_luz_11;
    QLabel *label_eventos;
    QLabel *label_status_luces;
    QPushButton *Button_evento_agregar;
    QTableView *tableView_eventos;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pantalla_Principal)
    {
        if (Pantalla_Principal->objectName().isEmpty())
            Pantalla_Principal->setObjectName(QStringLiteral("Pantalla_Principal"));
        Pantalla_Principal->resize(800, 600);
        Pantalla_Principal->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(Pantalla_Principal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Button_luz_3 = new QPushButton(centralWidget);
        Button_luz_3->setObjectName(QStringLiteral("Button_luz_3"));
        Button_luz_3->setGeometry(QRect(170, 200, 161, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Button_luz_3->setFont(font);
        Button_luz_3->setCheckable(true);
        Button_luz_3->setChecked(false);
        label_luz_3 = new QLabel(centralWidget);
        label_luz_3->setObjectName(QStringLiteral("label_luz_3"));
        label_luz_3->setGeometry(QRect(50, 200, 111, 31));
        label_luz_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_luz_4 = new QLabel(centralWidget);
        label_luz_4->setObjectName(QStringLiteral("label_luz_4"));
        label_luz_4->setGeometry(QRect(50, 240, 111, 31));
        label_luz_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_luz_4 = new QPushButton(centralWidget);
        Button_luz_4->setObjectName(QStringLiteral("Button_luz_4"));
        Button_luz_4->setGeometry(QRect(170, 240, 161, 31));
        Button_luz_4->setFont(font);
        Button_luz_4->setCheckable(true);
        Button_luz_4->setChecked(false);
        label_luz_5 = new QLabel(centralWidget);
        label_luz_5->setObjectName(QStringLiteral("label_luz_5"));
        label_luz_5->setGeometry(QRect(50, 280, 111, 31));
        label_luz_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_luz_5 = new QPushButton(centralWidget);
        Button_luz_5->setObjectName(QStringLiteral("Button_luz_5"));
        Button_luz_5->setGeometry(QRect(170, 280, 161, 31));
        Button_luz_5->setFont(font);
        Button_luz_5->setCheckable(true);
        Button_luz_5->setChecked(false);
        label_luz_6 = new QLabel(centralWidget);
        label_luz_6->setObjectName(QStringLiteral("label_luz_6"));
        label_luz_6->setGeometry(QRect(50, 320, 111, 31));
        label_luz_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_luz_6 = new QPushButton(centralWidget);
        Button_luz_6->setObjectName(QStringLiteral("Button_luz_6"));
        Button_luz_6->setGeometry(QRect(170, 320, 161, 31));
        Button_luz_6->setFont(font);
        Button_luz_6->setCheckable(true);
        Button_luz_6->setChecked(false);
        label_luz_7 = new QLabel(centralWidget);
        label_luz_7->setObjectName(QStringLiteral("label_luz_7"));
        label_luz_7->setGeometry(QRect(50, 360, 111, 31));
        label_luz_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_luz_7 = new QPushButton(centralWidget);
        Button_luz_7->setObjectName(QStringLiteral("Button_luz_7"));
        Button_luz_7->setGeometry(QRect(170, 360, 161, 31));
        Button_luz_7->setFont(font);
        Button_luz_7->setCheckable(true);
        Button_luz_7->setChecked(false);
        label_luz_8 = new QLabel(centralWidget);
        label_luz_8->setObjectName(QStringLiteral("label_luz_8"));
        label_luz_8->setGeometry(QRect(50, 400, 111, 31));
        label_luz_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Slider_luz_8 = new QSlider(centralWidget);
        Slider_luz_8->setObjectName(QStringLiteral("Slider_luz_8"));
        Slider_luz_8->setGeometry(QRect(170, 410, 161, 16));
        Slider_luz_8->setMaximum(100);
        Slider_luz_8->setOrientation(Qt::Horizontal);
        label_luz_8_porcentaje = new QLabel(centralWidget);
        label_luz_8_porcentaje->setObjectName(QStringLiteral("label_luz_8_porcentaje"));
        label_luz_8_porcentaje->setGeometry(QRect(340, 400, 51, 31));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_luz_8_porcentaje->setFont(font1);
        label_luz_8_porcentaje->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_luz_10 = new QLabel(centralWidget);
        label_luz_10->setObjectName(QStringLiteral("label_luz_10"));
        label_luz_10->setGeometry(QRect(50, 160, 111, 31));
        label_luz_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_luz_11 = new QLabel(centralWidget);
        label_luz_11->setObjectName(QStringLiteral("label_luz_11"));
        label_luz_11->setGeometry(QRect(170, 160, 161, 31));
        QFont font2;
        font2.setItalic(true);
        label_luz_11->setFont(font2);
        label_luz_11->setAlignment(Qt::AlignCenter);
        label_eventos = new QLabel(centralWidget);
        label_eventos->setObjectName(QStringLiteral("label_eventos"));
        label_eventos->setGeometry(QRect(400, 50, 211, 31));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label_eventos->setFont(font3);
        label_eventos->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_status_luces = new QLabel(centralWidget);
        label_status_luces->setObjectName(QStringLiteral("label_status_luces"));
        label_status_luces->setGeometry(QRect(50, 50, 311, 31));
        label_status_luces->setFont(font3);
        label_status_luces->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_evento_agregar = new QPushButton(centralWidget);
        Button_evento_agregar->setObjectName(QStringLiteral("Button_evento_agregar"));
        Button_evento_agregar->setGeometry(QRect(400, 490, 141, 25));
        tableView_eventos = new QTableView(centralWidget);
        tableView_eventos->setObjectName(QStringLiteral("tableView_eventos"));
        tableView_eventos->setGeometry(QRect(400, 111, 381, 351));
        Pantalla_Principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Pantalla_Principal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        Pantalla_Principal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Pantalla_Principal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Pantalla_Principal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Pantalla_Principal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Pantalla_Principal->setStatusBar(statusBar);

        retranslateUi(Pantalla_Principal);

        QMetaObject::connectSlotsByName(Pantalla_Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Pantalla_Principal)
    {
        Pantalla_Principal->setWindowTitle(QApplication::translate("Pantalla_Principal", "Pantalla_Principal", 0));
        Button_luz_3->setText(QApplication::translate("Pantalla_Principal", "OFF", 0));
        label_luz_3->setText(QApplication::translate("Pantalla_Principal", "Luz 3", 0));
        label_luz_4->setText(QApplication::translate("Pantalla_Principal", "Luz 4", 0));
        Button_luz_4->setText(QApplication::translate("Pantalla_Principal", "OFF", 0));
        label_luz_5->setText(QApplication::translate("Pantalla_Principal", "Luz 5", 0));
        Button_luz_5->setText(QApplication::translate("Pantalla_Principal", "OFF", 0));
        label_luz_6->setText(QApplication::translate("Pantalla_Principal", "Luz 6", 0));
        Button_luz_6->setText(QApplication::translate("Pantalla_Principal", "OFF", 0));
        label_luz_7->setText(QApplication::translate("Pantalla_Principal", "Luz 7", 0));
        Button_luz_7->setText(QApplication::translate("Pantalla_Principal", "OFF", 0));
        label_luz_8->setText(QApplication::translate("Pantalla_Principal", "Luz 8", 0));
        label_luz_8_porcentaje->setText(QApplication::translate("Pantalla_Principal", "0%", 0));
        label_luz_10->setText(QApplication::translate("Pantalla_Principal", "Luz 1/2", 0));
        label_luz_11->setText(QApplication::translate("Pantalla_Principal", "Apagada", 0));
        label_eventos->setText(QApplication::translate("Pantalla_Principal", "Eventos Programados", 0));
        label_status_luces->setText(QApplication::translate("Pantalla_Principal", "Apagado/Encendido/Status de Luces", 0));
        Button_evento_agregar->setText(QApplication::translate("Pantalla_Principal", "Agregar un Evento", 0));
    } // retranslateUi

};

namespace Ui {
    class Pantalla_Principal: public Ui_Pantalla_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_PRINCIPAL_H
