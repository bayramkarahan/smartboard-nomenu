/****************************************************************************
** Meta object code from reading C++ file 'toolpromter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "toolpromter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolpromter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolPromter_t {
    QByteArrayData data[13];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolPromter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolPromter_t qt_meta_stringdata_toolPromter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "toolPromter"
QT_MOC_LITERAL(1, 12, 18), // "promterCloseSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "timerTextslot"
QT_MOC_LITERAL(4, 46, 8), // "saatslot"
QT_MOC_LITERAL(5, 55, 7), // "setSure"
QT_MOC_LITERAL(6, 63, 5), // "value"
QT_MOC_LITERAL(7, 69, 10), // "paintEvent"
QT_MOC_LITERAL(8, 80, 12), // "QPaintEvent*"
QT_MOC_LITERAL(9, 93, 2), // "pe"
QT_MOC_LITERAL(10, 96, 19), // "on_btnColor_clicked"
QT_MOC_LITERAL(11, 116, 18), // "on_btnFont_clicked"
QT_MOC_LITERAL(12, 135, 19) // "on_btnPause_clicked"

    },
    "toolPromter\0promterCloseSignal\0\0"
    "timerTextslot\0saatslot\0setSure\0value\0"
    "paintEvent\0QPaintEvent*\0pe\0"
    "on_btnColor_clicked\0on_btnFont_clicked\0"
    "on_btnPause_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolPromter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x09 /* Protected */,
       4,    0,   56,    2, 0x09 /* Protected */,
       5,    1,   57,    2, 0x09 /* Protected */,
       7,    1,   60,    2, 0x09 /* Protected */,
      10,    0,   63,    2, 0x09 /* Protected */,
      11,    0,   64,    2, 0x09 /* Protected */,
      12,    0,   65,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void toolPromter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<toolPromter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->promterCloseSignal(); break;
        case 1: _t->timerTextslot(); break;
        case 2: _t->saatslot(); break;
        case 3: _t->setSure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 5: _t->on_btnColor_clicked(); break;
        case 6: _t->on_btnFont_clicked(); break;
        case 7: _t->on_btnPause_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (toolPromter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPromter::promterCloseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject toolPromter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_toolPromter.data,
    qt_meta_data_toolPromter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *toolPromter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolPromter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_toolPromter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int toolPromter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void toolPromter::promterCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
