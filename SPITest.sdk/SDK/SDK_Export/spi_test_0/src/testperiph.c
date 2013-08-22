/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "xspi.h"
#include "xdevcfg.h"
#include "xemacps.h"
#include "xqspips.h"
#include "xscutimer.h"
#include "xscuwdt.h"

#include "xutil.h"
#include "font.h"

const int DELAY = 10000000;

u8 sendBufPtrInit[30] = {
	0xAE,
	0xD5,
	0x80,
	0xA8,
	0x3F,//Default: 0X3F(1/64)
	0xD3,
	0x00,
	0x40,
	0x8D,
	0x14,
	0x20,
	0x02,
	0xA0,
	0xC8,
	0xDA,
	0x12,
	0x81,
	0x8F,
	0xD9,
	0xF1,
	0xDB,
	0x30,
	0xA4,
	0xA7,//Clear Screen
	0xAF
};

u8 recvBufPtr[130] = {0};

u8 oledGram[8][128] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};

u8 oledPage[8][3] = {{
		0xB0, 0x02, 0x10
	}, {
		0xB1, 0x02, 0x10
	}, {
		0xB2, 0x02, 0x10
	}, {
		0xB3, 0x02, 0x10
	}, {
		0xB4, 0x02, 0x10
	}, {
		0xB5, 0x02, 0x10
	}, {
		0xB6, 0x02, 0x10
	}, {
		0xB7, 0x02, 0x10
	}
};

int Status;

static XSpi_Config *ConfigPtr;

static XGpio GpioRes;
static XGpio GpioDc;
static XGpio GpioVbat;
static XGpio GpioVdd;
static XSpi Spi;

int XSpi_RefreshGram();

/*
 * Clean the screen.
 */
void XSpi_Clear(void);

/*
 * Display words.
 * @param	x,y	is the position of the starting point.
 * @param	p	is the address of the character string to display.
 * Use the font sized 16.
 */
void XSpi_ShowString(u8 x,u8 y,const char *p);

/*
 * Display a certain character at the designated position.
 * @param	x		0~127.
 * @param	y		0~63.
 * @param	size	font selection, 12/16.
 * @param	mode	0, inverse; 1, normal.
 */
void XSpi_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);

/*
 * Mark a pixel.
 * @param	x	0~127.
 * @param	y	0~63.
 * @param	t	0, clear; 1, mark.
 */
void XSpi_DrawPoint(u8 x,u8 y,u8 t);

