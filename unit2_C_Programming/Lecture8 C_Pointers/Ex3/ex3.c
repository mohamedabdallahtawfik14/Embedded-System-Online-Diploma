/*
 * ex3.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[50], reversedText[50], *ptrText, *ptrReversed;
	int textLength;
	ptrText = text;
	ptrReversed = reversedText;
	printf("Pointer : Print a string in reverse order :\n");
	printf("------------------------------------------------\n");
	printf(" Input a string : ");
	// scanning text from user
	scanf("%s", text);
	// get length of this text to jump pointer to the last character
	textLength = strlen(text) - 1;
	ptrText += textLength;
	//when pointer reached first character end this loop
	while(ptrText != text)
	{
		*ptrReversed = *ptrText;
		ptrText--;
		ptrReversed++;
	}
	// copy the first character
	*ptrReversed = *ptrText;
	ptrReversed++;
	// terminate the text
	*ptrReversed = 0;
	// make the pointer to point to beginning of the reversed text again
	ptrReversed = reversedText;
	printf("Reverse of the string is : %s", ptrReversed);
	return 0;
}

