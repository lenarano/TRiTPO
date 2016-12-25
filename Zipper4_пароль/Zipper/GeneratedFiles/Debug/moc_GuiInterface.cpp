/****************************************************************************
** Meta object code from reading C++ file 'GuiInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GuiInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuiInterface_t {
    QByteArrayData data[15];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiInterface_t qt_meta_stringdata_GuiInterface = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GuiInterface"
QT_MOC_LITERAL(1, 13, 13), // "createToolBar"
QT_MOC_LITERAL(2, 27, 9), // "QToolBar*"
QT_MOC_LITERAL(3, 37, 0), // ""
QT_MOC_LITERAL(4, 38, 9), // "openActiv"
QT_MOC_LITERAL(5, 48, 9), // "saveActiv"
QT_MOC_LITERAL(6, 58, 14), // "openFilesActiv"
QT_MOC_LITERAL(7, 73, 22), // "openFileUnarchiveActiv"
QT_MOC_LITERAL(8, 96, 17), // "archiveFileAction"
QT_MOC_LITERAL(9, 114, 18), // "dearchiveFileActiv"
QT_MOC_LITERAL(10, 133, 12), // "helpProgramm"
QT_MOC_LITERAL(11, 146, 13), // "aboutProgramm"
QT_MOC_LITERAL(12, 160, 4), // "quit"
QT_MOC_LITERAL(13, 165, 6), // "zipper"
QT_MOC_LITERAL(14, 172, 8) // "unZipper"

    },
    "GuiInterface\0createToolBar\0QToolBar*\0"
    "\0openActiv\0saveActiv\0openFilesActiv\0"
    "openFileUnarchiveActiv\0archiveFileAction\0"
    "dearchiveFileActiv\0helpProgramm\0"
    "aboutProgramm\0quit\0zipper\0unZipper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    3, 0x08 /* Private */,
       4,    0,   75,    3, 0x08 /* Private */,
       5,    0,   76,    3, 0x08 /* Private */,
       6,    0,   77,    3, 0x08 /* Private */,
       7,    0,   78,    3, 0x08 /* Private */,
       8,    0,   79,    3, 0x08 /* Private */,
       9,    0,   80,    3, 0x08 /* Private */,
      10,    0,   81,    3, 0x08 /* Private */,
      11,    0,   82,    3, 0x08 /* Private */,
      12,    0,   83,    3, 0x08 /* Private */,
      13,    0,   84,    3, 0x08 /* Private */,
      14,    0,   85,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
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

void GuiInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiInterface *_t = static_cast<GuiInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QToolBar* _r = _t->createToolBar();
            if (_a[0]) *reinterpret_cast< QToolBar**>(_a[0]) = _r; }  break;
        case 1: _t->openActiv(); break;
        case 2: _t->saveActiv(); break;
        case 3: _t->openFilesActiv(); break;
        case 4: _t->openFileUnarchiveActiv(); break;
        case 5: _t->archiveFileAction(); break;
        case 6: _t->dearchiveFileActiv(); break;
        case 7: _t->helpProgramm(); break;
        case 8: _t->aboutProgramm(); break;
        case 9: _t->quit(); break;
        case 10: _t->zipper(); break;
        case 11: _t->unZipper(); break;
        default: ;
        }
    }
}

const QMetaObject GuiInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GuiInterface.data,
      qt_meta_data_GuiInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuiInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuiInterface.stringdata0))
        return static_cast<void*>(const_cast< GuiInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GuiInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
