/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *inputWindow;
    QLabel *outputWindow;
    QLabel *inputWindowLabel;
    QLabel *outputWindowLabel;
    QPushButton *loadImage;
    QPushButton *loadVideo;
    QPushButton *camSnap;
    QPushButton *camVideo;
    QPushButton *saveImage;
    QPushButton *saveVideo;
    QPushButton *saveProcess;
    QPushButton *playVideo;
    QPushButton *pauseVideo;
    QPushButton *processesPane;
    QPushButton *multiviewPane;
    QPlainTextEdit *currentOneviewProcess;
    QLabel *chosenOneviewProcess;
    QPushButton *processImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1316, 815);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputWindow = new QLabel(centralWidget);
        inputWindow->setObjectName(QStringLiteral("inputWindow"));
        inputWindow->setGeometry(QRect(80, 30, 480, 600));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputWindow->sizePolicy().hasHeightForWidth());
        inputWindow->setSizePolicy(sizePolicy);
        inputWindow->setFrameShape(QFrame::StyledPanel);
        inputWindow->setFrameShadow(QFrame::Raised);
        inputWindow->setLineWidth(1);
        outputWindow = new QLabel(centralWidget);
        outputWindow->setObjectName(QStringLiteral("outputWindow"));
        outputWindow->setGeometry(QRect(700, 30, 480, 600));
        outputWindow->setFrameShape(QFrame::StyledPanel);
        outputWindow->setFrameShadow(QFrame::Raised);
        inputWindowLabel = new QLabel(centralWidget);
        inputWindowLabel->setObjectName(QStringLiteral("inputWindowLabel"));
        inputWindowLabel->setGeometry(QRect(200, 10, 91, 16));
        outputWindowLabel = new QLabel(centralWidget);
        outputWindowLabel->setObjectName(QStringLiteral("outputWindowLabel"));
        outputWindowLabel->setGeometry(QRect(800, 10, 101, 16));
        loadImage = new QPushButton(centralWidget);
        loadImage->setObjectName(QStringLiteral("loadImage"));
        loadImage->setGeometry(QRect(4, 59, 71, 31));
        QFont font;
        font.setPointSize(8);
        loadImage->setFont(font);
        loadVideo = new QPushButton(centralWidget);
        loadVideo->setObjectName(QStringLiteral("loadVideo"));
        loadVideo->setGeometry(QRect(4, 100, 71, 31));
        loadVideo->setFont(font);
        camSnap = new QPushButton(centralWidget);
        camSnap->setObjectName(QStringLiteral("camSnap"));
        camSnap->setGeometry(QRect(4, 140, 71, 31));
        camSnap->setFont(font);
        camVideo = new QPushButton(centralWidget);
        camVideo->setObjectName(QStringLiteral("camVideo"));
        camVideo->setGeometry(QRect(4, 181, 71, 31));
        camVideo->setFont(font);
        saveImage = new QPushButton(centralWidget);
        saveImage->setObjectName(QStringLiteral("saveImage"));
        saveImage->setGeometry(QRect(1210, 59, 80, 31));
        saveImage->setFont(font);
        saveVideo = new QPushButton(centralWidget);
        saveVideo->setObjectName(QStringLiteral("saveVideo"));
        saveVideo->setGeometry(QRect(1210, 100, 80, 31));
        saveVideo->setFont(font);
        saveProcess = new QPushButton(centralWidget);
        saveProcess->setObjectName(QStringLiteral("saveProcess"));
        saveProcess->setGeometry(QRect(1210, 140, 80, 31));
        saveProcess->setFont(font);
        playVideo = new QPushButton(centralWidget);
        playVideo->setObjectName(QStringLiteral("playVideo"));
        playVideo->setGeometry(QRect(870, 7, 31, 19));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans Mono CJK TC"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        playVideo->setFont(font1);
        pauseVideo = new QPushButton(centralWidget);
        pauseVideo->setObjectName(QStringLiteral("pauseVideo"));
        pauseVideo->setGeometry(QRect(910, 7, 31, 18));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans Mono CJK TC"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        pauseVideo->setFont(font2);
        processesPane = new QPushButton(centralWidget);
        processesPane->setObjectName(QStringLiteral("processesPane"));
        processesPane->setGeometry(QRect(700, 660, 150, 35));
        processesPane->setFont(font);
        multiviewPane = new QPushButton(centralWidget);
        multiviewPane->setObjectName(QStringLiteral("multiviewPane"));
        multiviewPane->setGeometry(QRect(410, 660, 150, 35));
        multiviewPane->setFont(font);
        currentOneviewProcess = new QPlainTextEdit(centralWidget);
        currentOneviewProcess->setObjectName(QStringLiteral("currentOneviewProcess"));
        currentOneviewProcess->setGeometry(QRect(870, 660, 200, 35));
        chosenOneviewProcess = new QLabel(centralWidget);
        chosenOneviewProcess->setObjectName(QStringLiteral("chosenOneviewProcess"));
        chosenOneviewProcess->setGeometry(QRect(870, 630, 150, 30));
        processImage = new QPushButton(centralWidget);
        processImage->setObjectName(QStringLiteral("processImage"));
        processImage->setGeometry(QRect(1080, 660, 150, 35));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1316, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "See with C++", 0));
        inputWindow->setText(QString());
        outputWindow->setText(QString());
        inputWindowLabel->setText(QApplication::translate("MainWindow", "Input", 0));
        outputWindowLabel->setText(QApplication::translate("MainWindow", "Output", 0));
        loadImage->setText(QApplication::translate("MainWindow", "Load Image", 0));
        loadVideo->setText(QApplication::translate("MainWindow", "Load Video", 0));
        camSnap->setText(QApplication::translate("MainWindow", "Cam Snap", 0));
        camVideo->setText(QApplication::translate("MainWindow", "Cam Video", 0));
        saveImage->setText(QApplication::translate("MainWindow", "Save Image", 0));
        saveVideo->setText(QApplication::translate("MainWindow", "Save Video", 0));
        saveProcess->setText(QApplication::translate("MainWindow", "Save Process", 0));
        playVideo->setText(QApplication::translate("MainWindow", ">", 0));
        pauseVideo->setText(QApplication::translate("MainWindow", "||", 0));
        processesPane->setText(QApplication::translate("MainWindow", "One-View Processes Pane", 0));
        multiviewPane->setText(QApplication::translate("MainWindow", "Multi-View Pane", 0));
        chosenOneviewProcess->setText(QApplication::translate("MainWindow", "Chosen 1-view Process", 0));
        processImage->setText(QApplication::translate("MainWindow", "Process", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
