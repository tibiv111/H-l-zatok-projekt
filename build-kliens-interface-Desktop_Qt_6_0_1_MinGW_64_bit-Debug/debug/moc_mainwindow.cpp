/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../kliens-interface/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 31), // "on_sendToEveryoneButton_clicked"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 7), // "exitApp"
QT_MOC_LITERAL(52, 16), // "on_refreshWindow"
QT_MOC_LITERAL(69, 7), // "message"
QT_MOC_LITERAL(77, 12), // "onlinePeople"
QT_MOC_LITERAL(90, 8), // "username"
QT_MOC_LITERAL(99, 21), // "on_sendMessageOnEnter"
QT_MOC_LITERAL(121, 12), // "QPushButton*"
QT_MOC_LITERAL(134, 6), // "button"
QT_MOC_LITERAL(141, 23), // "on_MainWindow_destroyed"
QT_MOC_LITERAL(165, 21), // "on_exitButton_clicked"
QT_MOC_LITERAL(187, 23), // "on_sendPMButton_clicked"
QT_MOC_LITERAL(211, 40), // "on_currentlyOnlineListWidget_..."
QT_MOC_LITERAL(252, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(269, 4), // "item"
QT_MOC_LITERAL(274, 49) // "on_currentlyOnlineListWidget_..."

    },
    "MainWindow\0on_sendToEveryoneButton_clicked\0"
    "\0exitApp\0on_refreshWindow\0message\0"
    "onlinePeople\0username\0on_sendMessageOnEnter\0"
    "QPushButton*\0button\0on_MainWindow_destroyed\0"
    "on_exitButton_clicked\0on_sendPMButton_clicked\0"
    "on_currentlyOnlineListWidget_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_currentlyOnlineListWidget_itemSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    0 /* Private */,
       3,    0,   69,    2, 0x08,    1 /* Private */,
       4,    3,   70,    2, 0x08,    2 /* Private */,
       8,    1,   77,    2, 0x08,    6 /* Private */,
      11,    0,   80,    2, 0x08,    8 /* Private */,
      12,    0,   81,    2, 0x08,    9 /* Private */,
      13,    0,   82,    2, 0x08,   10 /* Private */,
      14,    1,   83,    2, 0x08,   11 /* Private */,
      17,    0,   86,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_sendToEveryoneButton_clicked(); break;
        case 1: _t->exitApp(); break;
        case 2: _t->on_refreshWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->on_sendMessageOnEnter((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 4: _t->on_MainWindow_destroyed(); break;
        case 5: _t->on_exitButton_clicked(); break;
        case 6: _t->on_sendPMButton_clicked(); break;
        case 7: _t->on_currentlyOnlineListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_currentlyOnlineListWidget_itemSelectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
