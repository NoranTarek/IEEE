/*
 * SSD_Interface.h
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE  	0
#define SSD_COMMON_ANODE		1

typedef struct
{
	u8 Port;
	u8 Type;
	u8 EnablePort;
	u8 EnablePin;
}SSD_Type;

u8 SSD_u8InitialDataPort  ( SSD_Type Copy_structConfig );
u8 SSD_u8SendNumber       ( SSD_Type Copy_structConfig , u8 Copy_u8Number );

#endif /* SSD_INTERFACE_H_ */
