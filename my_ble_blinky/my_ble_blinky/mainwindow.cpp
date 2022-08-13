#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QBluetoothDeviceInfo>
#include <QBluetoothHostInfo>
#include <QBluetoothLocalDevice>
#include <QLowEnergyCharacteristic>

#include <QMutex>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , localDevice(new QBluetoothLocalDevice)
{
    ui->setupUi(this);

    // Initialize status.
    ui->labelStatus->setText("OFF");
    ui->labelBleConnectionStatus->setText("BLE disconnected...");


    QBluetoothAddress address("A0:9F:10:C0:79:7A");
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(address);
    discoveryAgent->setLowEnergyDiscoveryTimeout(2000);

    // Connect slot for new device discovery.
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(on_bleDeviceDiscovered(QBluetoothDeviceInfo)));

    // Connect slot for scan fininshing.
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(on_bleScanFinished()));

    // connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred, this,
            // &Device::deviceScanError);

    // connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &Device::deviceScanFinished);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete discoveryAgent;
}

void MainWindow::on_listWidgetBleDevices_itemClicked(QListWidgetItem *item)
{
    QString deviceAttributes = "";
    QBluetoothDeviceInfo deviceInfo = bleDevices[item->text()];
    deviceAttributes += "name " + deviceInfo.name() + "\n";
    deviceAttributes += "mac address " + deviceInfo.address().toString() + "\n";

    ui->textBrowserDeviceAttributes->setText(deviceAttributes);
}


void MainWindow::on_pushButtonToggle_clicked()
{
    if (ui->labelStatus->text() == "OFF") {
        ui->labelStatus->setText("ON");
    } else {
        ui->labelStatus->setText("OFF");
    }
}

void MainWindow::on_pushButtonBleConnect_clicked()
{
    if (NULL == ui->listWidgetBleDevices->currentItem()) {
        return;
    }

    ui->labelBleConnectionStatus->setText("Connecting...");
    QString userSelectedBleDeviceName = ui->listWidgetBleDevices->currentItem()->text();

    // Get the device from the bleDevices name-address lookup table.
    QBluetoothDeviceInfo deviceToConnect = bleDevices[userSelectedBleDeviceName];
    qInfo() << "Trying to connect to device: " << deviceToConnect.address();

    // Create a ble central device.
    bleController = QLowEnergyController::createCentral(deviceToConnect, this);
    qInfo() << bleController->state();

    // Callback when service is discovered.
    connect(bleController, &QLowEnergyController::serviceDiscovered,
            this, &MainWindow::on_bleServiceDiscovered);

    // Callback when discovery is finished.
    connect(bleController, &QLowEnergyController::discoveryFinished,
            this, &MainWindow::on_bleServiceScanFinished);

    connect(bleController,
            static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>
                (&QLowEnergyController::error),
            this,
            &MainWindow::on_bleControllerError);

    // Callback when connection is made.
    connect(bleController, &QLowEnergyController::connected, this, &MainWindow::on_bleControllerConnected);
    // Callback when disconnects.
    connect(bleController, &QLowEnergyController::disconnected, this, &MainWindow::on_bleControllerDisconnected);

    // Connect
    bleController->connectToDevice();
}

void MainWindow::on_bleDeviceDiscovered(const QBluetoothDeviceInfo &info)
{
    // Since we are only interested in Low Energy devices we filter the device type within the receiving slot.
    // The device type can be ascertained using the QBluetoothDeviceInfo::coreConfigurations() flag.
    // QString label = info.name() + " " + info.address().toString();
    // QString label = info.name();
    // qInfo() << info.name() << " " << info.serviceUuids();
    qInfo() << info.name();
    bleDevices[info.name()] = info;
    QListWidgetItem *item = new QListWidgetItem(info.name());
    ui->listWidgetBleDevices->addItem(item);
    //  // If the items does not exist in the list, then add to the list.
    //  if (items.empty()) {
    //      QListWidgetItem *item = new QListWidgetItem(label);
    //      ui->listWidgetBleDevices->addItem(item);
    //  }

    /*
    if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {

    } else {
        // skip.
    }
    */
}

/**
 * @brief Scan button clicked to scan peripheral ble devices.
 */
void MainWindow::on_pushButtonScan_clicked()
{
    ui->listWidgetBleDevices->clear();
    ui->pushButtonScan->setEnabled(false);

    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    ui->labelBleConnectionStatus->setText("Searching for peripheral devices...");
}


void MainWindow::on_bleScanFinished()
{
    ui->labelBleConnectionStatus->setText("Scan finished.");
    ui->pushButtonScan->setEnabled(true);
}


void MainWindow::on_bleServiceDiscovered(const QBluetoothUuid &gatt)
{
    ui->labelBleConnectionStatus->setText("Ble service is discovered");
    /*
    if (gatt == QBluetoothUuid::HeartRate) {
        qInfo() << "Heart rate service has been detected.";

        qInfo() << "uuid: " << gatt.toString();
        bleService = bleController->createServiceObject(gatt, this);
        bleService->discoverDetails();

        // Get a list of characteristics.
        bleCharacteristicsList = bleService->characteristics();
        for (auto characteristic : bleCharacteristicsList) {
            qInfo() << "characteristic name: " << characteristic.name();
        }
    }
    */
}

void MainWindow::on_bleServiceScanFinished()
{
    qInfo() << "ble service scan has finished";
    ui->labelBleConnectionStatus->setText("Connected. Service scan done.");
}



void MainWindow::on_bleControllerError()
{
    qWarning()<< "ble connection error";
    ui->labelBleConnectionStatus->setText("Disconnected. Connection error.");
}


void MainWindow::on_bleControllerConnected()
{
    qInfo() << "ble service connected";
    // Once connected, detect service from the device.
    bleController->discoverServices();
}

void MainWindow::on_bleControllerDisconnected()
{
    qInfo() << "ble service unconnected";
}




