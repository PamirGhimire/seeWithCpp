#ifndef MULTIVIEWPANE_H
#define MULTIVIEWPANE_H

#include <QWidget>
#include<qstring.h>
#include<qfiledialog.h>
#include<qdebug.h>

#include <opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace Ui {
class multiviewPane;
}

class multiviewPane : public QWidget
{
    Q_OBJECT

private slots:
    void on_pushButton_2_clicked();

    void on_closebutton_clicked();

    void on_setim1_clicked();

    void on_setim2_clicked();

    void on_match_clicked();

    void on_okbutton_clicked();

    void on_fundamentalMat_clicked();

private:
    Ui::multiviewPane *ui;

signals:
    // signal for loading im1
    void ms_setIm1_clicked();

    // signal for loading im2
    void ms_setIm2_clicked();

    // signal for matching
    void ms_im12Match_clicked();

    // signal for fundamental matrix computation
    void ms_fundamentalMat_clicked();


public:
    explicit multiviewPane(QWidget *parent = 0);
    ~multiviewPane();

    // filename for im1
    QString mv_im1name;

    // filename for im2
    QString mv_im2name;

    // choice of descriptor
    int mv_descriptor;

    // result of matching
    cv::Mat mv_displayim;

    // show result of matching
    void mf_showDisplayim();
    QImage mv_displayqim;
};

#endif // MULTIVIEWPANE_H
