/*
 * interrupt.h
 *
 * Created: 9/18/2022 12:42:20 AM
 *  Author: Workstation
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "..\..\regesters.h"


/* define GICR bit */
#define  GICR_INT0   6
#define  GICR_INT1   7
#define  GICR_INT2   5

/*define MCUCR BIT */
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

/*define MCUCSR BIT */
#define MCUCSR_INT2  6

//define SERG bit
#define SREG_I       7


void INT0_init(void);
void INT1_init(void);
void INT2_init(void);
void SREG_enable(void);


#endif /* INTERRUPT_H_ */