#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @note  Constructs the main window on the program start.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_localDevice(new QBluetoothLocalDevice)
{
    ui->setupUi(this);

    // Initialize status.
    ui->labelStatus->setText("OFF");
    ui->labelBleConnectionStatus->setText("BLE disconnected...");

    ui->pushButtonOpenHeartRateDialog->setIcon(QIcon(":/my_resources/icons/heart-icon.png"));
    ui->pushButtonOpenHeartRateDialog->setIconSize(QSize(50,50));
    ui->pushButtonOpenHeartRateDialog->setEnabled(false);

}



/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete m_localDevice;

    if (NULL != m_discoveryAgent) {
        // (!) Must call stop method. Otherwise when Linux goes to sleep BlueZ will catch in "Unknown Remomte Device Error".
        m_discoveryAgent->stop();
        delete m_discoveryAgent;
    }


    if (NULL != m_bleController) {
        m_bleController->disconnectFromDevice();
        delete m_bleController;
    }

    delete m_bleService;
    delete m_bleCharacteristic;
}


/**
 * @brief MainWindow::on_pushButtonScan_clicked
 * @note  Slot called when the "Scan Near Devices" button is clicked.
 */
void MainWindow::on_pushButtonScan_clicked()
{


    // NULL check
    if (NULL != m_discoveryAgent) {
        delete m_discoveryAgent;
    }

    QBluetoothAddress address("A0:9F:10:C0:79:7A");
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(address);

    // Search for near bluetooth devices for x ms.
    m_discoveryAgent->setLowEnergyDiscoveryTimeout(1000);

    // Connect slot for new device discovery.
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &MainWindow::on_bleDeviceDiscovered);

    // Connect slot for finishing scanning devices.
    connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &MainWindow::on_bleScanFinished);

    // Connect slot for error handling.
    // connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
    //         this, &MainWindow::on_bleScanErrorOccured);
    // connect(m_discoveryAgent, QBluetoothDeviceDiscoveryAgent::errorOccured  this,
    //         &MainWindow::on_bleScanErrorOccured);

    // connect(m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &Device::deviceScanFinished);

    // Clear (delete) the list of ble devices if any already exist from an old search.
    if (0 != ui->listWidgetBleDevices->count()) {
        ui->listWidgetBleDevices->clear();
    }


    // Once the scanning has started, disable the scan button so that the user will wait until scan finish.
    ui->pushButtonScan->setEnabled(false);

    // Clear the list of devices if exists.
    m_bleDevices.clear();

    // Ask the (bluetooth device) discovery agent to start searching for near devices.
    m_discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

    // Set the label so that the user know the searching has started.
    ui->labelBleConnectionStatus->setText("Searching for near bluetooth devices...");
}







/**
 * @brief MainWindow::on_listWidgetBleDevices_itemClicked
 * @param item
 */
void MainWindow::on_listWidgetBleDevices_itemClicked(QListWidgetItem *item)
{
    QString deviceAttributes = "";
    QBluetoothDeviceInfo deviceInfo = m_bleDevices[item->text()];
    deviceAttributes += "Name: " + deviceInfo.name() + "\n";
    deviceAttributes += "MAC address: " + deviceInfo.address().toString() + "\n";
    ui->textBrowserDeviceAttributes->setText(deviceAttributes);
}




/**
 * @brief MainWindow::on_pushButtonBleConnect_clicked
 */
