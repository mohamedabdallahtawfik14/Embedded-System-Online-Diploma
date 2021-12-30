/*
 * main.c
 *
 *  Created on: Dec 30, 2021
 *      Author: mohamed
 */

#include <stdio.h>
#include <string.h>
void removeSpecificChar(char string[], char character)
{
	char temp[200];
	int count, i;
	for (count = 0, i = 0; count < strlen(string); ++count)
	{
		if(string[count] != character)
		{
			temp[count - i] = string[count];
		}
		else
		{
			i++;
		}
	}
	temp[count - i] = '\0';
	strcpy(string, temp);
}
void addDot(char string[])
{
	char temp[200];
	int count, i;
	for (count = 0, i=0; count < strlen(string); ++count, i+=2)
	{
		temp[i] = '.';
		temp[i + 1] = string[count];
	}
	temp[i] = '\0';
	strcpy(string, temp);
}
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[200];
	strlwr(gets(text));
	removeSpecificChar(text, 'a');
	removeSpecificChar(text, 'o');
	removeSpecificChar(text, 'y');
	removeSpecificChar(text, 'e');
	removeSpecificChar(text, 'u');
	removeSpecificChar(text, 'i');
	addDot(text);
	printf("%s", text);
	return 0;
}

