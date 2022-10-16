/*
 * Button.h
 *
 * Created: 9/13/2022 7:16:01 PM
 *  Author: ahmed refaat
 */ 
 #include "..\MCAL\Dio Driver\Dio.h"

#ifndef BUTTON_H_
#define BUTTON_H_


#define BUTTON_PORT  PORT_D
#define BUTTON_PIN   2

void BUTTON_init(uint8_t pinNumber , uint8_t portNumber);
void BUTTON_read(uint8_t pinNumber , uint8_t portNumber ,uint8_t *value);


#endif /* BUTTON_H_ */