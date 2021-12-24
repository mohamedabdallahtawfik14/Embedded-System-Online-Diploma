/*
 * main.c
 *
 *  Created on: Dec 24, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfStatements, count, x=0;
	char statement[4];
	scanf("%d ", &noOfStatements);
	for (count = 0; count < noOfStatements; ++count)
	{
		gets(statement);
		if(((statement[0] == 'X') && (statement[1] == '+'))|| ((statement[0] == '+') && (statement[2] == 'X')))
		{
			x++;
		}
		else
		{
			x--;
		}
	}
	printf("%d", x);
	return 0;
}

