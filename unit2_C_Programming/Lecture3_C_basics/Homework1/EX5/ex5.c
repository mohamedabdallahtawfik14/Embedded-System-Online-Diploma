/*
 * ex5.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mohamed
 */


#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char character;
	printf("Enter a character : ");
	scanf("%c", &character);
	printf("ASCII value of %c = %d", character, character);
	return 0;
}
