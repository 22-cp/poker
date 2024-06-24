/****************************************************************************
** Meta object code from reading C++ file 'desk.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../desk.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSdeskENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSdeskENDCLASS = QtMocHelpers::stringData(
    "desk",
    "setNum",
    "",
    "std::vector<int>",
    "num1",
    "getNum",
    "getNumRef",
    "touchCard",
    "getP1Hand",
    "std::vector<people::poker>",
    "getP2Hand",
    "getP3Hand"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSdeskENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x02,    1 /* Public */,
       5,    0,   59,    2, 0x02,    3 /* Public */,
       6,    0,   60,    2, 0x02,    4 /* Public */,
       7,    0,   61,    2, 0x02,    5 /* Public */,
       8,    0,   62,    2, 0x02,    6 /* Public */,
      10,    0,   63,    2, 0x02,    7 /* Public */,
      11,    0,   64,    2, 0x02,    8 /* Public */,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    0x80000000 | 3,
    QMetaType::Int,
    QMetaType::Void,
    0x80000000 | 9,
    0x80000000 | 9,
    0x80000000 | 9,

       0        // eod
};

Q_CONSTINIT const QMetaObject desk::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSdeskENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSdeskENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSdeskENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<desk, std::true_type>,
        // method 'setNum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'getNum'
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'getNumRef'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'touchCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getP1Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getP2Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getP3Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>
    >,
    nullptr
} };

void desk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<desk *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setNum((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1]))); break;
        case 1: { std::vector<int> _r = _t->getNum();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getNumRef();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->touchCard(); break;
        case 4: { std::vector<people::poker> _r = _t->getP1Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 5: { std::vector<people::poker> _r = _t->getP2Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 6: { std::vector<people::poker> _r = _t->getP3Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *desk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *desk::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSdeskENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int desk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
