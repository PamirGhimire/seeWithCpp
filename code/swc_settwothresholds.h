#ifndef SWC_SETTWOTHRESHOLDS_H
#define SWC_SETTWOTHRESHOLDS_H

#include <QDialog>

namespace Ui {
class swc_setTwoThresholds;
}

class swc_setTwoThresholds : public QDialog
{
    Q_OBJECT

public:
    explicit swc_setTwoThresholds(QWidget *parent = 0);
    ~swc_setTwoThresholds();

    // lower threshold
    double mv_lowerThresh;

    // upper threshold
    double mv_upperThresh;


private:
    Ui::swc_setTwoThresholds *ui;

signals:
    void ms_ok_clicked();
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // SWC_SETTWOTHRESHOLDS_H
