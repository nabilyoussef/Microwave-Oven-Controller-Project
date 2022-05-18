//---------counter_NABIL---------//
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
			else if (((GPIO_PORTF_DATA_R&0x10)==0x00)| ((GPIO_PORTA_DATA_R&0x04)==0x00))//sw1 on or door is open
				{
					delay_ms(300);
					while((GPIO_PORTF_DATA_R&0x01)==0x01 & (GPIO_PORTA_DATA_R & 0X04)==0x00 ){//true when sw2 off and
						GPIO_PORTF_DATA_R &= 0x11;//off leds
						delay_ms(300);
						GPIO_PORTF_DATA_R |=0x1F;//on leds
						delay_ms(300);
						if(((GPIO_PORTF_DATA_R&0x01)==0x01))//sw1 on gives true and end this counter
						{
							delay_ms(300);
							i=min;
							j=59; //to end couneter
							break;
						}
	} 
				}

		}
		sec=59;	
	}
}
//******************************************//
