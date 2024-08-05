#include <STC8G.H>
#include <intrins.h>   //24M

#define Uchar unsigned char
#define Uint  unsigned int
#define Ulong unsigned long
#define uchar unsigned char
#define uint  unsigned int
	
void 	delay_ms(Uint t)//24M
{
	unsigned long i;
	while(--t)
	{
	_nop_();
	_nop_();
	_nop_();
	i = 5998UL;
	while (i) i--;
	}
}
void uDelay(Uchar l)
{
	unsigned long i;
	while(l--)
	{		
	_nop_();
	_nop_();
	_nop_();
	i = 4UL;
	while (i) i--;
	}
}
