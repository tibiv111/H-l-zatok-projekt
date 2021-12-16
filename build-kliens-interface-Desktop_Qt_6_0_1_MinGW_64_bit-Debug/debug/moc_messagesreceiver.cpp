/****************************************************************************
** Meta object code from reading C++ file 'messagesreceiver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../kliens-interface/messagesreceiver.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagesreceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessagesReceiver_t {
    const uint offsetsAndSize[12];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MessagesReceiver_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MessagesReceiver_t qt_meta_stringdata_MessagesReceiver = {
    {
QT_MOC_LITERAL(0, 16), // "MessagesReceiver"
QT_MOC_LITERAL(17, 13), // "refreshWindow"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 7), // "message"
QT_MOC_LITERAL(40, 12), // "onlinePeople"
QT_MOC_LITERAL(53, 8) // "username"

    },
    "MessagesReceiver\0refreshWindow\0\0message\0"
    "onlinePeople\0username"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessagesReceiver[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   20,    2, 0x06,    0 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void MessagesReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessagesReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessagesReceiver::*)(QString , QVector<QString> , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessagesReceiver::refreshWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MessagesReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_MessagesReceiver.offsetsAndSize,
    qt_meta_data_MessagesReceiver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MessagesReceiver_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *MessagesReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessagesReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessagesReceiver.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MessagesReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MessagesReceiver::refreshWindow(QString _t1, QVector<QString> _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
