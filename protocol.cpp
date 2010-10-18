/*
 * protocol.c	To implement the FTP protocol for file transferring vi USBtoSPI adapter
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

#include "ui_usb2spiwindow.h"
#include "usb2spiwindow.h"
#include <stdio.h>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>


void USB2SPIWindow::WriteFile()
  {
    ui->dataEdit->clear();
    ui->infoEdit->clear();
    QString filename = QFileDialog::getOpenFileName(    //open file dialog
        this,
        tr("Open Document"),
        QDir::currentPath(),
        tr("Audio files (*.mp3 *.wav);;All files (*.*)") );
    //if( !filename.isNull() )
    //{
    //  qDebug( filename.toAscii() );
    //}

    FileSize(filename);             //to write the file size to USBtoSPI adapter
    FileNameCodingType(filename);   //to write the file name coding type
    FileName(filename);             //to write the pure file name
    FileRawDataWrite(filename);        //to write the file data to

    char *sDataFirst = new char [255];
    sDataFirst[0] = 0xA;    //0xA - Flag 'first'
    sDataFirst[1-4] = 1;    //running page number = 1
    //sDataFirst[5-8] = sDataOfFileSize[0-3];   //to combine the file size
    sDataFirst[9] = 0;      //to combine the filename coding type, to be updated
    //sDataFirst[10-255] = sDataOfFileName[0-245];    //to combine the file name
  }

void USB2SPIWindow::FileSize(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QString str1 = QString::number(file.size());        //to change the file size to String type
    ui->infoEdit->append(tr("File size is:"));           //to show the file size
    ui->infoEdit->append(str1);

    char *sDataOfFileSize = new char [3];               //to write the file size to USBtoSPI adapter
    sDataOfFileSize[0] = 0xFF & (file.size());
    sDataOfFileSize[1] = (0xFF & (file.size())>>8);
    sDataOfFileSize[2] = (0xFF & (file.size())>>16);
    sDataOfFileSize[3] = (0xFF & (file.size())>>24);
    WriteData(0, 0, 4, sDataOfFileSize);

    file.close();
}

void USB2SPIWindow::FileNameCodingType(QString filename)
{

}

void USB2SPIWindow::FileName(QString filename)
{
    //To apply UTF8 encoding for non-English filename display
    ui->infoEdit->append(QString::fromUtf8(filename.toUtf8()));

    QFileInfo fi(filename);
    QString purefilename = fi.fileName();
    ui->infoEdit->append(QString::fromUtf8(purefilename.toUtf8().data()));
    WriteData(0, 0, 245, purefilename.toUtf8().data());
}

void USB2SPIWindow::FileRawDataWrite(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QDataStream d(&file);                     //to read the file data to sDataOfFile
    char *sDataOfFile = new char [file.size()];
    d.readRawData(sDataOfFile, file.size());

    WriteData(0, 0, 32, sDataOfFile);      //to write data to USBtoSPI adapter
    //m_bRadio = 0;       //CS = 0: low enable
    //m_nReadNum = 0;
    //m_nWriteNum = 3;

    QString str;                   //to show the file data in lineEdit
    for (int j=0; j<=31;j++)
    {
        for(int i=0;i<=15;i++)
        {
            str.append(QString::number(0xFF &(sDataOfFile[i+j*16]),16));    //to print the sent data in HEX(16) format
            str.append("  ");
        }
        ui->dataEdit->append(str);
        str.clear();
    }

    file.close();
}
