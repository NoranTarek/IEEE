/*
 * LED_Interface.h
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_t;

#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0

u8 LED_u8Init(LED_t Copy_pstrLed);

u8 LED_u8TurnON(LED_t Copy_pstrLedID);

u8 LED_u8TurnOFF(LED_t Copy_pstrLedID);

u8 LED_u8Toggle(LED_t Copy_pstrLedID);

#endif /* LED_INTERFACE_H_ */
