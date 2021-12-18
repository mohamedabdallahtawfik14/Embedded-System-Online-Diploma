/*
 * ex3.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	printf("Enter the string: ");
	gets(text);
	int count;
	// getting length of the string
	int textLength = strlen(text);
	// swap between characters
	for (count = 0; count < textLength / 2; ++count) {
		text[count] = text[count] + text[textLength - count - 1];
		text[textLength - count - 1] = text[count] - text[textLength - count - 1];
		text[count] = text[count] - text[textLength - count - 1];
	}
	printf("Reverse String is : %s", text);
	return 0;
}

