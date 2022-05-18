#include "tm4c123gh6pm.h"    // Device header
#include "delay.h"
#include "ports.h"

#define LCD GPIOB    		//LCD port with Tiva C 
#define RS 0x01				 	//RS -> PB0 (0x01)
#define RW 0x02         //RW -> PB1 (0x02)
#define EN 0x04  		 	 	//EN -> PB2 (0x04)

#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38

#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80

void LCD_Write4bits(unsigned char data, unsigned char control)
{
	data &= 0xF0;                       //clear lower nibble for control 
	control &= 0x0F;                    //clear upper nibble for data
	GPIO_PORTB_DATA_R = data | control;         //Include RS value (command or data ) with data 
	GPIO_PORTB_DATA_R = data | control | EN;    //pulse EN
	delayUs(0);													//delay for pulsing EN
	GPIO_PORTB_DATA_R = data | control;					//Turn off the pulse EN
	GPIO_PORTB_DATA_R = 0;                      //Clear the Data 
}

void LCD4bits_Data(unsigned char data)
{
	LCD_Write4bits(data & 0xF0 , RS);   //upper nibble first
	LCD_Write4bits(data << 4 , RS);     //then lower nibble
	delayUs(40);												//delay for LCD (MCU is faster than LCD)
}

void LCD_WriteString(char * str)
{  
	volatile int i = 0;          //volatile is important i must be pulled from memory 
	
	while(*(str+i) != '\0')       //until the end of the string
	{
		LCD4bits_Data(*(str+i));    //Write each character of string
		i++;                        //increment for next character
	}
}

void LCD4bits_Cmd(unsigned char command)
{
	LCD_Write4bits(command & 0xF0 , 0);    //upper nibble first
	LCD_Write4bits(command << 4 , 0);			 //then lower nibble
	
	if(command < 4)
		delayMs(2);       //commands 1 and 2 need up to 1.64ms
	else
		delayUs(40);      //all others 40 us
}

void LCD4bits_Init(void)
{

	LCD4bits_Cmd(0x28);          //2 lines  (4-bit data, D4 to D7)
	LCD4bits_Cmd(0x20);					 // 5x7 font size
	LCD4bits_Cmd(0x06);          //Automatic Increment cursor (shift cursor to right)
	LCD4bits_Cmd(0x01);					 //Clear display screen
	LCD4bits_Cmd(0x0F);          //Display on, cursor blinking
}

void LCD_Timer(int minute , int second)
{
int i , j;

for(i = minute; i>=0; i--)
{
for(j = second; j>=0; j--)
{
	if ((GPIO_PORTF_DATA_R&0x10)==0x10)// sw1 is off
	{
		LCD4bits_Data((i/10)+'0');// Send ten's of minutes
 

		LCD4bits_Data((i%10)+'0'); // Send unit's of minutes
 

		LCD4bits_Data(':');


		LCD4bits_Data((j/10)+'0'); // Send ten's of seconds


		LCD4bits_Data((j%10)+'0'); // Send unit's of seconds
		delay(100); //wait 1 sec
		LCD4bits_Cmd(clear_display);
	}
	else if (((GPIO_PORTF_DATA_R&0x10)==0x01)||((GPIO_PORTA_DATA_R&0x08)==0x00))//sw1 on or door is open
				{
					while(1){//true when sw2 off and
		GPIO_PORTF_DATA_R &= 0x11;
		delay(500);
		GPIO_PORTF_DATA_R |=0x1F;
		delay(500);
		if((SW1_Input()==0x01))//sw1 on gives true and end this counter
		{
			i=-1;
			j=-1;			//to end couneter
		}
		else if(SW2_Input()!=0x10&&SW3_Input()!=0x00)
		{
			break;
		}
	} 
				}
		
 
//while(sw3==0){}
}
second = 59; // min become 59sec after 1sec

}
	
}

void dec_cursor(int i){
	int j;
	for(j=0;j<i;j++){
		LCD4bits_Cmd(0x10);
	}
}

void inc_cursor(int i){
	int j;
	for(j=0;j<i;j++){
		LCD4bits_Cmd(0x14);
	}
}









