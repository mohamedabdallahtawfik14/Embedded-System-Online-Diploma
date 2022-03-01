/*
 * US.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */
#include "US.h"
#include "platform_Types.h"
uint32 US_Get_Distance_Random(uint32 l, uint32 r);
//static Variables
uint32 US_distance = 0;

// pointer to fun
void (*US_state)();
void US_init()
{
	printf("-------- ultraSonic init --------\n");
}
STATE_define(US_Busy)
{
	US_state_id = US_Busy;
	US_distance = US_Get_Distance_Random(45, 55);
	printf("US_Waiting state: distance = %d \n", US_distance);
	get_distance_US(US_distance);
	US_state = STATE(US_Busy);

}
uint32 US_Get_Distance_Random(uint32 l, uint32 r)
{
	uint32 rand_num = (rand() % (r)) + 1;
	return rand_num;
}
