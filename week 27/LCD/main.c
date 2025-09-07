/*
 * main.c
 *
 *  Created on: Aug 10, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "SWITCH_Interface.h"
#include "LCD_Interface.h"

#include <util/delay.h>

void main()
{
	u8 Lives = 3;
	u8 Score = 0;
	u8 Position = 0;
	u8 Step = 2;
	u16 Time = 250;
	u16 Time_Step = 20;
	u8 Time_Sstep = 1;

	u8 State , State_1 , State_2 , State_3 , State_4 , State_5;
	u8 Flag = 0;

	LED_t LED_1 = {DIO_u8PORTC , DIO_u8PIN0 , DIO_u8LOW};
	LED_u8Init(LED_1);
	LED_t LED_2 = {DIO_u8PORTC , DIO_u8PIN1 , DIO_u8LOW};
	LED_u8Init(LED_2);

	SW_t Switch_1 = {DIO_u8PORTA , DIO_u8PIN0 , DIO_u8HIGH};
	Switch_u8Init(Switch_1);
	SW_t Switch_2 = {DIO_u8PORTA , DIO_u8PIN1 , DIO_u8HIGH};
	Switch_u8Init(Switch_2);
	SW_t Switch_3 = {DIO_u8PORTA , DIO_u8PIN2 , DIO_u8HIGH};
	Switch_u8Init(Switch_3);
	SW_t Switch_4 = {DIO_u8PORTA , DIO_u8PIN3 , DIO_u8HIGH};
	Switch_u8Init(Switch_4);
	SW_t Switch_5 = {DIO_u8PORTA , DIO_u8PIN4 , DIO_u8HIGH};
	Switch_u8Init(Switch_5);

	LCD_init_PortDirection();
	LCD_voidInit();

	while(Lives > 0)
	{
	    Flag = 0;
	    Time = 250 - (Time_Sstep * Time_Step);
	    State = 0;

	    LCD_voidClearDisplay();
	    LCD_u8GoToXY(Position , 0);
	    LCD_voidSendData('*');
	    LCD_u8GoToXY(0 , 1);
	    LCD_voidSendString("Score : ");
	    LCD_voidSendNumber(Score);

	    while(Time--)
	    {
	        Switch_u8GetState(Switch_1 , &State_1);
	        Switch_u8GetState(Switch_2 , &State_2);
	        Switch_u8GetState(Switch_3 , &State_3);
	        Switch_u8GetState(Switch_4 , &State_4);
	        Switch_u8GetState(Switch_5 , &State_5);

	        if(State_1 == SW_PRESSED) { State = 1; break; }
	        if(State_2 == SW_PRESSED) { State = 2; break; }
	        if(State_3 == SW_PRESSED) { State = 3; break; }
	        if(State_4 == SW_PRESSED) { State = 4; break; }
	        if(State_5 == SW_PRESSED) { State = 5; break; }

	        _delay_ms(10);
	    }

	    if(State == (Position+1))
	    {
	        Score++;
	        LCD_voidClearDisplay();
	        LCD_voidSendString("Success!");
	        Time_Sstep++;
	        LED_u8TurnON(LED_1);
	        _delay_ms(200);
	        LED_u8TurnOFF(LED_1);
	    }
	    else if(State != 0)
	    {
	        Lives--;
	        LCD_voidClearDisplay();
	        LCD_voidSendString("Wrong!");
	        LED_u8TurnON(LED_2);
	        _delay_ms(200);
	        LED_u8TurnOFF(LED_2);
	    }
	    else
	    {
	        Lives--;
	        LCD_voidClearDisplay();
	        LCD_voidSendString("Missed!");
	        LED_u8TurnON(LED_2);
	        _delay_ms(200);
	        LED_u8TurnOFF(LED_2);
	    }

	    Position = (Step % 5);
	    Step *= 3;
	}

	LCD_voidClearDisplay();
	LCD_voidSendString("Game Over!");
	LCD_u8GoToXY(0,1);
	LCD_voidSendString("Final Score:");
	LCD_voidSendNumber(Score);
}
