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
#include <QMessageBox>

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

    WritePages(filename);
  }

void USB2SPIWindow::WritePages(QString filename)
{
    //1st page write
    char *firstpage = new char [265];
    firstpage[0] = 0x1;                      //flag: 1st page '1'; 1 byte

    int *ptr1;                           //running page number = 1; int: 32bit, 4 bytes
    ptr1 = (int*)(&firstpage[1]);        //(int *) is type casting
    *ptr1 = 1;

    int *ptr2;                           //file size, 4 bytes
    ptr2 = (int*)(&firstpage[5]);
    *ptr2 = GetFileSize(filename);

    char *ptr3;                           //file name coding type, 1 byte
    ptr3 = &firstpage[9];
    *ptr3 = GetFilenameCodingtype(filename);

    int len = GetFilename(filename, true)->length;    //file name
    char *ptr4 = new char [len];
    ptr4 = &firstpage[10];
    for(int i=0;i<len;i++)
        *(ptr4+i) = *(GetFilename(filename, false)->nameadd+i);    //copy each byte of the file name
    *(ptr4+len) = 0x0;//NULL terminated


    int totalpagenum;   //total page number
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    totalpagenum = ((file.size()-10-len-1)%251 == 0)?((file.size()-10-len-1)/251 +1):((file.size()-10-len-1)/251 + 2);

    QDataStream d(&file);                       //to read the file data to sDataOfFile
    char *sDataOfFile = new char [file.size()];
    d.readRawData(sDataOfFile, file.size());


    int fdatanum = 256-10-len-1;

    for(int i=0;i<fdatanum;i++)         //file data of 1st page
        firstpage[10+len+1+i] = sDataOfFile[i];

    WriteData(0, 0, 256, firstpage, true);


    //2, 3, 4, 5... middle page write
    char *restpage = new char [256];
    restpage[0] = 0x2;                 //flag: middle page '2'; 1 byte

    int *ptr8;
    int i;
    for(i=2;i<(totalpagenum-1);i++)
    {
        ptr8 = (int*)(&restpage[1]);    //running page number = 2, 3, 4, 5...
        *ptr8 = i;
        for(int j=0;j<251;j++)
            restpage[5+j] = sDataOfFile[j+(i-2)*251+fdatanum];
        WriteData(0, 0, 256, restpage, true);
    }

    //last page write ???
    char *lastpage = new char [256];
    lastpage[0] = 0x3;                 //flag: last page '3'; 1 byte

    int *ptr9;
    ptr9 = (int*)(&lastpage[1]);    //running page number
    *ptr9 = i;
    for(int j=0;j<251;j++)
        lastpage[5+j] = sDataOfFile[j+(i-2)*251+fdatanum];
    WriteData(0, 0, 256, lastpage, true);
}

int USB2SPIWindow::GetFileSize(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QString str1 = QString::number(file.size());        //to change the file size to String type
    ui->infoEdit->append(tr("File size is:"));           //to show the file size
    ui->infoEdit->append(str1);

    file.close();

    return file.size();     //to write the file size to USBtoSPI adapter
}

char USB2SPIWindow::GetFilenameCodingtype(QString filename)   //to be updated...
{
    ui->infoEdit->append("File name coding type is fixed to '1' currently");

    char coding = 1;
    return coding;
}


fname* USB2SPIWindow::GetFilename(QString filename, bool print)
{
    //To apply UTF8 encoding for non-English filename display
    if(print)
        ui->infoEdit->append(QString::fromUtf8(filename.toUtf8()));

    QFileInfo fi(filename);
    QString purefilename = fi.fileName();
    if(print)
        ui->infoEdit->append(QString::fromUtf8(purefilename.toUtf8().data()));
    //int len = purefilename.toUtf8().length();

    fname *fn;
    //page 95 of <C and pointer>
    //warning: 'fn' may be used uninitialized in this function
    fn = (fname*)malloc(sizeof(fname*));
    fn->nameadd = purefilename.toUtf8().data();
    fn->length = purefilename.toUtf8().size();

    return fn;
}

void USB2SPIWindow::Test()
{
    ui->infoEdit->clear();

    int len;
    len = ui->spinBox->text().toInt(0, 10);
    if(len%2 != 0)
        QMessageBox::information(this,"Wrong","Please input even number");

    char *n = new char [len];
    for(int i=0;i<len;i++)
        n[i] = i+5;
    WriteData(0,0,len,n,true);

    //emit(ui->fileButton->click());
}

void USB2SPIWindow::on_aboutButton_clicked()
{
    QMessageBox::information(this,"Copyright","Tom Xue, Qctober of 2010");
}
