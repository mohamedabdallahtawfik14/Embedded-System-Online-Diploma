/*
 * main.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <math.h>
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int bacteria;
	scanf("%d", &bacteria);
	int count = 1;
	while(bacteria != 0 && log2(bacteria) !=  (int)log2(bacteria) )
	{

		if(bacteria & 1)
		{
			count ++;
		}
		bacteria = bacteria >> 1;
	}
	printf("%d", count);
	return 0;
}