int main()
{

	Xil_ICacheEnable();
	Xil_DCacheEnable();

	print("---Entering main---\n\r");

	Status = XGpio_Initialize(&GpioRes, XPAR_AXI_GPIO_OLED_RES_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Status = XGpio_Initialize(&GpioDc, XPAR_AXI_GPIO_OLED_DC_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Status = XGpio_Initialize(&GpioVbat, XPAR_AXI_GPIO_OLED_VBAT_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Status = XGpio_Initialize(&GpioVdd, XPAR_AXI_GPIO_OLED_VDD_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Status = XSpi_Initialize(&Spi, XPAR_AXI_SPI_OLED_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	ConfigPtr = XSpi_LookupConfig(XPAR_AXI_SPI_OLED_DEVICE_ID);
	if (ConfigPtr == NULL) {
		return XST_DEVICE_NOT_FOUND;
	}

	Status = XSpi_SetOptions(&Spi, XSP_MASTER_OPTION | XSP_LOOPBACK_OPTION | XSP_MANUAL_SSELECT_OPTION);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Status = XSpi_Start(&Spi);
	if (Status != XST_SUCCESS) {
		print("---XST_FAILURE---\n\r");
	}
	XSpi_IntrGlobalDisable(&Spi);

	XSpi_SetSlaveSelect(&Spi,0x1);
	XGpio_SetDataDirection(&GpioRes, 1, 0x0);
	XGpio_SetDataDirection(&GpioDc, 1, 0x0);
	XGpio_SetDataDirection(&GpioVbat, 1, 0x0);
	XGpio_SetDataDirection(&GpioVdd, 1, 0x0);

	XGpio_DiscreteWrite(&GpioVdd, 1, 0);
	volatile int i;
	for(i = 0; i != DELAY; ++i);

	XGpio_DiscreteWrite(&GpioRes, 1, 0);
	print("---Entering reset---\n\r");
	for(i = 0; i != DELAY; ++i);
	XGpio_DiscreteWrite(&GpioRes, 1, 1);
	for(i = 0; i != DELAY; ++i);
	XGpio_DiscreteWrite(&GpioVbat, 1, 0);


	XGpio_DiscreteWrite(&GpioDc, 1, 0);//Write Command

	Status = XSpi_Transfer(&Spi, sendBufPtrInit, recvBufPtr, 25);
	if (Status != XST_SUCCESS) {
		print("---XST_FAILURE---\n\r");
	}

	print("---Entering data---\n\r");
	
	XSpi_ShowString(0,3, "LHC NSKeyLab OLED TEST ");

	XSpi_RefreshGram();

	print("---Exiting main---\n\r");
	i = 0;
	while(Spi.IsBusy){
		printf("---Spi not complete %d---\n\r", recvBufPtr[i++ % 23]);
	}
	
	Xil_DCacheDisable();
	Xil_ICacheDisable();
	
	return 0;
}

/*
 * Renew video memory to LCD.
 */
int XSpi_RefreshGram(){
	u8 i;
	for(i = 0; i != 8; ++i){
		XGpio_DiscreteWrite(&GpioDc, 1, 0);//Write Command
		Status = XSpi_Transfer(&Spi, oledPage[i], recvBufPtr, 3);
		if (Status != XST_SUCCESS) {
			printf("---oledPage[%d]---\n\r", i);
		}
		XGpio_DiscreteWrite(&GpioDc, 1, 1);//Write Data
		Status = XSpi_Transfer(&Spi, oledGram[i], recvBufPtr, 128);
		if (Status != XST_SUCCESS) {
			printf("---oledGram[%d]---\n\r", i);
		}
	}
	return Status;
}

/*
 * Clean the screen.
 */
void XSpi_Clear(void)
{
	u8 i,n;
	for(i=0;i<8;i++)
		for(n=0;n<128;n++)
			oledGram[i][n]=0X00;
	XSpi_RefreshGram();// Renew video memory to LCD.
}

/*
 * Display words.
 * @param	x,y	is the position of the starting point.
 * @param	p	is the address of the character string to display.
 * Use the font sized 16.
 */
void XSpi_ShowString(u8 x,u8 y,const char *p)
{
	#define MAX_CHAR_POSX 122
	#define MAX_CHAR_POSY 58
	while(*p!='\0')
	{
		if(x>MAX_CHAR_POSX){x=0;y+=16;}
		if(y>MAX_CHAR_POSY){y=x=0;XSpi_Clear();}
		XSpi_ShowChar(x,y,*p,16,1);
		x+=8;
		p++;
	}
}

//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~63
//mode:0,������ʾ;1,������ʾ
//size:ѡ������ 16/12
void XSpi_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{
	u8 temp,t,t1;
	u8 y0=y;
	chr=chr-' ';//�õ�ƫ�ƺ��ֵ
	for(t=0;t<size;t++)
	{
		if(size==12)temp=asc2_1206[chr][t];  //����1206����
		else temp=asc2_1608[chr][t];		 //����1608����
		for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)XSpi_DrawPoint(x,y,mode);
			else XSpi_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}
	}
}

//����
//x:0~127
//y:0~63
//t:1 ��� 0,���
void XSpi_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 pos,bx,temp=0;

	if(x>127||y>63)
		return;//������Χ��.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);

	if(t)
		oledGram[pos][x]|=temp;
	else
		oledGram[pos][x]&=~temp;
}
