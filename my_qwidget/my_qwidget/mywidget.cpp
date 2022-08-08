#include "mywidget.h"
#include "ui_mywidget.h"

/*
 *               QWidget (Base of all window-based classes)
 *                  |
 *          -----------------
 *          |                |
 * 		  QMainWindow       QDialog
 *
 */

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}
