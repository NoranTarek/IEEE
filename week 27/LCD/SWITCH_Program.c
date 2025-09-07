/*
 * SWITCH_Program.c
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "SWITCH_Configuration.h"
#include "SWITCH_Interface.h"
#include "SWITCH_Private.h"


u8 Switch_u8Init(SW_t copy_SWAstr)
{
	u8 Local_u8ErrorState = ES_OK;
	Local_u8ErrorState = DIO_enuSetPinDirection(copy_SWAstr.Switch_PortID , copy_SWAstr.Switch_PinID , DIO_u8INPUT);
	Local_u8ErrorState = DIO_enuSetPinValue(copy_SWAstr.Switch_PortID , copy_SWAstr.Switch_PinID , copy_SWAstr.Switch_status);
	return Local_u8ErrorState;
}

u8 Switch_u8GetState(SW_t copy_SWAstr, u8 *copy_SWState)
{
	u8 Local_u8ErrorState = ES_OK;
	if(copy_SWState == NULL)
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	else
	{
		u8 Local_u8PinValue;
		Local_u8ErrorState = DIO_enuGetPinValue(copy_SWAstr.Switch_PortID , copy_SWAstr.Switch_PinID , &Local_u8PinValue);
		if(copy_SWAstr.Switch_status == DIO_u8HIGH)
		{
			if(Local_u8PinValue == 0)
			{
				*copy_SWState = SW_PRESSED;
				while(Local_u8PinValue == 0)
				{
					Local_u8ErrorState = DIO_enuGetPinValue(copy_SWAstr.Switch_PortID , copy_SWAstr.Switch_PinID , &Local_u8PinValue);
				}
			}
			else if(Local_u8PinValue == 1)
			{
				*copy_SWState = SW_NOTPRESSED;
			}
		}
		else if(copy_SWAstr.Switch_status == DIO_u8LOW)
		{
			if(Local_u8PinValue == 1)
			{
				*copy_SWState = SW_PRESSED;
				while(Local_u8PinValue == 1)
				{
					Local_u8ErrorState = DIO_enuGetPinValue(copy_SWAstr.Switch_PortID , copy_SWAstr.Switch_PinID , &Local_u8PinValue);
				}
			}
			else if(Local_u8PinValue == 0)
			{
				*copy_SWState = SW_NOTPRESSED;
			}
		}
	}
	return Local_u8ErrorState;
}

