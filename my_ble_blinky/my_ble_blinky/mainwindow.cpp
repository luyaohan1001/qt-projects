#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QBluetoothDeviceInfo>
#include <QBluetoothHostInfo>
#include <QBluetoothLocalDevice>
#include <QLowEnergyCharacteristic>
#include <QLowEnergyDescriptor>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @note  Constructs the main window on the program start.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , localDevice(new QBluetoothLocalDevice)
{
    ui->setupUi(this);

    // Initialize status.
    ui->labelStatus->setText("OFF");
    ui->labelBleConnectionStatus->setText("BLE disconnected...");
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
    deviceAttributes += "Name: " + deviceInfo.name() + "\n";
    deviceAttributes += "MAC address: " + deviceInfo.address().toString() + "\n";
    ui->textBrowserDeviceAttributes->setText(deviceAttributes);
}




void MainWindow::on_pushButtonToggle_clicked()
{
    if (ui->labelStatus->text() == "OFF") {
        ui->labelStatus->setText("ON");
        QByteArray ba = QByteArrayLiteral("\x01");
        bleService->writeCharacteristic(*bleCharacteristic, ba, QLowEnergyService::WriteWithoutResponse);
    } else {
        QByteArray ba = QByteArrayLiteral("\x00");
        bleService->writeCharacteristic(*bleCharacteristic, ba, QLowEnergyService::WriteWithoutResponse);
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
    QString textToAppend = "Trying to connect to device: " + deviceToConnect.address().toString() + "...\n";
    ui->textBrowserDeviceAttributes->append(textToAppend);



    // Create a ble central device.
    bleController = QLowEnergyController::createCentral(deviceToConnect);
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
    bleController->disconnectFromDevice();
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
    if (discoveryAgent != NULL) {
        delete discoveryAgent;
    }
    QBluetoothAddress address("A0:9F:10:C0:79:7A");
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(address);
    discoveryAgent->setLowEnergyDiscoveryTimeout(3000);

    // Connect slot for new device discovery.
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(on_bleDeviceDiscovered(QBluetoothDeviceInfo)));

    // Connect slot for scan fininshing.
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(on_bleScanFinished()));

    // connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred, this,
            // &Device::deviceScanError);

    // connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &Device::deviceScanFinished);

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




// -------- Service related functions -------
void MainWindow::on_bleServiceDiscovered(const QBluetoothUuid &gatt)
{
    QString textToAppend = "";
    textToAppend += "ble service discovered:\n";
    textToAppend += "uuid: " + gatt.toString() + "\n";

    bleService = bleController->createServiceObject(gatt, this);
    bleService->discoverDetails();

    // connect(bleService, &QLowEnergyService::characteristicRead, this, &MainWindow::on_bleCharacteristicRead);


    // Get a list of characteristics.
    bleCharacteristicsList = bleService->characteristics();

    for (auto characteristic : bleCharacteristicsList) {
        // textToAppend +=  "characteristic name: " + characteristic.name() + "\n";
        textToAppend += "uuid: " + characteristic.uuid().toString() + "\n";

        if (characteristic.uuid().toString() == "{00001525-1212-efde-1523-785feabcd123}") {
            bleCharacteristic = new QLowEnergyCharacteristic(characteristic);
            ui->textBrowserDeviceAttributes->append("======");
            ui->textBrowserDeviceAttributes->append("Found led characteritics,  writing value...\n");
            ui->textBrowserDeviceAttributes->append(characteristic.name());
            ui->textBrowserDeviceAttributes->append(characteristic.uuid().toString());
            ui->textBrowserDeviceAttributes->append(characteristic.value());
            qInfo() << bleService->state();
            ui->textBrowserDeviceAttributes->append("======");

            QByteArray ba;
            ba.append(0x01);
            bleService->writeCharacteristic(characteristic, ba, QLowEnergyService::WriteWithoutResponse);
            bleService->readCharacteristic(characteristic);
        }

    }

    ui->textBrowserDeviceAttributes->append(textToAppend);
}

void MainWindow::on_bleServiceScanFinished()
{
    qInfo() << "ble service scan has finished";
    ui->labelBleConnectionStatus->setText("Connected. Service scan has finished.");
}



void MainWindow::on_bleControllerError(QLowEnergyController::Error)
{
    // qWarning()<< "ble connection error";
    qWarning() << "Error: " << bleController->errorString();
    qWarning() << bleController->error();

    ui->labelBleConnectionStatus->setText("Disconnected. Connection error.");

    QString textToAppend = bleController->errorString() + "\n";
    ui->textBrowserDeviceAttributes->append(textToAppend);
}


void MainWindow::on_bleControllerConnected()
{
    qInfo() << "ble controller connected";

    QString textToAppend =  "ble controller connected";
    ui->textBrowserDeviceAttributes->append(textToAppend);

    // Once connected, detect service from the device.
    bleController->discoverServices();
}

void MainWindow::on_bleControllerDisconnected()
{
    qInfo() << "ble service unconnected";
}


