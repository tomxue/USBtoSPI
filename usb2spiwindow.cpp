/*
 * usb2spiwindow.cpp
 *              To implement the FTP protocol for file transferring vi USBtoSPI adapter
 *
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		as published by the Free Software Foundation; either version
 *		2 of the License, or (at your option) any later version.
 *
 * Authors:	Tom Xue <tomxue0126@gmail.com>
 *
 * ==========================================================================
 *
 *   Detailed functionality description...
 */
#include "usb2spiwindow.h"
#include "ui_usb2spiwindow.h"
#include <stdio.h>
#include <QTextStream>

USB2SPIWindow::USB2SPIWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::USB2SPIWindow)
{
    ui->setupUi(this);

    connect(ui->openButton, SIGNAL(clicked()),
            this, SLOT(OpenDevice()));

    connect(ui->closeButton, SIGNAL(clicked()),
            this, SLOT(CloseDevice()));

    connect(ui->CloseAllButton, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(ui->fileButton, SIGNAL(clicked()),
            this, SLOT(WriteFile()));

    connect(ui->testButton, SIGNAL(clicked()),
            this, SLOT(Test()));
}

USB2SPIWindow::~USB2SPIWindow()
{
    delete ui;
}

void USB2SPIWindow::OpenDevice()
{
    if(GY7502_USBSPI_Open()==0)
        ui->infoEdit->append("Failed to open USB-SPI adapter!");
    else
        ui->infoEdit->append("Successful to open USB-SPI adapter!");


    //SetConfig of Device
    GY7502_CONFIG_INFO pConfigInfo[1];
    m_nFreq = 4;    //4~2000kHz
    m_nSpiMode = 3; //SPI Mode,to define CKPOL,CKPHA //Tom supposes: 3~CKPHA=1, CKPOL=1
    pConfigInfo->kFreq = m_nFreq;
    pConfigInfo->SpiMode = m_nSpiMode;

    if(GY7502_USBSPI_SetConfig(pConfigInfo)==0)
        ui->infoEdit->append("Failed to setting adapter!\n");
    else
        ui->infoEdit->append("Successful to setting adapter!\n");
}

void USB2SPIWindow::CloseDevice()
{
    if(GY7502_USBSPI_Close()==0)
        ui->infoEdit->append("Failed to close USB-SPI adapter!\n");
    else
        ui->infoEdit->append("Successful to close USB-SPI adapter!\n");
}

void USB2SPIWindow::on_openButton_clicked()
{
    ui->openButton->setEnabled(false);
    ui->closeButton->setEnabled(true);
}

void USB2SPIWindow::on_closeButton_clicked()
{
    ui->closeButton->setEnabled(false);
    ui->openButton->setEnabled(true);
}


void USB2SPIWindow::WriteData(int m_bRadio, int m_nReadNum, int m_nWriteNum, char DB[256], bool print)
{
    GY7502_DATA_INFO pDataInfo[1];
    pDataInfo->ChipSelect=m_bRadio;
    pDataInfo->ReadNum=m_nReadNum;
    pDataInfo->WriteNum=1;

    QString str;            //to store the written data so that they can be shown in infoEdit
    int i = 0;
    int j = 0;
    int k = 0;
    for(j=0;j<m_nWriteNum/16;j++)   //to show each (16 bytes) written data in infoEdit
    {
        pDataInfo->Databuffer[0]=DB[i+j*16];
        GY7502_USBSPI_Write(pDataInfo);

        if(print)
        {
            for(i=0;i<16;i++)
            {
                str.append(QString::number(0xFF & DB[i+j*16], 16));
                str.append("  ");
            }
            ui->infoEdit->append(str);
            str.clear();
        }
    }

    for(k=j*16;k<m_nWriteNum;k++) //to show the rest of wriiten data in infoEdit
    {
        pDataInfo->Databuffer[0]=DB[k];
        GY7502_USBSPI_Write(pDataInfo);

        str.append(QString::number(0xFF & DB[k], 16));
        str.append("  ");
    }
    ui->infoEdit->append(str);
    str.clear();
}

void USB2SPIWindow::Test()
{
    ui->infoEdit->clear();
    char *n = new char [57];
    for(int i=0;i<57;i++)
        n[i] = i;
    WriteData(0,0,57,n,true);
}
