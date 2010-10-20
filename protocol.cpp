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

    WriteFirstPage(filename);
    WriteMiddlePage(filename);
  }

void USB2SPIWindow::WriteFirstPage(QString filename)
{
    char *flag = new char [5];
    flag[0] = 0xA;                      //flag: first page 'A'

    int *ptr;                           //running page number = 1; int: 32bit, 4 bytes
    ptr = (int*)(&flag[1]);
    *ptr = 1;

    WriteData(0,0,5,flag,true);          //to write the flag, 5 bytes
    WriteFileSize(filename);             //to write the file size to USBtoSPI adapter, 4 bytes
    WriteFileNameCodingType(filename);   //to write the file name coding type, 1 byte
    WriteFileName(filename);             //to write the pure file name, 246 bytes
}

void USB2SPIWindow::WriteMiddlePage(QString filename)
{
    char *flag = new char [2];
    flag[0] = 0xB;                 //flag: middle page 'B'

    int totalpagenum;   //total page number
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    totalpagenum = (file.size()-242)/251;

    int *ptr;                           //running page number = 1; int: 32bit, 4 bytes
    ptr = (int*)(&flag[1]);
    *ptr = 2;

    WriteData(0,0,5,flag,true); //to write the flag, 5 bytes

    char *str = new char [9];
    for(int j=0;j<9;j++)
        str[j] = 0;                  //initialize str (part of file name) with zero
    WriteData(0,0,9,str,true);       //9 bytes of FileName
    WriteFileRawData(filename,0,242);

    int *ptr2;
    int i;
    for(i=1;i<=totalpagenum;i++)
    {
        ptr2 = (int*)(&flag[1]);    //running page number = 3..
        *ptr2 = (i+2);
        WriteData(0,0,5,flag,true); //to write the flag, 5 bytes
        WriteFileRawData(filename,(i-1)*251+242,251);
    }

    if((file.size()-242)%251 != 0)  //to write the last page
    {
        flag[0] = 0xC;              //flag of last page 'C'
        ptr2 = (int*)(&flag[1]);    //running page number = 3..
        *ptr2 = (i+2);
        WriteData(0,0,5,flag,true); //to write the flag, 5 bytes
        WriteFileRawData(filename,(i-1)*251+242,251);
    }
}

void USB2SPIWindow::WriteFileSize(QString filename)
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
    WriteData(0,0,4,sDataOfFileSize,true);

    file.close();
}

void USB2SPIWindow::WriteFileNameCodingType(QString filename)   //to be updated...
{
    ui->infoEdit->append("File name coding type is below:");

    char *coding = new char [1];
    coding[0] = 0x1;
    WriteData(0,0,1,coding,true);
}

void USB2SPIWindow::WriteFileName(QString filename)
{
    //To apply UTF8 encoding for non-English filename display
    ui->infoEdit->append(QString::fromUtf8(filename.toUtf8()));

    QFileInfo fi(filename);
    QString purefilename = fi.fileName();
    ui->infoEdit->append(QString::fromUtf8(purefilename.toUtf8().data()));
    int len = purefilename.toUtf8().length();
    WriteData(0,0,len,purefilename.toUtf8().data(),true);

    char *str = new char [246-len];
    for(int i=0;i<(246-len);i++)
        str[i] = 0;                  //initialize str with zero
    WriteData(0,0,246-len,str,true); //246-len bytes, assume file name size <= 246 bytes
}

void USB2SPIWindow::WriteFileRawData(QString filename,int startadd,int numTowrite)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QDataStream d(&file);                    //to read the file data to sDataOfFile
    char *sDataOfFile = new char [file.size()];
    d.readRawData(sDataOfFile, file.size());

    WriteData(0,0,numTowrite,&sDataOfFile[startadd],true);  //to write data to USBtoSPI adapter

    file.close();
}
