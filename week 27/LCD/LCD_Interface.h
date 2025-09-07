/*
 * LCD_Interface.h
 *
 *  Created on: Jul 20, 2025
 *      Author: mylap
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_init_PortDirection(void);

void LCD_voidSendString(const u8 *str);

void LCD_voidSendNumber(u32 value);

void LCD_voidSendFloatingNumber(f32 value);

u8 LCD_u8GoToXY(u8 col , u8 row);

void LCD_voidClearDisplay();

#endif /* LCD_INTERFACE_H_ */
