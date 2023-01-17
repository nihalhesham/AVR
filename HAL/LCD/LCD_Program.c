/*
 * LCD_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "util/delay.h"
#include"DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_private.h"
#include "LCD_Config.h"

void LCD_voidWriteBitsToSend(u8 copy_u8Byte)
{

	//DIO_voidSetPinValue(RW_PORT,RW_PIN, PIN_LOW);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);




	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 7) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 6) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 5) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 4) & 1);

	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(30);

	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 3) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 2) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 1) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 0) & 1);

	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(30);



}


void LCD_voidInit(void)
{
	_delay_ms(30);

	DIO_voidSetPinDirection(RS_PORT,RS_PIN,PIN_OUTPUT);
	// DIO_voidSetPinDirection(RW_PORT,RW_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(EN_PORT, EN_PIN,PIN_OUTPUT);


	DIO_voidSetPinDirection(D4_PORT,D4_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT,D5_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT,D6_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT,D7_PIN,PIN_OUTPUT);



    //LCD_voidWriteCommand(0x02);
    _delay_ms(2);
	LCD_voidWriteCommand(FUNCTION_SET_4BIT_2LINES_5X7_DOTS);
	_delay_ms(2);

	LCD_voidWriteCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(2);

	LCD_voidWriteCommand(DISPLAY_CLEAR);

	_delay_ms(2);

	LCD_voidWriteCommand(ENTRY_MODE_SET  );

}
void LCD_voidWriteData(u8 copy_u8data)
{

	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_HIGH);


	LCD_voidWriteBitsToSend(copy_u8data);
}
void LCD_voidWriteCommand(u8 copy_u8Command)
{
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_LOW);



	LCD_voidWriteBitsToSend(copy_u8Command);
}
void LCD_voidWriteString(u8 * copy_str)
{
	u32 i= 0;
	while(copy_str[i] != '\0')
	{
		LCD_voidWriteData(copy_str[i]);
		i++;
	}
}
void LCD_WriteNumber (num)
{
	u16 *arr;
}

void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col)
{

	u8 local_address ;
	switch(copy_u8row)
	{
	case 0 : local_address =copy_u8col ;
	break ;

	case 1 : local_address =copy_u8col+0x40 ;
	break ;

	LCD_voidWriteCommand(local_address+SET_DDRAM_ADDRESS) ;
	}

}
void LCD_voidClear(void)
{
	LCD_voidWriteCommand( DISPLAY_CLEAR);
}

void LCD_voidWriteNumber( u32 Copy_u8num )

{
	u32 LOCAL_NUMBER=Copy_u8num ;
	u8 LOCAL_ARR[10] ,i=0 ;

	do
	{
		LOCAL_ARR[i]= ((LOCAL_NUMBER%10)+48);
		LOCAL_NUMBER=LOCAL_NUMBER/10 ;

		i++ ;
	}
	while(LOCAL_NUMBER!=0);
	/*
	if(Copy_u8num==0)
		{
				LCD_voidWriteData(48);
		}*/

	for(;i>0;i--)
	{
		LCD_voidWriteData(LOCAL_ARR[i-1]);
	}



}
