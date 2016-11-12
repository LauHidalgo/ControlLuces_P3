/********************************************************************************
** Form generated from reading UI file 'pantalla_historial.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_HISTORIAL_H
#define UI_PANTALLA_HISTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pantalla_historial
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_Historial;
    QPushButton *pushButton_Historial_Aceptar;

    void setupUi(QDialog *pantalla_historial)
    {
        if (pantalla_historial->objectName().isEmpty())
            pantalla_historial->setObjectName(QStringLiteral("pantalla_historial"));
        pantalla_historial->setWindowModality(Qt::WindowModal);
        pantalla_historial->resize(800, 400);
        pantalla_historial->setModal(true);
        widget = new QWidget(pantalla_historial);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 781, 381));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_Historial = new QTextBrowser(widget);
        textBrowser_Historial->setObjectName(QStringLiteral("textBrowser_Historial"));

        verticalLayout->addWidget(textBrowser_Historial);

        pushButton_Historial_Aceptar = new QPushButton(widget);
        pushButton_Historial_Aceptar->setObjectName(QStringLiteral("pushButton_Historial_Aceptar"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_Historial_Aceptar->setFont(font);

        verticalLayout->addWidget(pushButton_Historial_Aceptar);


        retranslateUi(pantalla_historial);

        QMetaObject::connectSlotsByName(pantalla_historial);
    } // setupUi

    void retranslateUi(QDialog *pantalla_historial)
    {
        pantalla_historial->setWindowTitle(QApplication::translate("pantalla_historial", "Dialog", 0));
        pushButton_Historial_Aceptar->setText(QApplication::translate("pantalla_historial", "Aceptar", 0));
    } // retranslateUi

};

namespace Ui {
    class pantalla_historial: public Ui_pantalla_historial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_HISTORIAL_H
