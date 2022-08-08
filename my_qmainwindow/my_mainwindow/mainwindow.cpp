#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *               QWidget (Base of all window-based classes)
 *                  |
 *          -----------------
 *          |                |
 * 		  QMainWindow       QDialog
 *
 * QMainWindow also cannot be embedded into another window.
 * It can have:
 * 1. MenuBar. 菜单栏 --> can only have one.
 * 2. ToolBar. 工具栏 --> Can have multiple.
 * 3. StatusBar. 状态栏 --> can only have one.
 * Add or delete these in mainwindow.ui.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

