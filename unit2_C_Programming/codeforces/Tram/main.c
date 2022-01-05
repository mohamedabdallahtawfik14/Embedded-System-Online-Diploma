/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int tramStop, entered, exit, count, capacity = 0, max = 0;
	scanf("%d", &tramStop);
	for (count = 0; count < tramStop; ++count)
	{
		scanf("%d %d", &exit, &entered);
		capacity += entered;
		capacity -= exit;
		if(capacity > max)
		{
			max = capacity;
		}
	}
	printf("%d", max);
	return 0;
}

