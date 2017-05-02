#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize the process manager
    processManager = new swc_processManager();

    // Initialize the controller
    controller = new swc_controller();

    // Initialize the processes pane
    mw_oneViewProcessesPane = new processesPane();

    // Initialize default one-view process as identity transform
    mv_currentOneViewProcess = identity;

    //----------------------------------------------------------
    // Connecting one-view process pane signals with mainwindow slots:
    //----------------------------------------------------------
    connect(mw_oneViewProcessesPane, SIGNAL(ms_applyButtonClicked()), this, SLOT(on_apply_in_processPane_clicked()) );
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

    // update current-process display
    QString currProcess = QString::fromStdString(processManager->mf_getProcessName(mv_currentOneViewProcess) );
    ui->currentOneviewProcess->document()->setPlainText(currProcess);

    // tell the process manager to execute current process code
    processManager->mf_executeProcess(mv_currentOneViewProcess, controller);

    // update display
    mf_mainwindow_setdisplay();
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

    // ask controller to load the fileName bearing image
    controller->mf_setInputImage(fileName.toStdString());

    // update display
    mf_mainwindow_setdisplay();
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

    // add logo if logoflag is true
    if (logoFlag == true){
        controller->addLogo_process_addLogoTo(displayim_in, displayim_in);
        controller->addLogo_process_addLogoTo(displayim_out, displayim_out);
    }

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
    processManager->mf_executeProcess(mv_currentOneViewProcess, controller);
    mf_mainwindow_setdisplay();
}
