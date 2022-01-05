/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100], reversed[100];
	gets(text);
	gets(reversed);
	strrev(reversed);
	if(strcmp(text, reversed) == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}

