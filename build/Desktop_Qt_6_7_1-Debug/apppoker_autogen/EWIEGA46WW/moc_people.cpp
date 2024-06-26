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
    "onRefChanged",
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
    "ref"
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
      11,   14, // methods
       1,  101, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   81,    2, 0x0a,    3 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   82,    2, 0x02,    4 /* Public */,
       5,    0,   83,    2, 0x02,    5 /* Public */,
       6,    1,   84,    2, 0x02,    6 /* Public */,
       9,    1,   87,    2, 0x02,    8 /* Public */,
      11,    1,   90,    2, 0x02,   10 /* Public */,
      14,    1,   93,    2, 0x02,   12 /* Public */,
      15,    0,   96,    2, 0x02,   14 /* Public */,
      16,    0,   97,    2, 0x02,   15 /* Public */,
      17,    1,   98,    2, 0x02,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::QString, QMetaType::Int,   10,
    QMetaType::Int,
    0x80000000 | 7,
    QMetaType::Bool, 0x80000000 | 7,    8,

 // properties: name, type, flags
      18, QMetaType::Int, 0x00015903, uint(0), 0,

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
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<people, std::true_type>,
        // method 'refChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRefChanged'
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
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>
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
        case 1: _t->onRefChanged(); break;
        case 2: _t->output1(); break;
        case 3: _t->sortHand(); break;
        case 4: _t->usingCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1]))); break;
        case 5: _t->select((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setHand((*reinterpret_cast< std::add_pointer_t<std::vector<poker>>>(_a[1]))); break;
        case 7: { QString _r = _t->getCardName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getHandSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { std::vector<int> _r = _t->getNum1();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->pushCard((*reinterpret_cast< std::add_pointer_t<std::vector<int>>>(_a[1])));
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
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<people *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getRef(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<people *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRef(*reinterpret_cast< int*>(_v)); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void people::refChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
