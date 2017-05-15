#ifndef PROCESSESPANE_H
#define PROCESSESPANE_H

#include <QDialog>
#include<qdebug.h>

//----------------------------------------------------
// One-view process code words:
//----------------------------------------------------
// Identity Transformation           //oneviewPcode -100
//("Add salt and pepper noise");     //oneviewPcode 0
//("Show Logo at bottom right corner");  //oneviewPcode 1
//("Convert to new colorspace");     //oneviewPcode 2
//("Equalize histogram");            //oneviewPcode 3
//("Dilate");        //oneviewPcode 4
//("Erode");         //oneviewPcode 5
//("Open");          //oneviewPcode 6
//("Close");         //oneviewPcode 7
//("Blur");          //oneviewPcode 8
//("Apply Sobel");   //oneviewPcode 9
//("Apply Laplacian");           //oneviewPcode 10
//("Apply custom kernel");       //oneviewPcode 11
//("Detect Edges using Canny");  //oneviewPcode 12
//("Extract lines and Circles using Hough");     //oneviewPcode 13
//("Find contours of connected components");     //oneviewPcode 14
//("Compute Histogram")                         //oneviewPcode 15
enum{addSaltAndPepper = 0,
     showLogo = 1,
     convertToNewCspace = 2,
     equalizeHistogram = 3,
     dilate = 4,
     erode = 5,
     open_morph = 6,
     close_morph = 7,
     blur = 8,
     sobel = 9,
     laplacian = 10,
     customKernel = 11,
     cannyedge = 12,
     showHistogram = 15,
     identity = -100};
//----------------------------------------------------

namespace Ui {
class processesPane;
}

class processesPane : public QDialog
{
    Q_OBJECT

private:
    Ui::processesPane *ui;

    // current one-view process code
    int mv_currentOneViewProcess;

private slots:


    void on_i2iProcesses_activated(const QModelIndex &index);

    void on_close_clicked();

    void on_apply_clicked();

    void on_setDetails_clicked();

    void on_i2mProcesses_activated(const QModelIndex &index);

signals:
    // Emitted when apply button is clicked in one-view process pane
    void ms_applyButtonClicked();

    // Emitted when set details button is clicked in one-view process pane
    void ms_setDetailsButtonClicked();

public:
    explicit processesPane(QWidget *parent = 0);
    ~processesPane();

    // Returns process-code word of current 'applied' process
    int mf_getCurrentOneViewProcess();


};

#endif // PROCESSESPANE_H
