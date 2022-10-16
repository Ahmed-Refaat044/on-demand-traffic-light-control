/*
 * CFile1.c
 *
 * Created: 9/13/2022 7:15:18 PM
 *  Author: ahmed refaat
 */ 
#include "Button.h"

void BUTTON_init(uint8_t buttonpin , uint8_t buttonport)
{
	
	DIO_init(buttonpin , buttonport , IN) ;
}
void BUTTON_read(uint8_t buttonpin , uint8_t buttonport ,uint8_t *value)
{
	
	DIO_read(buttonpin , buttonport ,value);
}
