void PopCorn(void)
{	
	int i;
	LCD4bits_Cmd(clear_display);
	delay(500);
	LCD_WriteString("Popcorn");
	delay(2000);
	LCD4bits_Cmd(clear_display);
	i=pause();
	if(i==2)
	{
		LCD_Timer(1,0);
	}
}
