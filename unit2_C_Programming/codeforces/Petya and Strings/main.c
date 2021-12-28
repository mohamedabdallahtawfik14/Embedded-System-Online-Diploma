/*
 * main.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char firstString[100], secondString[100];
	gets(firstString);
	gets(secondString);
	if(stricmp(firstString, secondString) == 0)
	{
		printf("0");
	}
	else if(stricmp(firstString, secondString) == 1)
	{
		printf("1");
	}
	else
	{
		printf("-1");
	}
	return 0;
}

