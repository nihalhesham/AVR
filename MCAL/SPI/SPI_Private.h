/*
 * SPI_Private.h
 *
 *  Created on: ??�/??�/????
 *      Author: lenovo
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR_REG  *((volatile u8 *)0x2D)
#define SPCR_SPR0 0
#define SPCR_SPR1 1
#define SPCR_CPHA 2
#define SPCR_CPOL 3
#define SPCR_MSTR 4
#define SPCR_DORD 5
#define SPCR_SPE  6
#define SPCR_SPIE 7


#define SPSR_REG  *((volatile u8 *)0x2E)
#define SPSR_SPI2X 0
#define SPSR_WCOL  6
#define SPSR_SPIF  7

#define SPDR_REG  *((volatile u8 *)0x2F)

#define 	SPI_MASTER  0
#define 	SPI_SLAVE  1








#endif /* SPI_PRIVATE_H_ */
