/****************************************************************************
** Meta object code from reading C++ file 'people.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../people.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'people.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSpeopleENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSpeopleENDCLASS = QtMocHelpers::stringData(
    "people",
    "output1",
    "",
    "sortHand",
    "usingCard",
    "std::vector<int>",
    "num",
    "select",
    "n",
    "setHand",
    "std::vector<poker>",
    "Poker",
    "getCardName",
    "setRef",
    "getRef",
    "getHandSize",
    "getNum1",
    "pushCard",
    "setPlayCard",
    "s",
    "getPlayCard"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSpeopleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x02,    1 /* Public */,
       3,    0,   93,    2, 0x02,    2 /* Public */,
       4,    1,   94,    2, 0x02,    3 /* Public */,
       7,    1,   97,    2, 0x02,    5 /* Public */,
       9,    1,  100,    2, 0x02,    7 /* Public */,
      12,    1,  103,    2, 0x02,    9 /* Public */,
      13,    1,  106,    2, 0x02,   11 /* Public */,
      14,    0,  109,    2, 0x02,   13 /* Public */,
      15,    0,  110,    2, 0x02,   14 /* Public */,
      16,    0,  111,    2, 0x02,   15 /* Public */,
      17,    1,  112,    2, 0x02,   16 /* Public */,
      18,    1,  115,    2, 0x02,   18 /* Public */,
      20,    0,  118,    2, 0x02,   20 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::QString, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 5,
    QMetaType::Bool, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Bool,

       0        // eod
};

Q_CONSTINIT const QMetaObject people::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSpeopleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpeopleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpeopleENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<people, std::true_type>,
        // method 'output1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'usingCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setHand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<poker>, std::false_type>,
        // method 'getCardName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setRef'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getRef'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getHandSize'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getNum1'
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'pushCard'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'setPlayCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getPlayCard'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void people::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<people *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->output1(); break;
        case 1: _t->sortHand(); break;
        case 2: _t->usingCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1]))); break;
        case 3: _t->select((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setHand((*reinterpret_cast< std::add_pointer_t<std::vector<poker>>>(_a[1]))); break;
        case 5: { QString _r = _t->getCardName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setRef((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: { int _r = _t->getRef();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getHandSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { std::vector<int> _r = _t->getNum1();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->pushCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setPlayCard((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: { bool _r = _t->getPlayCard();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *people::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *people::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSpeopleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int people::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
