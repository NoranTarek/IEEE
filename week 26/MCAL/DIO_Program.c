/*
 * DIO_Program.c
 *
 *  Created on: Jul 17, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

ES_t DIO_enuSetPortDirection(u8 port_name,u8 port_direction)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: DDRA = port_direction; break;
			case DIO_u8PORTB: DDRB = port_direction; break;
			case DIO_u8PORTC: DDRC = port_direction; break;
			case DIO_u8PORTD: DDRD = port_direction; break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuSetPortValue(u8 port_name,u8 port_value)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: PORTA = port_value; break;
			case DIO_u8PORTB: PORTB = port_value; break;
			case DIO_u8PORTC: PORTC = port_value; break;
			case DIO_u8PORTD: PORTD = port_value; break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuTogPort(u8 port_name)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: PORTA = ~PORTA; break;
			case DIO_u8PORTB: PORTB = ~PORTB; break;
			case DIO_u8PORTC: PORTC = ~PORTC; break;
			case DIO_u8PORTD: PORTD = ~PORTD; break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuGetPortValue(u8 port_name , u8 *port_value)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD) && (port_value != NULL))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: *port_value = PINA; break;
			case DIO_u8PORTB: *port_value = PINB; break;
			case DIO_u8PORTC: *port_value = PINC; break;
			case DIO_u8PORTD: *port_value = PIND; break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuSetPinDirection(u8 port_name,u8 pin_number,u8 pin_direction)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD) && (pin_number <= DIO_u8PIN7) && (pin_direction <= DIO_u8OUTPUT))
	{
		if(pin_direction == DIO_u8INPUT)
		{
			switch(port_name)
			{
			case DIO_u8PORTA: CLR_BIT(DDRA , pin_number); break;
			case DIO_u8PORTB: CLR_BIT(DDRB , pin_number); break;
			case DIO_u8PORTC: CLR_BIT(DDRC , pin_number); break;
			case DIO_u8PORTD: CLR_BIT(DDRD , pin_number); break;
			}
		}
		else if(pin_direction == DIO_u8OUTPUT)
		{
			switch(port_name)
			{
			case DIO_u8PORTA: SET_BIT(DDRA , pin_number); break;
			case DIO_u8PORTB: SET_BIT(DDRB , pin_number); break;
			case DIO_u8PORTC: SET_BIT(DDRC , pin_number); break;
			case DIO_u8PORTD: SET_BIT(DDRD , pin_number); break;
			}
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuSetPinValue(u8 port_name,u8 pin_number, u8 pin_value)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD) && (pin_number <= DIO_u8PIN7) && (pin_value <= DIO_u8HIGH))
	{
		if(pin_value == DIO_u8LOW)
		{
			switch(port_name)
			{
				case DIO_u8PORTA: CLR_BIT(PORTA,pin_number); break;
				case DIO_u8PORTB: CLR_BIT(PORTB,pin_number); break;
				case DIO_u8PORTC: CLR_BIT(PORTC,pin_number); break;
				case DIO_u8PORTD: CLR_BIT(PORTD,pin_number); break;
			}
		}
		else
		{
			switch(port_name)
			{
				case DIO_u8PORTA: SET_BIT(PORTA,pin_number); break;
				case DIO_u8PORTB: SET_BIT(PORTB,pin_number); break;
				case DIO_u8PORTC: SET_BIT(PORTC,pin_number); break;
				case DIO_u8PORTD: SET_BIT(PORTD,pin_number); break;
			}
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuTogPin(u8 port_name , u8 pin_number)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD) && (pin_number <= DIO_u8PIN7))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: TOG_BIT(PORTA,pin_number); break;
			case DIO_u8PORTB: TOG_BIT(PORTB,pin_number); break;
			case DIO_u8PORTC: TOG_BIT(PORTC,pin_number); break;
			case DIO_u8PORTD: TOG_BIT(PORTD,pin_number); break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}

ES_t DIO_enuGetPinValue(u8 port_name , u8 pin_number , u8 *pin_value)
{
	ES_t ErrorState = ES_OK;
	if((port_name <= DIO_u8PORTD) && (pin_number <= DIO_u8PIN7))
	{
		switch(port_name)
		{
			case DIO_u8PORTA: *pin_value = GET_BIT(PINA,pin_number); break;
			case DIO_u8PORTB: *pin_value = GET_BIT(PINB,pin_number); break;
			case DIO_u8PORTC: *pin_value = GET_BIT(PINC,pin_number); break;
			case DIO_u8PORTD: *pin_value = GET_BIT(PIND,pin_number); break;
		}
	}
	else
	{
		ErrorState = ES_NOK;
	}
	return ErrorState;
}
