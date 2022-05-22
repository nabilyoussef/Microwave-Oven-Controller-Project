#include "tm4c123gh6pm.h"
#include "delay.h"
#include "ports.h"
#include "lcd_functions.h"
#include "keybad.h"
#include "microwaveopp.h"




int main(void)
{
 char keypadIn;
 PORTF_init();
 PORTA_init();
 PORTB_init();
 PORTC_init();
 PORTE_init();
 SW1_Input();
 SW2_Input();
 SW3_Input();
	LCD4bits_Init();
	
	
	
while(1){
	
		keypadIn = keypad_scan();
		LCD4bits_Data(keypadIn);
		delay(250);
		if (keypadIn == 'A')
		{	int i;
			PopCorn();
			LCD4bits_Cmd(clear_display);
			LCD_WriteString("Task is Completed");
			for(i=0;i<3;i++){
				GPIO_PORTA_DATA_R |=0x04;
				GPIO_PORTF_DATA_R |= 0x0E;
				delay(250);
				GPIO_PORTF_DATA_R &= ~0x0E;
				GPIO_PORTA_DATA_R &=~0x04;
				delay(1000);
			}
			LCD4bits_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'B')
		{
			int i;
			FunctionB();
			LCD4bits_Cmd(clear_display);
			LCD_WriteString("Task is Completed");
			for(i=0;i<3;i++){
				GPIO_PORTA_DATA_R |=0x04;
				GPIO_PORTF_DATA_R |= 0x0E;
				delay(250);
				GPIO_PORTF_DATA_R &= ~0x0E;
				GPIO_PORTA_DATA_R &=~0x04;
				delay(1000);
			} 
			LCD4bits_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'C')
		{
			int i;
			FunctionC();
			LCD4bits_Cmd(clear_display);
			LCD_WriteString("Task is Completed");
			for(i=0;i<3;i++){
				GPIO_PORTA_DATA_R |=0x04;
				GPIO_PORTF_DATA_R |= 0x0E;
				delay(250);
				GPIO_PORTF_DATA_R &= ~0x0E;
				GPIO_PORTA_DATA_R &=~0x04;
				delay(1000);
			} 
			LCD4bits_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'D')
		{
			int i;
			CookTime();		
			LCD4bits_Cmd(clear_display);
			LCD_WriteString("Task is Completed");
			for(i=0;i<3;i++){
				GPIO_PORTA_DATA_R |=0x04;
				GPIO_PORTF_DATA_R |= 0x0E;
				delay(250);
				GPIO_PORTF_DATA_R &= ~0x0E;
				GPIO_PORTA_DATA_R &=~0x04;
				delay(1000);
			} 
			LCD4bits_Cmd(clear_display);
			//buzzer and blink function
		}
		else{}
	}
}


	

