#include "keyboard.h"
#include "led.h"
#define LOOP_FACTOR 5455

void Delay(unsigned int iNumOfMiliSec){
	
	int iLoopCounter;
	
	for(iLoopCounter=0; iLoopCounter<LOOP_FACTOR*iNumOfMiliSec; iLoopCounter++){}
}

/*// do main 6.1
enum LedState{LED_LEFT, LED_RIGHT}; 
enum LedState eLedState = LED_LEFT;
// */

/* // do main 6.2
enum LedState{STATE0, STATE1, STATE2, STATE3, STATE4, STATE5}; 
enum LedState eLedState = STATE0;
// */

/* // do main 6.3
enum LedState{STATE_LEFT, STATE_RIGHT};
enum LedState eLedState = STATE_LEFT;
unsigned char ucShiftCounter=0;
// */

/* /// do main 6.4
enum LedState{STATE_STOP, STATE_RIGHT};
enum LedState eLedState = STATE_STOP;
unsigned char ucShiftCounter=0;
// */

/* // do main 6.5
enum LedState{STATE_STOP, STATE_RIGHT};
enum LedState eLedState = STATE_RIGHT;
// */

 // do main 6.6
enum LedState{STATE_STOP, STATE_RIGHT, STATE_LEFT};
enum LedState eLedState = STATE_STOP;
// */

/* //main 6.1 /////////////////////////////////////////
int main(){
	Ledinit();
	while(1){
		switch(eLedState){       
				case LED_LEFT:             
					eLedState = LED_RIGHT; 
					LedStepRight();             
					break;       
				case LED_RIGHT:              
					eLedState = LED_LEFT; 
					LedStepLeft();             
				break;   
		}
		Delay(250); 
	} 
}
*/ //

/* // main 6.2 /////////////////////////////////////////
 int main(){
	LedInit();
	while(1){ 
		switch(eLedState){
				case STATE0:
					eLedState = STATE1;
					LedStepLeft();
					break;
					
					case STATE1:
					eLedState = STATE2;
					LedStepLeft();
					break;
					
					case STATE2:
					eLedState = STATE3;
					LedStepLeft();
					break;
								
					case STATE3:
					eLedState = STATE4;
					LedStepRight();
					break;
								
					case STATE4:
					eLedState = STATE5;
					LedStepRight();
					break;
								
					case STATE5:
					eLedState = STATE0;
					LedStepRight();
					break;
		}
	 Delay(250);
	}
}
// */

/* // main 6.3 /////////////////////////////////////////
 int main() {
	LedInit();
	
	while(1){
		
		switch(eLedState){
				case STATE_LEFT:
					if(ucShiftCounter==3){
						eLedState = STATE_RIGHT;
						ucShiftCounter=0;
					}else{
					LedStepLeft();
					ucShiftCounter++;
					}
				break;
					
				case STATE_RIGHT:
					if(ucShiftCounter==3){
						eLedState = STATE_LEFT;
						ucShiftCounter=0;
					}else{
					LedStepRight();
					ucShiftCounter++;
				}
				break;
		}
	Delay(250);
	}
}
// */

/* // main 6.4 /////////////////////////////////////////
 int main() {
	LedInit();
	
	while(1){
		
		switch(eLedState){
			case STATE_RIGHT:
					if(ucShiftCounter == 3){
						eLedState = STATE_STOP;
						ucShiftCounter=0;
					}
					else{
						LedStepRight();
						ucShiftCounter++;
						eLedState = STATE_RIGHT;
					}
					break;
			case STATE_STOP:
					if(eKeyboardRead() == BUTTON_1){
							eLedState = STATE_RIGHT;
					}
					else{
						eLedState = STATE_STOP;
					}
					break;
		}
	Delay(250);
	}
}
// */

/* // main 6.5 /////////////////////////////////////////
 int main() {
	LedInit();
	
	while(1){
		
		switch(eLedState){
			case STATE_RIGHT:
					LedStepRight();
					if(eKeyboardRead() == BUTTON_1){
						eLedState = STATE_STOP;
					}
					else{
						eLedState = STATE_RIGHT;
					}
					break;
			case STATE_STOP:
					if(eKeyboardRead() == BUTTON_2){
						eLedState = STATE_RIGHT;
					}
					else{
						eLedState = STATE_STOP;
					}
					break;
		}
	Delay(250);
	}
}
// */

/* // main 6.6 /////////////////////////////////////////
 int main() {
	LedInit();
	
	while(1){
		switch(eLedState){
			case STATE_STOP:
					if(eKeyboardRead() == BUTTON_1){
						eLedState = STATE_LEFT;
					}
					else if(eKeyboardRead() == BUTTON_3){
						eLedState = STATE_RIGHT;
					}
					else{
						eLedState = STATE_STOP;
					}
					break;
			case STATE_RIGHT:
					LedStepRight();
					if(eKeyboardRead() == BUTTON_2){
						eLedState = STATE_STOP;
					}
					else{
						eLedState = STATE_RIGHT;
					}
					break;
			case STATE_LEFT:
					LedStepLeft();
					if(eKeyboardRead() == BUTTON_2){
						eLedState = STATE_STOP;
					}
					else{
						eLedState = STATE_LEFT;
					}
					break;
		}
	Delay(100);
	}
}
// */

 // main 6.6 /////////////////////////////////////////
 int main() {
	LedInit();
	KeyboardInit();
	 
	while(1){
		switch(eLedState){
			case STATE_STOP:
					if(eKeyboardRead() == BUTTON_1){
						eLedState = STATE_LEFT;
					}
					else if(eKeyboardRead() == BUTTON_3){
						eLedState = STATE_RIGHT;
					}
					else{
						eLedState = STATE_STOP;
					}
					break;
			case STATE_RIGHT:
					LedStepRight();
					if(eKeyboardRead() == BUTTON_2){
						eLedState = STATE_STOP;
					}
					else{
						eLedState = STATE_RIGHT;
					}
					break;
			case STATE_LEFT:
					LedStepLeft();
					if(eKeyboardRead() == BUTTON_2){
						eLedState = STATE_STOP;
					}
					else{
						eLedState = STATE_LEFT;
					}
					break;
		}
	Delay(100);
	}
}
// */

