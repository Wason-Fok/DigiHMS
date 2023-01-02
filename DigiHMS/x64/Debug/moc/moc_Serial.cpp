/****************************************************************************
** Meta object code from reading C++ file 'Serial.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../source/IO/Serial/Serial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Serial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Serial_t {
    const uint offsetsAndSize[94];
    char stringdata0[646];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Serial_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Serial_t qt_meta_stringdata_Serial = {
    {
QT_MOC_LITERAL(0, 6), // "Serial"
QT_MOC_LITERAL(7, 11), // "portChanged"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 13), // "parityChanged"
QT_MOC_LITERAL(34, 15), // "baudRateChanged"
QT_MOC_LITERAL(50, 15), // "dataBitsChanged"
QT_MOC_LITERAL(66, 15), // "stopBitsChanged"
QT_MOC_LITERAL(82, 16), // "portIndexChanged"
QT_MOC_LITERAL(99, 18), // "flowControlChanged"
QT_MOC_LITERAL(118, 19), // "baudRateListChanged"
QT_MOC_LITERAL(138, 20), // "autoReconnectChanged"
QT_MOC_LITERAL(159, 20), // "baudRateIndexChanged"
QT_MOC_LITERAL(180, 21), // "availablePortsChanged"
QT_MOC_LITERAL(202, 15), // "connectionError"
QT_MOC_LITERAL(218, 4), // "name"
QT_MOC_LITERAL(223, 16), // "disconnectDevice"
QT_MOC_LITERAL(240, 12), // "setPortIndex"
QT_MOC_LITERAL(253, 9), // "portIndex"
QT_MOC_LITERAL(263, 11), // "setBaudRate"
QT_MOC_LITERAL(275, 4), // "rate"
QT_MOC_LITERAL(280, 11), // "setDataBits"
QT_MOC_LITERAL(292, 13), // "dataBitsIndex"
QT_MOC_LITERAL(306, 9), // "setParity"
QT_MOC_LITERAL(316, 11), // "parityIndex"
QT_MOC_LITERAL(328, 11), // "setStopBits"
QT_MOC_LITERAL(340, 13), // "stopBitsIndex"
QT_MOC_LITERAL(354, 14), // "setFlowControl"
QT_MOC_LITERAL(369, 16), // "flowControlIndex"
QT_MOC_LITERAL(386, 16), // "setAutoReconnect"
QT_MOC_LITERAL(403, 13), // "autoreconnect"
QT_MOC_LITERAL(417, 14), // "appendBaudRate"
QT_MOC_LITERAL(432, 8), // "baudRate"
QT_MOC_LITERAL(441, 11), // "onReadyRead"
QT_MOC_LITERAL(453, 12), // "readSettings"
QT_MOC_LITERAL(466, 13), // "writeSettings"
QT_MOC_LITERAL(480, 20), // "refreshSerialDevices"
QT_MOC_LITERAL(501, 11), // "handleError"
QT_MOC_LITERAL(513, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(542, 5), // "error"
QT_MOC_LITERAL(548, 8), // "portName"
QT_MOC_LITERAL(557, 13), // "autoReconnect"
QT_MOC_LITERAL(571, 8), // "portList"
QT_MOC_LITERAL(580, 12), // "baudRateList"
QT_MOC_LITERAL(593, 10), // "parityList"
QT_MOC_LITERAL(604, 12), // "dataBitsList"
QT_MOC_LITERAL(617, 12), // "stopBitsList"
QT_MOC_LITERAL(630, 15) // "flowControlList"

    },
    "Serial\0portChanged\0\0parityChanged\0"
    "baudRateChanged\0dataBitsChanged\0"
    "stopBitsChanged\0portIndexChanged\0"
    "flowControlChanged\0baudRateListChanged\0"
    "autoReconnectChanged\0baudRateIndexChanged\0"
    "availablePortsChanged\0connectionError\0"
    "name\0disconnectDevice\0setPortIndex\0"
    "portIndex\0setBaudRate\0rate\0setDataBits\0"
    "dataBitsIndex\0setParity\0parityIndex\0"
    "setStopBits\0stopBitsIndex\0setFlowControl\0"
    "flowControlIndex\0setAutoReconnect\0"
    "autoreconnect\0appendBaudRate\0baudRate\0"
    "onReadyRead\0readSettings\0writeSettings\0"
    "refreshSerialDevices\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "portName\0autoReconnect\0portList\0"
    "baudRateList\0parityList\0dataBitsList\0"
    "stopBitsList\0flowControlList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serial[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
      14,  216, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x06,   15 /* Public */,
       3,    0,  171,    2, 0x06,   16 /* Public */,
       4,    0,  172,    2, 0x06,   17 /* Public */,
       5,    0,  173,    2, 0x06,   18 /* Public */,
       6,    0,  174,    2, 0x06,   19 /* Public */,
       7,    0,  175,    2, 0x06,   20 /* Public */,
       8,    0,  176,    2, 0x06,   21 /* Public */,
       9,    0,  177,    2, 0x06,   22 /* Public */,
      10,    0,  178,    2, 0x06,   23 /* Public */,
      11,    0,  179,    2, 0x06,   24 /* Public */,
      12,    0,  180,    2, 0x06,   25 /* Public */,
      13,    1,  181,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  184,    2, 0x0a,   28 /* Public */,
      16,    1,  185,    2, 0x0a,   29 /* Public */,
      18,    1,  188,    2, 0x0a,   31 /* Public */,
      20,    1,  191,    2, 0x0a,   33 /* Public */,
      22,    1,  194,    2, 0x0a,   35 /* Public */,
      24,    1,  197,    2, 0x0a,   37 /* Public */,
      26,    1,  200,    2, 0x0a,   39 /* Public */,
      28,    1,  203,    2, 0x0a,   41 /* Public */,
      30,    1,  206,    2, 0x0a,   43 /* Public */,
      32,    0,  209,    2, 0x08,   45 /* Private */,
      33,    0,  210,    2, 0x08,   46 /* Private */,
      34,    0,  211,    2, 0x08,   47 /* Private */,
      35,    0,  212,    2, 0x08,   48 /* Private */,
      36,    1,  213,    2, 0x08,   49 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::UChar,   21,
    QMetaType::Void, QMetaType::UChar,   23,
    QMetaType::Void, QMetaType::UChar,   25,
    QMetaType::Void, QMetaType::UChar,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,

 // properties: name, type, flags
      39, QMetaType::QString, 0x00015001, uint(0), 0,
      40, QMetaType::Bool, 0x00015001, uint(8), 0,
      17, QMetaType::UChar, 0x00015001, uint(5), 0,
      23, QMetaType::UChar, 0x00015003, uint(1), 0,
      21, QMetaType::UChar, 0x00015003, uint(3), 0,
      25, QMetaType::UChar, 0x00015003, uint(4), 0,
      27, QMetaType::UChar, 0x00015003, uint(6), 0,
      31, QMetaType::Int, 0x00015103, uint(2), 0,
      41, QMetaType::QStringList, 0x00015001, uint(10), 0,
      42, QMetaType::QStringList, 0x00015001, uint(7), 0,
      43, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      44, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      45, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      46, QMetaType::QStringList, 0x00015401, uint(-1), 0,

       0        // eod
};

