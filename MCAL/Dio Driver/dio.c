	/*
 * CFile1.c
 *
 * Created: 9/12/2022 4:42:33 PM
 *  Author: Workstation
 */ 
#include "dio.h"
#include <avr/io.h>
#include <util/delay.h>

EN_Dio_error DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction )

{
	switch(portNumber)
	{
		case PORT_A :
		if (direction == IN)
		{
			DDRA &=~(1<<pinNumber);
			return OK ;
		}
		else if (direction == OUT){
			DDRA |=(1<<pinNumber);
			return OK ;
		}
		else{
			return Dio_init_error;      //error
		}
		break;
		case PORT_B :
		if (direction == IN)
		{
			DDRB &=~(1<<pinNumber);
			return OK ;
		}
		else if (direction == OUT){
			DDRB |=(1<<pinNumber);
			return OK ;
		}
		else{
			
			return Dio_init_error;       	//error
		}
		break;
		case PORT_C :
		if (direction == IN)
		{
			DDRC &=~(1<<pinNumber);
			return OK ;
		}
		else if (direction == OUT){
			DDRC |=(1<<pinNumber);
			return OK ;
		}
		else{
				return Dio_init_error; 	//error
		}
		break;
		case PORT_D :
		if (direction == IN)
		{
			DDRD &=~(1<<pinNumber);
			return OK ;
		}
		else if (direction == OUT){
			DDRD |=(1<<pinNumber);
			return OK ;
		}
		else{
				return Dio_init_error;	//error
		}
		break;
	}
	
	
}

EN_Dio_error DIO_toggle(uint8_t pinNumber , uint8_t portNumber )
{
	switch(portNumber){
		
		case PORT_A :
		PORTA^=(1<<pinNumber);
		
		break;
		
		case PORT_B :
		PORTB^=(1<<pinNumber);
	
		break;
		case PORT_C :
		PORTC^=(1<<pinNumber);
		break;
		
		case PORT_D :
		PORTD ^=(1<<pinNumber);
		break;
		default:
		Dio_toggle_error;
		break;
		
     }
}
	EN_Dio_error DIO_write(uint8_t pinNumber , uint8_t portNumber , uint8_t value)
	{
		switch(portNumber)
		{
			case PORT_A :
			if (value == LOW)
			{
				PORTA &=~(1<<pinNumber);
				return OK ;
			}
			else if (value ==HIGH){
				PORTA |=(1<<pinNumber);
				return OK ;
				} else{
			Dio_write_error    ;  	//error
			}
			break;
			case PORT_B :
			if (value == LOW)
			{
				PORTB &=~(1<<pinNumber);
				return OK ;
			}
			else if (value ==HIGH){
				PORTB |=(1<<pinNumber);
				return OK ;
			}
			else{
			Dio_write_error	 ;  //error
			}
			break;
			case PORT_C :
			if (value == LOW)
			{
				PORTC &=~(1<<pinNumber);
				return OK ;
			}
			else if (value ==HIGH){
				PORTC |=(1<<pinNumber);
				return OK ;
			}
			else{
				Dio_write_error  ; //error
			}
			break;
			case PORT_D :
			if (value == LOW)
			{
				PORTD &=~(1<<pinNumber);
				return OK ;
			}
			else if (value ==HIGH){
				PORTD |=(1<<pinNumber);
				return OK ;
			}
			else{
				Dio_write_error  ;//error
			}
			break;
		}
		
		
	}


	EN_Dio_error DIO_read(uint8_t pinNumber , uint8_t portNumber , uint8_t *value)
	{

		switch (portNumber){
			
			case PORT_A :
			
			*value = (PINA & (1<<pinNumber))>>pinNumber ;
			break;
			
			case PORT_B :
			*value = (PINB & (1<<pinNumber))>>pinNumber ;
			break;
			
			case PORT_C:
			*value = (PINC & (1<<pinNumber))>>pinNumber ;
			break;
			
			case  PORT_D:
			*value = (PIND & (1<<pinNumber))>>pinNumber ;
			break;
			default:
			Dio_init_error;
			break;

			

		}
	}
	

	

