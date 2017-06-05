#ifndef SWC_MATRIXOUTPUT_H
#define SWC_MATRIXOUTPUT_H

#include <QWidget>
#include<opencv2/core/core.hpp>

namespace Ui {
class swc_matrixOutput;
}

class swc_matrixOutput : public QWidget
{
    Q_OBJECT

public:
    explicit swc_matrixOutput(QWidget *parent = 0);
    ~swc_matrixOutput();

    // display matrix
    cv::Mat mv_mat;

    // matrix name
    QString mv_matname;

    // display matrix
    void mf_displayMvmat();

private:
    Ui::swc_matrixOutput *ui;
};

#endif // SWC_MATRIXOUTPUT_H
