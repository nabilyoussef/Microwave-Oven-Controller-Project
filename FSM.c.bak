#include <C:\Keil\Labware\tm4c123gh6pm.h>
#define SW1 0x10
#define SW2 0x01
#define SW3 //to be adjusted
//Define keypad header here, can't do this because the location will change on whoever will assemble the whole project
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
			      //if(SW3 == 0){ e.g: on
						//	state = IDLE;
						//}
						break;
			COOKS:
						if(GPIO_PORTF_DATA_R == SW1){
							state = PAUSE;
						}
						if(CookingDone == 1){
							state = IDLE;
						}
						//if(SW3 == 0){ SW3 Pressed
						//state = PAUSE;
						break;
			 DATA_ENTRY:
					  if(keypadIn == 'B' | keypadIn == 'C'){
							if(keypadIn <= 1 || keypadIn >= 9){
							state = DATA_ENTRY;
							}
						}
						if(keypadIn == 'D'){
							//if reload time less than 1 or greater than 30
							state = DATA_ENTRY; //to be adjusted
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
						if(GPIO_PORTF_DATA_R == SW2 | SW3 == High){ //to be adjusted
						state = COOKS;
						}
						if(GPIO_PORTF_DATA_R == SW1){
						state = IDLE;
				    }					 
			}
		}
	}