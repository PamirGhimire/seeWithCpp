#include "swc_settwothresholds.h"
#include "ui_swc_settwothresholds.h"

//---------------------------------------------
// Default constructor:
//---------------------------------------------
swc_setTwoThresholds::swc_setTwoThresholds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swc_setTwoThresholds)
{
    ui->setupUi(this);
    ui->lowerThresh->setText(QString('0'));
    ui->upperThresh->setText(QString('0'));
}

//---------------------------------------------
// default destructor
//---------------------------------------------
swc_setTwoThresholds::~swc_setTwoThresholds()
{
    delete ui;
}

//---------------------------------------------
//ok button clicked
//---------------------------------------------
void swc_setTwoThresholds::on_okButton_clicked()
{
    // read line edits, update membember variables
    mv_lowerThresh = ui->lowerThresh->text().toFloat();
    mv_upperThresh = ui->upperThresh->text().toFloat();

    // emit signal announcing click
    emit ms_ok_clicked();

    // close the ui
    this->close();
}

//---------------------------------------------
//cancel button clicked
//---------------------------------------------
void swc_setTwoThresholds::on_cancelButton_clicked()
{
    this->close();
}
