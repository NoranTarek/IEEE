/*
 * DIO_Interface.h
 *
 *  Created on: Jul 17, 2025
 *      Author: mylap
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Private.h"

#define PIN_NUMBERS   8

/*
port_name :
1-DIO_u8PORTA.
2-DIO_u8PORTB.
3-DIO_u8PORTC.
4-DIO_u8PORTD.
*/

#define DIO_u8PORTA   0
#define DIO_u8PORTB   1
#define DIO_u8PORTC   2
#define DIO_u8PORTD   3

/*
pin_direcion :
1-DIO_u8INPUT .
2-DIO_u8OUTPUT.
 */

#define DIO_u8INPUT   0
#define DIO_u8OUTPUT  1

#define DIO_u8PORTOUTPUT 0b11111111

/*
pin_number :
0-DIO_u8PIN0.
1-DIO_u8PIN1.
2-DIO_u8PIN2.
3-DIO_u8PIN3.
4-DIO_u8PIN4.
5-DIO_u8PIN5.
6-DIO_u8PIN6.
7-DIO_u8PIN7.
*/

#define DIO_u8PIN0    0
#define DIO_u8PIN1    1
#define DIO_u8PIN2    2
#define DIO_u8PIN3    3
#define DIO_u8PIN4    4
#define DIO_u8PIN5    5
#define DIO_u8PIN6    6
#define DIO_u8PIN7    7

/*
pin_value :
1-DIO_u8LOW .
2-DIO_u8HIGH.
 */

#define DIO_u8LOW     0
#define DIO_u8HIGH    1

#define DIO_u8PORTHIGH 0b11111111

ES_t DIO_enuSetPortDirection(u8 port_name,u8 port_direction);

ES_t DIO_enuSetPortValue(u8 port_name,u8 port_value);

ES_t DIO_enuTogPort(u8 port_name);

ES_t DIO_enuGetPortValue(u8 port_name , u8 *port_value);

ES_t DIO_enuSetPinDirection(u8 port_name,u8 pin_number,u8 pin_direction);

ES_t DIO_enuSetPinValue(u8 port_name,u8 pin_number, u8 pin_value);

ES_t DIO_enuTogPin(u8 port_name , u8 pin_number);

ES_t DIO_enuGetPinValue(u8 port_name , u8 pin_number , u8 *pin_value);

#endif /* DIO_INTERFACE_H_ */
