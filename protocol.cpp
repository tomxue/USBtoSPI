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
    firstpage[0] = 0xA;                      //flag: 1st page 'A'; 1 byte

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
    for(int i=len;i<255;i++)
        *(ptr4+i) = 0;                                      //rest of the filename space is set with 0

    WriteData(0, 0, 256, firstpage, true);


    //2nd page write
    int totalpagenum;   //total page number
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    totalpagenum = ((file.size()-242)%251 == 0)?(2+(file.size()-242)/251):(2+(file.size()-242)/251+1);

    QDataStream d(&file);                    //to read the file data to sDataOfFile
    char *sDataOfFile = new char [file.size()];
    d.readRawData(sDataOfFile, file.size());


    char *secondpage = new char [256];
    secondpage[0] = 0xB;                      //flag: 2nd page 'B'; 1 byte

    int *ptr5;                           //running page number = 2; int: 32bit, 4 bytes
    ptr5 = (int*)(&secondpage[1]);
    *ptr5 = 2;

    char *ptr6 = new char [9];        //rest of file name
    ptr6 = &secondpage[5];
    for(int i=0;i<9;i++)
        *(ptr6+i) = 0;                //rest of the filename in 2nd page is set with 0

    char *ptr7 = new char [242];        //file data of 2nd page
    ptr7 = &secondpage[14];
    for(int i=0;i<242;i++)
        secondpage[14+i] = sDataOfFile[i];

    WriteData(0, 0, 256, secondpage, true);

    //3, 4, 5... page write
    char *restpage = new char [256];
    restpage[0] = 0xB;                 //flag: middle page 'B'; 1 byte

    int *ptr8;
    int i;
    for(i=3;i<totalpagenum;i++)
    {
        ptr8 = (int*)(&restpage[1]);    //running page number = 3, 4, 5...
        *ptr8 = i;
        for(int j=0;j<251;j++)
            restpage[5+j] = sDataOfFile[j+(i-3)*251+242];
        WriteData(0, 0, 256, restpage, true);
    }

    //last page write ???
    char *lastpage = new char [256];
    lastpage[0] = 0xC;                 //flag: last page 'C'; 1 byte

    int *ptr9;
    ptr9 = (int*)(&lastpage[1]);    //running page number
    *ptr9 = i;
    for(int j=0;j<251;j++)
        lastpage[5+j] = sDataOfFile[j+(i-3)*251+242];
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
    ui->infoEdit->append("File name coding type is below:");

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
        n[i] = i;
    WriteData(0,0,len,n,true);

    //emit(ui->fileButton->click());
}
