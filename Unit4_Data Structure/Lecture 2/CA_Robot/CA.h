/*
 * CA.h
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */

#ifndef CA_H_
#define CA_H_

//INCS
#include "state.h"

//define states
enum
{
	CA_Waiting,
	CA_Driving
}CA_state_id;

// pointer to fun
extern void (*CA_state)();

//APIs
STATE_define(CA_waiting);
STATE_define(CA_driving);
#endif /* CA_H_ */
