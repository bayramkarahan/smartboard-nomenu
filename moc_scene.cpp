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
    QByteArrayData data[22];
    char stringdata0[239];
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
QT_MOC_LITERAL(7, 85, 6), // "Scene*"
QT_MOC_LITERAL(8, 92, 5), // "scene"
QT_MOC_LITERAL(9, 98, 12), // "additemstate"
QT_MOC_LITERAL(10, 111, 11), // "Scene::Mode"
QT_MOC_LITERAL(11, 123, 4), // "mode"
QT_MOC_LITERAL(12, 128, 24), // "DiagramItem::DiagramType"
QT_MOC_LITERAL(13, 153, 4), // "type"
QT_MOC_LITERAL(14, 158, 22), // "sceneItemRemovedSignal"
QT_MOC_LITERAL(15, 181, 9), // "selection"
QT_MOC_LITERAL(16, 191, 12), // "deleteAction"
QT_MOC_LITERAL(17, 204, 8), // "slotMove"
QT_MOC_LITERAL(18, 213, 11), // "signalOwner"
QT_MOC_LITERAL(19, 225, 2), // "dx"
QT_MOC_LITERAL(20, 228, 2), // "dy"
QT_MOC_LITERAL(21, 231, 7) // "donSlot"

    },
    "Scene\0signalSelectItem\0\0QGraphicsItem*\0"
    "item\0signalNewSelectItem\0sceneItemAddedSignal\0"
    "Scene*\0scene\0additemstate\0Scene::Mode\0"
    "mode\0DiagramItem::DiagramType\0type\0"
    "sceneItemRemovedSignal\0selection\0"
    "deleteAction\0slotMove\0signalOwner\0dx\0"
    "dy\0donSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    5,   50,    2, 0x06 /* Public */,
      14,    4,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    3,   70,    2, 0x0a /* Public */,
      21,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3, QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 12,    8,    4,    9,   11,   13,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 10, 0x80000000 | 3, QMetaType::Bool,    8,   11,   15,   16,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QReal, QMetaType::QReal,   18,   19,   20,
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
        case 2: _t->sceneItemAddedSignal((*reinterpret_cast< Scene*(*)>(_a[1])),(*reinterpret_cast< QGraphicsItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< Scene::Mode(*)>(_a[4])),(*reinterpret_cast< DiagramItem::DiagramType(*)>(_a[5]))); break;
        case 3: _t->sceneItemRemovedSignal((*reinterpret_cast< Scene*(*)>(_a[1])),(*reinterpret_cast< Scene::Mode(*)>(_a[2])),(*reinterpret_cast< QGraphicsItem*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->slotMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 5: _t->donSlot((*reinterpret_cast< DiagramItem::DiagramType(*)>(_a[1]))); break;
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
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Scene* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Scene* >(); break;
            }
            break;
        case 4:
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
            using _t = void (Scene::*)(Scene * , QGraphicsItem * , bool , Scene::Mode , DiagramItem::DiagramType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::sceneItemAddedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Scene::*)(Scene * , Scene::Mode , QGraphicsItem * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::sceneItemRemovedSignal)) {
                *result = 3;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
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
void Scene::sceneItemAddedSignal(Scene * _t1, QGraphicsItem * _t2, bool _t3, Scene::Mode _t4, DiagramItem::DiagramType _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Scene::sceneItemRemovedSignal(Scene * _t1, Scene::Mode _t2, QGraphicsItem * _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
