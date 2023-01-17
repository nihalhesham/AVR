/*
 * ADC_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
//#include "DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "LCD_Interface.h"

static void (*ADC_CallBack)(void) = {NULL};

void ADC_voidInit()
{
ADMUX_REG -> REFS = REF_VOLT;
ADMUX_REG -> ADLAR = TYPE_DATA;
ADCSRA_REG->ADPS = PRSCALLER ;
ADCSRA_REG->ADEN = 1;
ADCSRA_REG->ADATE=0;
	/*
	 * if you will use ISR
	 * ADCSRA_REG->ADIE=1 ;
	 */
}

void ADC_voidCHANNELSellect(u8 copy_u8ChannelSellect)
{
	ADMUX_REG->MUX=copy_u8ChannelSellect;
}

void Start_Conversion(u16 *num)
{

	ADCSRA_REG->ADSC=1;

	while ( ADCSRA_REG->ADIF ==0 ) ;

	ADCSRA_REG->ADIF =1;


	*num= ADC_DATA ;
}
void ADC_voidSetCallBack(void(*ptr_ext)(void))

{
	if(ptr_ext!=NULL)
		{
			ADC_CallBack=ptr_ext;
		}
}
void  __vector_16() __attribute__((signal)) ;
void __vector_16 ()
{
	ADC_CallBack();


}




