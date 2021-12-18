/*
 * ex2.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	printf("Enter a string : ");
	gets(text);
	int count = 0;
	while(text[count] != '\0')
	{
		count++;
	}
	printf("Length of string : %d", count);
	return 0;
}

