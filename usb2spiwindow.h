#ifndef USB2SPIWINDOW_H
#define USB2SPIWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <QApplication>
#include <QFile>


extern "C"
{
#include "GY7502_USBSPI.h"
}

namespace Ui {
    class USB2SPIWindow;
}

class USB2SPIWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit USB2SPIWindow(QWidget *parent = 0);
    ~USB2SPIWindow();

private:
    Ui::USB2SPIWindow *ui;
    int m_nFreq;
    int m_nSpiMode;

private slots:
    void OpenDevice();
    void CloseDevice();
    void on_openButton_clicked();
    void on_closeButton_clicked();
    void WriteData(int m_bRadio, int m_nReadNum, int m_nWriteNum, char DB[50]);
    void WriteFile();
    void FileSize(QString filename);
    void FileNameCodingType(QString filename);
    void FileName(QString filename);
    void FileRawDataWrite(QString filename);
};

#endif // USB2SPIWINDOW_H
