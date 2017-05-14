#include "swc_matrixinput.h"
#include "ui_swc_matrixinput.h"

swc_matrixInput::swc_matrixInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swc_matrixInput)
{
    ui->setupUi(this);
}

swc_matrixInput::~swc_matrixInput()
{
    delete ui;
}
