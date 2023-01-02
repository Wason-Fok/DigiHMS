/****************************************************************************
** Meta object code from reading C++ file 'Manager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../source/IO/Manager/Manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Manager_t {
    const uint offsetsAndSize[112];
    char stringdata0[821];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Manager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Manager_t qt_meta_stringdata_Manager = {
    {
QT_MOC_LITERAL(0, 7), // "Manager"
QT_MOC_LITERAL(8, 13), // "driverChanged"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 16), // "connectedChanged"
QT_MOC_LITERAL(40, 19), // "writeEnabledChanged"
QT_MOC_LITERAL(60, 20), // "configurationChanged"
QT_MOC_LITERAL(81, 20), // "receivedBytesChanged"
QT_MOC_LITERAL(102, 20), // "maxBufferSizeChanged"
QT_MOC_LITERAL(123, 20), // "startSequenceChanged"
QT_MOC_LITERAL(144, 21), // "finishSequenceChanged"
QT_MOC_LITERAL(166, 21), // "selectedDriverChanged"
QT_MOC_LITERAL(188, 24), // "separatorSequenceChanged"
QT_MOC_LITERAL(213, 27), // "frameValidationRegexChanged"
QT_MOC_LITERAL(241, 8), // "dataSent"
QT_MOC_LITERAL(250, 4), // "data"
QT_MOC_LITERAL(255, 12), // "dataReceived"
QT_MOC_LITERAL(268, 13), // "frameReceived"
QT_MOC_LITERAL(282, 5), // "frame"
QT_MOC_LITERAL(288, 13), // "connectDevice"
QT_MOC_LITERAL(302, 16), // "disconnectDriver"
QT_MOC_LITERAL(319, 16), // "toggleConnection"
QT_MOC_LITERAL(336, 14), // "setWriteEnable"
QT_MOC_LITERAL(351, 7), // "enabled"
QT_MOC_LITERAL(359, 14), // "processPayload"
QT_MOC_LITERAL(374, 7), // "payload"
QT_MOC_LITERAL(382, 16), // "setMaxBufferSize"
QT_MOC_LITERAL(399, 13), // "maxBufferSize"
QT_MOC_LITERAL(413, 17), // "setSelectedDriver"
QT_MOC_LITERAL(431, 23), // "Manager::SelectedDriver"
QT_MOC_LITERAL(455, 6), // "driver"
QT_MOC_LITERAL(462, 16), // "setStartSequence"
QT_MOC_LITERAL(479, 8), // "sequence"
QT_MOC_LITERAL(488, 17), // "setFinishSequence"
QT_MOC_LITERAL(506, 20), // "setSeparatorSequence"
QT_MOC_LITERAL(527, 10), // "readFrames"
QT_MOC_LITERAL(538, 15), // "clearTempBuffer"
QT_MOC_LITERAL(554, 9), // "setDriver"
QT_MOC_LITERAL(564, 11), // "HAL_Driver*"
QT_MOC_LITERAL(576, 14), // "onDataReceived"
QT_MOC_LITERAL(591, 16), // "AvailableDrivers"
QT_MOC_LITERAL(608, 9), // "WriteData"
QT_MOC_LITERAL(618, 8), // "readOnly"
QT_MOC_LITERAL(627, 9), // "readWrite"
QT_MOC_LITERAL(637, 9), // "connected"
QT_MOC_LITERAL(647, 15), // "deviceAvailable"
QT_MOC_LITERAL(663, 14), // "selectedDriver"
QT_MOC_LITERAL(678, 13), // "startSequence"
QT_MOC_LITERAL(692, 14), // "finishSequence"
QT_MOC_LITERAL(707, 17), // "separatorSequence"
QT_MOC_LITERAL(725, 15), // "configurationOk"
QT_MOC_LITERAL(741, 14), // "SelectedDriver"
QT_MOC_LITERAL(756, 6), // "Serial"
QT_MOC_LITERAL(763, 16), // "ValidationStatus"
QT_MOC_LITERAL(780, 7), // "FrameOk"
QT_MOC_LITERAL(788, 13), // "ChecksumError"
QT_MOC_LITERAL(802, 18) // "ChecksumIncomplete"

    },
    "Manager\0driverChanged\0\0connectedChanged\0"
    "writeEnabledChanged\0configurationChanged\0"
    "receivedBytesChanged\0maxBufferSizeChanged\0"
    "startSequenceChanged\0finishSequenceChanged\0"
    "selectedDriverChanged\0separatorSequenceChanged\0"
    "frameValidationRegexChanged\0dataSent\0"
    "data\0dataReceived\0frameReceived\0frame\0"
    "connectDevice\0disconnectDriver\0"
    "toggleConnection\0setWriteEnable\0enabled\0"
    "processPayload\0payload\0setMaxBufferSize\0"
    "maxBufferSize\0setSelectedDriver\0"
    "Manager::SelectedDriver\0driver\0"
    "setStartSequence\0sequence\0setFinishSequence\0"
    "setSeparatorSequence\0readFrames\0"
    "clearTempBuffer\0setDriver\0HAL_Driver*\0"
    "onDataReceived\0AvailableDrivers\0"
    "WriteData\0readOnly\0readWrite\0connected\0"
    "deviceAvailable\0selectedDriver\0"
    "startSequence\0finishSequence\0"
    "separatorSequence\0configurationOk\0"
    "SelectedDriver\0Serial\0ValidationStatus\0"
    "FrameOk\0ChecksumError\0ChecksumIncomplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       9,  250, // properties
       2,  295, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  194,    2, 0x06,   10 /* Public */,
       3,    0,  195,    2, 0x06,   11 /* Public */,
       4,    0,  196,    2, 0x06,   12 /* Public */,
       5,    0,  197,    2, 0x06,   13 /* Public */,
       6,    0,  198,    2, 0x06,   14 /* Public */,
       7,    0,  199,    2, 0x06,   15 /* Public */,
       8,    0,  200,    2, 0x06,   16 /* Public */,
       9,    0,  201,    2, 0x06,   17 /* Public */,
      10,    0,  202,    2, 0x06,   18 /* Public */,
      11,    0,  203,    2, 0x06,   19 /* Public */,
      12,    0,  204,    2, 0x06,   20 /* Public */,
      13,    1,  205,    2, 0x06,   21 /* Public */,
      15,    1,  208,    2, 0x06,   23 /* Public */,
      16,    1,  211,    2, 0x06,   25 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    0,  214,    2, 0x0a,   27 /* Public */,
      19,    0,  215,    2, 0x0a,   28 /* Public */,
      20,    0,  216,    2, 0x0a,   29 /* Public */,
      21,    1,  217,    2, 0x0a,   30 /* Public */,
      23,    1,  220,    2, 0x0a,   32 /* Public */,
      25,    1,  223,    2, 0x0a,   34 /* Public */,
      27,    1,  226,    2, 0x0a,   36 /* Public */,
      30,    1,  229,    2, 0x0a,   38 /* Public */,
      32,    1,  232,    2, 0x0a,   40 /* Public */,
      33,    1,  235,    2, 0x0a,   42 /* Public */,
      34,    0,  238,    2, 0x08,   44 /* Private */,
      35,    0,  239,    2, 0x08,   45 /* Private */,
      36,    1,  240,    2, 0x08,   46 /* Private */,
      38,    1,  243,    2, 0x08,   48 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      39,    0,  246,    2, 0x102,   50 /* Public | MethodIsConst  */,
      40,    1,  247,    2, 0x02,   51 /* Public */,

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
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::QByteArray,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::QByteArray,   24,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   29,
    QMetaType::Void, QMetaType::QByteArray,   14,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::LongLong, QMetaType::QByteArray,   14,

 // properties: name, type, flags
      41, QMetaType::Bool, 0x00015001, uint(1), 0,
      42, QMetaType::Bool, 0x00015001, uint(1), 0,
      43, QMetaType::Bool, 0x00015001, uint(1), 0,
      44, QMetaType::Bool, 0x00015001, uint(0), 0,
      45, 0x80000000 | 28, 0x0001510b, uint(8), 0,
      46, QMetaType::QString, 0x00015103, uint(6), 0,
      47, QMetaType::QString, 0x00015103, uint(7), 0,
      48, QMetaType::QString, 0x00015103, uint(9), 0,
      49, QMetaType::Bool, 0x00015001, uint(3), 0,

 // enums: name, alias, flags, count, data
      50,   50, 0x2,    1,  305,
      52,   52, 0x2,    3,  307,

 // enum data: key, value
      51, uint(Manager::SelectedDriver::Serial),
      53, uint(Manager::ValidationStatus::FrameOk),
      54, uint(Manager::ValidationStatus::ChecksumError),
      55, uint(Manager::ValidationStatus::ChecksumIncomplete),

       0        // eod
};

void Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->driverChanged(); break;
        case 1: _t->connectedChanged(); break;
        case 2: _t->writeEnabledChanged(); break;
        case 3: _t->configurationChanged(); break;
        case 4: _t->receivedBytesChanged(); break;
        case 5: _t->maxBufferSizeChanged(); break;
        case 6: _t->startSequenceChanged(); break;
        case 7: _t->finishSequenceChanged(); break;
        case 8: _t->selectedDriverChanged(); break;
        case 9: _t->separatorSequenceChanged(); break;
        case 10: _t->frameValidationRegexChanged(); break;
        case 11: _t->dataSent((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 12: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 13: _t->frameReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 14: _t->connectDevice(); break;
        case 15: _t->disconnectDriver(); break;
        case 16: _t->toggleConnection(); break;
        case 17: _t->setWriteEnable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->processPayload((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 19: _t->setMaxBufferSize((*reinterpret_cast< std::add_pointer_t<qint32>>(_a[1]))); break;
        case 20: _t->setSelectedDriver((*reinterpret_cast< std::add_pointer_t<Manager::SelectedDriver>>(_a[1]))); break;
        case 21: _t->setStartSequence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->setFinishSequence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->setSeparatorSequence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->readFrames(); break;
        case 25: _t->clearTempBuffer(); break;
        case 26: _t->setDriver((*reinterpret_cast< std::add_pointer_t<HAL_Driver*>>(_a[1]))); break;
        case 27: _t->onDataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 28: { QStringList _r = _t->AvailableDrivers();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 29: { qint64 _r = _t->WriteData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::driverChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::connectedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::writeEnabledChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::configurationChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::receivedBytesChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::maxBufferSizeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::startSequenceChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::finishSequenceChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::selectedDriverChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::separatorSequenceChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Manager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::frameValidationRegexChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Manager::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::dataSent)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Manager::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::dataReceived)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Manager::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manager::frameReceived)) {
                *result = 13;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Manager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->ReadOnly(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->ReadWrite(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->Connected(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->DeviceAvailable(); break;
        case 4: *reinterpret_cast< Manager::SelectedDriver*>(_v) = _t->GetSelectedDriver(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->StartSequence(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->FinishSequence(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->SeparatorSequence(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->ConfigurationOk(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Manager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setSelectedDriver(*reinterpret_cast< Manager::SelectedDriver*>(_v)); break;
        case 5: _t->setStartSequence(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setFinishSequence(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setSeparatorSequence(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Manager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Manager.offsetsAndSize,
    qt_meta_data_Manager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Manager_t
, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<Manager::SelectedDriver, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<Manager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const qint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Manager::SelectedDriver &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<HAL_Driver *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>

>,
    nullptr
} };


const QMetaObject *Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Manager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Manager::driverChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Manager::connectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Manager::writeEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Manager::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Manager::receivedBytesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Manager::maxBufferSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Manager::startSequenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Manager::finishSequenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Manager::selectedDriverChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Manager::separatorSequenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Manager::frameValidationRegexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Manager::dataSent(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Manager::dataReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Manager::frameReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
