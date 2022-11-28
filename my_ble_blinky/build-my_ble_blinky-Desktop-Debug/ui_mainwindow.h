/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonBleConnect;
    QLabel *labelStatus;
    QPushButton *pushButtonToggle;
    QPushButton *pushButtonScan;
    QListWidget *listWidgetBleDevices;
    QLabel *labelBleConnectionStatus;
    QTextBrowser *textBrowserDeviceAttributes;
    QPushButton *pushButtonOpenHeartRateDialog;
    QMenuBar *menubar;
    QMenu *menuBluetooth_LE_Console;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(527, 605);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonBleConnect = new QPushButton(centralwidget);
        pushButtonBleConnect->setObjectName(QString::fromUtf8("pushButtonBleConnect"));
        pushButtonBleConnect->setGeometry(QRect(10, 320, 131, 41));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(370, 330, 81, 21));
        pushButtonToggle = new QPushButton(centralwidget);
        pushButtonToggle->setObjectName(QString::fromUtf8("pushButtonToggle"));
        pushButtonToggle->setGeometry(QRect(140, 320, 181, 41));
        pushButtonScan = new QPushButton(centralwidget);
        pushButtonScan->setObjectName(QString::fromUtf8("pushButtonScan"));
        pushButtonScan->setGeometry(QRect(10, 0, 181, 21));
        listWidgetBleDevices = new QListWidget(centralwidget);
        listWidgetBleDevices->setObjectName(QString::fromUtf8("listWidgetBleDevices"));
        listWidgetBleDevices->setGeometry(QRect(10, 20, 501, 301));
        labelBleConnectionStatus = new QLabel(centralwidget);
        labelBleConnectionStatus->setObjectName(QString::fromUtf8("labelBleConnectionStatus"));
        labelBleConnectionStatus->setGeometry(QRect(200, 0, 251, 21));
        textBrowserDeviceAttributes = new QTextBrowser(centralwidget);
        textBrowserDeviceAttributes->setObjectName(QString::fromUtf8("textBrowserDeviceAttributes"));
        textBrowserDeviceAttributes->setGeometry(QRect(10, 360, 501, 201));
        pushButtonOpenHeartRateDialog = new QPushButton(centralwidget);
        pushButtonOpenHeartRateDialog->setObjectName(QString::fromUtf8("pushButtonOpenHeartRateDialog"));
        pushButtonOpenHeartRateDialog->setGeometry(QRect(470, 320, 41, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 527, 22));
        menuBluetooth_LE_Console = new QMenu(menubar);
        menuBluetooth_LE_Console->setObjectName(QString::fromUtf8("menuBluetooth_LE_Console"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBluetooth_LE_Console->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonBleConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Light off", nullptr));
        pushButtonToggle->setText(QCoreApplication::translate("MainWindow", "Toggle Blinky", nullptr));
        pushButtonScan->setText(QCoreApplication::translate("MainWindow", "Scan Peripheral Devices", nullptr));
        labelBleConnectionStatus->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonOpenHeartRateDialog->setText(QString());
        menuBluetooth_LE_Console->setTitle(QCoreApplication::translate("MainWindow", "Bluetooth LE Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
