#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize a processes pane
    mw_oneViewProcessesPane = new processesPane();

    // Initialize default one-view process as identity transform
    mv_currentOneViewProcess = identity;

    //----------------------------------------------------------
    // Connecting one-view process pane signals with mainwindow slots:
    //----------------------------------------------------------
    connect(mw_oneViewProcessesPane, SIGNAL(ms_applyButtonClicked()), this, SLOT(on_apply_in_processPane_clicked()) );
    //----------------------------------------------------------
}

//----------------------------------------------------------
// Destructor of main window
//----------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------------------------------------
// Show one-view processes pane
//----------------------------------------------------------
void MainWindow::on_processesPane_clicked()
{
    mw_oneViewProcessesPane->show();
}

//----------------------------------------------------------
// Update code for current process when a process is applied
// in the one-view process pane
//----------------------------------------------------------
void MainWindow::on_apply_in_processPane_clicked()
{
    mv_currentOneViewProcess = mw_oneViewProcessesPane->mf_getCurrentOneViewProcess();
}
