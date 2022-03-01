/*
 * DC.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */
#include "DC.h"

//static Variables
static uint32 DC_speed = 0;

// pointer to fun
void (*DC_state)();

void DC_init()
{
	printf("-------- DC_Motor init --------\n");
}
void DC_Motor(uint32 speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_Busy);
	printf("CA ---------------- speed = %d -----------------> DC\n", DC_speed);
}
STATE_define(DC_Idle)
{
	DC_state_id = DC_Idle;
	printf("DC_Idle state: speed = %d\n", DC_speed);
}
STATE_define(DC_Busy)
{
	DC_state_id = DC_Busy;
	DC_state = STATE(DC_Idle);
	printf("DC_Busy state: speed = %d\n", DC_speed);
}
