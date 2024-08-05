#include "SYS.h"
#include "PIC.h"
#include "IIC.C"
#include <math.h>    //Keil library
#include <stdio.h>
#include <stdlib.h>

sbit left=P3^2;
sbit right=P3^5;
sbit up=P3^4;
sbit down=P3^6;
sbit zhong=P3^3;

float i;
Uchar g,p,q,k,c,m,n;
Uchar dian1;
Uchar bl,djsl,js,sw;
signed int djz[7]={1,1,1,1,1,1,1};
Uchar djh[7]={1,1,1,1,1,1,1};
Uint jc,df,sd;
const Uchar dian[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//const Uchar fjh[45]={0,0,1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,6,6,6,6,6,7,7,7,8,8};
//const Uchar fjz[45]={5,6,4,5,6,3,4,5,6,8,1,2,3,4,5,6,7,8,0,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,3,4,5,6,8,4,5,6,5,6};
code Uchar fjzf[16][16]={
				  {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
				  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
				  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
				  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
				  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				  {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0}
};

code Uchar djzf[16][16]={
				  {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
				  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
				  {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				  {0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},
				  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
				  {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
				  {0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}
};
//void pic13(void)
//{
//	Uchar i,j;
//	Uint k;
//	k=0;
//	for(j=4;j<8;j++)
//	{
//		Write_Command3(0x22);//--set page1
//		Write_Command3(j);//--set start page
//		Write_Command3(0x07);//--set end page
//
// 		for(i=0;i<128;i++)		  				//??那?米ㄓ谷?那y?Y米?LCD
//		{
//			Write_Data3(color13[k]);
//			k=k+1;
//
//		}
//	}
//}

//void Disp(uchar X_st,uchar Y_st,uint num)
//{
//			Uchar i,j;
//	for(j=0;j<2;j++)
//		{
//			Write_Command3(0x22);//--set page1
//			Write_Command3(Y_st+j);//--set start page
//			Write_Command3(0x07);//--set end page
//			for(i=0;i<X_st;i++)
//					{	Write_Data3(0x00);}
//			for(i=0;i<8;i++)		  				
//					{	Write_Data3(suzi[(num/10000)%10][i+8*j]);}	//??那?米ㄓ谷?那y?Y米?LCD
//			for(i=0;i<8;i++)		  				
//					{	Write_Data3(suzi[(num/1000)%10][i+8*j]);}	//??那?米ㄓ谷?那y?Y米?LCD
//			for(i=0;i<8;i++)		  				
//					{	Write_Data3(suzi[(num/100)%10][i+8*j]);}	//??那?米ㄓ谷?那y?Y米?LCD
//			for(i=0;i<8;i++)		  				
//					{	Write_Data3(suzi[(num/10)%10][i+8*j]);}		//??那?米ㄓ谷?那y?Y米?LCD
//			for(i=0;i<8;i++)		  				
//					{	Write_Data3(suzi[num%10][i+8*j]);}					//??那?米ㄓ谷?那y?Y米?LCD
//			for(i=X_st+40;i<128;i++)
//					{	Write_Data3(0x00);}			
//		}
//}

//void xsmz(uchar X_st,uchar Y_st)
//{
// Uchar i;
// Write_Command3(0x22);//--set page1
// Write_Command3(Y_st);//--set start page
// Write_Command3(0x07);//--set end page
// for(i=0;i<X_st;i++)
// {	Write_Data3(0x00);}
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[0][i]);}	//??那?米ㄓ谷?那y?Y米?LCD
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[2][i]);}
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[4][i]);}
// for(i=X_st+48;i<128;i++)
// {	Write_Data3(0x00);}
// Write_Command3(0x22);//--set page1
// Write_Command3(Y_st+1);//--set start page
// Write_Command3(0x07);//--set end page
// for(i=0;i<X_st;i++)
// {	Write_Data3(0x00);}
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[1][i]);}	//??那?米ㄓ谷?那y?Y米?LCD
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[3][i]);}	
// for(i=0;i<16;i++)		  				
// {	Write_Data3(mz[5][i]);}
// for(i=X_st+48;i<128;i++)
// {	Write_Data3(0x00);}		
//}

void zb(uchar Y,uchar X)
{
 OLED_SetCursor((Y/8),X);
 if(dian1==0)
 {
  Write_Data3(dian[Y%8]);
 }
 else
 {
  Write_Data3(dian1);
 }
}

void xs(uchar Y,uchar X)
{
 OLED_SetCursor((Y/8),X);
 Write_Data3(dian1);
}

