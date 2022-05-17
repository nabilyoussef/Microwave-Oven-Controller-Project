#include <C:\Keil\Labware\tm4c123gh6pm.h>
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
	int pause = 0;
	int cooking_time_in_minutes;
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
						if((GPIO_PORTA_DATA_R & 0X08) == 0X00){
							state = IDLE;
						}
						break;
			COOKS:
						if(GPIO_PORTF_DATA_R == SW1){
							state = PAUSE;
						}
						if(CookingDone == 1){
							state = IDLE;
						}
						if((GPIO_PORTA_DATA_R & 0X08) == 0X00){
						state = PAUSE;
						break;
						}
			 DATA_ENTRY:
					  if(keypadIn == 'B' | keypadIn == 'C'){
							if(keypadIn <= 1 || keypadIn >= 9){
							state = DATA_ENTRY;
							}
						}
						if(keypadIn == 'D'){
							if(cooking_time_in_minutes<=1 || cooking_time_in_minutes >= 30){
							state = DATA_ENTRY;}
							else{
								state = COOKS;
							}
						}
						if(keypadIn == 'B' && GPIO_PORTF_DATA_R == SW2){
						state = COOKS;
						}
						if(keypadIn == 'C' && GPIO_PORTF_DATA_R == SW2){
						state = COOKS;
						}
						if(keypadIn == 'D' & GPIO_PORTF_DATA_R == SW2){
						state = COOKS;
						}
						break;
				PAUSE:
						if(GPIO_PORTF_DATA_R == SW2 | &&  (GPIO_PORTA_DATA_R&0X08) ==  0X08){
						state = COOKS;
						}
						if(GPIO_PORTF_DATA_R == SW1){
						state = IDLE;
				    }					 
			}
		}
	}