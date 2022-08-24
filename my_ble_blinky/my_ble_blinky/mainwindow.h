#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothLocalDevice>

#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QListWidgetItem>

#include <QMutex>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonToggle_clicked();

    // Callbacks for searching ble devices.
    void on_pushButtonScan_clicked();
    void on_bleDeviceDiscovered(const QBluetoothDeviceInfo &info);
    void on_bleScanFinished();

    // Callbacks for connecting to peripherals and search for services.
    void on_pushButtonBleConnect_clicked();
    void on_bleServiceDiscovered(const QBluetoothUuid &gatt);
    void on_bleServiceScanFinished();
    void on_bleControllerError(QLowEnergyController::Error);
    void on_bleControllerConnected();
    void on_bleControllerDisconnected();

    void on_listWidgetBleDevices_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QBluetoothLocalDevice *localDevice;

    // Discovers ble devices.
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = NULL;
    // Stores bleDevices Name - Address
    QHash<QString, QBluetoothDeviceInfo> bleDevices;

    // Create a central device.
    QLowEnergyController *bleController;

    // Create a ble service.
    QLowEnergyService *bleService;

    // Create a ble characteristics.
    QList<QLowEnergyCharacteristic> bleCharacteristicsList;

    // ble characiertics interested to read/write
    QLowEnergyCharacteristic *bleCharacteristic;
};
#endif // MAINWINDOW_H