//void xsd(uchar Y,uchar X,uchar gs,uchar fx)
//{
// OLED_SetCursor((Y/8),X);
// Y%=8;
// if(fx==1)
// {
//  while(gs--)
//  {
//   dian1+=dian[Y];
//   Y++;
//  }
// }
// if(fx==0)
// {
//  while(gs--)
//  {
//   dian1+=dian[Y];
//   Y--;
//  }
// }
// Write_Data3(dian1);
//}

//void yuan(uchar a,uchar b,uchar r)
//{
// Uchar d1,d2;
// Uchar z1,z2;
// Uchar d;
// z1=0;
// z2=0;
// d=0;
// for(i=0;i<=6.28;i+=0.01)
// {
//  d1=a+r*cos(i); 
//  d2=b+r*sin(i);
//  if(z1==d1&z2!=d2&d2/8==d/8)
//  {
//   dian1+=dian[d2%8];
//  }
//  else if(z1!=d1||d2/8!=d/8)
//  {
//   dian1=0;
//  }
//  z1=a+r*cos(i);
//  z2=b+r*sin(i);
//  d=b+r*sin(i);
//  zb(z2,z1);
//
// }
//}

void fj(Uchar a,Uchar b)
{
 Uchar d1,d2;
 Uchar z1,z2;
 Uchar d;
 Uchar t;
 Uchar b1;
 z1=0;
 z2=0;
 d=0;
 d1=0;
 d2=0;
 k=0;
 c=0;
 b1=0;
 t=0;
 while(t<16)
 {
  dian1=0;
  b1=b+q;
  t=8-(b1%8)+c;
  if(t>16)
  {
   t=16;
  }
  for(p=0;p<16;p++)
  {
   dian1=0;
   for(q=c;q<t;q++)
   {
    d1=a+p; 
    d2=b+q;
    if(fjzf[q][p]==1&d2/8==d/8)
    {
     dian1+=dian[d2%8];
    }
    d=b+q;
	k++;
   }
   z1=a+p-1;
   z2=b+q-1;
   xs(z2,z1);
   b1=0;
  }
  c=k/16;
 }
}

