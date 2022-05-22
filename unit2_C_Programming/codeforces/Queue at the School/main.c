/*
 * main.c
 *
 *  Created on: May 22, 2022
 *      Author: Mohamed
 */

#include "stdio.h"
#include "string.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfChildern, time;
	char queue[51];

	scanf("%d %d %s", &noOfChildern, &time, queue);
	int i, j;
	for (i = 0; i < time; ++i)
	{
		for (j = 0; j < strlen(queue); ++j)
		{
			if(queue[j] == 'B' && queue[j+1] == 'G')
			{
				queue[j] = queue [j] + queue[j + 1];
				queue[j + 1] = queue[j] - queue[j + 1];
				queue[j] = queue[j] - queue[j + 1];
				j++;
			}
		}
	}
	printf("%s", queue);
	return 0;
}
