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

	int noOfTestCases;
	int values[30000];
	scanf("%d", &noOfTestCases);
	int count = 0, logBase2;
	for (count = 0; count < noOfTestCases; ++count) {
		scanf("%d", &values[count]);
	}
	for (count = 0; count < noOfTestCases; ++count) {
//		while((values[count] != 0))
//		{
//			if((values[count] & (--values[count])) == 0)
//			{
//				break;
//			}
//		}
		logBase2 = log2(values[count]);
		printf("%d\n", (int)(pow(2, logBase2) - 1));
	}
	return 0;
}


