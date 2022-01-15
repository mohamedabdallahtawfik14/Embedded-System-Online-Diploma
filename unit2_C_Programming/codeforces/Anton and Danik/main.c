/*
 * main.c
 *
 *  Created on: Jan 15, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfGames, count, anton = 0, danik = 0;
	char text[100000];
	scanf("%d ", &numOfGames);
	gets(text);
	for (count = 0; count < numOfGames; ++count)
	{
		if (text[count] == 'A')
		{
			anton++;
		}
		else
		{
			danik++;
		}
	}
	if(anton > danik)
	{
		printf("Anton");
	}
	else if(anton < danik)
	{
		printf("Danik");
	}
	else
	{
		printf("Friendship");
	}
	return 0;
}

