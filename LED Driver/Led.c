/*
 * Led_c.c
 *
 * Created: 9/12/2022 5:10:24 PM
 *  Author: Workstation
 */ 
 #include "Led.h"
 #include "..\MCAL\Timer\Timer.h"
 
 
 void LED_init(uint8_t ledpin ,uint8_t ledport)
 {
	 DIO_init(ledpin , ledport , OUT);
	 
 }
 void LED_ON (uint8_t ledpin ,uint8_t ledport)
 {
	 
	 DIO_write(ledpin , ledport , HIGH);
 }
 void LED_OFF (uint8_t ledpin ,uint8_t ledport)
 {
	 
	 DIO_write(ledpin , ledport , LOW) ;
 }
 void LED_toggle(uint8_t ledpin ,uint8_t ledport)
 {
	 DIO_toggle(ledpin , ledport);
 }
 