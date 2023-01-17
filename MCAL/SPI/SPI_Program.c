/*
 * SPI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */
#include "SPI_Private.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"DIO_Private.h"
#include "SPI_Config.h"


void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER
	SET_BIT(SPCR_REG,SPCR_MSTR);
	SET_BIT(DDRB_REG,PIN4);
	SET_BIT(DDRB_REG,PIN5);
	CLR_BIT(DDRB_REG,PIN6);
	SET_BIT(DDRB_REG,PIN7);
	//CLR_BIT(PORTB_REG,PIN4);
	// FACTOR 128
	SET_BIT(SPCR_REG,SPCR_SPR0);
	SET_BIT(SPCR_REG,SPCR_SPR1);
	CLR_BIT(SPSR_REG,SPSR_SPI2X);


#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR_REG,SPCR_MSTR);
	CLR_BIT(DDRB_REG,PIN4);
	CLR_BIT(DDRB_REG,PIN5);
	SET_BIT(DDRB_REG,PIN6);
	CLR_BIT(DDRB_REG,PIN7);

#endif
	SET_BIT(SPCR_REG,SPCR_SPE);
}

u8 SPI_transive (u8 datasend)
{
	SPDR_REG=datasend;
	while (GET_BIT(SPSR_REG,SPSR_SPIF)==0);
	return SPDR_REG;
}

