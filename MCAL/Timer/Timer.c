/*
 * Timer.c
 *
 * Created: 9/18/2022 12:20:05 AM
 *  Author: ahmed refaat
 */ 
#include "Timer.h"

void set_timer(){
	  TCCR0=0x00; // normal mode
	  TCNT0=0x00; // set timer initial value
}
void start_timer(unsigned int overFlowsNumber){
	unsigned int overFlowCounter=0;
	TCCR0 |=(1<<0);

	while(overFlowCounter<overFlowsNumber){
		while((TIFR & (1<<0))==0);
		TIFR |=(1<<0);
		overFlowCounter++;
	
	}
	overFlowCounter=0;
}
void stop_timer(){
	
	TCCR0 =0x00;
}