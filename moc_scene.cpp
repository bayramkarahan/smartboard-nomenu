/****************************************************************************
** Meta object code from reading C++ file 'scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scene_t {
    QByteArrayData data[14];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scene_t qt_meta_stringdata_Scene = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Scene"
QT_MOC_LITERAL(1, 6, 16), // "signalSelectItem"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 39, 4), // "item"
QT_MOC_LITERAL(5, 44, 19), // "signalNewSelectItem"
QT_MOC_LITERAL(6, 64, 20), // "sceneItemAddedSignal"
QT_MOC_LITERAL(7, 85, 8), // "slotMove"
QT_MOC_LITERAL(8, 94, 11), // "signalOwner"
QT_MOC_LITERAL(9, 106, 2), // "dx"
QT_MOC_LITERAL(10, 109, 2), // "dy"
QT_MOC_LITERAL(11, 112, 7), // "donSlot"
QT_MOC_LITERAL(12, 120, 24), // "DiagramItem::DiagramType"
QT_MOC_LITERAL(13, 145, 4) // "type"

    },
    "Scene\0signalSelectItem\0\0QGraphicsItem*\0"
    "item\0signalNewSelectItem\0sceneItemAddedSignal\0"
    "slotMove\0signalOwner\0dx\0dy\0donSlot\0"
    "DiagramItem::DiagramType\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,   46,    2, 0x0a /* Public */,
      11,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QReal, QMetaType::QReal,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSelectItem((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->signalNewSelectItem((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->sceneItemAddedSignal(); break;
        case 3: _t->slotMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 4: _t->donSlot((*reinterpret_cast< DiagramItem::DiagramType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Scene::*)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::signalSelectItem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Scene::*)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::signalNewSelectItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Scene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::sceneItemAddedSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Scene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_Scene.data,
    qt_meta_data_Scene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Scene::signalSelectItem(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scene::signalNewSelectItem(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scene::sceneItemAddedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
