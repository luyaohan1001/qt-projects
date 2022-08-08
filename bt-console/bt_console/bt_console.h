#ifndef BT_CONSOLE_H
#define BT_CONSOLE_H
#include "QBluetoothDeviceDiscoveryAgent">

class bt_console : public QObject
{
public:
    bt_console();


private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;


public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);

signals:
    void updateChanged();

};

#endif // BT_CONSOLE_H
