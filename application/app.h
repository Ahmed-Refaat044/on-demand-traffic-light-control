/*
 * app.h
 *
 * Created: 9/19/2022 8:45:58 PM
 *  Author: ahmed refaat
 */ 
#include "..\MCAL\Timer\Timer.h"
#include <avr\interrupt.h>
#include <avr\io.h>
#include "..\MCAL\interrupt\interrupt.h"
#include "..\MCAL\Dio Driver\dio.h"
#include "..\LED Driver\Led.h"
#include "..\Button Driver\Button.h"
#include "..\regesters.h"
#ifndef APP_H_
#define APP_H_


typedef enum {
	CAR_STATE,
	CAR_Y_STATE,
	MAN_STATE,
	MAN_Y_STATE
} EN_state_t;

void app_init(void);
void app_start(void) ;

#endif /* APP_H_ */