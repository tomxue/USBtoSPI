#include "usb2spiwindow.h"
#include "ui_usb2spiwindow.h"


USB2SPIWindow::USB2SPIWindow(QWidget *parent) :
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

    connect(ui->WriteButton, SIGNAL(clicked()),
            this, SLOT(WriteData()));
}

USB2SPIWindow::~USB2SPIWindow()
{
    delete ui;
}

void USB2SPIWindow::OpenDevice()
{
    if(GY7502_USBSPI_Open()==0)
        ui->label1->setText("Failed to open USB-SPI adapter!");
    else
        ui->label1->setText("Successful to open USB-SPI adapter!");


    //SetConfig of Device
    GY7502_CONFIG_INFO pConfigInfo[1];
    m_nFreq = 3;    //3~1000kHz
    m_nSpiMode = 3; //SPI Mode,to define CKPOL,CKPHA //Tom supposes: 3~CKPHA=1, CKPOL=1
    pConfigInfo->kFreq = m_nFreq;
    pConfigInfo->SpiMode = m_nSpiMode;

    if(GY7502_USBSPI_SetConfig(pConfigInfo)==0)
        ui->label3->setText("Failed to setting adapter!");
    else
        ui->label3->setText("Successful to setting adapter!");
}

void USB2SPIWindow::CloseDevice()
{
    if(GY7502_USBSPI_Close()==0)
        ui->label2->setText("Failed to close USB-SPI adapter!");
    else
        ui->label2->setText("Successful to close USB-SPI adapter!");
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


void USB2SPIWindow::WriteData()
{
    GY7502_DATA_INFO pDataInfo[1];
    m_bRadio = 0;
    m_nReadNum = 0;
    m_nWriteNum = 1;
    pDataInfo->ChipSelect=m_bRadio;
    pDataInfo->ReadNum=m_nReadNum;
    pDataInfo->WriteNum=m_nWriteNum;
    pDataInfo->Databuffer[0]=136;

    if(GY7502_USBSPI_Write(pDataInfo)!=1)
        {
            ui->label4->setText("Failed to write!");
            return;
        }
    else
            ui->label4->setText("Successful to write data!");
}
