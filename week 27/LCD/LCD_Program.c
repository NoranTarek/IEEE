/*
 * LCD_Program.c
 *
 *  Created on: Jul 20, 2025
 *      Author: mylap
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Configuration.h"
#include "LCD_Interface.h"

#include "util/delay.h"

void LCD_voidInit(void)
{
	_delay_ms(40);
	LCD_voidSendCommand(FUNCTION_SET);
	_delay_ms(1);
	LCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);
	LCD_voidSendCommand(DISPLAY_CLEAR);
	//_delay_ms(2);
	//LCD_SendCommand(ENTRY_MODE_SET);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	//Reset RS
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_RS , DIO_u8LOW);

	//Send Command
	DIO_enuSetPortValue(LCD_PORT_DATA , Copy_u8Command);

	//Latch
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8LOW);
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8HIGH);
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	//Reset RS
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_RS , DIO_u8HIGH);

	//Send Data
	DIO_enuSetPortValue(LCD_PORT_DATA , Copy_u8Data);

	//Latch
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8LOW);
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8HIGH);
	_delay_ms(2);
	DIO_enuSetPinValue(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8LOW);
}

void LCD_init_PortDirection(void)
{
	// Pins -> Output
	DIO_enuSetPortDirection(LCD_PORT_DATA , DIO_u8PORTOUTPUT);
	// RS -> Output
	DIO_enuSetPinDirection(LCD_PORT_INSTRUCTION , LCD_RS , DIO_u8OUTPUT);
	// EN -> Output
	DIO_enuSetPinDirection(LCD_PORT_INSTRUCTION , LCD_EN , DIO_u8OUTPUT);
}

void LCD_voidSendString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		LCD_voidSendData(str[i]);
		i++;
	}
}

void LCD_voidSendNumber(u32 value)
{
	u8 counter = 0;
	u8 arr[100];
	while(value != 0)
	{
		arr[counter] = ((value % 10) + '0');
		value /= 10;
		counter++;
	}
	for(int i = counter-1; i >= 0; i--)
	{
		LCD_voidSendData(arr[i]);
	}
}

void LCD_voidSendFloatingNumber(f32 value)
{
	LCD_voidSendNumber((u32)value);
	LCD_voidSendData('.');
	LCD_voidSendNumber((u32)((value-((u32)value))*1000000));
}

u8 LCD_u8GoToXY(u8 col , u8 row)
{
	u8 Local_u8PinState=0;
	if((row == 0) && (col < 16))
	{
		LCD_voidSendCommand((0x00) + col + 128);
	}
	else if((row == 1) && (col < 16))
	{
		LCD_voidSendCommand((0x40) + col + 128);
	}
	else
	{
		Local_u8PinState = 1;
	}
	return Local_u8PinState;
}

void LCD_voidClearDisplay()
{
	LCD_voidSendCommand(1);
	_delay_ms(2);
}
