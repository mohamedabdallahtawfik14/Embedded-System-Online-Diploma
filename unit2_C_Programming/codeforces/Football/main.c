/*
 * main.c
 *
 *  Created on: Jan 4, 2022
 *      Author: mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char text[100];
	gets(text);
	int count, sum1 = 0, sum0 = 0;
	for (count = 0; count < strlen(text); ++count)
	{
		if((sum1 >= 7) || (sum0 >= 7))
		{
			break;
		}
		if(text[count] == '1')
		{
			sum0= 0;
			sum1++;
		}
		else
		{
			sum0++;
			sum1 = 0;
		}
	}
	if((sum1 >= 7) || (sum0 >= 7))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}

