/*
 * I2C_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo
 */
#include"I2C_Config.h"
#include"I2C_Interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Private.h"

void I2C_voidMastrInit(void)
{
	/*		Set the Bit Rate = 100KHz			*/
	I2C_TWBR = 72;
	/*		Enable I2C							*/
	SET_BIT(I2C_TWCR,2);
	/*		Enable ACK							*/
	SET_BIT(I2C_TWCR,6);
	/*		Assign the master Address			*/
	I2C_TWAR = (MASTER_ADD<<1);
}
void I2C_voidSlaveInit(u8 Copy_u8SlaveAdd)
{
	/*		Enable I2C							*/
	SET_BIT(I2C_TWCR,2);
	/*		Enable ACK							*/
	SET_BIT(I2C_TWCR,6);
	/*		Assign the Slave Address			*/
	I2C_TWAR = (Copy_u8SlaveAdd<<1);
}


I2C_Error I2C_enuSendStrCond(void)
{
	I2C_Error	Local_enuErr = I2C_NOK;
	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);
	/*		Send a Start cond.		*/
	SET_BIT(I2C_TWCR,5);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x08)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = STRAT_COD_ERR;
	}
	return Local_enuErr;
}
I2C_Error I2C_enuSendStopCond(void)
{
	I2C_Error	Local_enuErr = I2C_NOK;
	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);
	/*		Send a Stop cond.		*/
	SET_BIT(I2C_TWCR,4);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0xA0)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = STOP_COD_ERR;
	}
	return Local_enuErr;
}

I2C_Error I2C_enuSendSlAWrite(u8 Copy_u8SlaveAdd)
{
	I2C_Error	Local_enuErr = I2C_NOK;
	/*		Clear the Start Cond	*/
	CLR_BIT(I2C_TWCR,5);
	/*		Set the Slave Add		*/
	I2C_TWDR = (Copy_u8SlaveAdd <<1) ;

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x18)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = SLA_W_ERR;
	}
	return Local_enuErr;
}
I2C_Error I2C_enuSendSlARead(u8 Copy_u8SlaveAdd)
{
	I2C_Error	Local_enuErr = I2C_NOK;
	/*		Clear the Start Cond	*/
	CLR_BIT(I2C_TWCR,5);
	/*		Set the Slave Add		*/
	I2C_TWDR = (Copy_u8SlaveAdd <<1) ;
	/*		For Read Operation		*/
	SET_BIT(I2C_TWDR,0);

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x40)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = SLA_R_ERR;
	}
	return Local_enuErr;
}

I2C_Error I2C_enuSendDataMstr(u8 Copy_u8Data)
{
	I2C_Error	Local_enuErr = I2C_NOK;

	/*		Set the Data			*/
	I2C_TWDR = Copy_u8Data ;

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x28)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = DATA_M_S_ERR;
	}
	return Local_enuErr;
}
I2C_Error I2C_enuReceiveDataMstr(u8 * Copy_u8Data)
{
	I2C_Error	Local_enuErr = I2C_NOK;

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x50)
	{
		Local_enuErr = I2C_OK;
		*Copy_u8Data = I2C_TWDR  ;

	}else
	{
		Local_enuErr = DATA_M_S_ERR;
	}
	return Local_enuErr;
}

I2C_Error I2C_enuSendDataSl(u8 Copy_u8Data)
{
	I2C_Error	Local_enuErr = I2C_NOK;

	/*		Set the Data			*/
	I2C_TWDR = Copy_u8Data ;

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0xB8)
	{
		Local_enuErr = I2C_OK;
	}else
	{
		Local_enuErr = DATA_S_S_ERR ;
	}
	return Local_enuErr;
}
I2C_Error I2C_enuReceiveDataSl(u8 * Copy_u8Data)
{
	I2C_Error	Local_enuErr = I2C_NOK;

	/*		Clear the Flag			*/
	SET_BIT(I2C_TWCR,7);

	/*		Wait on the Flag		*/
	while ((GET_BIT(I2C_TWCR,7)) == 0);

	/*		Error Check				*/
	if ((I2C_TWSR & 0xF8) == 0x80)
	{
		Local_enuErr = I2C_OK;
		*Copy_u8Data = I2C_TWDR  ;

	}else
	{
		Local_enuErr = DATA_S_R_ERR;
	}
	return Local_enuErr;
}
