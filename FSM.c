#include <C:\Keil\Labware\tm4c123gh6pm.h>
#define SW1 0x10
#define SW2 0x01
#define SW3 0x0111
typedef enum
{
	IDLE,
	COOKS,
	DATA_ENTRY, //for weight & cooking time
	PAUSE,
} state;


int CookingDone; //Set when cooking is done 

void MicrowaveStateMachine(){
	char keypadIn = keypad_scan();
	int state = IDLE; //initial state
	int minutes_reload;
	while(1){
		switch(state){
			IDLE:
						if(keypadIn == 'A'){
							(state = COOKS);
						}
						if(keypadIn == 'B'){
							state = DATA_ENTRY;
						}
						if(keypadIn == 'C'){
							state = DATA_ENTRY;
						}
						if(keypadIn == 'D'){
							state = DATA_ENTRY;
						}
			            if((GPIO_PORTB_DATA_R & 0X1111) == SW3){ e.g: on
							state = IDLE;
						}
						break;
			COOKS:
						if((GPIO_PORTF_DATA_R &0X11) == SW1){
							state = PAUSE;
						}
						if(CookingDone == 1){
							state = IDLE;
						}
						if((GPIO_PORTB_DATA_R & 0X1111) == SW3){ e.g: on
							state = PAUSE;
						}
						break;
			 DATA_ENTRY:
					  if(keypadIn == 'B' | keypadIn == 'C'){
						    keypadIn = (int)keypadIn - '0';
							if((int)keypadIn <= 1 || (int)keypadIn >= 9){
							state = DATA_ENTRY;
							}
						}
						if(keypadIn == 'D'){
							if(minutes_reload >= 30 && minutes_reload <=1)
							state = DATA_ENTRY; 
						else
								state = COOKS;
						}
						if(keypadIn == 'B' && (GPIO_PORTF_DATA_R0x11) == SW2){
						state = COOKS;
						}
						if(keypadIn == 'C' && (GPIO_PORTF_DATA_R&0x11) == SW2){
						state = COOKS;
						}
						if(keypadIn == 'D' && (GPIO_PORTF_DATA_R&0x11) == SW2){
						state = COOKS;
						}
						break;
				PAUSE:
						if((GPIO_PORTF_DATA_R&0X11) == SW2 || (GPIO_PORTB_DATA_R&0X1111)== 0X1111){
						state = COOKS;
						}
						if((GPIO_PORTF_DATA_R&0X11) == SW1){
						state = IDLE;
				    }					 
			}
		}
	}