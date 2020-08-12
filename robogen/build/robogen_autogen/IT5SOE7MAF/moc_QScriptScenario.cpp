/****************************************************************************
** Meta object code from reading C++ file 'QScriptScenario.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scenario/QScriptScenario.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QScriptScenario.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_robogen__QScriptScenario_t {
    QByteArrayData data[10];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__QScriptScenario_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__QScriptScenario_t qt_meta_stringdata_robogen__QScriptScenario = {
    {
QT_MOC_LITERAL(0, 0, 24), // "robogen::QScriptScenario"
QT_MOC_LITERAL(1, 25, 8), // "getRobot"
QT_MOC_LITERAL(2, 34, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 47, 0), // ""
QT_MOC_LITERAL(4, 48, 14), // "getEnvironment"
QT_MOC_LITERAL(5, 63, 11), // "getCurTrial"
QT_MOC_LITERAL(6, 75, 14), // "vectorDistance"
QT_MOC_LITERAL(7, 90, 7), // "vector1"
QT_MOC_LITERAL(8, 98, 7), // "vector2"
QT_MOC_LITERAL(9, 106, 17) // "stopSimulationNow"

    },
    "robogen::QScriptScenario\0getRobot\0"
    "QScriptValue\0\0getEnvironment\0getCurTrial\0"
    "vectorDistance\0vector1\0vector2\0"
    "stopSimulationNow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__QScriptScenario[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x0a /* Public */,
       4,    0,   40,    3, 0x0a /* Public */,
       5,    0,   41,    3, 0x0a /* Public */,
       6,    2,   42,    3, 0x0a /* Public */,
       9,    0,   47,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    QMetaType::Int,
    QMetaType::Float, 0x80000000 | 2, 0x80000000 | 2,    7,    8,
    QMetaType::Void,

       0        // eod
};

void robogen::QScriptScenario::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QScriptScenario *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getRobot();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getEnvironment();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getCurTrial();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { float _r = _t->vectorDistance((*reinterpret_cast< QScriptValue(*)>(_a[1])),(*reinterpret_cast< QScriptValue(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->stopSimulationNow(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::QScriptScenario::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__QScriptScenario.data,
    qt_meta_data_robogen__QScriptScenario,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::QScriptScenario::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::QScriptScenario::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__QScriptScenario.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Scenario"))
        return static_cast< Scenario*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::QScriptScenario::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
