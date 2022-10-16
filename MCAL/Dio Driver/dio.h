/*
 * dio.h
 *
 * Created: 9/12/2022 4:43:01 PM
 *  Author: ahmed refaat
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "..\..\regesters.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'





//direction
#define IN 0
#define OUT 1

// value
#define LOW 0
#define HIGH 1



//ERROR HANDLING
typedef enum EN_Dio_error{
	OK=0,
	Dio_init_error,
	Dio_read_error,
	Dio_write_error,
	Dio_toggle_error,
}EN_Dio_error;


EN_Dio_error DIO_init(uint8_t pinNumber , uint8_t portNumber , uint8_t direction );
EN_Dio_error DIO_toggle(uint8_t PinNumber , uint8_t portNumber );
EN_Dio_error DIO_write(uint8_t PinNumber , uint8_t portNumber , uint8_t value);
EN_Dio_error DIO_read(uint8_t PinNumber , uint8_t portNumber , uint8_t *value);



#endif /* DIO_H_ */