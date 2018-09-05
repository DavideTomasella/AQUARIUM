/****************************************************************************
** Meta object code from reading C++ file 'inoutconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AQUARIUM/inoutconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inoutconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InOutConnection_t {
    QByteArrayData data[16];
    char stringdata[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InOutConnection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InOutConnection_t qt_meta_stringdata_InOutConnection = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 9),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 15),
QT_MOC_LITERAL(4, 43, 9),
QT_MOC_LITERAL(5, 53, 19),
QT_MOC_LITERAL(6, 73, 14),
QT_MOC_LITERAL(7, 88, 16),
QT_MOC_LITERAL(8, 105, 13),
QT_MOC_LITERAL(9, 119, 12),
QT_MOC_LITERAL(10, 132, 14),
QT_MOC_LITERAL(11, 147, 20),
QT_MOC_LITERAL(12, 168, 8),
QT_MOC_LITERAL(13, 177, 11),
QT_MOC_LITERAL(14, 189, 13),
QT_MOC_LITERAL(15, 203, 15)
    },
    "InOutConnection\0dataReady\0\0connectionError\0"
    "errorCode\0initInOutConnection\0"
    "requestVersion\0requestINOUTdata\0"
    "sendINOUTdata\0requestClock\0udpUpdateState\0"
    "initializeQUDPSocket\0sendData\0receiveData\0"
    "updateVersion\0updateINOUTdata"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InOutConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   83,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x09 /* Protected */,
      11,    0,   89,    2, 0x09 /* Protected */,
      12,    0,   90,    2, 0x09 /* Protected */,
      13,    0,   91,    2, 0x09 /* Protected */,
      14,    0,   92,    2, 0x09 /* Protected */,
      15,    0,   93,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

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
    QMetaType::Void,

       0        // eod
};

void InOutConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InOutConnection *_t = static_cast<InOutConnection *>(_o);
        switch (_id) {
        case 0: _t->dataReady(); break;
        case 1: _t->connectionError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->initInOutConnection(); break;
        case 3: _t->requestVersion(); break;
        case 4: _t->requestINOUTdata(); break;
        case 5: _t->sendINOUTdata(); break;
        case 6: _t->requestClock(); break;
        case 7: _t->udpUpdateState(); break;
        case 8: _t->initializeQUDPSocket(); break;
        case 9: _t->sendData(); break;
        case 10: _t->receiveData(); break;
        case 11: _t->updateVersion(); break;
        case 12: _t->updateINOUTdata(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InOutConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutConnection::dataReady)) {
                *result = 0;
            }
        }
        {
            typedef void (InOutConnection::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutConnection::connectionError)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject InOutConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InOutConnection.data,
      qt_meta_data_InOutConnection,  qt_static_metacall, 0, 0}
};


const QMetaObject *InOutConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InOutConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InOutConnection.stringdata))
        return static_cast<void*>(const_cast< InOutConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int InOutConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void InOutConnection::dataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void InOutConnection::connectionError(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
