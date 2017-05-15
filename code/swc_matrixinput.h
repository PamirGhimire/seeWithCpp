#ifndef SWC_MATRIXINPUT_H
#define SWC_MATRIXINPUT_H

#include <QDialog>
#include<opencv2/core/core.hpp>


namespace Ui {
class swc_matrixInput;
}

class swc_matrixInput : public QDialog
{
    Q_OBJECT

public:
    // kernel set in the ui
    cv::Mat mv_kernel;

    explicit swc_matrixInput(QWidget *parent = 0);
    ~swc_matrixInput();

private:
    Ui::swc_matrixInput *ui;

signals:
    void ms_ok_clicked();
private slots:
    void on_Ok_button_clicked();
    void on_cancel_button_clicked();
};

#endif // SWC_MATRIXINPUT_H
