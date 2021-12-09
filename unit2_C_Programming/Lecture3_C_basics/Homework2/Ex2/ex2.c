/*
 * ex2.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char character;
	printf("Enter an alphabet: ");
	scanf("%c", &character);
	switch(character)
	{
		case 'a' :
		case 'A' :
		case 'e' :
		case 'E' :
		case 'i' :
		case 'I' :
		case 'o' :
		case 'O' :
		case 'u' :
		case 'U' :
		{
			printf("%c is a vowel", character);
		}
		break;
		default :
		{
			printf("%c is a consonant", character);
		}
		break;
	}
	return 0;
}

