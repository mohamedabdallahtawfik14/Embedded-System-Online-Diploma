/*
 * main.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfParticipants, refernce, scores[50];
	scanf("%d %d", &noOfParticipants, &refernce);
	int count, passed = 0;
	for (count = 0; count < noOfParticipants; ++count)
	{
		scanf("%d", &scores[count]);
	}

	for (count = 0; count < noOfParticipants; ++count)
	{
		if((scores[count] >= scores[refernce - 1]) && (scores[count] > 0))
		{
			passed += 1;
		}
	}
	printf("%d", passed);
	return 0;
}

