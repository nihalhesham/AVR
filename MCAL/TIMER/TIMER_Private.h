/*
 * TIMER_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define NO_PRESCALER 0
#define PRESCALER_8  1
#define PRESCALER_64 2
#define PRESCALER_256 3

#define NORMAL_MODE 0
#define PWM_MODE    1
#define CTC_MODE    2
#define FAST_PWM    3

#define NORMAL  0
#define CLEAR   1
#define SET     2


#define TCCR0  *((volatile u8 *)0x53)
#define TCCR0_FOC0  7
#define TCCR0_WGW01 3
#define TCCR0_WGW00 6
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_CS00  0
#define TCCR0_CS01  1
#define TCCR0_CS02  2

#define TCNT0	*((volatile u8*) 0x52)

#define OCR	*((volatile u8*) 0x5C)


#define TIMSK *((volatile u8 *)0x59)
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0

#define TIFR *((volatile u8 *)0x58)
#define TIFR_OCF0 1
#define TIFR_TOC0 0





#endif /* TIMER_PRIVATE_H_ */
