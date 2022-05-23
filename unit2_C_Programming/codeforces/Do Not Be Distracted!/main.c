/*
 * main.c
 *
 *  Created on: May 23, 2022
 *      Author: Mohamed
 */

#include "stdio.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int testCases, days;
	char letters[100][28] = {0};
	char tasks[100];
	scanf("%d", &testCases);
	int count, j, flag = 0;
	for(count = 0; count < testCases; count++)
		//DDBBCCCBBEZ	ABA
	{
		scanf("%d %s", &days, tasks);
		for (j = 0; j < days; ++j)
		{
			if(tasks[j] != tasks[j + 1])
			{
				if(!letters[count][tasks[j] - 65])
				{
					letters[count][tasks[j] - 65]++;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		flag = 0;
	}
	return 0;
}