void MainWindow::on_pushButtonBleConnect_clicked()
{
    if (NULL == ui->listWidgetBleDevices->currentItem()) {
        return;
    }

    ui->labelBleConnectionStatus->setText("Connecting...");
    QString userSelectedBleDeviceName = ui->listWidgetBleDevices->currentItem()->text();

    // Get the device from the m_bleDevices name-address lookup table.
    QBluetoothDeviceInfo deviceToConnect = m_bleDevices[userSelectedBleDeviceName];
    qInfo() << "Trying to connect to device: " << deviceToConnect.address();
    QString textToAppend = "Trying to connect to device: " + deviceToConnect.address().toString() + "...\n";
    ui->textBrowserDeviceAttributes->append(textToAppend);

    // Create a ble central device.
    if (NULL != m_bleController) {
        delete m_bleController;
    }

    m_bleController = QLowEnergyController::createCentral(deviceToConnect);
    qInfo() << m_bleController->state();

    // Callback when service is discovered.
    connect(m_bleController, &QLowEnergyController::serviceDiscovered,
            this, &MainWindow::on_bleServiceDiscovered);

    // Callback when discovery is finished.
    connect(m_bleController, &QLowEnergyController::discoveryFinished,
            this, &MainWindow::on_bleServiceScanFinished);

    connect(m_bleController,
            static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>
                (&QLowEnergyController::error),
            this,
            &MainWindow::on_bleControllerError);

    // Callback when connection is made.
    connect(m_bleController, &QLowEnergyController::connected, this, &MainWindow::on_bleControllerConnected);
    // Callback when disconnects.
    connect(m_bleController, &QLowEnergyController::disconnected, this, &MainWindow::on_bleControllerDisconnected);

    // Connect
    m_bleController->disconnectFromDevice();
    m_bleController->connectToDevice();
}







/**
 * @brief MainWindow::on_bleDeviceDiscovered
 * @param info
 */
void MainWindow::on_bleDeviceDiscovered(const QBluetoothDeviceInfo &info)
{
    // qInfo() << info.name() << " " << info.serviceUuids();
    qInfo() << info.name();
    m_bleDevices[info.name()] = info;
    QListWidgetItem *item = new QListWidgetItem(info.name());
    ui->listWidgetBleDevices->addItem(item);
}



/**
 * @brief MainWindow::on_bleScanErrorOccured
 * @param error
 */
void MainWindow::on_bleScanErrorOccured(QBluetoothDeviceDiscoveryAgent::Error error)
{
    qInfo() << "Error occured when discovert agent looking for near Bluetooth devices";
}




/**
 * @brief MainWindow::on_bleDeviceScanFinished
 */
void MainWindow::on_bleDeviceScanFinished()
{
    qInfo() << "BLE scan has finished.";
}

/**
 * @brief MainWindow::on_bleScanFinished
 * @note  Slot called when the m_discoveryAgent has finished scanning for other near bluetooth devices.
 */
void MainWindow::on_bleScanFinished()
{
    ui->labelBleConnectionStatus->setText("Scan finished.");
    ui->pushButtonScan->setEnabled(true);
}






/**
 * @brief MainWindow::on_bleServiceDiscovered
 * @param gatt
 * @note  Slot called when a new service has been discovered from a connected device.
 */
void MainWindow::on_bleServiceDiscovered(const QBluetoothUuid &gatt)
{
    QString textToAppend = "";

    ui->textBrowserDeviceAttributes->setTextColor(QColor("black"));
    textToAppend += "ble service discovered:\n";
    textToAppend += "uuid: " + gatt.toString() + "\n";
    ui->textBrowserDeviceAttributes->append(textToAppend);

    m_bleService = m_bleController->createServiceObject(gatt, this);
    m_bleService->discoverDetails();

    // connect(m_bleService, &QLowEnergyService::characteristicRead, this, &MainWindow::on_m_bleCharacteristicRead);
    // Get a list of characteristics.
    m_bleCharacteristicsList = m_bleService->characteristics();

    // if it is a heart rate monitor device.
    // if (gatt == QBluetoothUuid(QBluetoothUuid::HeartRate)) {
    // }

    textToAppend = "";
    // Iterate each characteritic, and display information in the window.
    ui->textBrowserDeviceAttributes->setTextColor(QColor("red"));
    for (auto currCharacteristic : m_bleCharacteristicsList) {
        ui->textBrowserDeviceAttributes->setTextColor(QColor("red"));
        textToAppend +=  "characteristic name: " + currCharacteristic.name() + "\n";
        textToAppend += "uuid: " + currCharacteristic.uuid().toString() + "\n";


        // uuid for led service. Only for ble_app_blinky example
        // if (currCharacteristic.uuid().toString() == "{00002a37-0000-1000-8000-00805f9b34fb}") {
        // if (currCharacteristic.uuid().toString() == "{00002a19-0000-1000-8000-00805f9b34fb}") {
        if (currCharacteristic.uuid().toString() == "{00002a38-0000-1000-8000-00805f9b34fb}") {
        // if (currCharacteristic.uuid().toString() == "{00002a29-0000-1000-8000-00805f9b34fb}") {
        // if (currCharacteristic.uuid().toString() == "{00001524-1212-efde-1523-785feabcd123}") {
            // can be used in heart rate monitor timer callback function to display the value.
            m_bleCharacteristic = new QLowEnergyCharacteristic(currCharacteristic);
            ui->pushButtonOpenHeartRateDialog->setEnabled(true);
        }

        // uuid for led service. Only for ble_app_blinky example
        if (currCharacteristic.uuid().toString() == "{00001525-1212-efde-1523-785feabcd123}") {
            m_bleCharacteristic = new QLowEnergyCharacteristic(currCharacteristic);
            ui->textBrowserDeviceAttributes->append("======");
            ui->textBrowserDeviceAttributes->append("Found led characteritics,  writing value...\n");
            ui->textBrowserDeviceAttributes->append(currCharacteristic.name());
            ui->textBrowserDeviceAttributes->append(currCharacteristic.uuid().toString());
            ui->textBrowserDeviceAttributes->append(currCharacteristic.value());
            qInfo() << m_bleService->state();
            ui->textBrowserDeviceAttributes->append("======");
        }

    }
    ui->textBrowserDeviceAttributes->append(textToAppend);



}





