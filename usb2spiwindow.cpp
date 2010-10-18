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


void USB2SPIWindow::WriteData(int m_bRadio, int m_nReadNum, int m_nWriteNum, char DB[60])
{
    GY7502_DATA_INFO pDataInfo[3];

    pDataInfo->ChipSelect=m_bRadio;
    pDataInfo->ReadNum=m_nReadNum;
    pDataInfo->WriteNum=m_nWriteNum;

    for(int i=0; i<=59; i++)
        pDataInfo->Databuffer[i]=DB[i];

    if(GY7502_USBSPI_Write(pDataInfo)!=1)
        {
            ui->infoEdit->append("Failed to write!\n");
            return;
        }
    else
        {
            QString str;            //to show the written data in infoEdit
            ui->infoEdit->append("Successful to write data!");
            for(int i=0;i<=30;i++)
            {
                str.append(QString::number(DB[i], 16));
                str.append("  ");
            }
            ui->infoEdit->append(str);
            str.clear();
        }

}


