/****************************************************************************
** Meta object code from reading C++ file 'spinbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code_package/src/spinbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spinbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spinbox_vx_t {
    QByteArrayData data[5];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_vx_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_vx_t qt_meta_stringdata_spinbox_vx = {
    {
QT_MOC_LITERAL(0, 0, 10), // "spinbox_vx"
QT_MOC_LITERAL(1, 11, 13), // "Show_Vx_value"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "vx"
QT_MOC_LITERAL(4, 29, 11) // "box_disable"

    },
    "spinbox_vx\0Show_Vx_value\0\0vx\0box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_vx[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_vx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_vx *_t = static_cast<spinbox_vx *>(_o);
        switch (_id) {
        case 0: _t->Show_Vx_value((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_vx::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_vx.data,
      qt_meta_data_spinbox_vx,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_vx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_vx::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_vx.stringdata))
        return static_cast<void*>(const_cast< spinbox_vx*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_vx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_spinbox_vy_t {
    QByteArrayData data[5];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_vy_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_vy_t qt_meta_stringdata_spinbox_vy = {
    {
QT_MOC_LITERAL(0, 0, 10), // "spinbox_vy"
QT_MOC_LITERAL(1, 11, 13), // "Show_Vy_value"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "vy"
QT_MOC_LITERAL(4, 29, 11) // "box_disable"

    },
    "spinbox_vy\0Show_Vy_value\0\0vy\0box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_vy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_vy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_vy *_t = static_cast<spinbox_vy *>(_o);
        switch (_id) {
        case 0: _t->Show_Vy_value((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_vy::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_vy.data,
      qt_meta_data_spinbox_vy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_vy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_vy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_vy.stringdata))
        return static_cast<void*>(const_cast< spinbox_vy*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_vy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_spinbox_vz_t {
    QByteArrayData data[5];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_vz_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_vz_t qt_meta_stringdata_spinbox_vz = {
    {
QT_MOC_LITERAL(0, 0, 10), // "spinbox_vz"
QT_MOC_LITERAL(1, 11, 13), // "Show_Vz_value"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "vz"
QT_MOC_LITERAL(4, 29, 11) // "box_disable"

    },
    "spinbox_vz\0Show_Vz_value\0\0vz\0box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_vz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_vz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_vz *_t = static_cast<spinbox_vz *>(_o);
        switch (_id) {
        case 0: _t->Show_Vz_value((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_vz::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_vz.data,
      qt_meta_data_spinbox_vz,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_vz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_vz::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_vz.stringdata))
        return static_cast<void*>(const_cast< spinbox_vz*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_vz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_spinbox_color_R_t {
    QByteArrayData data[5];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_color_R_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_color_R_t qt_meta_stringdata_spinbox_color_R = {
    {
QT_MOC_LITERAL(0, 0, 15), // "spinbox_color_R"
QT_MOC_LITERAL(1, 16, 12), // "Show_color_R"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "r"
QT_MOC_LITERAL(4, 32, 11) // "box_disable"

    },
    "spinbox_color_R\0Show_color_R\0\0r\0"
    "box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_color_R[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_color_R::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_color_R *_t = static_cast<spinbox_color_R *>(_o);
        switch (_id) {
        case 0: _t->Show_color_R((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_color_R::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_color_R.data,
      qt_meta_data_spinbox_color_R,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_color_R::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_color_R::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_color_R.stringdata))
        return static_cast<void*>(const_cast< spinbox_color_R*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_color_R::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_spinbox_color_G_t {
    QByteArrayData data[5];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_color_G_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_color_G_t qt_meta_stringdata_spinbox_color_G = {
    {
QT_MOC_LITERAL(0, 0, 15), // "spinbox_color_G"
QT_MOC_LITERAL(1, 16, 12), // "Show_color_G"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "g"
QT_MOC_LITERAL(4, 32, 11) // "box_disable"

    },
    "spinbox_color_G\0Show_color_G\0\0g\0"
    "box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_color_G[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_color_G::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_color_G *_t = static_cast<spinbox_color_G *>(_o);
        switch (_id) {
        case 0: _t->Show_color_G((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_color_G::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_color_G.data,
      qt_meta_data_spinbox_color_G,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_color_G::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_color_G::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_color_G.stringdata))
        return static_cast<void*>(const_cast< spinbox_color_G*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_color_G::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_spinbox_color_B_t {
    QByteArrayData data[5];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spinbox_color_B_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spinbox_color_B_t qt_meta_stringdata_spinbox_color_B = {
    {
QT_MOC_LITERAL(0, 0, 15), // "spinbox_color_B"
QT_MOC_LITERAL(1, 16, 12), // "Show_color_B"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "b"
QT_MOC_LITERAL(4, 32, 11) // "box_disable"

    },
    "spinbox_color_B\0Show_color_B\0\0b\0"
    "box_disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spinbox_color_B[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,

       0        // eod
};

void spinbox_color_B::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spinbox_color_B *_t = static_cast<spinbox_color_B *>(_o);
        switch (_id) {
        case 0: _t->Show_color_B((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->box_disable(); break;
        default: ;
        }
    }
}

const QMetaObject spinbox_color_B::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_spinbox_color_B.data,
      qt_meta_data_spinbox_color_B,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spinbox_color_B::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spinbox_color_B::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spinbox_color_B.stringdata))
        return static_cast<void*>(const_cast< spinbox_color_B*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int spinbox_color_B::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
