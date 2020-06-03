/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Praktikum3/MyGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[31];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyGLWidget"
QT_MOC_LITERAL(1, 11, 21), // "cameraToCenterChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "cameraToCenter"
QT_MOC_LITERAL(4, 49, 17), // "isAnimatedChanged"
QT_MOC_LITERAL(5, 67, 10), // "isAnimated"
QT_MOC_LITERAL(6, 78, 10), // "adjustNear"
QT_MOC_LITERAL(7, 89, 5), // "value"
QT_MOC_LITERAL(8, 95, 9), // "adjustFar"
QT_MOC_LITERAL(9, 105, 15), // "fovValueChanged"
QT_MOC_LITERAL(10, 121, 17), // "angleValueChanged"
QT_MOC_LITERAL(11, 139, 26), // "projectionModeValueChanged"
QT_MOC_LITERAL(12, 166, 14), // "projectionMode"
QT_MOC_LITERAL(13, 181, 16), // "nearValueChanged"
QT_MOC_LITERAL(14, 198, 15), // "farValueChanged"
QT_MOC_LITERAL(15, 214, 21), // "rotationAValueChanged"
QT_MOC_LITERAL(16, 236, 21), // "rotationBValueChanged"
QT_MOC_LITERAL(17, 258, 21), // "rotationCValueChanged"
QT_MOC_LITERAL(18, 280, 13), // "setIsAnimated"
QT_MOC_LITERAL(19, 294, 17), // "setCameraToCenter"
QT_MOC_LITERAL(20, 312, 6), // "setFOV"
QT_MOC_LITERAL(21, 319, 8), // "setAngle"
QT_MOC_LITERAL(22, 328, 17), // "setProjectionMode"
QT_MOC_LITERAL(23, 346, 7), // "setNear"
QT_MOC_LITERAL(24, 354, 6), // "setFar"
QT_MOC_LITERAL(25, 361, 12), // "setRotationA"
QT_MOC_LITERAL(26, 374, 12), // "setRotationB"
QT_MOC_LITERAL(27, 387, 12), // "setRotationC"
QT_MOC_LITERAL(28, 400, 15), // "onMessageLogged"
QT_MOC_LITERAL(29, 416, 19), // "QOpenGLDebugMessage"
QT_MOC_LITERAL(30, 436, 7) // "message"

    },
    "MyGLWidget\0cameraToCenterChanged\0\0"
    "cameraToCenter\0isAnimatedChanged\0"
    "isAnimated\0adjustNear\0value\0adjustFar\0"
    "fovValueChanged\0angleValueChanged\0"
    "projectionModeValueChanged\0projectionMode\0"
    "nearValueChanged\0farValueChanged\0"
    "rotationAValueChanged\0rotationBValueChanged\0"
    "rotationCValueChanged\0setIsAnimated\0"
    "setCameraToCenter\0setFOV\0setAngle\0"
    "setProjectionMode\0setNear\0setFar\0"
    "setRotationA\0setRotationB\0setRotationC\0"
    "onMessageLogged\0QOpenGLDebugMessage\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       4,    1,  132,    2, 0x06 /* Public */,
       6,    1,  135,    2, 0x06 /* Public */,
       8,    1,  138,    2, 0x06 /* Public */,
       9,    1,  141,    2, 0x06 /* Public */,
      10,    1,  144,    2, 0x06 /* Public */,
      11,    1,  147,    2, 0x06 /* Public */,
      13,    1,  150,    2, 0x06 /* Public */,
      14,    1,  153,    2, 0x06 /* Public */,
      15,    1,  156,    2, 0x06 /* Public */,
      16,    1,  159,    2, 0x06 /* Public */,
      17,    1,  162,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  165,    2, 0x0a /* Public */,
      19,    1,  168,    2, 0x0a /* Public */,
      20,    1,  171,    2, 0x0a /* Public */,
      21,    1,  174,    2, 0x0a /* Public */,
      22,    1,  177,    2, 0x0a /* Public */,
      23,    1,  180,    2, 0x0a /* Public */,
      24,    1,  183,    2, 0x0a /* Public */,
      25,    1,  186,    2, 0x0a /* Public */,
      26,    1,  189,    2, 0x0a /* Public */,
      27,    1,  192,    2, 0x0a /* Public */,
      28,    1,  195,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 29,   30,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cameraToCenterChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->isAnimatedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->adjustNear((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->adjustFar((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->fovValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->angleValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->projectionModeValueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->nearValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->farValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->rotationAValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->rotationBValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->rotationCValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setIsAnimated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setCameraToCenter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setFOV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setProjectionMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setNear((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->setFar((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->setRotationA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setRotationB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setRotationC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->onMessageLogged((*reinterpret_cast< QOpenGLDebugMessage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOpenGLDebugMessage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::cameraToCenterChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::isAnimatedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::adjustNear)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::adjustFar)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::fovValueChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::angleValueChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::projectionModeValueChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::nearValueChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::farValueChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationAValueChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationBValueChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationCValueChanged)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_MyGLWidget.data,
    qt_meta_data_MyGLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::cameraToCenterChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::isAnimatedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::adjustNear(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGLWidget::adjustFar(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGLWidget::fovValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::angleValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGLWidget::projectionModeValueChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGLWidget::nearValueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGLWidget::farValueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyGLWidget::rotationAValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyGLWidget::rotationBValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MyGLWidget::rotationCValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
