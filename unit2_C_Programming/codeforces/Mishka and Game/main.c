/*
 * main.c
 *
 *  Created on: Jan 7, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int gamerRounds, mishka, chris, mishkaResult = 0, chrisResult = 0, count;
	scanf("%d", &gamerRounds);
	for (count = 0; count < gamerRounds; ++count)
	{
		scanf("%d %d", &mishka, &chris);
		if(mishka > chris)
		{
			mishkaResult++;
		}
		else if(mishka < chris)
		{
			chrisResult++;
		}
		else
		{
			//No action
		}
	}
	if(mishkaResult > chrisResult)
	{
		printf("Mishka");
	}
	else if(mishkaResult < chrisResult)
	{
		printf("Chris");

	}
	else
	{
		printf("Friendship is magic!^^");
	}
	return 0;
}

