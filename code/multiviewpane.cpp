#include "multiviewpane.h"
#include "ui_multiviewpane.h"

multiviewPane::multiviewPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multiviewPane)
{
    ui->setupUi(this);
}

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

    if (!mv_im1name.data()->isNull()){
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

    if (!mv_im2name.data()->isNull()){
        // signal (mainwindow -> controller) to load the fileName bearing image into mv_im1
        emit ms_setIm2_clicked();
    }
}

//---------------------------------------------
// Button : match im1-2 clicked
//---------------------------------------------
void multiviewPane::on_match_clicked()
{
    emit ms_im12Match_clicked();
}
