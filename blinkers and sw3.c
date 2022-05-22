#include "tm4c123gh6pm.h"
#include "signal.h"
void portAInit()
{
    SYSCTL_RCGCGPIO_R |= 0X20;
    while((SYSCTL_PRGPIO_R&0X20)==0);
    GPIO_PORTA_LOCK_R=0X4C4F434B;
    GPIO_PORTA_CR_R |=0XC0;
    GPIO_PORTA_AMSEL_R &= ~0XFF;
    GPIO_PORTA_AFSEL_R &= ~0XFF;
    GPIO_PORTA_PCTL_R  &= ~0XFFFFFFFF;
    GPIO_PORTA_DIR_R   |= 0X80;
		GPIO_PORTA_DIR_R   &= ~0X40;
    GPIO_PORTA_DEN_R   |= 0XC0;
		GPIO_PORTA_PUR_R   |=0X40;
}


void portFInit()
{
    SYSCTL_RCGCGPIO_R |= 0X20;
    while((SYSCTL_PRGPIO_R&0X20)==0);
    GPIO_PORTF_LOCK_R=0X4C4F434B;
    GPIO_PORTF_CR_R |=0X0E;
    GPIO_PORTF_AMSEL_R &= ~0X1F;
    GPIO_PORTF_AFSEL_R &= ~0X1F;
    GPIO_PORTF_PCTL_R  &= ~0X000FFFFF;
    GPIO_PORTF_DIR_R   |= 0XE;
    GPIO_PORTF_DEN_R   |= 0X1F;
    GPIO_PORTF_DATA_R  |= 0X1E;
		GPIO_PORTF_PUR_R   |= 0X11;
}

void waitHalve(unsigned long delay)//this function takes an argument and the delay is halve that argument
{
   unsigned long i;
   for (i=0;i<delay;i++)
   {
		cont: if(((GPIO_PORTA_DATA_R & 0X40)==0x40))
		{
       NVIC_ST_CTRL_R    = 0;
       NVIC_ST_RELOAD_R  = (16000000/2)-1;
       NVIC_ST_CURRENT_R = 0;
       NVIC_ST_CTRL_R    = 0X05;
       while ((NVIC_ST_CTRL_R & 0x00010000) == 0){}
		}
		else if((GPIO_PORTA_DATA_R & 0X40)!=0x40)
		{
			while((GPIO_PORTA_DATA_R & 0X40)!=0x40){};
				goto cont ;
		}
   }
}
char buzzerAndBlinkers(char cookingDone)
{
	char i;
	if(cookingDone==1)
	{
		for(i=0;i<3;i++)
		{
			GPIO_PORTA_DATA_R |= 0X80;
			GPIO_PORTF_DATA_R  |= 0XE;
			waitHalve(1);
			GPIO_PORTA_DATA_R &= 0X7F;
			GPIO_PORTF_DATA_R  &= ~0XE;
			waitHalve(1);
		}
	}
}