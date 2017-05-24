/****************************************************************************
** Meta object code from reading C++ file 'processespane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../code/processespane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processespane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_processesPane_t {
    QByteArrayData data[10];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_processesPane_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_processesPane_t qt_meta_stringdata_processesPane = {
    {
QT_MOC_LITERAL(0, 0, 13), // "processesPane"
QT_MOC_LITERAL(1, 14, 21), // "ms_applyButtonClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 26), // "ms_setDetailsButtonClicked"
QT_MOC_LITERAL(4, 64, 25), // "on_i2iProcesses_activated"
QT_MOC_LITERAL(5, 90, 5), // "index"
QT_MOC_LITERAL(6, 96, 16), // "on_close_clicked"
QT_MOC_LITERAL(7, 113, 16), // "on_apply_clicked"
QT_MOC_LITERAL(8, 130, 21), // "on_setDetails_clicked"
QT_MOC_LITERAL(9, 152, 25) // "on_i2mProcesses_activated"

    },
    "processesPane\0ms_applyButtonClicked\0"
    "\0ms_setDetailsButtonClicked\0"
    "on_i2iProcesses_activated\0index\0"
    "on_close_clicked\0on_apply_clicked\0"
    "on_setDetails_clicked\0on_i2mProcesses_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_processesPane[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,

       0        // eod
};

void processesPane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        processesPane *_t = static_cast<processesPane *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ms_applyButtonClicked(); break;
        case 1: _t->ms_setDetailsButtonClicked(); break;
        case 2: _t->on_i2iProcesses_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_close_clicked(); break;
        case 4: _t->on_apply_clicked(); break;
        case 5: _t->on_setDetails_clicked(); break;
        case 6: _t->on_i2mProcesses_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (processesPane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processesPane::ms_applyButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (processesPane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&processesPane::ms_setDetailsButtonClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject processesPane::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_processesPane.data,
      qt_meta_data_processesPane,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *processesPane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *processesPane::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_processesPane.stringdata0))
        return static_cast<void*>(const_cast< processesPane*>(this));
    return QDialog::qt_metacast(_clname);
}

int processesPane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void processesPane::ms_applyButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void processesPane::ms_setDetailsButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
