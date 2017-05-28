#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qfiledialog.h>
#include"swc_controller.h"
#include"swc_processmanager.h"
#include"processespane.h"
#include"swc_processcommunicator.h"
#include"swc_structuringelementinput.h"
#include"swc_matrixinput.h"
#include"swc_settwothresholds.h"
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

    void on_setDetails_in_processPane_clicked();

    void on_ok_in_selInput_clicked();

    void on_ok_in_matrixInput_clicked();

    void on_ok_in_settwothresholds_clicked();

    void on_loadImage_clicked();

    void on_processImage_clicked();

    void on_CloseMain_clicked();

private:
    Ui::MainWindow *ui;

    // Current one-view-process code
    int mv_currentOneViewProcess;

    // Member-window containing one-view processes
    processesPane* mw_oneViewProcessesPane;

    // Member-window for setting structuring element (Morphological operations)
    swc_structuringElementInput* mw_selInput;

    // Member-window for setting custom kernel for 2D filtering
    swc_matrixInput* mw_matrixInput;

    // Member-window for setting two thresholds
    swc_setTwoThresholds* mw_settwothresholds;

    // Interface to the controller
    swc_controller* controller;

    // Interface to process manager
    swc_processManager* processManager;

    // Interface to the process communicator
    swc_processcommunicator* processComm;

    // Function: set gui display by reading controller's image buffers
    void mf_mainwindow_setdisplay();

    // variables for displaying image
    cv::Mat displayim_in;
    cv::Mat displayim_out;

    QImage displayqim_in;
    QImage displayqim_out;

    const int displayim_width = 480;
    const int displayim_height = 600;

    // logoFlag is true if user has requested showing logo
    bool logoFlag;

};


#endif // MAINWINDOW_H
