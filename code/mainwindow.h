#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qfiledialog.h>
#include"swc_controller.h"
#include"swc_processmanager.h"
#include"processespane.h"
#include"multiviewpane.h"
#include"swc_processcommunicator.h"
#include"swc_structuringelementinput.h"
#include"swc_matrixinput.h"
#include"swc_matrixoutput.h"
#include"swc_settwothresholds.h"
#include"swc_camstream.h"

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video/video.hpp>

#include<qdebug.h>
#include<qthread.h>

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
    // Main-window slots
    void on_processesPane_clicked();

    void on_loadImage_clicked();

    void on_processImage_clicked();

    void on_CloseMain_clicked();

    void on_multiviewPane_clicked();

    void on_camVideo_clicked();

    void on_camSnap_clicked();

    void on_playVideo_clicked();

    void on_pauseVideo_clicked();

    // slots for threads
    void on_camstream_frame_available();


    // one-view process pane slots
    void on_apply_in_processPane_clicked();

    void on_setDetails_in_processPane_clicked();


    // multi-view and geometry pane slots
    void on_setIm1_in_multiviewPane_clicked();

    void on_setIm2_in_multiviewPane_clicked();

    void on_matchIm12_in_multiviewPane_clicked();

    void on_fundamentalMat_in_multiviewPane_clicked();

    void on_calibrate_in_multiviewPane_clicked();

    void on_undistort_in_multiviewPane_clicked();


    // input ui for structuring element (morphology)
    void on_ok_in_selInput_clicked();
    // input ui for 3x3 kernel (im convolutions)
    void on_ok_in_matrixInput_clicked();
    // input ui for canny edge (needs 2 thresholds)
    void on_ok_in_settwothresholds_clicked();

    void on_saveinput_clicked();

    void on_saveImage_clicked();

signals:
    void ms_closeStream();

private:
    Ui::MainWindow *ui;

    // Current one-view-process code
    int mv_currentOneViewProcess;

    // camera device (md : member device)
    cv::VideoCapture* md_cam;

    // process-video flag
    bool mv_processVideoFlag;

    // video capture thread
    QThread* mt_cam0;

    // video capture worker
    swc_camstream* mw_camstreamer;

    // Member-window containing one-view processes
    processesPane* mw_oneViewProcessesPane;

    // Member-window containing multi-view and camera geometry processes
    multiviewPane* mw_multiviewPane;

    // Member-window for setting structuring element (Morphological operations)
    swc_structuringElementInput* mw_selInput;

    // Member-window for setting custom kernel for 2D filtering
    swc_matrixInput* mw_matrixInput;

    // Member-window for displaying 3x3 matrix
    swc_matrixOutput* mw_matrixOutput;

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

    int displayim_width;
    int displayim_height;

    // logoFlag is true if user has requested showing logo
    bool logoFlag;

};


#endif // MAINWINDOW_H
