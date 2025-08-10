/*
 * main.c
 *
 *  Created on: Aug 10, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <util/delay.h>

void main()
{
	u8 flag = 1;
	DIO_enuSetPortDirection(DIO_u8PORTA, DIO_u8PORTOUTPUT);
	while(1)
	{
		switch(flag)
		{
		case 1:
			DIO_enuSetPortValue(DIO_u8PORTA , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH);
			_delay_ms(500);
			flag = 2;
			break;
		case 2:
			DIO_enuSetPortValue(DIO_u8PORTA , DIO_u8LOW);
			for(int i = 0; i < 5;++i)
			{
				DIO_enuTogPin(DIO_u8PORTA , DIO_u8PIN1);
				_delay_ms(50);
			}
			flag = 3;
			break;
		case 3:
			DIO_enuSetPortValue(DIO_u8PORTA , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTA , DIO_u8PIN2 , DIO_u8HIGH);
			_delay_ms(1000);
			flag = 1;
			break;
		}
	}
}
