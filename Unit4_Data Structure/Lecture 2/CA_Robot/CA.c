/*
 * CA.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */
#include "CA.h"

//static Variables
static uint32 CA_speed = 0;
static uint32 CA_distance = 0;
static uint32 CA_threshold = 50;

// pointer to fun
void (*CA_state)();

void get_distance_US(uint32 distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ---------------- distance = %d -----------------> CA\n", CA_distance);
}
STATE_define(CA_waiting)
{
	CA_state_id = CA_Waiting;
	printf("CA_Waiting state: distance = %d  speed = %d\n", CA_distance, CA_speed);
	CA_speed = 0;
	DC_Motor(CA_speed);

}
STATE_define(CA_driving)
{
	CA_state_id = CA_Driving;
	printf("CA_driving state: distance = %d  speed = %d\n", CA_distance, CA_speed);
	CA_speed = 30;
	DC_Motor(CA_speed);


}
