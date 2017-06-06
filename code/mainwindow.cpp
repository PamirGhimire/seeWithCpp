#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayim_width = ui->inputWindow->width();
    displayim_height = ui->inputWindow->height();

    // Initialize camera device
    md_cam = new cv::VideoCapture();
    md_cam->open(0);

    // Initialize process video flag as false
    mv_processVideoFlag = false;

    // Initialize the process communicator
    processComm = new swc_processcommunicator();

    // Initialize the process manager
    processManager = new swc_processManager();

    // Initialize the controller
    controller = new swc_controller();

    // Initialize the processes pane
    mw_oneViewProcessesPane = new processesPane();

    // Initialize multi-view and geometry pane
    mw_multiviewPane = new multiviewPane();

    // Initialize the structuring element input window
    mw_selInput = new swc_structuringElementInput();

    // Initialize the 3x3 kernel input window
    mw_matrixInput = new swc_matrixInput();

    // Initialize the 3x3 matrix output window
    mw_matrixOutput = new swc_matrixOutput();

    // Initialize the two thresholds window
    mw_settwothresholds = new swc_setTwoThresholds();

    // Initialize default one-view process as identity transform
    mv_currentOneViewProcess = identity;

    //----------------------------------------------------------
    // Connecting one-view process pane signals with mainwindow slots:
    //----------------------------------------------------------
    connect(mw_oneViewProcessesPane, SIGNAL(ms_applyButtonClicked()), this, SLOT(on_apply_in_processPane_clicked()) );
    connect(mw_oneViewProcessesPane, SIGNAL(ms_setDetailsButtonClicked()), this, SLOT(on_setDetails_in_processPane_clicked()) );
    connect(mw_selInput, SIGNAL(ms_ok_clicked()), this, SLOT(on_ok_in_selInput_clicked()) );
    connect(mw_matrixInput, SIGNAL(ms_ok_clicked()), this, SLOT(on_ok_in_matrixInput_clicked()) );
    connect(mw_settwothresholds, SIGNAL(ms_ok_clicked()), this, SLOT(on_ok_in_settwothresholds_clicked()) );
    //----------------------------------------------------------

    //----------------------------------------------------------
    // Connecting multiview and geometry pane signals with mainwindow slots:
    //----------------------------------------------------------
    connect(mw_multiviewPane, SIGNAL(ms_setIm1_clicked()), this, SLOT(on_setIm1_in_multiviewPane_clicked()) );
    connect(mw_multiviewPane, SIGNAL(ms_setIm2_clicked()), this, SLOT(on_setIm2_in_multiviewPane_clicked()) );
    connect(mw_multiviewPane, SIGNAL(ms_im12Match_clicked()), this, SLOT(on_matchIm12_in_multiviewPane_clicked()) );
    connect(mw_multiviewPane, SIGNAL(ms_fundamentalMat_clicked()), this, SLOT(on_fundamentalMat_in_multiviewPane_clicked()) );
    connect(mw_multiviewPane, SIGNAL(ms_calibrate_clicked()), this, SLOT(on_calibrate_in_multiviewPane_clicked()) );
    connect(mw_multiviewPane, SIGNAL(ms_undistort_clicked()), this, SLOT(on_undistort_in_multiviewPane_clicked()) );
    //----------------------------------------------------------
}

//----------------------------------------------------------
// Destructor of main window
//----------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------------------------------------
// Show one-view processes pane
//----------------------------------------------------------
void MainWindow::on_processesPane_clicked()
{
    mw_oneViewProcessesPane->show();
}

