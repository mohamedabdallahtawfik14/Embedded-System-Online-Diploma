/*
 * ex3.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

void reversString(char text[], int n)
{
	// don't put = because odd length of string to avoid swap for same place
	// by this algorithm
	// lead to zero and it will make the string wrong
	if(n > strlen(text) - n - 1)
	{
		text[n] = text[strlen(text) - n - 1] + text[n];
		text[strlen(text) - n - 1] =  text[n] - text[strlen(text) - n - 1];
		text[n] = text[n] - text[strlen(text) - n - 1];
		reversString(text, n-1);
	}
}

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	printf("Enter a sentence: ");
	gets(text);
	reversString(text, strlen(text) - 1);
	printf("%s", text);
	return 0;
}

