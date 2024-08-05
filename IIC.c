
#define SCL3	P15				// Serial Clock Input
#define SDA3	P14				// Serial Data Inpu

Uchar F;
//void I2C_3(Uchar mcmd)
//{
//Uchar length = 8;			// Send Command
//
//	while(length--)
//	{
//		if(mcmd & 0x80)
//		{
//			SDA3=1;
//		}
//		else
//		{
//			SDA3=0;
//		}
//		uDelay(2);
//		SCL3=1;
//		uDelay(2);
//		SCL3=0;
//		uDelay(2);
//		mcmd = mcmd << 1;
//	}
//}
//
//
//void I2C_Ack3()
//{
//	SDA3=1;
//	uDelay(2);
//	SCL3=1;
//	uDelay(2);
//	SCL3=0;
//	uDelay(2);
//}
//
//
////void I2C_NAck3()
////{
////	SDA3=0;
////	uDelay(3);
////	SCL3=1;
////	uDelay(3);
////	SCL3=0;
////	uDelay(3);
////}
//
//
//void I2C_Start3()
//{
//	SDA3=0;
//	uDelay(2);
//	SCL3=1;
//	uDelay(2);
//	SCL3=0;
//	uDelay(2);
//	I2C_3(0x78);
//	I2C_Ack3();
//}
//
//
//void I2C_Stop3()
//{
//	SCL3=1;
//	uDelay(5);
//	SDA3=0;
//	uDelay(5);
//	SDA3=1;
//	uDelay(5);
//}
//
//void Write_Command3(Uchar Data)
//{
//	I2C_Start3();
//	I2C_3(0x00);
//	I2C_Ack3();
//	I2C_3(Data);
//	I2C_Ack3();
//	I2C_Stop3();
//}
//
//
//void Write_Data3(Uchar Data)
//{
//	I2C_Start3();
//	I2C_3(0x40);
//	I2C_Ack3();
//	I2C_3(Data);
//	I2C_Ack3();
//	I2C_Stop3();
//}
//
//void OLED_SetCursor(uchar Y, uchar X)
//{
//	Write_Command3(0xB0 | Y);					//设置Y位置
//	Write_Command3(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
//	Write_Command3(0x00 | (X & 0x0F));			//设置X位置低4位
//}
//
//void zb(uchar Y,uchar X)
//{
// OLED_SetCursor((Y/8),X);
// Write_Data3(dian[Y%8]);
//}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void wait()
{
 while(!(I2CMSST&0X40));
 I2CMSST&=~0X40;
}

//void I2C_3(Uchar mcmd)
//{
// I2CTXD=mcmd;
// I2CMSCR=0X82;
// wait();
//}

//void I2C_Ack3()
//{
// I2CMSCR=0X83;
// wait();
//}

void I2C_Start3()
{
 I2CMSCR=0X81;
 wait();
// I2C_3(0X78);
}

void I2C_Stop3()
{
 I2CMSCR=0X86;
 wait();
}


void Write_Command3(Uchar Data)
{
 I2C_Start3();
 I2CTXD=0X78;
 I2CMSCR=0X8a;
 wait();
 I2CTXD=0X00;
 I2CMSCR=0X8a;
 wait();
 I2CTXD=Data;
 I2CMSCR=0X8a;
 wait();
 I2C_Stop3();

// I2C_Start3();
// I2C_3(0x00);
// I2C_Ack3();
// I2C_3(Data);
// I2C_Ack3();
// I2C_Stop3();
}

void Write_Data3(Uchar Data)
{
 I2C_Start3();
 I2CTXD=0X78;
 I2CMSCR=0X8a;
 wait();
 I2CTXD=0X40;
 I2CMSCR=0X8a;
 wait();
 I2CTXD=Data;
 I2CMSCR=0X8a;
 wait();
 I2C_Stop3();

// I2C_Start3();
// I2C_3(0x40);
// I2C_Ack3();
// I2C_3(Data);
// I2C_Ack3();
// I2C_Stop3();
}

void OLED_SetCursor(uchar Y, uchar X)
{
	Write_Command3(0xB0 | Y);					//设置Y位置
	Write_Command3(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	Write_Command3(0x00 | (X & 0x0F));			//设置X位置低4位
}

void	LCD_Init3(void)
{

//uDelay(2);

//internal setting

Write_Command3(0xae);	//--turn off oled panel

Write_Command3(0x00);	//--set low column address
Write_Command3(0x10);	//--set high column address

Write_Command3(0x40);	//--set start line address

Write_Command3(0xb0);	//--set page address

Write_Command3(0x81);	//--set contrast control register
Write_Command3(0xff);

Write_Command3(0xa1);	//--set segment re-map 127 to 0   a0:0 to seg127
Write_Command3(0xa6);	//--set normal display

Write_Command3(0xc9);	//--set com(N-1)to com0  c0:com0 to com(N-1)

Write_Command3(0xa8);	//--set multiples ratio(1to64)
Write_Command3(0x3f);	//--1/64 duty

Write_Command3(0xd3);	//--set display offset
Write_Command3(0x00);	//--not offset

Write_Command3(0xd5);	//--set display clock divide ratio/oscillator frequency
Write_Command3(0x80);	//--set divide ratio

Write_Command3(0xd9);	//--set pre-charge period
Write_Command3(0xf1);

Write_Command3(0xda);	//--set com pins hardware configuration
Write_Command3(0x12);

Write_Command3(0xdb);	//--set vcomh
Write_Command3(0x40);

Write_Command3(0x8d);	//--set chare pump enable/disable
Write_Command3(0x14);	//--set(0x10) disable
//Write_Command3(0x10);	//--set(0x10) disable
Write_Command3(0xaf);	//--turn on oled panel
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=void 	LCD_Init(void)
}