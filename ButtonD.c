#include "Io.h"
#include "TM4C123GH6PM.h"
#include "keybad.h"
#include "delay.h"
#include "lcd_functions.h"
#define SW1 0x10
#define SW2 0x01

void ButtonD (){

if (keypad_scan() == 'D'){
	unsigned char KeypadInput, KeypadInput1, KeypadInput2, KeypadInput3;
	int save, save1, save2, save3;
	int minutes;
	int seconds;
	int x;
	LCD_WriteString("Cooking Time?");
	delayMs(1000);
	LCD_WriteString("00:00");
	delayMs(500);
	dec_cursor(1);
	KeypadInput = keypad_scan();
	x = KeypadInput - '0';
	if (x >= 0 && x <= 3){
	LCD4bits_Data(KeypadInput);
	delayMs(500);
	save = x;
						}	
	KeypadInput1 = keypad_scan();
	x = KeypadInput1 - '0';
	if (save == 3){
											if (x == 0){
																											delayMs(500);
																											dec_cursor(2);
																											LCD4bits_Data(KeypadInput);
																											LCD4bits_Data(KeypadInput1);
																											save1 = x;
																										}	
										}
		else if (save == 0)
		{
			if (x >= 1  && x <= 9){
				delayMs(500);
				dec_cursor(2);
				LCD4bits_Data(KeypadInput);
				LCD4bits_Data(KeypadInput1);
				save1 = x;
																																	}
		}	
	else {
		if (x >= 0 && x <= 9)
		{
			delayMs(500);
			dec_cursor(2);
			LCD4bits_Data(KeypadInput);
			LCD4bits_Data(KeypadInput1);
			save1 = x;
		}
		
				}
		KeypadInput2 = keypad_scan();
		x = KeypadInput2 - '0';
		if (save == 3) {
			if (x == 0) {
				delayMs(500);
				dec_cursor(3);
				LCD4bits_Data(KeypadInput);
				LCD4bits_Data(KeypadInput1);
				LCD4bits_Data(KeypadInput2);
				save2 = x;
			}
		}
													
if (x >= 0 && x <= 5)
		{
	delayMs(500);
	dec_cursor(3);
	LCD4bits_Data(KeypadInput);
	LCD4bits_Data(KeypadInput1);
	LCD4bits_Data(KeypadInput2);
	save2 = x;
		}
		
		KeypadInput3 = keypad_scan();
		x = KeypadInput3 - '0';
		if (save == 3) {
			if (x == 0) {
				delayMs(500);
				dec_cursor(3);
				LCD4bits_Data(KeypadInput);
				LCD4bits_Data(KeypadInput1);
				LCD4bits_Data(KeypadInput2);
				LCD4bits_Data(KeypadInput3);
				save3 = x;
			}
		}
	  if (x >= 0 && x <= 9)
		{
		  delayMs(500);
		  dec_cursor(4);
		  LCD4bits_Data(KeypadInput);
		  LCD4bits_Data(KeypadInput1);
		  LCD4bits_Data(KeypadInput2)
		  LCD4bits_Data(KeypadInput3);
		  save3 = x;
		}
		
		if (GPIO_PORTF_DATA_R == SW1){
																											LCD4bits_Cmd (clear_display);
																									}
		if (GPIO_PORTF_DATA_R == SW2){
																											minutes = save * 10 + save1;
																											seconds = save2 * 10 + save3;
																											LCD_Timer (minutes ,seconds);
																										}

	
	
	
	}
}