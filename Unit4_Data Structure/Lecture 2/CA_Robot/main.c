/*
 * main.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Mohamed
 */
#include "CA.h"
#include "DC.h"
#include "US.h"
void setup()
{
	US_init();
	DC_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_Busy);
	DC_state = STATE(DC_Idle);
}
int main(void)
{
	vuint32_t count;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for (count = 0; count < 20000; ++count);
	}
	return 0;
}

