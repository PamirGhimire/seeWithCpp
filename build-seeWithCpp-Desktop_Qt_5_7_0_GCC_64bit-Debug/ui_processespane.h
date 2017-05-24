/********************************************************************************
** Form generated from reading UI file 'processespane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSESPANE_H
#define UI_PROCESSESPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_processesPane
{
public:
    QPushButton *apply;
    QPushButton *close;
    QLabel *image2image;
    QLabel *image2measurement;
    QListWidget *i2iProcesses;
    QListWidget *i2mProcesses;
    QPushButton *setDetails;

    void setupUi(QDialog *processesPane)
    {
        if (processesPane->objectName().isEmpty())
            processesPane->setObjectName(QStringLiteral("processesPane"));
        processesPane->resize(654, 492);
        apply = new QPushButton(processesPane);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setGeometry(QRect(460, 460, 80, 22));
        QFont font;
        font.setPointSize(8);
        apply->setFont(font);
        close = new QPushButton(processesPane);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(560, 460, 80, 22));
        close->setFont(font);
        image2image = new QLabel(processesPane);
        image2image->setObjectName(QStringLiteral("image2image"));
        image2image->setGeometry(QRect(20, 10, 261, 16));
        image2measurement = new QLabel(processesPane);
        image2measurement->setObjectName(QStringLiteral("image2measurement"));
        image2measurement->setGeometry(QRect(20, 240, 251, 16));
        i2iProcesses = new QListWidget(processesPane);
        i2iProcesses->setObjectName(QStringLiteral("i2iProcesses"));
        i2iProcesses->setGeometry(QRect(20, 30, 260, 192));
        i2mProcesses = new QListWidget(processesPane);
        i2mProcesses->setObjectName(QStringLiteral("i2mProcesses"));
        i2mProcesses->setGeometry(QRect(20, 260, 260, 192));
        setDetails = new QPushButton(processesPane);
        setDetails->setObjectName(QStringLiteral("setDetails"));
        setDetails->setGeometry(QRect(290, 30, 81, 21));

        retranslateUi(processesPane);

        QMetaObject::connectSlotsByName(processesPane);
    } // setupUi

    void retranslateUi(QDialog *processesPane)
    {
        processesPane->setWindowTitle(QApplication::translate("processesPane", "One-view Processes", 0));
        apply->setText(QApplication::translate("processesPane", "Apply", 0));
        close->setText(QApplication::translate("processesPane", "Close", 0));
        image2image->setText(QApplication::translate("processesPane", "Image to Image - Set details, then Apply ", 0));
        image2measurement->setText(QApplication::translate("processesPane", "Image to Measurement - Apply", 0));
        setDetails->setText(QApplication::translate("processesPane", "Set Details", 0));
    } // retranslateUi

};

namespace Ui {
    class processesPane: public Ui_processesPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSESPANE_H
