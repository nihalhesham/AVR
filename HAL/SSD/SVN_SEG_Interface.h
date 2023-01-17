/*
 * SVN_SEG_Interface.h
 *
 *  Created on: Nov 13, 2022
 *      Author: mmont
 */

#include "StdTypes.h"

#ifndef SVN_SEG_INTERFACE_H_
#define SVN_SEG_INTERFACE_H_


void SVN_SEG_Init();
void SVN_SEG_EN1(u8 state);
void SVN_SEG_EN2(u8 state);
void SVN_SEG_DT_State(u8 state);
void SVN_SEG_Display(u8 num);
void SVN_SEG_Display2Digits(u8 num);
u8 switchNumber(u8 num);
void SVN_SEG_Display1Digits(u8*num);


#endif /* SVN_SEG_INTERFACE_H_ */
