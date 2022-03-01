/*
 * state.h
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "platform_Types.h"

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_)  ST_##_stateFUN_

void get_distance_US(uint32 distance);
void DC_Motor(uint32 speed);

#endif /* STATE_H_ */
