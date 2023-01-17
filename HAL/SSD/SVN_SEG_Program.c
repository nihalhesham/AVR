/*
 * SVN_SEG_Program.c
 *
 *  Created on: Nov 13, 2022
 *      Author: mmont
 */

#include "util/delay.h"
#include "SVN_SEG_Interface.h"
#include "SVN_SEG_Private.h"
#include "SVN_SEG_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "StdTypes.h"




void SVN_SEG_Init() {
	DIO_setPortDirections(SVN_SEG_LEDS_PORT, PORT_OUTPUT);
	DIO_setPinDirection(SVN_EN_PORT, SVN_EN1_PIN, PIN_OUTPUT);
	DIO_setPinDirection(SVN_EN_PORT, SVN_EN2_PIN, PIN_OUTPUT);
	DIO_setPinDirection(SVN_DT_PORT, SVN_DT_PIN, PIN_OUTPUT);

}

void SVN_SEG_EN1(u8 state) {
	DIO_WritePinValue(SVN_EN_PORT, SVN_EN1_PIN, state);
}

void SVN_SEG_EN2(u8 state) {
	DIO_WritePinValue(SVN_EN_PORT, SVN_EN2_PIN, state);
}

void SVN_SEG_DT_State(u8 state) {
	DIO_WritePinValue(SVN_DT_PORT, SVN_DT_PIN, state);
}

void SVN_SEG_Display(u8 num) {
	DIO_setPortValue(SVN_SEG_LEDS_PORT, num << 1);
}

u8 switchNumber(u8 num) {
	switch(num) {
	case 0: return SVN_DISPLAY_0;
	case 1: return SVN_DISPLAY_1;
	case 2: return SVN_DISPLAY_2;
	case 3: return SVN_DISPLAY_3;
	case 4: return SVN_DISPLAY_4;
	case 5: return SVN_DISPLAY_5;
	case 6: return SVN_DISPLAY_6;
	case 7: return SVN_DISPLAY_7;
	case 8: return SVN_DISPLAY_8;
	case 9: return SVN_DISPLAY_9;
	default: return SVN_DISPLAY_0;
	}
}


void SVN_SEG_Display2Digits(u8 num) {
	u8 first_digit = num % 10;
	u8 second_digit = num /10;
	_delay_ms(5);
	SVN_SEG_EN1(PIN_HIGH);
	SVN_SEG_EN2(PIN_LOW);
	SVN_SEG_Display(switchNumber(first_digit));
	_delay_ms(5);
	SVN_SEG_EN1(PIN_LOW);
	SVN_SEG_EN2(PIN_HIGH);
	SVN_SEG_Display(switchNumber(second_digit));
}

void SVN_SEG_Display1Digits(u8 *num)
{
	_delay_ms(5);
	SVN_SEG_EN1(PIN_HIGH);
	SVN_SEG_EN2(PIN_LOW);
	SVN_SEG_Display(switchNumber(num));
}
