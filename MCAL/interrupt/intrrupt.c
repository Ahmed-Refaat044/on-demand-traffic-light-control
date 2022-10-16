/*
 * intrrupt.c
 *
 * Created: 9/18/2022 12:41:49 AM
 *  Author: ahmed refaat
 */ 

#include "interrupt.h"
#include "..\..\regesters.h"
void INT0_init(void){
	MCUCR |= (1<<MCUCR_ISC00)|(1<<MCUCR_ISC01); //set sense control as rising edge
	GICR |=(1<<GICR_INT0);    // enable peripheral interrupt INT0
}
void SREG_enable(void)
{
	SREG |= (1<<SREG_I);
}
void INT1_init(void);
void INT2_init(void);