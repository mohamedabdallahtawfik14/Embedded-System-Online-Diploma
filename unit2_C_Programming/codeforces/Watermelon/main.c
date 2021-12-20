/*
 * main.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int weightOfWatermelon;
	scanf("%d", &weightOfWatermelon);
	if((weightOfWatermelon & 1) || (weightOfWatermelon ==2))
	{
		printf("NO");
	}
	else
	{
		printf("YES");
	}
	return 0;
}


