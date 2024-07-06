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
    "nowPlayChanged",
    "",
    "numChanged",
    "landlordChanged",
    "alreadyChanged",
    "temLandlordChanged",
    "markChanged",
    "onNowPlayChanged",
    "onNumChanged",
    "onLandlordChanged",
    "onAlreadyChanged",
    "onTemLandlordChanged",
    "onMarkChanged",
    "getNumRef",
    "dealCard",
    "getP1Hand",
    "std::vector<people::poker>",
    "getP2Hand",
    "getP3Hand",
    "getLandlordHand",
    "getNum",
    "std::vector<int>",
    "setAlready",
    "n",
    "nowPlay",
    "num",
    "landlord",
    "already",
    "temLandlord",
    "mark"
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
      20,   14, // methods
       6,  156, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  134,    2, 0x06,    7 /* Public */,
       3,    0,  135,    2, 0x06,    8 /* Public */,
       4,    0,  136,    2, 0x06,    9 /* Public */,
       5,    0,  137,    2, 0x06,   10 /* Public */,
       6,    0,  138,    2, 0x06,   11 /* Public */,
       7,    0,  139,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  140,    2, 0x0a,   13 /* Public */,
       9,    0,  141,    2, 0x0a,   14 /* Public */,
      10,    0,  142,    2, 0x0a,   15 /* Public */,
      11,    0,  143,    2, 0x0a,   16 /* Public */,
      12,    0,  144,    2, 0x0a,   17 /* Public */,
      13,    0,  145,    2, 0x0a,   18 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  146,    2, 0x02,   19 /* Public */,
      15,    0,  147,    2, 0x02,   20 /* Public */,
      16,    0,  148,    2, 0x02,   21 /* Public */,
      18,    0,  149,    2, 0x02,   22 /* Public */,
      19,    0,  150,    2, 0x02,   23 /* Public */,
      20,    0,  151,    2, 0x02,   24 /* Public */,
      21,    0,  152,    2, 0x02,   25 /* Public */,
      23,    1,  153,    2, 0x02,   26 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void,
    0x80000000 | 17,
    0x80000000 | 17,
    0x80000000 | 17,
    0x80000000 | 17,
    0x80000000 | 22,
    QMetaType::Void, QMetaType::Int,   24,

 // properties: name, type, flags
      25, QMetaType::Int, 0x00015903, uint(0), 0,
      26, 0x80000000 | 22, 0x0001590b, uint(1), 0,
      27, QMetaType::Int, 0x00015903, uint(2), 0,
      28, QMetaType::Int, 0x00015903, uint(3), 0,
      29, QMetaType::Int, 0x00015903, uint(4), 0,
      30, QMetaType::Int, 0x00015903, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject desk::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSdeskENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSdeskENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSdeskENDCLASS_t,
        // property 'nowPlay'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'num'
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::true_type>,
        // property 'landlord'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'already'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'temLandlord'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'mark'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<desk, std::true_type>,
        // method 'nowPlayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'numChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'landlordChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'alreadyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'temLandlordChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'markChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNowPlayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNumChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLandlordChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAlreadyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTemLandlordChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMarkChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getNumRef'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'dealCard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getP1Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getP2Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getP3Hand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getLandlordHand'
        QtPrivate::TypeAndForceComplete<std::vector<people::poker>, std::false_type>,
        // method 'getNum'
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        // method 'setAlready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void desk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<desk *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nowPlayChanged(); break;
        case 1: _t->numChanged(); break;
        case 2: _t->landlordChanged(); break;
        case 3: _t->alreadyChanged(); break;
        case 4: _t->temLandlordChanged(); break;
        case 5: _t->markChanged(); break;
        case 6: _t->onNowPlayChanged(); break;
        case 7: _t->onNumChanged(); break;
        case 8: _t->onLandlordChanged(); break;
        case 9: _t->onAlreadyChanged(); break;
        case 10: _t->onTemLandlordChanged(); break;
        case 11: _t->onMarkChanged(); break;
        case 12: { int _r = _t->getNumRef();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->dealCard(); break;
        case 14: { std::vector<people::poker> _r = _t->getP1Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 15: { std::vector<people::poker> _r = _t->getP2Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 16: { std::vector<people::poker> _r = _t->getP3Hand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 17: { std::vector<people::poker> _r = _t->getLandlordHand();
            if (_a[0]) *reinterpret_cast< std::vector<people::poker>*>(_a[0]) = std::move(_r); }  break;
        case 18: { std::vector<int> _r = _t->getNum();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->setAlready((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::nowPlayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::numChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::landlordChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::alreadyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::temLandlordChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (desk::*)();
            if (_t _q_method = &desk::markChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<desk *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getNowPlay(); break;
        case 1: *reinterpret_cast< std::vector<int>*>(_v) = _t->getNum(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getLandlord(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getAlready(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getTemLandlord(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getMark(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<desk *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNowPlay(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setNum(*reinterpret_cast< std::vector<int>*>(_v)); break;
        case 2: _t->setLandlord(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setAlready(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setTemLandlord(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setMark(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void desk::nowPlayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void desk::numChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void desk::landlordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void desk::alreadyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void desk::temLandlordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void desk::markChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
