/****************************************************************************
** Meta object code from reading C++ file 'pantalla_evento_agregar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Proyecto_3/pantalla_evento_agregar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pantalla_evento_agregar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pantalla_evento_agregar_t {
    QByteArrayData data[12];
    char stringdata[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pantalla_evento_agregar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pantalla_evento_agregar_t qt_meta_stringdata_pantalla_evento_agregar = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 14),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 25),
QT_MOC_LITERAL(4, 66, 25),
QT_MOC_LITERAL(5, 92, 25),
QT_MOC_LITERAL(6, 118, 25),
QT_MOC_LITERAL(7, 144, 25),
QT_MOC_LITERAL(8, 170, 30),
QT_MOC_LITERAL(9, 201, 5),
QT_MOC_LITERAL(10, 207, 29),
QT_MOC_LITERAL(11, 237, 30)
    },
    "pantalla_evento_agregar\0ventana_cerrar\0"
    "\0on_Button_luz_3_2_pressed\0"
    "on_Button_luz_4_2_pressed\0"
    "on_Button_luz_5_2_pressed\0"
    "on_Button_luz_6_2_pressed\0"
    "on_Button_luz_7_2_pressed\0"
    "on_Slider_luz_8_2_valueChanged\0value\0"
    "on_pushButton_Aceptar_pressed\0"
    "on_pushButton_Cancelar_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pantalla_evento_agregar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pantalla_evento_agregar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pantalla_evento_agregar *_t = static_cast<pantalla_evento_agregar *>(_o);
        switch (_id) {
        case 0: _t->ventana_cerrar(); break;
        case 1: _t->on_Button_luz_3_2_pressed(); break;
        case 2: _t->on_Button_luz_4_2_pressed(); break;
        case 3: _t->on_Button_luz_5_2_pressed(); break;
        case 4: _t->on_Button_luz_6_2_pressed(); break;
        case 5: _t->on_Button_luz_7_2_pressed(); break;
        case 6: _t->on_Slider_luz_8_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_Aceptar_pressed(); break;
        case 8: _t->on_pushButton_Cancelar_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pantalla_evento_agregar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pantalla_evento_agregar::ventana_cerrar)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject pantalla_evento_agregar::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_pantalla_evento_agregar.data,
      qt_meta_data_pantalla_evento_agregar,  qt_static_metacall, 0, 0}
};


const QMetaObject *pantalla_evento_agregar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pantalla_evento_agregar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pantalla_evento_agregar.stringdata))
        return static_cast<void*>(const_cast< pantalla_evento_agregar*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int pantalla_evento_agregar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void pantalla_evento_agregar::ventana_cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
