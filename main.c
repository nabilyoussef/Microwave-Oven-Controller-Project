//--------project--------//
#include "libraries\tm4c123gh6pm.h"
#include "libraries\keypad.h"
#include "libraries\lcd.h"
#include "libraries\ports.h"
//--------prototypes--------//
void SystemInit();
void SW_Init();
void PopCorn();
void Beef();
void Chicken();
void CookTime();
void SystemInit();
unsigned char SW1_Input(void);
//--------main--------//
int main()
{
	mainScreen:
	// Init section
	SystemInit();
	LCD_init();
	keypad_Init();
	SW3Init ();
	//buzzer
	while(1){
		keypadIn = keypad_getkey();
		LCD_Write_Char(keypadIn);
		delay
		if (keypadIn == 'A')
		{
			PopCorn();
			LCD_String("Task is Completed");
			//delay 2 seconds 
			LCD_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'B')
		{
			Beef();
			LCD_String("Task is Completed");
			//delay 2 seconds 
			LCD_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'C')
		{
			Chicken();
			LCD_String("Task is Completed");
			//delay 2 seconds 
			LCD_Cmd(clear_display);
			//buzzer and blink function
		}
		else if (keypadIn == 'D')
		{
			CookTime();
			LCD_String("Task is Completed");
			//delay 2 seconds 
			LCD_Cmd(clear_display);
			//buzzer and blink function
		}
	}


}

//--------LedInit--------//
void SystemInit()
{
	SYSCTL_RCGCGPIO_R |= 0X20;
	while((SYSCTL_PRGPIO_R&0X20)==0);
	GPIO_PORTF_LOCK_R=0X4C4F434B;
	GPIO_PORTF_CR_R |=0X0E;
	GPIO_PORTF_AMSEL_R &= ~0X1F;
	GPIO_PORTF_AFSEL_R &= ~0X1F;
	GPIO_PORTF_PCTL_R  &= ~0X000FFFFF;
	GPIO_PORTF_DIR_R   |= 0XE; 
	GPIO_PORTF_DEN_R   |= 0XE;
	GPIO_PORTF_DATA_R  |= 0XE;
}
//--------SW 1&2 Init--------//
void SW_Init(){
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x11;
GPIO_PORTF_AMSEL_R &= ~0x11;
GPIO_PORTF_PCTL_R &= ~0x000F000F;
GPIO_PORTF_AFSEL_R &= ~0x11;
GPIO_PORTF_DIR_R &= ~0x11;
GPIO_PORTF_PUR_R |= 0x11;
GPIO_PORTF_DATA_R &= ~0x0E;
}
//--------Sw1Input--------//
unsigned char SW1_Input(void){
return GPIO_PORTF_DATA_R & 0x10;
}
//--------Sw2Input--------//
unsigned char SW2_Input(void){
return GPIO_PORTF_DATA_R & 0x01;
}
//--------PopCornA--------//
void PopCorn()
{
	unsigned long A;
	//delay
	LCD_Cmd(clear_display);
	LCD_Cmd(Fline);
	LCD_String("Popcorn");
	LCD_Cmd(Sline);
	LCD_String("press Sw2 to start");
	x=SW2_Input();
	if(x==0x01){
		counter(0,60);
	}
}
//--------BeefB--------//
void Beef(){
    int weight, time, min, sec;
    //delay
    LCD_Cmd(clear_display);
    LCD_String("Beef weight?");
    keypadIn=keypad_getkey();// from 1 to 9
    weight=(uint32_t)keypadIn;
       if (weight<=9&&weight >0){
        	LCD_Write_Char(keypadIn); //output the input weight to LCD
        	counter(1);
        	time =  (0.5*weight)*60;
        	min = (int)time/60;
        	sec =  time % 60;
        	x=SW2_Input();
			if(x==0x01){
				LCD_Timer(min, sec);//LCD DISPLAY TIME
			}
       }
        else
        { 
        	LCD_WriteString("ERR");
        	delay(1);//LCD DISPLAY TIME
        }
    }
//--------ChickenC--------//
void Chicken(){
    int weight, time, min, sec;
    //delay
    LCD_Cmd(clear_display);
    LCD_String("Chicken weight?");
    keypadIn=keypad_getkey();// from 1 to 9
    weight=(uint32_t)keypadIn;
       if (weight<=9&&weight >0){
        	LCD_Write_Char(keypadIn); //output the input weight to LCD
        	counter(1);
        	time =  (0.2*weight)*60;
        	min = (int)time/60;
        	sec =  time % 60;
        	x=SW2_Input();
			if(x==0x01){
				LCD_Timer(min, sec);//LCD DISPLAY TIME
			}
       }
        else
        { 
        	LCD_WriteString("ERR");
        	delay(1);//LCD DISPLAY TIME
        }
    }
//--------CookTimeD--------//

void CookTime(){
	unsigned char KeypadInput, KeypadInput1, KeypadInput2, KeypadInput3;
	int save, save1, save2, save3;
	int minutes, seconds, x;
	LCD_WriteString("Cooking Time?");
	delayMs(1000);
	LCD_WriteString("00:00");
	delayMs(500);
	dec_cursor(1);
	\\
	KeypadInput = keypad_scan();//2
	x = KeypadInput - '0';
	if (x >= 0 && x <= 3){
	LCD4bits_Data(KeypadInput);
	delayMs(500);
	save = x;
	}	
	\\
	KeypadInput1 = keypad_scan();//0 to9
	x = KeypadInput1 - '0';
	if (save == 3){
		if (x == 0){
			delayMs(500);
			dec_cursor(2);
			LCD4bits_Data(KeypadInput);
			LCD4bits_Data(KeypadInput1);
			save1 = x;}	
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
//--------counter_NABIL--------//
void counter(uint32_t min, uint32_t sec )//13:45
{
	unsigned long i, j;// i for min , j for sec
	char a, b;			// to print lcd
	for (i = 0; i <min ; i++) 
	{
		for(j=0;j<sec;j++)
		{
			if (GPIO_PORTF_DATA_R&0x10==0x10)// sw1 is off 
				{	
					SysTick_Wait(80000000);// one sec on 80Mhz
					a=min-i;
					a=(char)a;
					b=sec-j;
					b=(char)b;
					LCD_Cmd(clear_display);
					LCD_Write_Char(a);
					LCD_Write_Char(':'); 
					LCD_Write_Char(b);
				}	
			else if (((GPIO_PORTF_DATA_R&0x10)==0x00)| ((GPIO_PORTA_DATA_R&0x40)==0x00))//sw1 on or door is open
				{
					Pause(); 
				}

		}
		sec=59;	
	}
}
//******************************************//
void Pause()
{
	while(GPIO_PORTF_DATA_R&0x01==0x01 & GPIO_PORTA_DATA_R & 0X40==0x00 ){//true when sw2 off and
		GPIO_PORTF_DATA_R &= 0x11;
		delay_ms(500);
		GPIO_PORTF_DATA_R |=0x1F;
		delay_ms(500);
		if(((GPIO_PORTF_DATA_R&0x01)==0x01))//sw1 on gives true and end this counter
		{
			goto mainScreen; //to end couneter
		}
	}
}
	
	
	
