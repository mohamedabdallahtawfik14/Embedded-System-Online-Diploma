/*
 * mian.c
 *
 *  Created on: Jan 28, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	int wires, birds[100], shots, currWire, birdPos, count;
	setvbuf(stdout, NULL, _IONBF, 0);
	scanf("%d", &wires);
	for (count = 0; count < wires; ++count)
	{
		scanf("%d", &birds[count]);
	}
	scanf("%d", &shots);
	for (count = 0; count < shots; ++count)
	{
		scanf("%d %d", &currWire, &birdPos);
		if((currWire - 2) >= 0)
		{
			birds[currWire - 1 - 1] += (birdPos - 1);
		}
		if((currWire)<= wires)
		{
			birds[currWire - 1 + 1] += (birds[currWire - 1] - birdPos);
		}
		birds[currWire - 1] = 0;
	}
	for (count = 0; count < wires; ++count)
	{
		printf("%d\n", birds[count]);
	}
	return 0;
}