//----------------------------------------------------------
// Update code for current process when a process is applied
// in the one-view process pane, and update current-process display
//----------------------------------------------------------
void MainWindow::on_apply_in_processPane_clicked()
{
    // update code for current one view process
    mv_currentOneViewProcess = mw_oneViewProcessesPane->mf_getCurrentOneViewProcess();

    // change process-video flag to true
    mv_processVideoFlag = true;

    // the process manager is called only if the current process is an image-to-image process
    if (mv_currentOneViewProcess < showHistogram){
        // update current-process display
        QString currProcess = QString::fromStdString(processManager->mf_getProcessName(mv_currentOneViewProcess) );
        ui->currentOneviewProcess->document()->setPlainText(currProcess);

        // tell the process manager to execute current process code
        processManager->mf_executeProcess(mv_currentOneViewProcess, controller, processComm);
    }

    // if not, the measurement is shown in a different window
    else{

        switch(mv_currentOneViewProcess){

        // measurement = histogram of input image
        case showHistogram:{
            qDebug() << "asked to show histogram of input";
            // tell controller to show histogram
            cv::Mat histImage = controller->computeHistogram_computeHistogramInput();
            cv::namedWindow("Histogram of Input Image");
            cv::imshow("Histogram of Input Image", histImage);
            cv::waitKey(0);
        }

            // measurement = histogram of output image
        case showHistogramOut:{
            qDebug() << "asked to show histogram of output";
            // tell controller to show histogram
            cv::Mat histImage = controller->computeHistogram_computeHistogramOutput();
            cv::namedWindow("Histogram of output Image");
            cv::imshow("Histogram of Output Image", histImage);
            cv::waitKey(0);
        }

        }
    }

    // update display
    mf_mainwindow_setdisplay();

    // set output of process as input for next
    //controller->mf_setMvInputim(controller->mf_getOutputImage());
}

//----------------------------------------------------------
// Get parameters for the user selected process
// Open dialog according to choice of process, pass the parameters to process communicator
//----------------------------------------------------------
void MainWindow::on_setDetails_in_processPane_clicked()
{
    switch(mw_oneViewProcessesPane->mf_getCurrentOneViewProcess()){
    case addSaltAndPepper:
        // get details for salt and pepper noise
        break;
        //----------------------------------------------------------
    case showLogo:{
        // get the logo filename
        QString logo_fileName = QFileDialog::getOpenFileName(this, tr("Select Logo"), "../../../", tr("Image Files(*.png *.jpg *jpeg *.bmp)") );

        // show one-view process pane again
        mw_oneViewProcessesPane->raise();

        // set logo
        controller->addLogo_setLogo(logo_fileName.toStdString());

        break;
    }
        //----------------------------------------------------------
    case dilate:{
        // display the input interface for structuring element
        mw_selInput->show();

        // read the input, and make changes in the process-communicator object
        // changes made through signals-slots mechanism

        break;

    }
        //----------------------------------------------------------
    case erode:{
        // display the input interface for structuring element
        mw_selInput->show();

        // read the input, and make changes in the process-communicator object
        // changes made through signals-slots mechanism

        break;
    }
        //----------------------------------------------------------
    case open_morph:{
        // display the input interface for structuring element
        mw_selInput->show();

        // read the input, and make changes in the process-communicator object
        // changes made through signals-slots mechanism

        break;
    }
        //----------------------------------------------------------
    case close_morph:{
        // display the input interface for structuring element
        mw_selInput->show();

        // read the input, and make changes in the process-communicator object
        // changes made through signals-slots mechanism

        break;
    }
        //----------------------------------------------------------
    case customKernel:{
        // display the input interface for 3x3 kernel input
        mw_matrixInput->show();

        // read the input, and make changes in the process-communicator object
        // changes made through signals-slots mechanism
        break;
    }
        //----------------------------------------------------------
    case cannyedge:{
        // display the input interface for 2 thresholds input
        mw_settwothresholds->show();

        // read the two thresholds, make changes in the process-communicator object
        // changes made through signals-slots mechanism
        break;
    }
    default:
        break;
        //----------------------------------------------------------
    }
}

