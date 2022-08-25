/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../my_ble_blinky/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[491];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_pushButtonToggle_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "on_pushButtonScan_clicked"
QT_MOC_LITERAL(4, 66, 22), // "on_bleDeviceDiscovered"
QT_MOC_LITERAL(5, 89, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(6, 110, 4), // "info"
QT_MOC_LITERAL(7, 115, 18), // "on_bleScanFinished"
QT_MOC_LITERAL(8, 134, 22), // "on_bleScanErrorOccured"
QT_MOC_LITERAL(9, 157, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(10, 195, 5), // "error"
QT_MOC_LITERAL(11, 201, 24), // "on_bleDeviceScanFinished"
QT_MOC_LITERAL(12, 226, 31), // "on_pushButtonBleConnect_clicked"
QT_MOC_LITERAL(13, 258, 23), // "on_bleServiceDiscovered"
QT_MOC_LITERAL(14, 282, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(15, 297, 4), // "gatt"
QT_MOC_LITERAL(16, 302, 25), // "on_bleServiceScanFinished"
QT_MOC_LITERAL(17, 328, 21), // "on_bleControllerError"
QT_MOC_LITERAL(18, 350, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(19, 378, 25), // "on_bleControllerConnected"
QT_MOC_LITERAL(20, 404, 28), // "on_bleControllerDisconnected"
QT_MOC_LITERAL(21, 433, 35), // "on_listWidgetBleDevices_itemC..."
QT_MOC_LITERAL(22, 469, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(23, 486, 4) // "item"

    },
    "MainWindow\0on_pushButtonToggle_clicked\0"
    "\0on_pushButtonScan_clicked\0"
    "on_bleDeviceDiscovered\0QBluetoothDeviceInfo\0"
    "info\0on_bleScanFinished\0on_bleScanErrorOccured\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0on_bleDeviceScanFinished\0"
    "on_pushButtonBleConnect_clicked\0"
    "on_bleServiceDiscovered\0QBluetoothUuid\0"
    "gatt\0on_bleServiceScanFinished\0"
    "on_bleControllerError\0QLowEnergyController::Error\0"
    "on_bleControllerConnected\0"
    "on_bleControllerDisconnected\0"
    "on_listWidgetBleDevices_itemClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,
      17,    1,   94,    2, 0x08 /* Private */,
      19,    0,   97,    2, 0x08 /* Private */,
      20,    0,   98,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonToggle_clicked(); break;
        case 1: _t->on_pushButtonScan_clicked(); break;
        case 2: _t->on_bleDeviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 3: _t->on_bleScanFinished(); break;
        case 4: _t->on_bleScanErrorOccured((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 5: _t->on_bleDeviceScanFinished(); break;
        case 6: _t->on_pushButtonBleConnect_clicked(); break;
        case 7: _t->on_bleServiceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 8: _t->on_bleServiceScanFinished(); break;
        case 9: _t->on_bleControllerError((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 10: _t->on_bleControllerConnected(); break;
        case 11: _t->on_bleControllerDisconnected(); break;
        case 12: _t->on_listWidgetBleDevices_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
