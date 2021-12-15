/*
 * ex1.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100], character;
	// take the string from user
	printf("Enter a string: ");
	gets(text);
	// take a character from user to find its freq in the text
	printf("Enter a character to find frequency: ");
	scanf("%c", &character);
	// calculate freq for specific character
	int index = 0, count = 0;
	while(text[index] != '\0')
	{
		if(text[index] == character)
		{
			count++;
		}
		index++;
	}
	if(count != 0)
	{
		printf("Frequency of %c = %d", character, count);
	}
	else
	{
		printf("character not found!!!");
	}
	return 0;
}

