#include "processespane.h"
#include "ui_processespane.h"

processesPane::processesPane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::processesPane)
{
    ui->setupUi(this);

    // Initialize default one-view process as identity transformation
    mv_currentOneViewProcess = identity;

    //----------------------------------------------------
    // ADD IMAGE-TO-IMAGE PROCESSES
    //----------------------------------------------------
    ui->i2iProcesses->addItem("Add salt and pepper noise");     //oneviewPcode 0
    ui->i2iProcesses->addItem("Show Logo at top left corner");  //oneviewPcode 1
    ui->i2iProcesses->addItem("Convert to new colorspace");     //oneviewPcode 2
    ui->i2iProcesses->addItem("Equalize histogram");            //oneviewPcode 3
    ui->i2iProcesses->addItem("Dilate");        //oneviewPcode 4
    ui->i2iProcesses->addItem("Erode");         //oneviewPcode 5
    ui->i2iProcesses->addItem("Open");          //oneviewPcode 6
    ui->i2iProcesses->addItem("Close");         //oneviewPcode 7
    ui->i2iProcesses->addItem("Blur");          //oneviewPcode 8
    ui->i2iProcesses->addItem("Apply Sobel");   //oneviewPcode 9
    ui->i2iProcesses->addItem("Apply Laplacian");           //oneviewPcode 10
    ui->i2iProcesses->addItem("Apply custom kernel");       //oneviewPcode 11
    ui->i2iProcesses->addItem("Detect Edges using Canny");  //oneviewPcode 12
    ui->i2iProcesses->addItem("Extract lines and Circles using Hough");     //oneviewPcode 13
    ui->i2iProcesses->addItem("Find contours of connected components");     //oneviewPcode 14
    //----------------------------------------------------

}

//---------------------------------------------------------------------
// Destructor of one-view process pane:
//---------------------------------------------------------------------
processesPane::~processesPane()
{
    delete ui;
}


//---------------------------------------------------------------------
//
//---------------------------------------------------------------------
void processesPane::on_i2iProcesses_activated(const QModelIndex &index)
{

}

//---------------------------------------------------------------------
// Close the one-view process pane:
//---------------------------------------------------------------------
void processesPane::on_close_clicked()
{
    this->close();
}

//---------------------------------------------------------------------
// Apply user's selection of one-view process:
//---------------------------------------------------------------------
void processesPane::on_apply_clicked()
{
    mv_currentOneViewProcess = ui->i2iProcesses->currentRow();
    emit ms_applyButtonClicked();
}
//---------------------------------------------------------------------
// Returns process-code word of current 'applied' process
//---------------------------------------------------------------------
int processesPane::mf_getCurrentOneViewProcess(){
    return mv_currentOneViewProcess;
}
