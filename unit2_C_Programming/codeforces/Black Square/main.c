/*
 * main.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int count, calories = 0;
	char text[100000];
	int cost[4];
	for (count = 0; count < 4; ++count)
	{
		scanf("%d ", &cost[count]);
	}
	gets(text);
	for (count = 0; count < strlen(text); ++count)
	{
		switch(text[count])
		{
			case '1':
			{
				calories += cost[0];
			}
			break;
			case '2':
			{
				calories += cost[1];
			}
			break;
			case '3':
			{
				calories += cost[2];
			}
			break;
			case '4':
			{
				calories += cost[3];
			}
			break;
		}
	}
	printf("%d", calories);
	return 0;
}
