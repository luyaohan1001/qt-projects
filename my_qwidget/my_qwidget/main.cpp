#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Entry function, initialize the main window.
    MainWindow w;
    w.show();
    return a.exec();
}
