/*
 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfPeople, opinion, count, isHard = 0;
	scanf("%d", &numOfPeople);
	for (count = 0; count < numOfPeople; ++count)
	{
		scanf("%d", &opinion);
		if(opinion == 1)
		{
			isHard = 1;
			break;
		}
	}
	if(isHard)
	{
		printf("HARD");
	}
	else
	{
		printf("EASY");
	}
	return 0;
}


