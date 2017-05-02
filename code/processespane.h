#ifndef PROCESSESPANE_H
#define PROCESSESPANE_H

#include <QDialog>
#include<qdebug.h>

//----------------------------------------------------
// One-view process code words:
//----------------------------------------------------
// Identity Transformation           //oneviewPcode -100
//("Add salt and pepper noise");     //oneviewPcode 0
//("Show Logo at top left corner");  //oneviewPcode 1
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
enum{addSaltAndPepper,
    showLogo,
    convertToNewCspace,
    equalizeHistogram,
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

signals:
    // Emitted when apply button is clicked in one-view process pane
    void ms_applyButtonClicked();

public:
    explicit processesPane(QWidget *parent = 0);
    ~processesPane();

    // Returns process-code word of current 'applied' process
    int mf_getCurrentOneViewProcess();


};

#endif // PROCESSESPANE_H