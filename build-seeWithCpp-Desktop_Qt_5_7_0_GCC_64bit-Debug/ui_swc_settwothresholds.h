/********************************************************************************
** Form generated from reading UI file 'swc_settwothresholds.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWC_SETTWOTHRESHOLDS_H
#define UI_SWC_SETTWOTHRESHOLDS_H

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

class Ui_swc_setTwoThresholds
{
public:
    QLabel *label;
    QLineEdit *lowerThresh;
    QLineEdit *upperThresh;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *swc_setTwoThresholds)
    {
        if (swc_setTwoThresholds->objectName().isEmpty())
            swc_setTwoThresholds->setObjectName(QStringLiteral("swc_setTwoThresholds"));
        swc_setTwoThresholds->resize(220, 163);
        label = new QLabel(swc_setTwoThresholds);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 151, 21));
        lowerThresh = new QLineEdit(swc_setTwoThresholds);
        lowerThresh->setObjectName(QStringLiteral("lowerThresh"));
        lowerThresh->setGeometry(QRect(20, 70, 113, 22));
        upperThresh = new QLineEdit(swc_setTwoThresholds);
        upperThresh->setObjectName(QStringLiteral("upperThresh"));
        upperThresh->setGeometry(QRect(20, 130, 113, 22));
        label_2 = new QLabel(swc_setTwoThresholds);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 111, 16));
        label_3 = new QLabel(swc_setTwoThresholds);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 111, 16));
        okButton = new QPushButton(swc_setTwoThresholds);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(160, 70, 50, 22));
        cancelButton = new QPushButton(swc_setTwoThresholds);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(160, 130, 50, 22));

        retranslateUi(swc_setTwoThresholds);

        QMetaObject::connectSlotsByName(swc_setTwoThresholds);
    } // setupUi

    void retranslateUi(QDialog *swc_setTwoThresholds)
    {
        swc_setTwoThresholds->setWindowTitle(QApplication::translate("swc_setTwoThresholds", "Dialog", 0));
        label->setText(QApplication::translate("swc_setTwoThresholds", "Set Thresholds:", 0));
        label_2->setText(QApplication::translate("swc_setTwoThresholds", "Lower Threshold:", 0));
        label_3->setText(QApplication::translate("swc_setTwoThresholds", "Upper Threshold:", 0));
        okButton->setText(QApplication::translate("swc_setTwoThresholds", "Ok", 0));
        cancelButton->setText(QApplication::translate("swc_setTwoThresholds", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class swc_setTwoThresholds: public Ui_swc_setTwoThresholds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWC_SETTWOTHRESHOLDS_H
