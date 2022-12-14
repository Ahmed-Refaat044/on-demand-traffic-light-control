/*
 * regesters.h
 *
 * Created: 9/12/2022 4:40:42 PM
 *  Author: ahmed refaat
 */ 


#ifndef REGESTERS_H_
#define REGESTERS_H_


typedef unsigned char uint8_t ;

#define PORTA *((volatile uint8_t*)0x3B)

#define DDRA *((volatile uint8_t*)0x3A)

#define PINA *((volatile uint8_t*)0x39)



#define PORTB *((volatile uint8_t*)0x38)

#define DDRB *((volatile uint8_t*)0x37)

#define PINB *((volatile uint8_t*)0x36)



#define PORTC *((volatile uint8_t*)0x35)

#define DDRC *((volatile uint8_t*)0x34)

#define PINC *((volatile uint8_t*)0x33)



#define PORTD *((volatile uint8_t*)0x32)

#define DDRD *((volatile uint8_t*)0x31)

#define PIND *((volatile uint8_t*)0x30)

// timer
#define  TCCR0 *((volatile uint8_t*)0x53)
#define  TCNT0  *((volatile uint8_t*)0x52)
#define  TIFR  *((volatile uint8_t*)0x58)


/*interrupt register*/
#define  GICR       *((volatile uint8_t*)0x5B)
#define  GIFR      *((volatile uint8_t*)0x5A)
#define  MCUCR     *((volatile uint8_t*)0x55)
#define  MCUCSR    *((volatile uint8_t*)0x54)


/*define Global interrupt*/
#define  SREG *((volatile uint8_t*)0x5F)





#endif /* REGESTERS_H_ */