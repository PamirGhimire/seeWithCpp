#include "swc_structuringelementinput.h"
#include "ui_swc_structuringelementinput.h"

// default constructor
swc_structuringElementInput::swc_structuringElementInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swc_structuringElementInput)
{
    ui->setupUi(this);

    // initialize the structuring element
    mv_sel = cv::Mat(5, 5, CV_8UC1, cv::Scalar(1));

    // set the status of the check-boxes accordingly
    ui->sel00->setChecked(true);
    ui->sel01->setChecked(true);
    ui->sel02->setChecked(true);
    ui->sel03->setChecked(true);
    ui->sel04->setChecked(true);

    ui->sel10->setChecked(true);
    ui->sel11->setChecked(true);
    ui->sel12->setChecked(true);
    ui->sel13->setChecked(true);
    ui->sel14->setChecked(true);

    ui->sel20->setChecked(true);
    ui->sel21->setChecked(true);
    ui->sel22->setChecked(true);
    ui->sel23->setChecked(true);
    ui->sel24->setChecked(true);

    ui->sel30->setChecked(true);
    ui->sel31->setChecked(true);
    ui->sel32->setChecked(true);
    ui->sel33->setChecked(true);
    ui->sel34->setChecked(true);

    ui->sel40->setChecked(true);
    ui->sel41->setChecked(true);
    ui->sel42->setChecked(true);
    ui->sel43->setChecked(true);
    ui->sel44->setChecked(true);

}



// default destructor
swc_structuringElementInput::~swc_structuringElementInput()
{
    delete ui;
}

//---------------------------------------------------------
// Returns structuring element
//---------------------------------------------------------
cv::Mat swc_structuringElementInput::mf_getSel()
{
    return mv_sel;
}

//---------------------------------------------------------
// Pushbutton ok
//---------------------------------------------------------
void swc_structuringElementInput::on_ok_clicked()
{
    // set the structuring element using status of checkboxes
    mv_sel.at<uchar>(0,0) = (ui->sel00->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(0,1) = (ui->sel01->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(0,2) = (ui->sel02->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(0,3) = (ui->sel03->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(0,4) = (ui->sel04->isChecked() == true? 1 : 0);

    mv_sel.at<uchar>(1,0) = (ui->sel10->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,1) = (ui->sel11->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,2) = (ui->sel12->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,3) = (ui->sel13->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,4) = (ui->sel14->isChecked() == true? 1 : 0);

    mv_sel.at<uchar>(2,0) = (ui->sel20->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,1) = (ui->sel21->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,2) = (ui->sel22->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,3) = (ui->sel23->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,4) = (ui->sel24->isChecked() == true? 1 : 0);

    mv_sel.at<uchar>(3,0) = (ui->sel30->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(3,1) = (ui->sel31->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(3,2) = (ui->sel32->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(3,3) = (ui->sel33->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(3,4) = (ui->sel34->isChecked() == true? 1 : 0);

    mv_sel.at<uchar>(4,0) = (ui->sel40->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(4,1) = (ui->sel40->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(4,2) = (ui->sel40->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(4,3) = (ui->sel40->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(4,4) = (ui->sel40->isChecked() == true? 1 : 0);

    // signal that ok was clicked
    emit ms_ok_clicked();

    // close the ui
    this->close();

}

