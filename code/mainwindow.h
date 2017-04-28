#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"swc_controller.h"
#include"processespane.h"
#include<qdebug.h>

//----------------------------------------------------
// One-view process code words:
//----------------------------------------------------
// Identity Transformation           //oneviewPcode -100
//("Add salt and pepper noise");     //oneviewPcode 0
//("Show Logo at top left corner");  //oneviewPcode 1
//("Convert to new colorspace");     //oneviewPcode 2
//("Equalize histogram");            //oneviewPcode 3
//("Dilate");        //oneviewPcode 4
//("Erode");         //oneviewPcode 5
//("Open");          //oneviewPcode 6
//("Close");         //oneviewPcode 7
//("Blur");          //oneviewPcode 8
//("Apply Sobel");   //oneviewPcode 9
//("Apply Laplacian");           //oneviewPcode 10
//("Apply custom kernel");       //oneviewPcode 11
//("Detect Edges using Canny");  //oneviewPcode 12
//("Extract lines and Circles using Hough");     //oneviewPcode 13
//("Find contours of connected components");     //oneviewPcode 14
//----------------------------------------------------


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_processesPane_clicked();
    void on_apply_in_processPane_clicked();

private:
    Ui::MainWindow *ui;

    // Current one-view-process code
    int mv_currentOneViewProcess;

    // Member-window containing one-view processes
    processesPane* mw_oneViewProcessesPane;

    // Interface to the controller
    swc_controller* controller;



};


#endif // MAINWINDOW_H
