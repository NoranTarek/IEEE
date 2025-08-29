/*
 * main.c
 *
 *  Created on: Aug 10, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "SWITCH_Interface.h"
#include "SSD_Interface.h"

#include <util/delay.h>

void main()
{
	u8 Switch1State , Switch2State;
	u8 counter1 = 0,counter2 = 0;

	SW_t switch1 = {DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH};
	SW_t switch2 = {DIO_u8PORTA , DIO_u8PIN1 , DIO_u8HIGH};
	Switch_u8Init(switch1);
	Switch_u8Init(switch2);

	SSD_Type SSD1 = {DIO_u8PORTC , SSD_COMMON_CATHODE};
	SSD_Type SSD2 = {DIO_u8PORTD , SSD_COMMON_CATHODE};
	SSD_u8InitialDataPort(SSD1);
	SSD_u8InitialDataPort(SSD2);

	SSD_u8SendNumber(SSD1 , counter1);
	SSD_u8SendNumber(SSD2 , counter2);

	while(1)
	{
		Switch_u8GetState(switch1 , &Switch1State);
		if(Switch1State == SW_PRESSED)
		{
			counter1 = 0;
			counter2 = 0;
		}
		else if(Switch1State == SW_NOTPRESSED)
		{
			Switch_u8GetState(switch2 , &Switch2State);
			if(Switch2State == SW_PRESSED)
			{
				if(counter1 == 9)
				{
					if(counter2 == 9)
					{
						counter1 = 0;
						counter2 = 0;
					}
					else
					{
						counter1 = 0;
						counter2++;
					}
				}
				else
				{
					counter1++;
				}
			}
			else if(Switch2State == SW_NOTPRESSED)
			{
				//Do nothing
			}
		}
		SSD_u8SendNumber(SSD1 , counter1);
		SSD_u8SendNumber(SSD2 , counter2);
	}
}
