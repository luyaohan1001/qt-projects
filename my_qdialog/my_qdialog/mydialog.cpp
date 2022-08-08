#include "mydialog.h"
#include "ui_mydialog.h"


/*
 *               QWidget (Base of all window-based classes)
 *                  |
 *          -----------------
 *          |                |
 * 		  QMainWindow       QDialog
 *
 */
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}
