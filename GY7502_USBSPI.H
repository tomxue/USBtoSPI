//GY7502_USBSPI.h


typedef struct GY7502_DATA_INFO{
						BYTE Databuffer[256];//buffer to write or read
						UINT WriteNum;//Valid num in Databuffer[]
						UINT ReadNum;// data num to Read
						BYTE IoSel;//bit value=1 means selected. bit0 for IO-PORT0, bit1 for IO-PORT1
						BYTE IoData;//only the bit will be valid which bit is 1 in IoSel.
						BYTE ChipSelect;//Chip Selected,output,  0~CS0, 1~CS1
						BYTE Reserved[4];//Reserved 
						}GY7502_DATA_INFO,*pGY7502_DATA_INFO;
						
typedef struct GY7502_CONFIG_INFO{
						BYTE kFreq;//SPI Clock define.Value=0..5
						//0~100kHz,1~200kHz,2~500kHz,3~1000kHz,4~2000kHz,5~6000kHz
						BYTE SpiMode;//SPI Mode,to define CKPOL,CKPHA
						BYTE Reserved[4];//Reserved						
						}GY7502_CONFIG_INFO,*pGY7502_CONFIG_INFO;
						
extern "C" 
{ 
	DWORD	__stdcall  GY7502_USBSPI_Open();//device open
	DWORD	__stdcall  GY7502_USBSPI_Close();//device close
	DWORD	__stdcall  GY7502_USBSPI_SetConfig(pGY7502_CONFIG_INFO pConfigInfo);//Set kFreq and SpiMode
	DWORD	__stdcall  GY7502_USBSPI_GetConfig(pGY7502_CONFIG_INFO pConfigInfo);//Get kFreq and SpiMode
	DWORD	__stdcall  GY7502_USBSPI_Read(pGY7502_DATA_INFO pDataInfo);//SPI Read
	DWORD	__stdcall  GY7502_USBSPI_Write(pGY7502_DATA_INFO pDataInfo);//SPI Write
	DWORD	__stdcall  GY7502_USBSPI_WriteRead(pGY7502_DATA_INFO pDataInfo);//SPI Sychronous Write&Read
	DWORD	__stdcall  GY7502_USBSPI_SetIO(pGY7502_DATA_INFO pDataInfo);// Set IO output
	DWORD	__stdcall  GY7502_USBSPI_GetIO(pGY7502_DATA_INFO pDataInfo);// Get IO status

}