void Serial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Serial *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->portChanged(); break;
        case 1: _t->parityChanged(); break;
        case 2: _t->baudRateChanged(); break;
        case 3: _t->dataBitsChanged(); break;
        case 4: _t->stopBitsChanged(); break;
        case 5: _t->portIndexChanged(); break;
        case 6: _t->flowControlChanged(); break;
        case 7: _t->baudRateListChanged(); break;
        case 8: _t->autoReconnectChanged(); break;
        case 9: _t->baudRateIndexChanged(); break;
        case 10: _t->availablePortsChanged(); break;
        case 11: _t->connectionError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->disconnectDevice(); break;
        case 13: _t->setPortIndex((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 14: _t->setBaudRate((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 15: _t->setDataBits((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 16: _t->setParity((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 17: _t->setStopBits((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 18: _t->setFlowControl((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 19: _t->setAutoReconnect((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->appendBaudRate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->onReadyRead(); break;
        case 22: _t->readSettings(); break;
        case 23: _t->writeSettings(); break;
        case 24: _t->refreshSerialDevices(); break;
        case 25: _t->handleError((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::portChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::parityChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::baudRateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::dataBitsChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::stopBitsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::portIndexChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::flowControlChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::baudRateListChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::autoReconnectChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::baudRateIndexChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Serial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::availablePortsChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Serial::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serial::connectionError)) {
                *result = 11;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Serial *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->PortName(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->AutoReconnect(); break;
        case 2: *reinterpret_cast< quint8*>(_v) = _t->PortIndex(); break;
        case 3: *reinterpret_cast< quint8*>(_v) = _t->ParityIndex(); break;
        case 4: *reinterpret_cast< quint8*>(_v) = _t->DataBitsIndex(); break;
        case 5: *reinterpret_cast< quint8*>(_v) = _t->StopBitsIndex(); break;
        case 6: *reinterpret_cast< quint8*>(_v) = _t->FlowControlIndex(); break;
        case 7: *reinterpret_cast< qint32*>(_v) = _t->BaudRate(); break;
        case 8: *reinterpret_cast< QStringList*>(_v) = _t->PortList(); break;
        case 9: *reinterpret_cast< QStringList*>(_v) = _t->BaudRateList(); break;
        case 10: *reinterpret_cast< QStringList*>(_v) = _t->ParityList(); break;
        case 11: *reinterpret_cast< QStringList*>(_v) = _t->DataBitsList(); break;
        case 12: *reinterpret_cast< QStringList*>(_v) = _t->StopBitsList(); break;
        case 13: *reinterpret_cast< QStringList*>(_v) = _t->FlowControlList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Serial *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setParity(*reinterpret_cast< quint8*>(_v)); break;
        case 4: _t->setDataBits(*reinterpret_cast< quint8*>(_v)); break;
        case 5: _t->setStopBits(*reinterpret_cast< quint8*>(_v)); break;
        case 6: _t->setFlowControl(*reinterpret_cast< quint8*>(_v)); break;
        case 7: _t->setBaudRate(*reinterpret_cast< qint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Serial::staticMetaObject = { {
    QMetaObject::SuperData::link<HAL_Driver::staticMetaObject>(),
    qt_meta_stringdata_Serial.offsetsAndSize,
    qt_meta_data_Serial,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Serial_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<quint8, std::true_type>, QtPrivate::TypeAndForceComplete<quint8, std::true_type>, QtPrivate::TypeAndForceComplete<quint8, std::true_type>, QtPrivate::TypeAndForceComplete<quint8, std::true_type>, QtPrivate::TypeAndForceComplete<quint8, std::true_type>, QtPrivate::TypeAndForceComplete<qint32, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<QStringList, std::true_type>, QtPrivate::TypeAndForceComplete<Serial, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const qint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint8, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>


>,
    nullptr
} };


const QMetaObject *Serial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Serial.stringdata0))
        return static_cast<void*>(this);
    return HAL_Driver::qt_metacast(_clname);
}

int Serial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HAL_Driver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Serial::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Serial::parityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Serial::baudRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Serial::dataBitsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Serial::stopBitsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Serial::portIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Serial::flowControlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Serial::baudRateListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Serial::autoReconnectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Serial::baudRateIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Serial::availablePortsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Serial::connectionError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
