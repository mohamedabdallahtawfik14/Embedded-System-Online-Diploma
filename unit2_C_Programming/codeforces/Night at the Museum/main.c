/*
 * main.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	int count, steps = 0, start = 0, index, distance;
	gets(text);
	for (count = 0; count < strlen(text); ++count)
	{
		index = text[count] - 97;
		distance = start - index;
		distance = (distance < 0)? distance * -1 : distance;
		steps += (distance > 13)? 26 - distance : distance;
		start = index;
	}
	printf("%d", steps);
	return 0;
}