//----------------------------------------------------------
// Ok button in structuring element input window clicked: update structuring element
//----------------------------------------------------------
void MainWindow::on_ok_in_selInput_clicked()
{
    // get the structuring element from the sel input window
    cv::Mat sel = mw_selInput->mf_getSel();

    // update the sel in process communicator
    if (mv_currentOneViewProcess == dilate || mv_currentOneViewProcess == close_morph){
        processComm->sel_dilation = sel;
    }
    else if (mv_currentOneViewProcess == erode || mv_currentOneViewProcess == open_morph){
        processComm->sel_erosion = sel;
    }

}
//----------------------------------------------------------
// Ok button in structuring element input window clicked: update structuring element
//----------------------------------------------------------
void MainWindow::on_ok_in_matrixInput_clicked(){

    // get the kernel from the kernel input window
    // update the kernel in the process communicator

    processComm->customKernel = mw_matrixInput->mv_kernel;

}
//----------------------------------------------------------
// Ok button in 2 thresholds input window clicked:
//----------------------------------------------------------
void MainWindow::on_ok_in_settwothresholds_clicked(){

    // if current process is canny edge detection
    if(mv_currentOneViewProcess == cannyedge){
        // get upper and lower thresholds from 2 thresholds window
        // update the thresholds in process communicator
        processComm->cannyLowerThresh = mw_settwothresholds->mv_lowerThresh;
        processComm->cannyUpperThresh = mw_settwothresholds->mv_upperThresh;
    }
}

//----------------------------------------------------------
// Load the selected image into controller's input image member variable
// Display the loaded image in the input viewer of the gui
//----------------------------------------------------------
void MainWindow::on_loadImage_clicked()
{
    qDebug() << "Button Pressed : Open Image";

    // get file name of image from ui
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "../../../", tr("Image Files(*.png *.jpg *jpeg *.bmp)") );

    if (!fileName.data()->isNull()){
        // ask controller to load the fileName bearing image
        controller->mf_setInputImage(fileName.toStdString());

        // update display
        mf_mainwindow_setdisplay();
    }
}

//---------------------------------------------------------------------------------------
// Set input and output windows to display input and result images in the controller
void MainWindow::mf_mainwindow_setdisplay()
{
    // get input image from the controller
    cv::Mat im_in = controller->mf_getInputImage();
    cv::resize(im_in, displayim_in, cv::Size(displayim_width, displayim_height) );

    // get output image from the controller
    cv::Mat im_out = controller->mf_getOutputImage();
    cv::resize(im_out, displayim_out, cv::Size(displayim_width, displayim_height));

    // get qt-label compatible image from input
    displayqim_in = QImage((const unsigned char*)(displayim_in.data), displayim_width, displayim_height, QImage::Format_Grayscale8);
    // get qt-label compatible image from output
    displayqim_out = QImage((const unsigned char*)(displayim_out.data), displayim_width, displayim_height, QImage::Format_Grayscale8);

    // set input label to display input qimage
    ui->inputWindow->setPixmap(QPixmap::fromImage(displayqim_in));

    // set output label to display output qimage
    ui->outputWindow->setPixmap(QPixmap::fromImage(displayqim_out));

}

//---------------------------------------------------------------------------------------
// GUI asks process manager to execute current process, also specifies a controller
//---------------------------------------------------------------------------------------
void MainWindow::on_processImage_clicked()
{
    processManager->mf_executeProcess(mv_currentOneViewProcess, controller, processComm);
    mf_mainwindow_setdisplay();
}
//---------------------------------------------------------------------------------------
// Close the main window (button display name = exit)
//---------------------------------------------------------------------------------------
void MainWindow::on_CloseMain_clicked()
{
    this->close();
    delete ui;
}

//---------------------------------------------------------------------------------------
// Multi-view and Geometry Pane
//---------------------------------------------------------------------------------------
void MainWindow::on_multiviewPane_clicked()
{
    // show the multiview and geometry pane
    mw_multiviewPane->show();
}
//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_setIm1_in_multiviewPane_clicked(){
    std::string im1name = mw_multiviewPane->mv_im1name.toStdString();
    controller->mf_setIm1(im1name);
}

//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_setIm2_in_multiviewPane_clicked(){
    std::string im2name = mw_multiviewPane->mv_im2name.toStdString();
    controller->mf_setIm2(im2name);
}

//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_matchIm12_in_multiviewPane_clicked(){
    // compute matches
    controller->matchImages_drawMatchesBwIm1and2(mw_multiviewPane->mv_descriptor);

    // show result of matching in the multiview window
    mw_multiviewPane->mv_displayim = controller->mf_getMatchIm1and2();
    mw_multiviewPane->mf_showDisplayim();

}

