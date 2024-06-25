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
    "refChanged",
    "",
    "playCardChanged",
    "onRefChanged",
    "onPlayCardChanged",
    "output1",
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
    "getHandSize",
    "getNum1",
    "pushCard",
    "setPlayCard",
    "s",
    "getPlayCard",
    "ref",
    "playCard"
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
      15,   14, // methods
       2,  131, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    3 /* Public */,
       3,    0,  105,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  106,    2, 0x0a,    5 /* Public */,
       5,    0,  107,    2, 0x0a,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  108,    2, 0x02,    7 /* Public */,
       7,    0,  109,    2, 0x02,    8 /* Public */,
       8,    1,  110,    2, 0x02,    9 /* Public */,
      11,    1,  113,    2, 0x02,   11 /* Public */,
      13,    1,  116,    2, 0x02,   13 /* Public */,
      16,    1,  119,    2, 0x02,   15 /* Public */,
      17,    0,  122,    2, 0x02,   17 /* Public */,
      18,    0,  123,    2, 0x02,   18 /* Public */,
      19,    1,  124,    2, 0x02,   19 /* Public */,
      20,    1,  127,    2, 0x02,   21 /* Public */,
      22,    0,  130,    2, 0x02,   23 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::QString, QMetaType::Int,   12,
    QMetaType::Int,
    0x80000000 | 9,
    QMetaType::Bool, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Bool,

 // properties: name, type, flags
      23, QMetaType::Int, 0x00015903, uint(0), 0,
      24, QMetaType::Bool, 0x00015903, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject people::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSpeopleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpeopleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpeopleENDCLASS_t,
        // property 'ref'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'playCard'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<people, std::true_type>,
        // method 'refChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playCardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRefChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPlayCardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: _t->refChanged(); break;
        case 1: _t->playCardChanged(); break;
        case 2: _t->onRefChanged(); break;
        case 3: _t->onPlayCardChanged(); break;
        case 4: _t->output1(); break;
        case 5: _t->sortHand(); break;
        case 6: _t->usingCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1]))); break;
        case 7: _t->select((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->setHand((*reinterpret_cast< std::add_pointer_t<std::vector<poker>>>(_a[1]))); break;
        case 9: { QString _r = _t->getCardName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->getHandSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { std::vector<int> _r = _t->getNum1();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->pushCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setPlayCard((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: { bool _r = _t->getPlayCard();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (people::*)();
            if (_t _q_method = &people::refChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (people::*)();
            if (_t _q_method = &people::playCardChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<people *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getRef(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getPlayCard(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<people *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRef(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setPlayCard(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void people::refChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void people::playCardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
