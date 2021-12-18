/*
 * ex1.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohamed
 */
int freq[60];
#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100], character;
	printf("Enter a string: ");
	gets(text);
	printf("Enter a character to find frequency: ");
	scanf("%c", &character);
	int index;
	for (index = 0; text[index] != '\0'; ++index) {
		if(text[index] != ' ')
		{
			freq[text[index] - 65]++;
		}
	}
	printf("Frequency of %c = %d", character, freq[character - 65]);
	return 0;
}


