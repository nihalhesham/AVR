/*
 * TIMER_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIM0_Inti();
void TIM0_start(void);
void TIM0_STOP(void);
void TIMER_voidCallBack(  void (*ptr_timer)(void) );
void FASTPWM (void);


#endif /* TIMER_INTERFACE_H_ */
