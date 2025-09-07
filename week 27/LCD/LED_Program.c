/*
 * LED_Program.c
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LED_Configuration.h"
#include "LED_Interface.h"
#include "LED_Private.h"

u8 LED_u8Init(LED_t Copy_pstrLed)
{
	u8 Local_u8ErrorState = ES_OK;
	Local_u8ErrorState = DIO_enuSetPinDirection(Copy_pstrLed.Port , Copy_pstrLed.Pin , DIO_u8OUTPUT);
	return Local_u8ErrorState;
}

u8 LED_u8TurnON(LED_t Copy_pstrLedID)
{
	u8 Local_u8ErrorState = ES_OK;
	if(Copy_pstrLedID.Active_State == ACTIVE_HIGH)
	{
		Local_u8ErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port , Copy_pstrLedID.Pin , DIO_u8LOW);
	}
	else if(Copy_pstrLedID.Active_State == ACTIVE_LOW)
	{
		Local_u8ErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port , Copy_pstrLedID.Pin , DIO_u8HIGH);
	}
	return Local_u8ErrorState;
}

u8 LED_u8TurnOFF(LED_t Copy_pstrLedID)
{
	u8 Local_u8ErrorState = ES_OK;
	if(Copy_pstrLedID.Active_State == ACTIVE_HIGH)
	{
		Local_u8ErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port , Copy_pstrLedID.Pin , DIO_u8HIGH);
	}
	else if(Copy_pstrLedID.Active_State == ACTIVE_LOW)
	{
		Local_u8ErrorState = DIO_enuSetPinValue(Copy_pstrLedID.Port , Copy_pstrLedID.Pin , DIO_u8LOW);
	}
	return Local_u8ErrorState;
}

u8 LED_u8Toggle(LED_t Copy_pstrLedID)
{
	u8 Local_u8ErrorState = ES_OK;
	Local_u8ErrorState = DIO_enuTogPin(Copy_pstrLedID.Port , Copy_pstrLedID.Pin);
	return Local_u8ErrorState;
}
