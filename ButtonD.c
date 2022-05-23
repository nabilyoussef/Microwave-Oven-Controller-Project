void CookTime(void){
	unsigned char KeypadInput, KeypadInput1, KeypadInput2, KeypadInput3;
	int minutes = 0, seconds = 0, x;
	int i;
	restart:LCD4bits_Cmd(clear_display);
	delay(500);
	LCD_WriteString("Cooking Time?");
	delay(500);
	LCD4bits_Cmd(clear_display);
	delay(500);
	LCD_WriteString("00:00");
	
	//
	KeypadInput = keypad_scan();//2
	x = KeypadInput - '0';
	if (x >= 0 && x <= 3){
			dec_cursor(1);
	LCD4bits_Data(KeypadInput);
	delay(500);
	minutes += x*10;	
	//
	KeypadInput1 = keypad_scan();//0 to9
	x = KeypadInput1 - '0';
	if (minutes == 30)
		{
		if (x == 0){
			delay(500);
			dec_cursor(2);
			LCD4bits_Data(KeypadInput);
			LCD4bits_Data(KeypadInput1);
			minutes += x;
		}
	else {
			LCD4bits_Cmd(clear_display);
			LCD_WriteString("ERR");
			delay(2000); 
			goto restart;
			} 			
		}

		else if (minutes == 0)
		{
			if (x >= 0  && x <= 9){
				delay(500);
				dec_cursor(2);
				LCD4bits_Data(KeypadInput);
				LCD4bits_Data(KeypadInput1);
				minutes += x;
		}
			else {
						LCD4bits_Cmd(clear_display);
						LCD_WriteString("ERR");
						delay(2000); 
						goto restart;
			}
	}	
	else {
		if (x >= 0 && x <= 9)
		{
			delay(500);
			dec_cursor(2);
			LCD4bits_Data(KeypadInput);
			LCD4bits_Data(KeypadInput1);
			minutes += x;
		}
		
				}
		KeypadInput2 = keypad_scan();
		x = KeypadInput2 - '0';
		if (minutes == 30) {
			if (x == 0) {
				delay(500);
				dec_cursor(4);
				LCD4bits_Data(KeypadInput);
				inc_cursor(1);
				LCD4bits_Data(KeypadInput1);
				LCD4bits_Data(KeypadInput2);
				seconds += x*10;
			}
			else {
						 LCD4bits_Cmd(clear_display);
						 LCD_WriteString("ERR");
						 delay(2000); 
				goto restart;
			}
		}
													
else {
if	(x >= 0 && x <= 5)
		{
	delay(500);
	dec_cursor(4);
	LCD4bits_Data(KeypadInput);
	inc_cursor(1);			
	LCD4bits_Data(KeypadInput1);
	LCD4bits_Data(KeypadInput2);
	seconds += x*10;
		}
	}
		
		KeypadInput3 = keypad_scan();
		x = KeypadInput3 - '0';
		if (minutes == 30) {
			if (x == 0) {
				delay(500);
				dec_cursor(5);
				LCD4bits_Data(KeypadInput);
				LCD4bits_Data(KeypadInput1);
				inc_cursor(1);
				LCD4bits_Data(KeypadInput2);
				LCD4bits_Data(KeypadInput3);
				seconds += x;
			}
			else {
						LCD4bits_Cmd(clear_display);
						LCD_WriteString("ERR");
						delay(2000); 
				goto restart;
			}
		}

	  else { 
			if (x >= 0 && x <= 9)
		{
		  delay(500);
		  dec_cursor(5);
		  LCD4bits_Data(KeypadInput);
		  LCD4bits_Data(KeypadInput1);
			inc_cursor(1);
		  LCD4bits_Data(KeypadInput2);
		  LCD4bits_Data(KeypadInput3);
		  seconds += x;
		}
	}
}
	else {
			LCD4bits_Cmd(clear_display);
		  LCD_WriteString("ERR");
			delay(2000); 
		goto restart;
}
		
		delay(500);
		LCD4bits_Cmd(clear_display);
		i=pause();
		if(i==2)
		{
			LCD_Timer(minutes, seconds);//LCD DISPLAY TIME
		}
		if(i==1)
		{
			minutes=0;
			seconds=0;
			goto restart;
		}
			
}	