//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_fundamentalMat_in_multiviewPane_clicked(){
    // get fundamental matrix
    cv::Mat funmat;
    //qDebug() << "selected descriptor = " << mw_multiviewPane->mv_descriptor;
    controller->matchImages_findFundamentalIm1and2(funmat, mw_multiviewPane->mv_descriptor);

    // display fundamental matrix
    mw_matrixOutput->mv_matname = "Fundamental Matrix";
    mw_matrixOutput->mv_mat = funmat;
    mw_matrixOutput->mf_displayMvmat();

    cv::Mat epilinesImage;
    controller->matchImages_drawEpipolarLinesIm1and2(epilinesImage);

    // show result of matching in the multiview window
    cv::cvtColor(epilinesImage, epilinesImage, cv::COLOR_GRAY2RGB);
    mw_multiviewPane->mv_displayim = epilinesImage;
    mw_multiviewPane->mf_showDisplayim();

}
//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_calibrate_in_multiviewPane_clicked(){



    // pass the image list to be used for calibration to controller
    controller->camcalib_setFileList(mw_multiviewPane->mv_calibrationImageFiles);

    // ask controller to calibrate the related camera
    controller->camcalib_calibrate();

    // display the related camera matrix
    mw_matrixOutput->mv_matname = "camera matrix";
    mw_matrixOutput->mv_mat = controller->mf_getCamMatrix();
    mw_matrixOutput->mf_displayMvmat();
}

//---------------------------------------------------------------------------------------
// multi-view and geometry pane slots
//---------------------------------------------------------------------------------------
void MainWindow::on_undistort_in_multiviewPane_clicked(){
    controller->camcalib_undistortInputim();
    mf_mainwindow_setdisplay();
}

//---------------------------------------------------------------------------------------
// Video stream from attached camera (start - stop)
//---------------------------------------------------------------------------------------
void MainWindow::on_camVideo_clicked()
{
    // signal to video-capture thread to start or stop capturing (= updating inputim container in controller)

    // if processVideo flag is true, process the grabbed frame
}

//---------------------------------------------------------------------------------------
// grab a frame from camera (index 0)
//---------------------------------------------------------------------------------------
void MainWindow::on_camSnap_clicked()
{
    if(!md_cam->isOpened()){
        md_cam->open(0);
    }

    cv::Mat frame;

    for (int ntrial = 0; ntrial < 5; ntrial++){
        md_cam->read(frame);
        // if reading succesful, stop trying
        if (!frame.empty()){
            break;
        }
    }

    cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
    controller->mf_setMvInputim(frame);

    mf_mainwindow_setdisplay();
    md_cam->release();

}

//---------------------------------------------------------------------------------------
// play video button (change process-video flag to true)
//---------------------------------------------------------------------------------------
void MainWindow::on_playVideo_clicked()
{
    mv_processVideoFlag =  true;
}

//---------------------------------------------------------------------------------------
// pause video button (change process-video flag to false)
//---------------------------------------------------------------------------------------
void MainWindow::on_pauseVideo_clicked()
{
    mv_processVideoFlag = false;
}

//---------------------------------------------------------------------------------------
// Save input image (for saving camera snaps)
//---------------------------------------------------------------------------------------
void MainWindow::on_saveinput_clicked()
{
    // get save file name
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/jana/untitled.png",
                                                    tr("Images (*.png *.xpm *.jpg)"));


    int lastPoint = fileName.lastIndexOf(".");

    if (!fileName.data()->isNull() && lastPoint > 0){
        controller->mf_saveInputim(fileName.toStdString());
    }

}
//---------------------------------------------------------------------------------------
// Save output image
//---------------------------------------------------------------------------------------
void MainWindow::on_saveImage_clicked()
{
    // get save file name
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/jana/untitled.png",
                                                    tr("Images (*.png *.xpm *.jpg)"));

    int lastPoint = fileName.lastIndexOf(".");

    if (!fileName.data()->isNull() && lastPoint > 0){
        controller->mf_saveOutputim(fileName.toStdString());
    }

}
