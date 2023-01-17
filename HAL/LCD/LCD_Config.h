/*
 * LCD_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_MODE  FOUR_BIT

/*
 * choose control pins
 */
#define RS_PIN   PIN1
#define RS_PORT  PORTA_ID


#define EN_PIN   PIN2
#define EN_PORT  PORTA_ID

/*
 * data pins
 */
#define D7_PIN    PIN6
#define D7_PORT   PORTA_ID

#define D6_PIN    PIN5
#define D6_PORT   PORTA_ID

#define D5_PIN    PIN4
#define D5_PORT   PORTA_ID

#define D4_PIN    PIN3
#define D4_PORT   PORTA_ID

#endif /* HAL_LCD_LCD_CONFIG_H_ */
