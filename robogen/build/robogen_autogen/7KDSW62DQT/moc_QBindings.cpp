/****************************************************************************
** Meta object code from reading C++ file 'QBindings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scripting/QBindings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QBindings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_robogen__qscript__QMotor_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QMotor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QMotor_t qt_meta_stringdata_robogen__qscript__QMotor = {
    {
QT_MOC_LITERAL(0, 0, 24), // "robogen::qscript::QMotor"
QT_MOC_LITERAL(1, 25, 5), // "getId"
QT_MOC_LITERAL(2, 31, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 44, 0), // ""
QT_MOC_LITERAL(4, 45, 11), // "getVelocity"
QT_MOC_LITERAL(5, 57, 11), // "getPosition"
QT_MOC_LITERAL(6, 69, 9) // "getTorque"

    },
    "robogen::qscript::QMotor\0getId\0"
    "QScriptValue\0\0getVelocity\0getPosition\0"
    "getTorque"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QMotor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a /* Public */,
       4,    0,   35,    3, 0x0a /* Public */,
       5,    0,   36,    3, 0x0a /* Public */,
       6,    0,   37,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QMotor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMotor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getId();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getVelocity();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { QScriptValue _r = _t->getPosition();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 3: { QScriptValue _r = _t->getTorque();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QMotor::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QMotor.data,
    qt_meta_data_robogen__qscript__QMotor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QMotor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QMotor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QMotor.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QMotor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QSensor_t {
    QByteArrayData data[6];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QSensor_t qt_meta_stringdata_robogen__qscript__QSensor = {
    {
QT_MOC_LITERAL(0, 0, 25), // "robogen::qscript::QSensor"
QT_MOC_LITERAL(1, 26, 8), // "getLabel"
QT_MOC_LITERAL(2, 35, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 48, 0), // ""
QT_MOC_LITERAL(4, 49, 7), // "getType"
QT_MOC_LITERAL(5, 57, 4) // "read"

    },
    "robogen::qscript::QSensor\0getLabel\0"
    "QScriptValue\0\0getType\0read"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    3, 0x0a /* Public */,
       4,    0,   30,    3, 0x0a /* Public */,
       5,    0,   31,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSensor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getLabel();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getType();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { QScriptValue _r = _t->read();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QSensor::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QSensor.data,
    qt_meta_data_robogen__qscript__QSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QSensor.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QModel_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QModel_t qt_meta_stringdata_robogen__qscript__QModel = {
    {
QT_MOC_LITERAL(0, 0, 24), // "robogen::qscript::QModel"
QT_MOC_LITERAL(1, 25, 15), // "getRootPosition"
QT_MOC_LITERAL(2, 41, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 54, 0), // ""
QT_MOC_LITERAL(4, 55, 15), // "getRootAttitude"
QT_MOC_LITERAL(5, 71, 7), // "getType"
QT_MOC_LITERAL(6, 79, 10), // "getSensors"
QT_MOC_LITERAL(7, 90, 5) // "getId"

    },
    "robogen::qscript::QModel\0getRootPosition\0"
    "QScriptValue\0\0getRootAttitude\0getType\0"
    "getSensors\0getId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QModel[] = {

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
       6,    0,   42,    3, 0x0a /* Public */,
       7,    0,   43,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getRootPosition();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getRootAttitude();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { QScriptValue _r = _t->getType();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 3: { QScriptValue _r = _t->getSensors();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 4: { QScriptValue _r = _t->getId();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QModel.data,
    qt_meta_data_robogen__qscript__QModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QModel.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_robogen__qscript__QRobot_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QRobot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QRobot_t qt_meta_stringdata_robogen__qscript__QRobot = {
    {
QT_MOC_LITERAL(0, 0, 24), // "robogen::qscript::QRobot"
QT_MOC_LITERAL(1, 25, 12), // "getBodyParts"
QT_MOC_LITERAL(2, 38, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 51, 0), // ""
QT_MOC_LITERAL(4, 52, 16), // "getCoreComponent"
QT_MOC_LITERAL(5, 69, 9), // "getMotors"
QT_MOC_LITERAL(6, 79, 10), // "getSensors"
QT_MOC_LITERAL(7, 90, 7) // "getAABB"

    },
    "robogen::qscript::QRobot\0getBodyParts\0"
    "QScriptValue\0\0getCoreComponent\0getMotors\0"
    "getSensors\0getAABB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QRobot[] = {

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
       6,    0,   42,    3, 0x0a /* Public */,
       7,    0,   43,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QRobot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QRobot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getBodyParts();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getCoreComponent();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { QScriptValue _r = _t->getMotors();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 3: { QScriptValue _r = _t->getSensors();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 4: { QScriptValue _r = _t->getAABB();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QRobot::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QRobot.data,
    qt_meta_data_robogen__qscript__QRobot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QRobot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QRobot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QRobot.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QRobot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_robogen__qscript__QPositionObservable_t {
    QByteArrayData data[5];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QPositionObservable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QPositionObservable_t qt_meta_stringdata_robogen__qscript__QPositionObservable = {
    {
QT_MOC_LITERAL(0, 0, 37), // "robogen::qscript::QPositionOb..."
QT_MOC_LITERAL(1, 38, 11), // "getPosition"
QT_MOC_LITERAL(2, 50, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 63, 0), // ""
QT_MOC_LITERAL(4, 64, 11) // "getAttitude"

    },
    "robogen::qscript::QPositionObservable\0"
    "getPosition\0QScriptValue\0\0getAttitude"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QPositionObservable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    3, 0x0a /* Public */,
       4,    0,   25,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QPositionObservable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QPositionObservable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getPosition();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getAttitude();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QPositionObservable::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QPositionObservable.data,
    qt_meta_data_robogen__qscript__QPositionObservable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QPositionObservable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QPositionObservable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QPositionObservable.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QPositionObservable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QLightSource_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QLightSource_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QLightSource_t qt_meta_stringdata_robogen__qscript__QLightSource = {
    {
QT_MOC_LITERAL(0, 0, 30), // "robogen::qscript::QLightSource"
QT_MOC_LITERAL(1, 31, 12), // "getIntensity"
QT_MOC_LITERAL(2, 44, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 57, 0), // ""
QT_MOC_LITERAL(4, 58, 11), // "setPosition"
QT_MOC_LITERAL(5, 70, 1), // "x"
QT_MOC_LITERAL(6, 72, 1), // "y"
QT_MOC_LITERAL(7, 74, 1), // "z"
QT_MOC_LITERAL(8, 76, 12), // "setIntensity"
QT_MOC_LITERAL(9, 89, 9) // "intensity"

    },
    "robogen::qscript::QLightSource\0"
    "getIntensity\0QScriptValue\0\0setPosition\0"
    "x\0y\0z\0setIntensity\0intensity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QLightSource[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    3, 0x0a /* Public */,
       4,    3,   30,    3, 0x0a /* Public */,
       8,    1,   37,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    5,    6,    7,
    QMetaType::Void, QMetaType::Float,    9,

       0        // eod
};

void robogen::qscript::QLightSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLightSource *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getIntensity();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->setIntensity((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QLightSource::staticMetaObject = { {
    &QPositionObservable::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QLightSource.data,
    qt_meta_data_robogen__qscript__QLightSource,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QLightSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QLightSource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QLightSource.stringdata0))
        return static_cast<void*>(this);
    return QPositionObservable::qt_metacast(_clname);
}

int robogen::qscript::QLightSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPositionObservable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QObstacle_t {
    QByteArrayData data[1];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QObstacle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QObstacle_t qt_meta_stringdata_robogen__qscript__QObstacle = {
    {
QT_MOC_LITERAL(0, 0, 27) // "robogen::qscript::QObstacle"

    },
    "robogen::qscript::QObstacle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QObstacle[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void robogen::qscript::QObstacle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QObstacle::staticMetaObject = { {
    &QPositionObservable::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QObstacle.data,
    qt_meta_data_robogen__qscript__QObstacle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QObstacle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QObstacle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QObstacle.stringdata0))
        return static_cast<void*>(this);
    return QPositionObservable::qt_metacast(_clname);
}

int robogen::qscript::QObstacle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPositionObservable::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QBoxObstacle_t {
    QByteArrayData data[4];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QBoxObstacle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QBoxObstacle_t qt_meta_stringdata_robogen__qscript__QBoxObstacle = {
    {
QT_MOC_LITERAL(0, 0, 30), // "robogen::qscript::QBoxObstacle"
QT_MOC_LITERAL(1, 31, 7), // "getSize"
QT_MOC_LITERAL(2, 39, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 52, 0) // ""

    },
    "robogen::qscript::QBoxObstacle\0getSize\0"
    "QScriptValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QBoxObstacle[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QBoxObstacle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QBoxObstacle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getSize();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QBoxObstacle::staticMetaObject = { {
    &QObstacle::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QBoxObstacle.data,
    qt_meta_data_robogen__qscript__QBoxObstacle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QBoxObstacle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QBoxObstacle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QBoxObstacle.stringdata0))
        return static_cast<void*>(this);
    return QObstacle::qt_metacast(_clname);
}

int robogen::qscript::QBoxObstacle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObstacle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_robogen__qscript__QEnvironment_t {
    QByteArrayData data[6];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robogen__qscript__QEnvironment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robogen__qscript__QEnvironment_t qt_meta_stringdata_robogen__qscript__QEnvironment = {
    {
QT_MOC_LITERAL(0, 0, 30), // "robogen::qscript::QEnvironment"
QT_MOC_LITERAL(1, 31, 15), // "getLightSources"
QT_MOC_LITERAL(2, 47, 12), // "QScriptValue"
QT_MOC_LITERAL(3, 60, 0), // ""
QT_MOC_LITERAL(4, 61, 15), // "getAmbientLight"
QT_MOC_LITERAL(5, 77, 12) // "getObstacles"

    },
    "robogen::qscript::QEnvironment\0"
    "getLightSources\0QScriptValue\0\0"
    "getAmbientLight\0getObstacles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robogen__qscript__QEnvironment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    3, 0x0a /* Public */,
       4,    0,   30,    3, 0x0a /* Public */,
       5,    0,   31,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2,

       0        // eod
};

void robogen::qscript::QEnvironment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QEnvironment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QScriptValue _r = _t->getLightSources();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 1: { QScriptValue _r = _t->getAmbientLight();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 2: { QScriptValue _r = _t->getObstacles();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject robogen::qscript::QEnvironment::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_robogen__qscript__QEnvironment.data,
    qt_meta_data_robogen__qscript__QEnvironment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *robogen::qscript::QEnvironment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robogen::qscript::QEnvironment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robogen__qscript__QEnvironment.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(this);
    return QObject::qt_metacast(_clname);
}

int robogen::qscript::QEnvironment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
