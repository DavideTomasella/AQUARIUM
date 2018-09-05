/****************************************************************************
** Meta object code from reading C++ file 'home.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AQUARIUM/home.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'home.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_home_t {
    QByteArrayData data[12];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_home_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_home_t qt_meta_stringdata_home = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 10),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 7),
QT_MOC_LITERAL(4, 25, 11),
QT_MOC_LITERAL(5, 37, 13),
QT_MOC_LITERAL(6, 51, 10),
QT_MOC_LITERAL(7, 62, 11),
QT_MOC_LITERAL(8, 74, 11),
QT_MOC_LITERAL(9, 86, 10),
QT_MOC_LITERAL(10, 97, 13),
QT_MOC_LITERAL(11, 111, 13)
    },
    "home\0openPARAMS\0\0openLOG\0openVERSION\0"
    "openCALIBRATE\0refreshALL\0refreshHome\0"
    "refreshTime\0refreshSun\0refreshStatus\0"
    "refreshParams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_home[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x09 /* Protected */,
       3,    0,   65,    2, 0x09 /* Protected */,
       4,    0,   66,    2, 0x09 /* Protected */,
       5,    0,   67,    2, 0x09 /* Protected */,
       6,    0,   68,    2, 0x09 /* Protected */,
       7,    0,   69,    2, 0x09 /* Protected */,
       8,    0,   70,    2, 0x09 /* Protected */,
       9,    0,   71,    2, 0x09 /* Protected */,
      10,    0,   72,    2, 0x09 /* Protected */,
      11,    0,   73,    2, 0x09 /* Protected */,

 // slots: parameters
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

       0        // eod
};

void home::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        home *_t = static_cast<home *>(_o);
        switch (_id) {
        case 0: _t->openPARAMS(); break;
        case 1: _t->openLOG(); break;
        case 2: _t->openVERSION(); break;
        case 3: _t->openCALIBRATE(); break;
        case 4: _t->refreshALL(); break;
        case 5: _t->refreshHome(); break;
        case 6: _t->refreshTime(); break;
        case 7: _t->refreshSun(); break;
        case 8: _t->refreshStatus(); break;
        case 9: _t->refreshParams(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject home::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_home.data,
      qt_meta_data_home,  qt_static_metacall, 0, 0}
};


const QMetaObject *home::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *home::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_home.stringdata))
        return static_cast<void*>(const_cast< home*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int home::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
