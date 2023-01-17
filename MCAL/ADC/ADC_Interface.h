/*
 * ADC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define CHANNEL_0 0x00
#define CHANNEL_1 0x01
#define CHANNEL_2 0x02
#define CHANNEL_3 0x03
#define CHANNEL_4 0x04
#define CHANNEL_5 0x05
#define CHANNEL_6 0x06
#define CHANNEL_7 0x07



void ADC_voidInit();
void Start_Conversion(u16 *num );

void ADC_voidCHANNELSellect(u8 copy_u8ChannelSellect);

void ADC_voidSetCallBack(void(*PTR)(void));

#endif /* ADC_INTERFACE_H_ */
