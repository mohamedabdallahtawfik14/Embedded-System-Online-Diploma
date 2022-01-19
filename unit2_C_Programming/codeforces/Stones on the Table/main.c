/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfStones, count, sum = 0;
	char text[50];
	scanf("%d ", &numOfStones);
	gets(text);
	for (count = 0; count < numOfStones; ++count) {
		if(text[count] == text[count + 1])
		{
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}

