/****************************************************************************
** Meta object code from reading C++ file 'toolsayac.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "toolsayac.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolsayac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolSayac_t {
    QByteArrayData data[9];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolSayac_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolSayac_t qt_meta_stringdata_toolSayac = {
    {
QT_MOC_LITERAL(0, 0, 9), // "toolSayac"
QT_MOC_LITERAL(1, 10, 16), // "sayacCloseSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "saatslot"
QT_MOC_LITERAL(4, 37, 7), // "setSure"
QT_MOC_LITERAL(5, 45, 5), // "value"
QT_MOC_LITERAL(6, 51, 10), // "paintEvent"
QT_MOC_LITERAL(7, 62, 12), // "QPaintEvent*"
QT_MOC_LITERAL(8, 75, 2) // "pe"

    },
    "toolSayac\0sayacCloseSignal\0\0saatslot\0"
    "setSure\0value\0paintEvent\0QPaintEvent*\0"
    "pe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolSayac[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    1,   36,    2, 0x09 /* Protected */,
       6,    1,   39,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void toolSayac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<toolSayac *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sayacCloseSignal(); break;
        case 1: _t->saatslot(); break;
        case 2: _t->setSure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (toolSayac::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolSayac::sayacCloseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject toolSayac::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_toolSayac.data,
    qt_meta_data_toolSayac,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *toolSayac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolSayac::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_toolSayac.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int toolSayac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void toolSayac::sayacCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
