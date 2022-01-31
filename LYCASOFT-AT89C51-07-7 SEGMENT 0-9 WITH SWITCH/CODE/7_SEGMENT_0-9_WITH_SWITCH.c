#include<reg51.h>
void delay()
{
	int i,j;
	for(i=0;i<100;i++)
		for(j=0;j<1000;j++);
}

char DIG[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x67};			//comman cathode type;
//char DIG[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};			//comman anode type;

int Count;
sbit SW = P2^7;

void main()
{
	P2 = 0x80;
	
	while(1)
	{
		if(SW == 0)
		{
			P2 = DIG[Count];
			Count++;
			if(Count >= 10)
			{
				Count = 0;
			}
		}
		else
			P2^8=1;
	}
}