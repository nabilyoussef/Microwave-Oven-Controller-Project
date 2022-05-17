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