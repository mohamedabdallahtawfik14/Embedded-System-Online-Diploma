/*
 * main.c
 *
 *  Created on: Jan 1, 2022
 *      Author: mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[1000];
//	char cap[2];
	gets(text);
//	cap[0] = text[0];
//	cap[1] = '\0';
//	strupr(cap);
//	text[0] = cap[0];
	if((text[0] >= 97)  && (text[0] <= 122))
	{
		text[0] -= 32;
	}
	printf("%s", text);
	return 0;
}

