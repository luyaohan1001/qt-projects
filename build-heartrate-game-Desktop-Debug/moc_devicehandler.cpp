/****************************************************************************
** Meta object code from reading C++ file 'devicehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../heartrate-game/devicehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceHandler_t {
    QByteArrayData data[20];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceHandler_t qt_meta_stringdata_DeviceHandler = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DeviceHandler"
QT_MOC_LITERAL(1, 14, 16), // "measuringChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "aliveChanged"
QT_MOC_LITERAL(4, 45, 12), // "statsChanged"
QT_MOC_LITERAL(5, 58, 16), // "startMeasurement"
QT_MOC_LITERAL(6, 75, 15), // "stopMeasurement"
QT_MOC_LITERAL(7, 91, 17), // "disconnectService"
QT_MOC_LITERAL(8, 109, 9), // "measuring"
QT_MOC_LITERAL(9, 119, 5), // "alive"
QT_MOC_LITERAL(10, 125, 2), // "hr"
QT_MOC_LITERAL(11, 128, 5), // "maxHR"
QT_MOC_LITERAL(12, 134, 5), // "minHR"
QT_MOC_LITERAL(13, 140, 7), // "average"
QT_MOC_LITERAL(14, 148, 4), // "time"
QT_MOC_LITERAL(15, 153, 8), // "calories"
QT_MOC_LITERAL(16, 162, 11), // "addressType"
QT_MOC_LITERAL(17, 174, 11), // "AddressType"
QT_MOC_LITERAL(18, 186, 13), // "PublicAddress"
QT_MOC_LITERAL(19, 200, 13) // "RandomAddress"

    },
    "DeviceHandler\0measuringChanged\0\0"
    "aliveChanged\0statsChanged\0startMeasurement\0"
    "stopMeasurement\0disconnectService\0"
    "measuring\0alive\0hr\0maxHR\0minHR\0average\0"
    "time\0calories\0addressType\0AddressType\0"
    "PublicAddress\0RandomAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       9,   50, // properties
       1,   86, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Bool, 0x00495001,
       9, QMetaType::Bool, 0x00495001,
      10, QMetaType::Int, 0x00495001,
      11, QMetaType::Int, 0x00495001,
      12, QMetaType::Int, 0x00495001,
      13, QMetaType::Float, 0x00495001,
      14, QMetaType::Int, 0x00495001,
      15, QMetaType::Float, 0x00495001,
      16, 0x80000000 | 17, 0x0009510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       2,
       2,
       2,
       2,
       2,
       0,

 // enums: name, alias, flags, count, data
      17,   17, 0x2,    2,   91,

 // enum data: key, value
      18, uint(DeviceHandler::AddressType::PublicAddress),
      19, uint(DeviceHandler::AddressType::RandomAddress),

       0        // eod
};

void DeviceHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->measuringChanged(); break;
        case 1: _t->aliveChanged(); break;
        case 2: _t->statsChanged(); break;
        case 3: _t->startMeasurement(); break;
        case 4: _t->stopMeasurement(); break;
        case 5: _t->disconnectService(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceHandler::measuringChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceHandler::aliveChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeviceHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceHandler::statsChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->measuring(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->alive(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->hr(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->maxHR(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->minHR(); break;
        case 5: *reinterpret_cast< float*>(_v) = _t->average(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->time(); break;
        case 7: *reinterpret_cast< float*>(_v) = _t->calories(); break;
        case 8: *reinterpret_cast< AddressType*>(_v) = _t->addressType(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 8: _t->setAddressType(*reinterpret_cast< AddressType*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DeviceHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<BluetoothBaseClass::staticMetaObject>(),
    qt_meta_stringdata_DeviceHandler.data,
    qt_meta_data_DeviceHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceHandler.stringdata0))
        return static_cast<void*>(this);
    return BluetoothBaseClass::qt_metacast(_clname);
}

int DeviceHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BluetoothBaseClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DeviceHandler::measuringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DeviceHandler::aliveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DeviceHandler::statsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
