#ifndef USB2SPIWINDOW_H
#define USB2SPIWINDOW_H

#include <QMainWindow>
#include <windows.h>

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
    int m_bRadio;
    int m_nReadNum;
    int m_nWriteNum;

private slots:
    void OpenDevice();
    void CloseDevice();
    void on_openButton_clicked();
    void on_closeButton_clicked();
    void WriteData();
};

#endif // USB2SPIWINDOW_H
