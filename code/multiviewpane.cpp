#include "multiviewpane.h"
#include "ui_multiviewpane.h"

//---------------------------------------------
// DEFAULT CONSTRUCTOR
//---------------------------------------------
multiviewPane::multiviewPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multiviewPane)
{
    ui->setupUi(this);

    // set default descriptor as sift
    mv_descriptor = 1;

    ui->Descriptor->addItem("SIFT");
    ui->Descriptor->addItem("SURF");

    // match can not be clicked without selecting images
    ui->match->setEnabled(false);
    ui->fundamentalMat->setEnabled(false);
    ui->undistort->setEnabled(false);

    mv_displayim = cv::Mat(500, 500, CV_32F, cv::Scalar(255, 200, 240));
    mf_showDisplayim();
}

//---------------------------------------------
// DEFAULT DESTRUCTOR
//---------------------------------------------
multiviewPane::~multiviewPane()
{
    delete ui;
}

// VESTIGIAL SLOT FOR CLOSE PUSHBUTTON
void multiviewPane::on_pushButton_2_clicked(){}

//---------------------------------------------
// Close button
//---------------------------------------------
void multiviewPane::on_closebutton_clicked()
{
    this->close();
}

//---------------------------------------------
// Button : load im1
//---------------------------------------------
void multiviewPane::on_setim1_clicked()
{
    // get file name of image from ui
    mv_im1name = QFileDialog::getOpenFileName(this, tr("Open Image"), "../../../", tr("Image Files(*.png *.jpg *jpeg *.bmp)") );

    // if a filename was selected for image 1
    if (!mv_im1name.data()->isNull()){

        // enable match button if a file was selected for second image as well
        if (!mv_im2name.data()->isNull()){
            ui->match->setEnabled(true);
            ui->fundamentalMat->setEnabled(true);

        }

        ui->multiviewOp->setText(mv_im1name);
        // signal (mainwindow -> controller) to load the fileName bearing image into mv_im1
        emit ms_setIm1_clicked();
    }
}

//---------------------------------------------
// Button : load im2
//---------------------------------------------
void multiviewPane::on_setim2_clicked()
{
    // get file name of image from ui
    mv_im2name = QFileDialog::getOpenFileName(this, tr("Open Image"), "../../../", tr("Image Files(*.png *.jpg *jpeg *.bmp)") );

    // enable match button if a file was selected for second image as well
    if (!mv_im2name.data()->isNull()){

        // enable match button if a file was selected for first image as well
        if (!mv_im1name.data()->isNull()){
            ui->match->setEnabled(true);
            ui->fundamentalMat->setEnabled(true);

        }

        ui->multiviewOp->setText(mv_im2name);
        // signal (mainwindow -> controller) to load the fileName bearing image into mv_im1
        emit ms_setIm2_clicked();
    }
}

//---------------------------------------------
// Button : match im1-2 clicked
//---------------------------------------------
void multiviewPane::on_match_clicked()
{
    ui->multiviewOp->setText("Point Correspondences");
    mv_descriptor = 1 + ui->Descriptor->currentIndex();
    emit ms_im12Match_clicked();
}

//---------------------------------------------
// show result of matching
//---------------------------------------------
void multiviewPane::mf_showDisplayim(){

    cv::Mat showim;
    cv::resize(mv_displayim, showim, cv::Size(ui->MultiviewDisplay->width(), ui->MultiviewDisplay->height()) );

    // get qt-label compatible image from input
    mv_displayqim = QImage((const unsigned char*)(showim.data), showim.cols, showim.rows, QImage::Format_RGB888);

    // set output label to display output qimage
    ui->MultiviewDisplay->setPixmap(QPixmap::fromImage(mv_displayqim));
}


//---------------------------------------------
// ok button : close window
//---------------------------------------------
void multiviewPane::on_okbutton_clicked()
{
    this->close();
}

//---------------------------------------------
// Fundamental Matrix button
//---------------------------------------------
void multiviewPane::on_fundamentalMat_clicked()
{
    ui->multiviewOp->setText("Fundamental Matrix and Epipolar Lines");
    emit ms_fundamentalMat_clicked();
}

//---------------------------------------------
// Descriptor selector dropdown
//---------------------------------------------
void multiviewPane::on_Descriptor_activated(const QString &arg1)
{
    mv_descriptor = 1 + ui->Descriptor->currentIndex();
}

//---------------------------------------------
// Select directory of calibration images
//---------------------------------------------
void multiviewPane::on_calImagesDir_clicked()
{
    QString folderpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),                                                 "../../..",
                                                           QFileDialog::ShowDirsOnly
                                                           | QFileDialog::DontResolveSymlinks);

    // if a directory was chosen
    if(!folderpath.data()->isNull()){

        // update multiview operation info. display
        ui->multiviewOp->setText(folderpath);

        if(!folderpath.isEmpty()){

            QDir dir(folderpath);

            // extension filters: we want to look at image files only
            QStringList filter;
            filter << QLatin1String("*.png");
            filter << QLatin1String("*.jpeg");
            filter << QLatin1String("*.jpg");

            dir.setNameFilters(filter);
            QFileInfoList filelistinfo = dir.entryInfoList();

            mv_calibrationImageFiles.clear();
            foreach (const QFileInfo &fileinfo, filelistinfo) {
                QString imageFile = fileinfo.absoluteFilePath();
                //imageFile is the image path, just put your (load image) code here
                mv_calibrationImageFiles.push_back(imageFile.toStdString());
            }
        }

    }


}

//---------------------------------------------
// calibrate camera button pressed in multi-view and geometry pane
//---------------------------------------------
void multiviewPane::on_calibrateButton_clicked()
{
    // signal calibration only if some images available
    if (!mv_calibrationImageFiles.empty()){
        ui->multiviewOp->setText("Calibrating camera, please hold your breath!");
        ui->undistort->setEnabled(true);

        emit ms_calibrate_clicked();
        qDebug() << "calibrating camera";
    }
}

//---------------------------------------------
// Undistort input image
//---------------------------------------------
void multiviewPane::on_undistort_clicked()
{
    ui->multiviewOp->setText("Undistorted input using camera matrix");
    emit ms_undistort_clicked();
}
