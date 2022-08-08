#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bt_console.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bt_console bt_console;
}

MainWindow::~MainWindow()
{
    delete ui;
}

