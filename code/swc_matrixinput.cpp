#include "swc_matrixinput.h"
#include "ui_swc_matrixinput.h"
#include<qdebug.h>

swc_matrixInput::swc_matrixInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swc_matrixInput)
{
    ui->setupUi(this);

    // Initialize the 3x3 kernel to identity
    mv_kernel = cv::Mat(3, 3, CV_32F, cv::Scalar(0));
    mv_kernel.at<float>(1,1) = 1;

    // initialize the 9 line edits accordingly
    ui->ker00->setText(QString('0'));
    ui->ker01->setText(QString('0'));
    ui->ker02->setText(QString('0'));

    ui->ker10->setText(QString('0'));
    ui->ker11->setText(QString('1'));
    ui->ker12->setText(QString('0'));

    ui->ker20->setText(QString('0'));
    ui->ker21->setText(QString('0'));
    ui->ker22->setText(QString('0'));
}


swc_matrixInput::~swc_matrixInput()
{
    delete ui;
}

//------------------------------------------
//OK button clicked
//------------------------------------------
void swc_matrixInput::on_Ok_button_clicked()
{
    // read the line edits and set kernel accordingly
    mv_kernel.at<float>(0,0) = ui->ker00->text().toFloat();
    mv_kernel.at<float>(0,1) = ui->ker01->text().toFloat();
    mv_kernel.at<float>(0,2) = ui->ker02->text().toFloat();

    mv_kernel.at<float>(1,0) = ui->ker10->text().toFloat();
    mv_kernel.at<float>(1,1) = ui->ker11->text().toFloat();
    mv_kernel.at<float>(1,2) = ui->ker12->text().toFloat();

    mv_kernel.at<float>(2,0) = ui->ker20->text().toFloat();
    mv_kernel.at<float>(2,1) = ui->ker21->text().toFloat();
    mv_kernel.at<float>(2,2) = ui->ker22->text().toFloat();

    // emit signal to inform about button press
    emit ms_ok_clicked();

    // close the input ui
    this->close();
}

//------------------------------------------
//Cancel button clicked
//------------------------------------------
void swc_matrixInput::on_cancel_button_clicked()
{
    this->close();
}
