/****************************************************************************
** Meta object code from reading C++ file 'list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code_package/src/list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Vertex_List_t {
    QByteArrayData data[8];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vertex_List_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vertex_List_t qt_meta_stringdata_Vertex_List = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Vertex_List"
QT_MOC_LITERAL(1, 12, 10), // "List_clear"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "Show_VertexItems"
QT_MOC_LITERAL(4, 41, 5), // "v_num"
QT_MOC_LITERAL(5, 47, 11), // "selected_ID"
QT_MOC_LITERAL(6, 59, 16), // "SetSelected_item"
QT_MOC_LITERAL(7, 76, 4) // "v_ID"

    },
    "Vertex_List\0List_clear\0\0Show_VertexItems\0"
    "v_num\0selected_ID\0SetSelected_item\0"
    "v_ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vertex_List[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Vertex_List::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Vertex_List *_t = static_cast<Vertex_List *>(_o);
        switch (_id) {
        case 0: _t->List_clear(); break;
        case 1: _t->Show_VertexItems((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SetSelected_item((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Vertex_List::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vertex_List::List_clear)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Vertex_List::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_Vertex_List.data,
      qt_meta_data_Vertex_List,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Vertex_List::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vertex_List::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Vertex_List.stringdata))
        return static_cast<void*>(const_cast< Vertex_List*>(this));
    return QListWidget::qt_metacast(_clname);
}

int Vertex_List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Vertex_List::List_clear()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_Face_List_t {
    QByteArrayData data[8];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Face_List_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Face_List_t qt_meta_stringdata_Face_List = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Face_List"
QT_MOC_LITERAL(1, 10, 10), // "List_clear"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "Show_FaceItems"
QT_MOC_LITERAL(4, 37, 5), // "f_num"
QT_MOC_LITERAL(5, 43, 11), // "selected_ID"
QT_MOC_LITERAL(6, 55, 16), // "SetSelected_item"
QT_MOC_LITERAL(7, 72, 4) // "f_ID"

    },
    "Face_List\0List_clear\0\0Show_FaceItems\0"
    "f_num\0selected_ID\0SetSelected_item\0"
    "f_ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Face_List[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Face_List::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Face_List *_t = static_cast<Face_List *>(_o);
        switch (_id) {
        case 0: _t->List_clear(); break;
        case 1: _t->Show_FaceItems((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SetSelected_item((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Face_List::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Face_List::List_clear)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Face_List::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_Face_List.data,
      qt_meta_data_Face_List,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Face_List::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Face_List::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Face_List.stringdata))
        return static_cast<void*>(const_cast< Face_List*>(this));
    return QListWidget::qt_metacast(_clname);
}

int Face_List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Face_List::List_clear()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_HalfEdge_List_t {
    QByteArrayData data[8];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HalfEdge_List_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HalfEdge_List_t qt_meta_stringdata_HalfEdge_List = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HalfEdge_List"
QT_MOC_LITERAL(1, 14, 10), // "List_clear"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "Show_HalfEdgeItems"
QT_MOC_LITERAL(4, 45, 5), // "l_num"
QT_MOC_LITERAL(5, 51, 11), // "selected_ID"
QT_MOC_LITERAL(6, 63, 16), // "SetSelected_item"
QT_MOC_LITERAL(7, 80, 4) // "l_ID"

    },
    "HalfEdge_List\0List_clear\0\0Show_HalfEdgeItems\0"
    "l_num\0selected_ID\0SetSelected_item\0"
    "l_ID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HalfEdge_List[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void HalfEdge_List::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HalfEdge_List *_t = static_cast<HalfEdge_List *>(_o);
        switch (_id) {
        case 0: _t->List_clear(); break;
        case 1: _t->Show_HalfEdgeItems((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SetSelected_item((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HalfEdge_List::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HalfEdge_List::List_clear)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HalfEdge_List::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_HalfEdge_List.data,
      qt_meta_data_HalfEdge_List,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HalfEdge_List::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HalfEdge_List::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HalfEdge_List.stringdata))
        return static_cast<void*>(const_cast< HalfEdge_List*>(this));
    return QListWidget::qt_metacast(_clname);
}

int HalfEdge_List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HalfEdge_List::List_clear()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
