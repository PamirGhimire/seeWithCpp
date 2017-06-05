#include "swc_matrixoutput.h"
#include "ui_swc_matrixoutput.h"

//---------------------------------------------------
// Default constructor
//---------------------------------------------------
swc_matrixOutput::swc_matrixOutput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::swc_matrixOutput)
{
    ui->setupUi(this);

    // Initialize member matrix and matrix name
    mv_mat = cv::Mat(3, 3, CV_32F, cv::Scalar(0));
    mv_matname = "Matrix";

}



swc_matrixOutput::~swc_matrixOutput()
{
    delete ui;
}

//---------------------------------------------------
// display matrix
//---------------------------------------------------
void swc_matrixOutput::mf_displayMvmat(){

    ui->matname->setText(mv_matname);

    ui->mat00->setText(QString::number(mv_mat.at<float>(0, 0)));
    ui->mat01->setText(QString::number(mv_mat.at<float>(0, 1)));
    ui->mat02->setText(QString::number(mv_mat.at<float>(0, 2)));

    ui->mat10->setText(QString::number(mv_mat.at<float>(1, 0)));
    ui->mat11->setText(QString::number(mv_mat.at<float>(1, 1)));
    ui->mat12->setText(QString::number(mv_mat.at<float>(1, 2)));

    ui->mat20->setText(QString::number(mv_mat.at<float>(2, 0)));
    ui->mat21->setText(QString::number(mv_mat.at<float>(2, 1)));
    ui->mat22->setText(QString::number(mv_mat.at<float>(2, 2)));

    this->show();
    this->raise();

}
