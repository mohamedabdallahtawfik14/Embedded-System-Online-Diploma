/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	int upperCount = 0, lowerCount = 0, count;
	gets(text);
	for (count = 0; count < strlen(text); ++count)
	{
		if((text[count] >= 97) && (text[count] <= 122))
		{
			lowerCount++;
		}
		else
		{
			upperCount++;
		}
	}
	if(upperCount > lowerCount)
	{
		strupr(text);
	}
	else
	{
		strlwr(text);
	}
	printf("%s", text);
	return 0;
}

