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
    ui->i2iProcesses->addItem("Show Logo at bottom right corner");  //oneviewPcode 1
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

    //----------------------------------------------------
    // ADD IMAGE-TO-MEASUREMENT PROCESSES:
    //----------------------------------------------------
    ui->i2mProcesses->addItem("Compute Histogram");
}

//---------------------------------------------------------------------
// Destructor of one-view process pane:
//---------------------------------------------------------------------
processesPane::~processesPane()
{
    delete ui;
}


//---------------------------------------------------------------------
// I2I Processes:
//---------------------------------------------------------------------
void processesPane::on_i2iProcesses_activated(const QModelIndex &index)
{
    ui->i2mProcesses->setCurrentRow(-100);
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
    if (ui->i2iProcesses->currentRow() > 0){
        mv_currentOneViewProcess = ui->i2iProcesses->currentRow();
    }else{
        mv_currentOneViewProcess = 15 + ui->i2mProcesses->currentRow();
    }

    qDebug()<< mv_currentOneViewProcess;
    emit ms_applyButtonClicked();
}
//---------------------------------------------------------------------
// Returns process-code word of current 'applied' process
//---------------------------------------------------------------------
int processesPane::mf_getCurrentOneViewProcess(){
    return mv_currentOneViewProcess;
}

//---------------------------------------------------------------------
// Set parameters (details) for user's process of choice:
// Signal to the mainwindow that user wants to set details
//---------------------------------------------------------------------
void processesPane::on_setDetails_clicked()
{
    int temp = mv_currentOneViewProcess;
    mv_currentOneViewProcess = ui->i2iProcesses->currentRow();
    emit ms_setDetailsButtonClicked();
    mv_currentOneViewProcess = temp;
    qDebug() << mv_currentOneViewProcess << " returned to previous";
}

//---------------------------------------------------------------------
// I2Measurement Processes:
//---------------------------------------------------------------------
void processesPane::on_i2mProcesses_activated(const QModelIndex &index)
{
    ui->i2iProcesses->setCurrentRow(-100);

}
