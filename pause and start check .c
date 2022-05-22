int check_and_delay(int t) 
{
    int i;
    int indication = 0;
    for(i = 0; i<t; i++)
    {

        Systick_Wait_1ms();

        if((SW1_Input()) == 0) // pause
        {
            indication = 1;
        }

        if((SW2_Input()) == 0) // start
        {
            indication = 2;
        }
        if(SW3_Input() == 0) // PA3 (Door is open) 
        {
            indication = 3;
        }

    }
    return indication;
}


int pause(void) // to take action for start or  clear
	{	
		while(1)
			{	
				int m = LEDS_blink();
				int l = check_and_delay(100);
				if(l==1||l==2)return l;
			}	
}