/**
 * @brief MainWindow::on_bleServiceScanFinished
 */
void MainWindow::on_bleServiceScanFinished()
{
    qInfo() << "ble service scan has finished";
    ui->labelBleConnectionStatus->setText("Connected. Service scan has finished.");
}





/**
 * @brief MainWindow::on_bleControllerError
 */
void MainWindow::on_bleControllerError(QLowEnergyController::Error)
{
    // qWarning()<< "ble connection error";
    qWarning() << "Error: " << m_bleController->errorString();
    qWarning() << m_bleController->error();

    ui->labelBleConnectionStatus->setText("Disconnected. Connection error.");

    QString textToAppend = m_bleController->errorString() + "\n";
    ui->textBrowserDeviceAttributes->append(textToAppend);
}




/**
 * @brief MainWindow::on_bleControllerConnected
 */
void MainWindow::on_bleControllerConnected()
{
    qInfo() << "ble controller connected";

    QString textToAppend =  "ble controller connected";
    ui->textBrowserDeviceAttributes->append(textToAppend);

    // Once connected, detect service from the device.
    m_bleController->discoverServices();
}






/**
 * @brief MainWindow::on_bleControllerDisconnected
 */
void MainWindow::on_bleControllerDisconnected()
{
    qInfo() << "ble service unconnected";
}


/**
 * @brief MainWindow::on_pushButtonToggle_clicked
 */
void MainWindow::on_pushButtonToggle_clicked()
{
    if (NULL == m_bleService) {
        return;
    }

    if (ui->labelStatus->text() == "OFF") {
        ui->labelStatus->setText("ON");
        QByteArray ba = QByteArrayLiteral("\x12");
        m_bleService->writeCharacteristic(*m_bleCharacteristic, ba, QLowEnergyService::WriteWithoutResponse);
    } else {
        QByteArray ba = QByteArrayLiteral("\x00");
        m_bleService->writeCharacteristic(*m_bleCharacteristic, ba, QLowEnergyService::WriteWithoutResponse);
        ui->labelStatus->setText("OFF");
    }
}



void MainWindow::on_pushButtonOpenHeartRateDialog_clicked()
{
    m_heartRateMonitorTimer = new QTimer();
    connect(m_heartRateMonitorTimer, &QTimer::timeout, this, &MainWindow::on_heartRateMonitorTimerTimeoutReached);
    m_heartRateMonitorTimer->start(1000);
}

void MainWindow::on_heartRateMonitorTimerTimeoutReached() {
    qInfo() << "heartRateMonitorTimer triggered...";
    connect(m_bleService, &QLowEnergyService::characteristicRead,
            this, &MainWindow::on_heartRateCharacteristicRead);
    m_bleService->readCharacteristic(*m_bleCharacteristic);
}

void MainWindow::on_heartRateCharacteristicRead(const QLowEnergyCharacteristic &characteristic, const QByteArray &heartRateData) {
    qInfo() << heartRateData;

}

