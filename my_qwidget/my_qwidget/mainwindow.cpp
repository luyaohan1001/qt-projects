#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"

// #define SHOW_WIDGETS_AS_SEPARATE_WINDOW
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifdef SHOW_WIDGETS_AS_SEPARATE_WINDOW
    // Display the my widget as a separate window, the parent object is not specified.
    MyWidget *myWidget = new MyWidget;
    myWidget->show();
#else
    // Parent pointer pointing to child object, example of polymorphism.
    // Prototype in MyWidget.h: explicit MyWidget(QWidget *parent = nullptr);
    // When the widget has initialized its parent, 'this', in this case.
    // When its parent shows, the my widget also shows within its parent.
    myWidget = new MyWidget(this);
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myWidget;
}

