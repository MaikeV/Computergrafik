/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Praktikum1/MyGLWidget.h"
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
    QByteArrayData data[19];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyGLWidget"
QT_MOC_LITERAL(1, 11, 15), // "fovValueChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "value"
QT_MOC_LITERAL(4, 34, 17), // "angleValueChanged"
QT_MOC_LITERAL(5, 52, 26), // "projectionModeValueChanged"
QT_MOC_LITERAL(6, 79, 16), // "nearValueChanged"
QT_MOC_LITERAL(7, 96, 15), // "farValueChanged"
QT_MOC_LITERAL(8, 112, 21), // "rotationAValueChanged"
QT_MOC_LITERAL(9, 134, 21), // "rotationBValueChanged"
QT_MOC_LITERAL(10, 156, 21), // "rotationCValueChanged"
QT_MOC_LITERAL(11, 178, 6), // "setFOV"
QT_MOC_LITERAL(12, 185, 8), // "setAngle"
QT_MOC_LITERAL(13, 194, 17), // "setProjectionMode"
QT_MOC_LITERAL(14, 212, 7), // "setNear"
QT_MOC_LITERAL(15, 220, 6), // "setFar"
QT_MOC_LITERAL(16, 227, 12), // "setRotationA"
QT_MOC_LITERAL(17, 240, 12), // "setRotationB"
QT_MOC_LITERAL(18, 253, 12) // "setRotationC"

    },
    "MyGLWidget\0fovValueChanged\0\0value\0"
    "angleValueChanged\0projectionModeValueChanged\0"
    "nearValueChanged\0farValueChanged\0"
    "rotationAValueChanged\0rotationBValueChanged\0"
    "rotationCValueChanged\0setFOV\0setAngle\0"
    "setProjectionMode\0setNear\0setFar\0"
    "setRotationA\0setRotationB\0setRotationC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    0,  100,    2, 0x06 /* Public */,
       6,    1,  101,    2, 0x06 /* Public */,
       7,    1,  104,    2, 0x06 /* Public */,
       8,    1,  107,    2, 0x06 /* Public */,
       9,    1,  110,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  116,    2, 0x0a /* Public */,
      12,    1,  119,    2, 0x0a /* Public */,
      13,    0,  122,    2, 0x0a /* Public */,
      14,    1,  123,    2, 0x0a /* Public */,
      15,    1,  126,    2, 0x0a /* Public */,
      16,    1,  129,    2, 0x0a /* Public */,
      17,    1,  132,    2, 0x0a /* Public */,
      18,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fovValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->angleValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->projectionModeValueChanged(); break;
        case 3: _t->nearValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->farValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->rotationAValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->rotationBValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->rotationCValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setFOV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setProjectionMode(); break;
        case 11: _t->setNear((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setFar((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setRotationA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setRotationB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setRotationC((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::fovValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::angleValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::projectionModeValueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::nearValueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::farValueChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationAValueChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationBValueChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyGLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGLWidget::rotationCValueChanged)) {
                *result = 7;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::fovValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::angleValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::projectionModeValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyGLWidget::nearValueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGLWidget::farValueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::rotationAValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGLWidget::rotationBValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGLWidget::rotationCValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
