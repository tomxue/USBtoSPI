#-------------------------------------------------
#
# Project created by QtCreator 2010-10-10T17:26:17
#
#-------------------------------------------------

QT       += core gui

TARGET = USBtoSPI
TEMPLATE = app


SOURCES += main.cpp\
        usb2spiwindow.cpp

HEADERS  += usb2spiwindow.h

FORMS    += usb2spiwindow.ui

LIBS     += -LC:/workspace/USBtoSPI -lGY7502_USBSPI
