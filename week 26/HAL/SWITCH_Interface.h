/*
 * SWITCH_Interface.h
 *
 *  Created on: Aug 29, 2025
 *      Author: mylap
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

typedef struct
{
	u8 Switch_PortID;
	u8 Switch_PinID;
	u8 Switch_status;
}SW_t;

#define SW_NOTPRESSED 0
#define SW_PRESSED    1

#define SW_NUM 1

u8 Switch_u8Init(SW_t copy_SWAstr);

u8 Switch_u8GetState(SW_t copy_SWAstr, u8 *copy_SWState);


#endif /* SWITCH_INTERFACE_H_ */
