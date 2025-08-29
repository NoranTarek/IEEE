/*
 * SSD_Program.c
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "SSD_Configuration.h"
#include "SSD_Interface.h"
#include "SSD_Private.h"

static u8 Local_u8SSDNumbers[10] = {0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111};


u8 SSD_u8InitialDataPort( SSD_Type Copy_structConfig )
{
	u8 Local_u8ErrorState = ES_OK;
	Local_u8ErrorState = DIO_enuSetPortDirection(Copy_structConfig.Port , DIO_u8PORTOUTPUT);
	return Local_u8ErrorState;
}

u8 SSD_u8SendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number )
{
	u8 Local_u8ErrorState = ES_OK;
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE )
	{
		Local_u8ErrorState = DIO_enuSetPortValue( Copy_structConfig.Port , Local_u8SSDNumbers[ Copy_u8Number ] );
	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE )
	{
		Local_u8ErrorState = DIO_enuSetPortValue( Copy_structConfig.Port , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );
	}
	return Local_u8ErrorState;
}


