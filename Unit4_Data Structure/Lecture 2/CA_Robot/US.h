/*
 * US.h
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */

#ifndef US_H_
#define US_H_

//INCS
#include "state.h"

//define states
enum
{
	US_Busy,
}US_state_id;

// pointer to fun
extern void (*US_state)();

//APIs
STATE_define(US_Busy);
void US_init();

#endif /* US_H_ */
