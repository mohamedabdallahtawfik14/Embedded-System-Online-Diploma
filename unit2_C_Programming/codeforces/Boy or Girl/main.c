/*
 * main.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

void uniqueOrNot(char text[], char charater)
{
	int count, founded = 0, textLength = strlen(text);
	for (count = 0; count < strlen(text); ++count)
	{
		if(text[count] == charater)
		{
			founded = 1;
			break;
		}
	}
	if (!founded)
	{
		text[textLength] = charater;
		text[textLength + 1] = 0;
	}
}
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char userName[100], unique[100];
	int count;
	gets(userName);
	unique[0] = userName[0];
	unique[1] = 0;
	for (count = 0; count < strlen(userName); ++count)
	{
		uniqueOrNot(unique, userName[count]);
	}
	if(strlen(unique) % 2 != 0)
	{
		printf("IGNORE HIM!");
	}
	else
	{
		printf("CHAT WITH HER!");
	}
	return 0;
}


