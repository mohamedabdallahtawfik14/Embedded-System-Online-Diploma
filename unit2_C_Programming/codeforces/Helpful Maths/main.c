/*
 * main.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	gets(text);
	int count, internalCount = 0;
	for (count = 0; count < strlen(text); ++count)
	{
		for (internalCount = count; internalCount < strlen(text); ++internalCount)
		{
			if(text[internalCount] == '+')
			{
				continue;
			}
			if(text[count] > text[internalCount])
			{
				text[count] = text[count] + text[internalCount];
				text[internalCount] = text[count] - text[internalCount];
				text[count] = text[count] - text[internalCount];
			}
		}

	}
	printf("%s", text);
	return 0;
}

