#include "tm4c123gh6pm.h"    // Device header
#include "ports.h" 

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

void SysTick_Wait(unsigned long delay) // delay = number of ticks
{
NVIC_ST_CTRL_R = 0X00;
NVIC_ST_RELOAD_R = delay - 1;
NVIC_ST_CURRENT_R = 0;
NVIC_ST_CTRL_R = 0X05; // ENABLE TIMER AND CLK SRC
while((NVIC_ST_CTRL_R&0x00010000)==0); 
}

void Systick_Wait_1ms(void)
{
	
	SysTick_Wait(16000);
	
	
}

 void delay(unsigned long time)
{
	int k=0;
	unsigned long i;
	for(i=0;i<time;i++)
	{
		Systick_Wait_1ms();
	}
	
}

int check_and_delay(int t) 
{
    int i;
    int indication = 0;
    for(i = 0; i<t; i++)
    {

        Systick_Wait_1ms();

        if((SW1_Input()) == 0) // pause
        {
            indication = 1;
        }

        if((SW2_Input()) == 0) // start
        {
            indication = 2;
        }
        if(SW3_Input() == 0) // PA3 (Door is open) 
        {
            indication = 3;
        }

    }
    return indication;
}


int pause(void) // to take action for start or  clear
	{	
		while(1)
			{	
				int m = LEDS_blink();
				int l = check_and_delay(100);
				if(l==1||l==2)return l;
			}	
}