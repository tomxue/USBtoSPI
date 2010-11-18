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

typedef struct fname
{
    int length;
    char* nameadd;
}fname;

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
    void on_aboutButton_clicked();
    void WriteData(int m_bRadio, int m_nReadNum, int m_nWriteNum, char DB[60], bool print);
    void WriteFile();
    void WritePages(QString filename);
    int  GetFileSize(QString filename);
    char GetFilenameCodingtype(QString filename);
    fname* GetFilename(QString filename, bool print);

    void Test();
    void ConfigSet();
};

#endif // USB2SPIWINDOW_H
