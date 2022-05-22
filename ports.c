#include "tm4c123gh6pm.h"


void PORTB_init(void){        
	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_PRGPIO_R &= 0x02) == 0);
	GPIO_PORTB_AMSEL_R &= ~0xFF;
	GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
	GPIO_PORTB_AFSEL_R &= ~0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DATA_R &= ~0xFF;	
}

void PORTC_init(void){        // columns
	SYSCTL_RCGCGPIO_R |= 0x04;
	while((SYSCTL_PRGPIO_R &= 0x04) == 0);
	GPIO_PORTC_AMSEL_R &= ~0xF0;
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_DATA_R &= ~0xF0;	
	 
	
	
}

void PORTE_init(void){       // rows
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