/*
 * DC.h
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */

#ifndef DC_H_
#define DC_H_

//INCS
#include "state.h"

//define states
enum
{
	DC_Idle,
	DC_Busy
}DC_state_id;

// pointer to fun
extern void (*DC_state)();

//APIs
STATE_define(DC_Idle);
STATE_define(DC_Busy);
void DC_init();
#endif /* DC_H_ */
