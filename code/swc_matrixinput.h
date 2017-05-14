#ifndef SWC_MATRIXINPUT_H
#define SWC_MATRIXINPUT_H

#include <QDialog>

namespace Ui {
class swc_matrixInput;
}

class swc_matrixInput : public QDialog
{
    Q_OBJECT

public:
    explicit swc_matrixInput(QWidget *parent = 0);
    ~swc_matrixInput();

private:
    Ui::swc_matrixInput *ui;
};

#endif // SWC_MATRIXINPUT_H
