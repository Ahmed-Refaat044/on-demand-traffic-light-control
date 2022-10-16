/*
 * app.c
 *
 * Created: 9/19/2022 8:45:41 PM
 *  Author: ahmed refaat
 */ 

#include "app.h"
#include "..\MCAL\interrupt\interrupt.h"

#define COUNTER_MAX 50

 EN_state_t state = CAR_STATE;
 	int counter = 0;



void app_init(void) 
{
	LED_init(5, PORT_D);
LED_init(LED_1_PIN ,LED_1_PORT);   //car red
LED_init(LED_2_PIN ,LED_2_PORT);   //car yellow
LED_init(LED_3_PIN ,LED_3_PORT);	//car green 		
LED_init(LED_4_PIN ,LED_4_PORT);	//pedestrian red
LED_init(LED_5_PIN ,LED_5_PORT);	 //pedestrian yellow
LED_init(LED_6_PIN,LED_6_PORT);	//pedestrian green

BUTTON_init(BUTTON_PIN ,BUTTON_PORT );  //pedestrian button

SREG_enable();	// enable global interrupt

set_timer();    //set the timer
INT0_init();	//interrupt 0

}
void app_start(void)
{
	
	
	
	switch(state)
	{
		case CAR_STATE:             //car's green on
		                             // ped's red on
		if(counter == COUNTER_MAX)
		{
				LED_OFF(LED_3_PIN ,LED_3_PORT);
				LED_OFF(LED_4_PIN ,LED_4_PORT);
			state = CAR_Y_STATE;
			counter=0 ;
		}
		else
		{
			
			
			LED_ON(LED_3_PIN,LED_3_PORT);
			LED_ON(LED_4_PIN , LED_4_PORT);
			LED_OFF(LED_1_PIN ,LED_1_PORT);
			LED_OFF(LED_2_PIN ,LED_2_PORT);
			LED_OFF(LED_5_PIN ,LED_5_PORT);
			LED_OFF(LED_6_PIN ,LED_6_PORT);

			counter++ ;
		}	break;
		
		
		case CAR_Y_STATE:                          //car's yellow on
													// ped's red on
		
		if(counter == COUNTER_MAX)
		{
				LED_OFF(LED_2_PIN ,LED_2_PORT);
				
			state = MAN_STATE;
			counter =0 ;
			
		}
		else
		{
			if (!(counter %10)){
			LED_toggle(LED_2_PIN, LED_2_PORT);
			LED_ON(LED_4_PIN ,LED_4_PORT);
			
			LED_OFF(LED_1_PIN ,LED_1_PORT);
			LED_OFF(LED_3_PIN ,LED_3_PORT);
			LED_OFF(LED_6_PIN ,LED_6_PORT);}
			counter++;
		
		
				//toggle
		}break;
	
		
		case MAN_STATE :                         //car's red on
												// ped's green on
		if (counter== COUNTER_MAX )
		{
				LED_OFF(LED_6_PIN ,LED_6_PORT);
				LED_OFF(LED_1_PIN ,LED_1_PORT);
			state = MAN_Y_STATE ;
			counter=0 ;
		}
		
		else 
		{
			LED_ON(LED_6_PIN ,LED_6_PORT);
			LED_ON(LED_1_PIN ,LED_1_PORT);
			LED_OFF(LED_3_PIN ,LED_3_PORT);
			LED_OFF(LED_2_PIN ,LED_2_PORT);
			LED_OFF(LED_4_PIN ,LED_4_PORT);
			LED_OFF(LED_5_PIN ,LED_5_PORT);
			counter++ ;
		}
		break;
			case MAN_Y_STATE:                       //car's yellow on
													// ped's red on
			if(counter == COUNTER_MAX)
			{
				state = CAR_STATE;
				LED_OFF(LED_2_PIN ,LED_2_PORT);
				LED_OFF(LED_5_PIN ,LED_5_PORT);	
				counter=0 ;
			}
			else
			{
			if (!(counter %10))
			{
			
				LED_toggle(LED_5_PIN ,LED_5_PORT);
				LED_ON(LED_1_PIN ,LED_1_PORT);
			
				LED_OFF(LED_3_PIN ,LED_3_PORT);
				LED_OFF(LED_4_PIN ,LED_4_PORT);
				LED_OFF(LED_6_PIN ,LED_6_PORT);
			
			}
				counter++ ;
				//toggle}
		}
			break;
			default : 
			break;
	}
	//wait 0.1 sec
	start_timer(390);		
	stop_timer();
	
}






void __vector_1(void) __attribute__((signal));     // ISR Function

void __vector_1(void)
{/*
	DIO_read(LED_3_PIN,LED_3_PORT,&PIN_value);
	if (PIN_value == HIGH)
	{
		state= CAR_Y_STATE;
		
	}
	else{
		state= MAN_STATE;
	}*/

	switch(state)
	{
	case CAR_STATE :
		
		LED_OFF(LED_3_PIN ,LED_3_PORT);
		LED_OFF(LED_4_PIN , LED_4_PORT);
		state= CAR_Y_STATE;
		counter=0 ;
		break;
	
	case  CAR_Y_STATE :
		break;
	
	case MAN_Y_STATE:
	
		state=MAN_STATE;
	
	
	 break;

	case MAN_STATE :
	break;
	default : 
	break;
	}
	}
	
