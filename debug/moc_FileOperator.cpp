/****************************************************************************
** Meta object code from reading C++ file 'FileOperator.h'
**
** Created: Wed Oct 13 11:15:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FileOperator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileOperator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileOperator[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      25,   13,   13,   13, 0x08,
      37,   13,   13,   13, 0x08,
      47,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileOperator[] = {
    "FileOperator\0\0openFile()\0openFiles()\0"
    "openDir()\0saveFile()\0"
};

const QMetaObject FileOperator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileOperator,
      qt_meta_data_FileOperator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileOperator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileOperator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileOperator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileOperator))
        return static_cast<void*>(const_cast< FileOperator*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileOperator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFile(); break;
        case 1: openFiles(); break;
        case 2: openDir(); break;
        case 3: saveFile(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
