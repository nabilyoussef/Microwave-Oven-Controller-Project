void GPIOF_Handler(void){
	if(GPIO_PORTF_MIS_R&0x10)//PF4 sw1
 	{while(x==0)       // x is a flag
 	{
 		x=1;
 		while(1){
		GPIO_PORTF_DATA_R &= ~0XE;
		counter(1);
		GPIO_PORTF_DATA_R |= 0XE;
		counter(1);
		 	}
		 }
	else if(x==1){
		LCD_Cmd(clear_display);
		counter(0);
		x=0;     
		GPIO_PORTF_ICR_R|=0x11;
	}
	}	// clear interrupt flag
	else if(GPIO_PORTF_MIS_R&0x01)//PF0 sw 2
	{
		x=0;
		GPIO_PORTF_ICR_R|=0x11;
	}
 }
