/*
 * main.c
 *
 *  Created on: Jan 8, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int friendsNum, wallHeight, friendHeight[1000], count, sum = 0;
	scanf("%d %d", &friendsNum, &wallHeight);
	for (count = 0; count < friendsNum; ++count)
	{
		scanf("%d", &friendHeight[count]);
		if(friendHeight[count] > wallHeight)
		{
			sum +=2;
			continue;
		}
		sum++;
	}
	printf("%d", sum);
	return 0;
}

