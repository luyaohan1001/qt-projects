#include "bt_console.h"
#include <QDebug>

bt_console::bt_console()
{
    // Create a discovery agent and connect to its signals
      QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
      connect(discoveryAgent,
              SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
              this,
              SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

      // Start a discovery
      discoveryAgent->start();
}

// In your local slot, read information about the found devices
void bt_console::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}
