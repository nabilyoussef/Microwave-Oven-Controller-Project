#include <C:\Keil\Labware\tm4c123gh6pm.h>
#define SW1 0x10
#define SW2 0x01
#define SW3 //to be adjusted

char keypadIn = keypad_scan();

void FunctionB(){
if(keypadIn == 'B'){
	while(1){
	LCD_WriteString("Beef weight?");
	keypadIn = keypad_scan();
		if((int)keypadIn >= 1 | (int)keypadIn <=9){
		LCD_WriteString(keypadIn); //output the input weight to LCD
    delay(200);
		int time =  (0.5*(int)keypadIn)*60;
		int delay = (int)time/0.01;
		int min =   (int)time/60;
		int sec =    time % 60;  
		//LCD DISPLAY TIME
		break;
		}
		else{
			LCD_WriteString("ERR");
			delay(200);
	 }
	}
 }
}


void FunctionC(){
if(keypadIn == 'C'){
	while(1){
	LCD_WriteString("Chicken weight?");
	keypadIn = keypad_scan();
		if((int)keypadIn >= 1 | (int)keypadIn <=9){
		LCD_WriteString(keypadIn); //output the input weight to LCD
    delay(200);
		int time =  (0.2*(int)keypadIn)*60;
		int delay = (int)time/0.01;
		int min =   (int)time/60;
		int sec =    time % 60;  
		//LCD DISPLAY TIME
		break;
		}
		else{
			LCD_WriteString("ERR");
			delay(200);
			}
		}
	}
}