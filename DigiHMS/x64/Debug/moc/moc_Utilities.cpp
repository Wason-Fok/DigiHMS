/****************************************************************************
** Meta object code from reading C++ file 'Utilities.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../source/Common/Utilities.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Utilities.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Utilities_t {
    const uint offsetsAndSize[12];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Utilities_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Utilities_t qt_meta_stringdata_Utilities = {
    {
QT_MOC_LITERAL(0, 9), // "Utilities"
QT_MOC_LITERAL(10, 7), // "AboutQt"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 10), // "RevealFile"
QT_MOC_LITERAL(30, 12), // "pathToReveal"
QT_MOC_LITERAL(43, 19) // "AskAutomaticUpdates"

    },
    "Utilities\0AboutQt\0\0RevealFile\0"
    "pathToReveal\0AskAutomaticUpdates"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Utilities[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    1,   33,    2, 0x0a,    2 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   36,    2, 0x02,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // methods: parameters
    QMetaType::Bool,

       0        // eod
};

void Utilities::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Utilities *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->AboutQt(); break;
        case 1: _t->RevealFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { bool _r = _t->AskAutomaticUpdates();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject Utilities::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Utilities.offsetsAndSize,
    qt_meta_data_Utilities,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Utilities_t
, QtPrivate::TypeAndForceComplete<Utilities, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>

>,
    nullptr
} };


const QMetaObject *Utilities::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Utilities::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Utilities.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Utilities::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
