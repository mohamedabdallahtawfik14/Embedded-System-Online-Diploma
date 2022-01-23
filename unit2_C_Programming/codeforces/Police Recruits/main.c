/*
 * main.c
 *
 *  Created on: Jan 20, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfEvents, event, untreatedCrimes = 0, freePolice = 0, count;
	scanf("%d", &numOfEvents);
	for (count = 0; count < numOfEvents; ++count)
	{
		scanf("%d", &event);
		if(event > 0)
		{
			freePolice += event;
		}
		else if(event == -1 && freePolice ==0)
		{
			untreatedCrimes += 1;
		}
		else
		{
			freePolice--;
		}
	}
	printf("%d", untreatedCrimes);
	return 0;
}


