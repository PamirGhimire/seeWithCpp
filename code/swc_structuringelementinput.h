#ifndef SWC_STRUCTURINGELEMENTINPUT_H
#define SWC_STRUCTURINGELEMENTINPUT_H

#include <QDialog>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>


namespace Ui {
class swc_structuringElementInput;
}

class swc_structuringElementInput : public QDialog
{
    Q_OBJECT
private:
    Ui::swc_structuringElementInput *ui;

    // structuring element
    cv::Mat mv_sel;


public:
    // default constructor
    explicit swc_structuringElementInput(QWidget *parent = 0);

    // default destructor
    ~swc_structuringElementInput();

    // returns the structuring element
    cv::Mat mf_getSel();

private slots:
    void on_ok_clicked();

signals:
    void ms_ok_clicked();
};

#endif // SWC_STRUCTURINGELEMENTINPUT_H
