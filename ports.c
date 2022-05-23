#include "tm4c123gh6pm.h"
#include "delay.h"
#include "lcd_functions.h"


void PORTF_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0X20;
	while((SYSCTL_PRGPIO_R &= 0X20) == 0);

	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x1F;
	GPIO_PORTF_AMSEL_R &= ~0x1F;
	GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
	GPIO_PORTF_AFSEL_R &= ~0x1F;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_DEN_R |= 0x1F;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_DATA_R &= ~0x0E;
}


void PORTA_init(void)
{         //A2 connected to buzzer A3 connected to PUR switch
	SYSCTL_RCGCGPIO_R |= 0x01;
	while((SYSCTL_PRGPIO_R &= 0x01) == 0);

	GPIO_PORTA_AMSEL_R &= ~0x0C;
	GPIO_PORTA_PCTL_R &= ~0x0000FF00;
	GPIO_PORTA_AFSEL_R &= ~0x0C;
	GPIO_PORTA_DIR_R |= 0x04;
	GPIO_PORTA_DIR_R &= ~0x08;
	GPIO_PORTA_DEN_R |= 0x0C;
	GPIO_PORTA_PUR_R |= 0x08;
	GPIO_PORTA_DATA_R &= ~0x0C;
}


void PORTB_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_PRGPIO_R &= 0x02) == 0);

	GPIO_PORTB_AMSEL_R &= ~0xFF;
	GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
	GPIO_PORTB_AFSEL_R &= ~0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DATA_R &= ~0xFF;
}


void PORTC_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x04;
	while((SYSCTL_PRGPIO_R &= 0x04) == 0);

	GPIO_PORTC_AMSEL_R &= ~0xF0;
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_DATA_R &= ~0xF0;
}


void PORTE_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x10;
	while((SYSCTL_PRGPIO_R &= 0x010) == 0);

	GPIO_PORTE_AMSEL_R &= ~0x0F;
	GPIO_PORTE_PCTL_R &= ~0x0000FFFF;
	GPIO_PORTE_CR_R |= 0x0F;
	GPIO_PORTE_AFSEL_R &= ~0x0F;
	GPIO_PORTE_DIR_R &= ~0x0F;
	GPIO_PORTE_DEN_R |= 0x0F;
	GPIO_PORTE_PDR_R |= 0x0F;
	GPIO_PORTE_DATA_R &= ~0x0F;
}


int SW1_Input(void)
{
    return (GPIO_PORTF_DATA_R&0x10);
}


int SW2_Input(void)
{
    return (GPIO_PORTF_DATA_R&0x01);
}


int SW3_Input(void)
{
    return (GPIO_PORTA_DATA_R & 0x08);
}


int LEDS_ON(void)
{
    return (GPIO_PORTF_DATA_R|=0x0E);
}


int LEDS_blink(void)
{
    return (GPIO_PORTF_DATA_R^=0x0E);
}

