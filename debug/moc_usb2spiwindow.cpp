/****************************************************************************
** Meta object code from reading C++ file 'usb2spiwindow.h'
**
** Created: Sat Oct 23 11:25:09 2010
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
      11,   14, // methods
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
     132,   91,   14,   14, 0x08,
     169,   14,   14,   14, 0x08,
     190,  181,   14,   14, 0x08,
     214,  181,  210,   14, 0x08,
     240,  181,  235,   14, 0x08,
     293,  278,  271,   14, 0x08,
     319,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_USB2SPIWindow[] = {
    "USB2SPIWindow\0\0OpenDevice()\0CloseDevice()\0"
    "on_openButton_clicked()\0"
    "on_closeButton_clicked()\0"
    "m_bRadio,m_nReadNum,m_nWriteNum,DB,print\0"
    "WriteData(int,int,int,char[60],bool)\0"
    "WriteFile()\0filename\0WritePages(QString)\0"
    "int\0GetFileSize(QString)\0char\0"
    "GetFilenameCodingtype(QString)\0fname*\0"
    "filename,print\0GetFilename(QString,bool)\0"
    "Test()\0"
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
        case 4: WriteData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< char(*)[60]>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: WriteFile(); break;
        case 6: WritePages((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { int _r = GetFileSize((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { char _r = GetFilenameCodingtype((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        case 9: { fname* _r = GetFilename((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< fname**>(_a[0]) = _r; }  break;
        case 10: Test(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
