/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MicroMove/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "on_Connect_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "checked"
QT_MOC_LITERAL(4, 39, 19), // "on_But_Back_clicked"
QT_MOC_LITERAL(5, 59, 22), // "on_But_Forward_clicked"
QT_MOC_LITERAL(6, 82, 19), // "on_But_Stop_clicked"
QT_MOC_LITERAL(7, 102, 24), // "on_But_Forward_V_pressed"
QT_MOC_LITERAL(8, 127, 25), // "on_But_Forward_V_released"
QT_MOC_LITERAL(9, 153, 21), // "on_But_Back_V_pressed"
QT_MOC_LITERAL(10, 175, 22), // "on_But_Back_V_released"
QT_MOC_LITERAL(11, 198, 25), // "on_But_SetVoltage_clicked"
QT_MOC_LITERAL(12, 224, 27), // "on_But_Forward_Scan_clicked"
QT_MOC_LITERAL(13, 252, 24), // "on_But_Back_Scan_clicked"
QT_MOC_LITERAL(14, 277, 21), // "on_But_UpData_clicked"
QT_MOC_LITERAL(15, 299, 25), // "on_But_ClearChart_clicked"
QT_MOC_LITERAL(16, 325, 29), // "on_But_ConnectToForce_clicked"
QT_MOC_LITERAL(17, 355, 19), // "on_But_Zero_clicked"
QT_MOC_LITERAL(18, 375, 19), // "on_But_Goto_clicked"
QT_MOC_LITERAL(19, 395, 19) // "on_But_Save_clicked"

    },
    "MainWindow\0on_Connect_clicked\0\0checked\0"
    "on_But_Back_clicked\0on_But_Forward_clicked\0"
    "on_But_Stop_clicked\0on_But_Forward_V_pressed\0"
    "on_But_Forward_V_released\0"
    "on_But_Back_V_pressed\0on_But_Back_V_released\0"
    "on_But_SetVoltage_clicked\0"
    "on_But_Forward_Scan_clicked\0"
    "on_But_Back_Scan_clicked\0on_But_UpData_clicked\0"
    "on_But_ClearChart_clicked\0"
    "on_But_ConnectToForce_clicked\0"
    "on_But_Zero_clicked\0on_But_Goto_clicked\0"
    "on_But_Save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    0,  102,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    1,  116,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
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
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_But_Back_clicked(); break;
        case 2: _t->on_But_Forward_clicked(); break;
        case 3: _t->on_But_Stop_clicked(); break;
        case 4: _t->on_But_Forward_V_pressed(); break;
        case 5: _t->on_But_Forward_V_released(); break;
        case 6: _t->on_But_Back_V_pressed(); break;
        case 7: _t->on_But_Back_V_released(); break;
        case 8: _t->on_But_SetVoltage_clicked(); break;
        case 9: _t->on_But_Forward_Scan_clicked(); break;
        case 10: _t->on_But_Back_Scan_clicked(); break;
        case 11: _t->on_But_UpData_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_But_ClearChart_clicked(); break;
        case 13: _t->on_But_ConnectToForce_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_But_Zero_clicked(); break;
        case 15: _t->on_But_Goto_clicked(); break;
        case 16: _t->on_But_Save_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
