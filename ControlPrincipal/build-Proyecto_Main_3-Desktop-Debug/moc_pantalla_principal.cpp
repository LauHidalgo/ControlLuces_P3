/****************************************************************************
** Meta object code from reading C++ file 'pantalla_principal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Proyecto_Main_3/pantalla_principal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pantalla_principal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Pantalla_Principal_t {
    QByteArrayData data[10];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pantalla_Principal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pantalla_Principal_t qt_meta_stringdata_Pantalla_Principal = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Pantalla_Principal"
QT_MOC_LITERAL(1, 19, 23), // "on_Button_luz_3_pressed"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 23), // "on_Button_luz_4_pressed"
QT_MOC_LITERAL(4, 68, 23), // "on_Button_luz_5_pressed"
QT_MOC_LITERAL(5, 92, 23), // "on_Button_luz_6_pressed"
QT_MOC_LITERAL(6, 116, 23), // "on_Button_luz_7_pressed"
QT_MOC_LITERAL(7, 140, 28), // "on_Slider_luz_8_valueChanged"
QT_MOC_LITERAL(8, 169, 5), // "value"
QT_MOC_LITERAL(9, 175, 32) // "on_Button_evento_agregar_pressed"

    },
    "Pantalla_Principal\0on_Button_luz_3_pressed\0"
    "\0on_Button_luz_4_pressed\0"
    "on_Button_luz_5_pressed\0on_Button_luz_6_pressed\0"
    "on_Button_luz_7_pressed\0"
    "on_Slider_luz_8_valueChanged\0value\0"
    "on_Button_evento_agregar_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pantalla_Principal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void Pantalla_Principal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pantalla_Principal *_t = static_cast<Pantalla_Principal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_luz_3_pressed(); break;
        case 1: _t->on_Button_luz_4_pressed(); break;
        case 2: _t->on_Button_luz_5_pressed(); break;
        case 3: _t->on_Button_luz_6_pressed(); break;
        case 4: _t->on_Button_luz_7_pressed(); break;
        case 5: _t->on_Slider_luz_8_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_Button_evento_agregar_pressed(); break;
        default: ;
        }
    }
}

const QMetaObject Pantalla_Principal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Pantalla_Principal.data,
      qt_meta_data_Pantalla_Principal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Pantalla_Principal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pantalla_Principal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Pantalla_Principal.stringdata0))
        return static_cast<void*>(const_cast< Pantalla_Principal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Pantalla_Principal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
