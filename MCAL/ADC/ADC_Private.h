/*
 * ADC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define PRSCALLER_2    0b001
#define PRSCALLER_4    0b010
#define PRSCALLER_8    0b011
#define PRSCALLER_16   0b100
#define PRSCALLER_32   0b101
#define PRSCALLER_64   0b110
#define PRSCALLER_128  0b111



#define AREF_InternalVrefturnedOff    0b00
#define AVCC                          0b01
#define INTERNAL_2_5V                 0b11


#define RIGHT_DATA   0
#define LEFT_DATA    1

 typedef struct
{
	u8 MUX : 5 ;
	u8 ADLAR :1 ;
	u8 REFS : 2;

} ADMUX;

#define ADMUX_REG	((volatile ADMUX*) 0x27)


typedef struct {
	u8 ADPS : 3;
	u8 ADIE : 1;
	u8 ADIF : 1;
	u8 ADATE : 1;
	u8 ADSC : 1;
	u8 ADEN : 1;
}ADCSRA;

#define ADCSRA_REG ((volatile ADCSRA*) 0x26)


#define ADCH *((volatile u8*)0x025)
#define ADCL *((volatile u8*)0x24)

#define ADC_DATA *((volatile u16*)0x024)




#endif /* ADC_PRIVATE_H_ */
