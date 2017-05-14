#include "swc_structuringelementinput.h"
#include "ui_swc_structuringelementinput.h"

// default constructor
swc_structuringElementInput::swc_structuringElementInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swc_structuringElementInput)
{
    ui->setupUi(this);

    // initialize the structuring element
    mv_sel = cv::Mat(3, 3, CV_8UC1, cv::Scalar(1));

    // set the status of the check-boxes accordingly
    ui->sel00->setChecked(true);
    ui->sel01->setChecked(true);
    ui->sel02->setChecked(true);
    ui->sel10->setChecked(true);
    ui->sel11->setChecked(true);
    ui->sel12->setChecked(true);
    ui->sel20->setChecked(true);
    ui->sel21->setChecked(true);
    ui->sel22->setChecked(true);
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

    mv_sel.at<uchar>(1,0) = (ui->sel10->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,1) = (ui->sel11->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(1,2) = (ui->sel12->isChecked() == true? 1 : 0);

    mv_sel.at<uchar>(2,0) = (ui->sel20->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,1) = (ui->sel21->isChecked() == true? 1 : 0);
    mv_sel.at<uchar>(2,2) = (ui->sel22->isChecked() == true? 1 : 0);

    // signal that ok was clicked
    emit ms_ok_clicked();

    // close the ui
    this->close();

}

