/*
 * LCD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
#include "STD_TYPES.H"
void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);

void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidWriteNumber( u32 Copy_u8num );

// this fn stores custom char in CGRAM


#endif /* _LCD_INTERFACE_H_ */
