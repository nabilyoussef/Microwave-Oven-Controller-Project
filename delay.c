#include "tm4c123gh6pm.h"    // Device header


void delayMs(int n)
{  
	volatile int i,j;             
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)         //delay for 1 msec
		{}
}

void delayUs(int n)             
{
	volatile int i,j;							
	for(i=0;i<n;i++)
		for(j=0;j<3;j++){}            //delay for 1 micro second
	
}

void Systick_Wait_10ms(){
	NVIC_ST_CTRL_R = 0X00;
	NVIC_ST_RELOAD_R = 160000-1;   //80MHz
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0X05;
	while((NVIC_ST_CTRL_R & 0X00010000) ==0);
 }

 void delay(unsigned long time)
{ 
	unsigned long i;
	for(i=0;i<time;i++)Systick_Wait_10ms();
}
