/****************************************************************************
** Meta object code from reading C++ file 'usb2spiwindow.h'
**
** Created: Mon Oct 18 14:57:35 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usb2spiwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usb2spiwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_USB2SPIWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      28,   14,   14,   14, 0x08,
      42,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
     126,   91,   14,   14, 0x08,
     158,   14,   14,   14, 0x08,
     179,  170,   14,   14, 0x08,
     197,  170,   14,   14, 0x08,
     225,  170,   14,   14, 0x08,
     243,  170,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_USB2SPIWindow[] = {
    "USB2SPIWindow\0\0OpenDevice()\0CloseDevice()\0"
    "on_openButton_clicked()\0"
    "on_closeButton_clicked()\0"
    "m_bRadio,m_nReadNum,m_nWriteNum,DB\0"
    "WriteData(int,int,int,char[50])\0"
    "WriteFile()\0filename\0FileSize(QString)\0"
    "FileNameCodingType(QString)\0"
    "FileName(QString)\0FileRawDataWrite(QString)\0"
};

const QMetaObject USB2SPIWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_USB2SPIWindow,
      qt_meta_data_USB2SPIWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &USB2SPIWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *USB2SPIWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *USB2SPIWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_USB2SPIWindow))
        return static_cast<void*>(const_cast< USB2SPIWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int USB2SPIWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OpenDevice(); break;
        case 1: CloseDevice(); break;
        case 2: on_openButton_clicked(); break;
        case 3: on_closeButton_clicked(); break;
        case 4: WriteData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< char(*)[50]>(_a[4]))); break;
        case 5: WriteFile(); break;
        case 6: FileSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: FileNameCodingType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: FileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: FileRawDataWrite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
