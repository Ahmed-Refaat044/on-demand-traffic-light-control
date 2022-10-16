/*
 * Led.h
 *
 * Created: 9/12/2022 5:10:44 PM
 *  Author: Workstation
 */ 


#ifndef LED_H_
#define LED_H_
#include "..\regesters.h"
#include "..\MCAL\Dio Driver\Dio.h"


#define LED_1_PORT PORT_A
#define LED_2_PORT PORT_A
#define LED_3_PORT PORT_A
#define LED_1_PIN  PINA0
#define LED_2_PIN  PINA1
#define LED_3_PIN  PINA2


#define LED_4_PORT PORT_C
#define LED_5_PORT PORT_C
#define LED_6_PORT PORT_C
#define LED_4_PIN  PINC0
#define LED_5_PIN  PINC1
#define LED_6_PIN  PINC2



void LED_init(uint8_t ledpin ,uint8_t ledport);
void LED_ON (uint8_t ledpin ,uint8_t ledport);
void LED_OFF (uint8_t ledpin ,uint8_t ledport);
void LED_toggle(uint8_t ledpin ,uint8_t ledport);
void LED_blink(uint8_t ledpin, uint8_t ledport);
void TWO_LED_blink(uint8_t ledpin_1, uint8_t ledport_1,uint8_t ledpin_2, uint8_t ledport_2);

#endif /* LED_H_ */