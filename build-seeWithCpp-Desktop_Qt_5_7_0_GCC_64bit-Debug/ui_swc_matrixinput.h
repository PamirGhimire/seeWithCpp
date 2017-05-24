/********************************************************************************
** Form generated from reading UI file 'swc_matrixinput.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWC_MATRIXINPUT_H
#define UI_SWC_MATRIXINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_swc_matrixInput
{
public:
    QLineEdit *ker00;
    QLineEdit *ker01;
    QLineEdit *ker02;
    QLineEdit *ker10;
    QLineEdit *ker11;
    QLineEdit *ker12;
    QLineEdit *ker20;
    QLineEdit *ker21;
    QLineEdit *ker22;
    QPushButton *Ok_button;
    QPushButton *cancel_button;
    QLabel *label;

    void setupUi(QDialog *swc_matrixInput)
    {
        if (swc_matrixInput->objectName().isEmpty())
            swc_matrixInput->setObjectName(QStringLiteral("swc_matrixInput"));
        swc_matrixInput->resize(143, 167);
        ker00 = new QLineEdit(swc_matrixInput);
        ker00->setObjectName(QStringLiteral("ker00"));
        ker00->setGeometry(QRect(10, 40, 40, 21));
        QFont font;
        font.setPointSize(7);
        ker00->setFont(font);
        ker01 = new QLineEdit(swc_matrixInput);
        ker01->setObjectName(QStringLiteral("ker01"));
        ker01->setGeometry(QRect(50, 40, 40, 21));
        ker01->setFont(font);
        ker02 = new QLineEdit(swc_matrixInput);
        ker02->setObjectName(QStringLiteral("ker02"));
        ker02->setGeometry(QRect(90, 40, 40, 21));
        ker02->setFont(font);
        ker10 = new QLineEdit(swc_matrixInput);
        ker10->setObjectName(QStringLiteral("ker10"));
        ker10->setGeometry(QRect(10, 70, 40, 21));
        ker10->setFont(font);
        ker11 = new QLineEdit(swc_matrixInput);
        ker11->setObjectName(QStringLiteral("ker11"));
        ker11->setGeometry(QRect(50, 70, 40, 21));
        ker11->setFont(font);
        ker12 = new QLineEdit(swc_matrixInput);
        ker12->setObjectName(QStringLiteral("ker12"));
        ker12->setGeometry(QRect(90, 70, 40, 21));
        ker12->setFont(font);
        ker20 = new QLineEdit(swc_matrixInput);
        ker20->setObjectName(QStringLiteral("ker20"));
        ker20->setGeometry(QRect(10, 100, 40, 21));
        ker20->setFont(font);
        ker21 = new QLineEdit(swc_matrixInput);
        ker21->setObjectName(QStringLiteral("ker21"));
        ker21->setGeometry(QRect(50, 100, 40, 21));
        ker21->setFont(font);
        ker22 = new QLineEdit(swc_matrixInput);
        ker22->setObjectName(QStringLiteral("ker22"));
        ker22->setGeometry(QRect(90, 100, 40, 21));
        ker22->setFont(font);
        Ok_button = new QPushButton(swc_matrixInput);
        Ok_button->setObjectName(QStringLiteral("Ok_button"));
        Ok_button->setGeometry(QRect(10, 130, 61, 22));
        cancel_button = new QPushButton(swc_matrixInput);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(80, 130, 51, 22));
        label = new QLabel(swc_matrixInput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 121, 16));

        retranslateUi(swc_matrixInput);

        QMetaObject::connectSlotsByName(swc_matrixInput);
    } // setupUi

    void retranslateUi(QDialog *swc_matrixInput)
    {
        swc_matrixInput->setWindowTitle(QApplication::translate("swc_matrixInput", "Dialog", 0));
        Ok_button->setText(QApplication::translate("swc_matrixInput", "Ok", 0));
        cancel_button->setText(QApplication::translate("swc_matrixInput", "Cancel", 0));
        label->setText(QApplication::translate("swc_matrixInput", "Enter 3x3 Kernel", 0));
    } // retranslateUi

};

namespace Ui {
    class swc_matrixInput: public Ui_swc_matrixInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWC_MATRIXINPUT_H
