#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h" // needs to be included to create a dialog here.

// #define MAKE_DIALOG_WINDOW_BLOCKING

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Unlike widget, QDialog cannot be embedded in another window.
    // exec() will block other window until dialog box is closed.
#ifdef MAKE_DIALOG_WINDOW_BLOCKING
    MyDialog *myDialog = new MyDialog(this);
    myDialog->exec();
#else
    MyDialog *myDialog = new MyDialog(this);
    // show() simply shows the dialog as a separate window.
    myDialog->show();
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}