Uchar pdpz(Uchar wh,Uchar wz,Uchar dh,Uchar dz)
{
 if(wz<=dz+11&wz+11>=dz)
 {
  if(dh+11>=wh&dh<=wh+11)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
 else
 {
  return 0;
 }
}

void dj(Uchar a,Uchar b)
{
 Uchar d1,d2;
 Uchar z1,z2;
 Uchar d;
 Uchar t;
 Uchar b1;
 z1=0;
 z2=0;
 d=0;
 d1=0;
 d2=0;
 k=0;
 c=0;
 b1=0;
 t=0;
 while(t<16)
 {
  dian1=0;
  b1=b+q;
  t=8-(b1%8)+c;
  if(t>16)
  {
   t=16;
  }
  for(p=0;p<16;p++)
  {
   dian1=0;
   if(b+c>=64)
   {
    t=16;
	break;
   }
   for(q=c;q<t;q++)
   {
    d1=a+p; 
    d2=b+q;
    if(djzf[q][p]==1&d2/8==d/8)
    {
     dian1+=dian[d2%8];
    }
    d=b+q;
	k++;
	if(b+q>=64)
    {
	 break;
    }
   }
   z1=a+p-1;
   z2=b+q-1;
   xs(z2,z1);
   b1=0;
  }
  c=k/16;
 }
}

void Clean()
{
 Uint i,j;
 for(i=0;i<8;i++)
 {
  Write_Command3(0x22);//--set page1
  Write_Command3(i);//--set start page
  Write_Command3(0x07);//--set end page
  for(j=0;j<128;j++)
  {
   Write_Data3(0x00);
  }
 }
}

void over()
{
 jc=0;
 for(g=0;g<8;g++)
 {
  for(p=0;p<4;p++)
  {
   OLED_SetCursor(p,16*g);
   for(q=0;q<16;q++)
   {
    Write_Data3(game_over[jc]);
	jc++;
   }
  }
 }
 for(g=0;g<8;g++)
 {
  for(p=4;p<8;p++)
  {
   OLED_SetCursor(p,16*g);
   for(q=0;q<16;q++)
   {
    Write_Data3(game_over[jc]);
	jc++;
   }
  }
 }
 delay_ms(500);
 Clean();
 jc=0;
 for(g=0;g<2;g++)
 {
  for(p=2;p<6;p++)
  {
   OLED_SetCursor(p,g*32);
   for(q=0;q<32;q++)
   {
	Write_Data3(dfsz[jc]);
	jc++;
   }
  }
 }
 jc=0;
 for(p=2;p<6;p++)
 {
  OLED_SetCursor(p,64);
  for(q=0;q<16;q++)
  {
   Write_Data3(dsz[11][jc]);
   jc++;
  }
 }
 jc=0;
 for(p=2;p<6;p++)
 {
  OLED_SetCursor(p,80);
  for(q=0;q<16;q++)
  {
   Write_Data3(dsz[(df/100)%10][jc]);
   jc++;
  }
 }
 jc=0;
 for(p=2;p<6;p++)
 {
  OLED_SetCursor(p,96);
  for(q=0;q<16;q++)
  {
   Write_Data3(dsz[(df/10)%10][jc]);
   jc++;
  }
 }
 jc=0;
 for(p=2;p<6;p++)
 {
  OLED_SetCursor(p,112);
  for(q=0;q<16;q++)
  {
   Write_Data3(dsz[df%10][jc]);
   jc++;
  }
 }
}

//void ALL()
//{
// Uint i,j;
// for(i=0;i<8;i++)
// {
//  Write_Command3(0x22);//--set page1
//  Write_Command3(i);//--set start page
//  Write_Command3(0x07);//--set end page
//  for(j=0;j<128;j++)
//  {
//   Write_Data3(0xFF);
//  }
// }
//}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void main()
{
 P1M0=0x00; P1M1=0x00;
 P3M0=0x00; P3M1=0x00;
 P_SW2=0X80;
 I2CCFG=0XC0;
 LCD_Init3();
 Clean();
 dian1=0;
 left=1;
 right=1;
 up=1;
 down=1;
 zhong=1;
 m=24;
 n=56;
 bl=0;
 df=0;
 sw=0;
// for(m=1;m<48;m++)
// {
//  for(n=1;n<112;n++)
//  {
//   fj(m,n);
//   delay_ms(100);
//   Clean();
//  }
// }
// fj(60,30);
// pic13();
// xsmz(34,2);
// yuan(63,31,31);
 while(zhong==1);
 while(1)
 {
  djsl=(df/5)+1;
  if(djsl>7)
  {
   djsl=7;
  }
  for(js=0;js<djsl;js++)
  {
   if(sd%3==0)
   {
    djz[js]++;
   }
   if(djz[js]>64)
   {
    djz[js]=1;
    df++;
    djh[js]+=rand()%40+20;
	djz[js]-=rand()%25;
   }
   if(djh[js]>112)
   {
    djh[js]=rand()%25+1;
   }
  }
  if(left==0)
  {
   delay_ms(1);
   if(left==0)
   {
	n--;
   }
  }
  if(right==0)
  {
   delay_ms(1);
   if(right==0)
   {
	n++;
	right=1;
   }
  }
  if(up==0)
  {
   delay_ms(1);
   if(up==0)
   {
	m--;
	up=1;
   }
  }
  if(down==0)
  {
   delay_ms(1);
   if(down==0)
   {
	m++;
	down=1;
   }
  }
  if(m<=1)
  {
   m=1;
  }
  if(m>=48)
  {
   m=48;
  }
  if(n<=1)
  {
   n=1;
  }
  if(n>=112)
  {
   n=112;
  }
  if(bl%2==0)
  {
   fj(n,m);
   for(js=0;js<djsl;js++)
   {
    if(djz>0)
	{
     dj(djh[js],djz[js]);
	}
   }
  }
  else
  {
   for(js=0;js<djsl;js++)
   {
    if(djz>0)
	{
     dj(djh[js],djz[js]);
	}
   }
   fj(n,m);
  }
  for(js=0;js<djsl;js++)
  {
   if(pdpz(n,m,djh[js],djz[js])==1)
   {
	sw++;
    break;
   }
  }
  if(sw>1)
  {
   over();
   delay_ms(500);
   break;
  }
  delay_ms(1);
  clean();
  bl++;
  sd++;
//  for(m=1;m<48;m++)
// {
//  for(n=1;n<112;n++)
//  {
//   fj(n,m);
//   delay_ms(10);
//   Clean();
//  }
// }
//  uint i; 
//  for(i=0;i<20000;i++)
//  Disp(40,0,i);
//  delay_ms(10);
//  for(i=6;i<=6.56;i+=0.1)
//  {
//   zb(31+31*sin(i),63+31*cos(i));
//  }
//  for(i=2.86;i<=3.42;i+=0.1)
//  {
//   zb(31+31*sin(i),63+31*cos(i));
//  }
 }
}
