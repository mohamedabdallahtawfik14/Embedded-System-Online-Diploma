/*
 * main..c
 *
 *  Created on: Dec 23, 2021
 *      Author: Mohamed
 */
#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfTestCases, b[7], count, internalCount;
	scanf("%d", &noOfTestCases);
	for (count = 0; count < noOfTestCases; ++count) {
		for (internalCount = 0; internalCount < 7; ++internalCount) {
			scanf("%d", &b[internalCount]);
		}
		// array is sorted so first two numbers we sure there were in array (a)
		// because we can't obtain on them by adding another two number
		// third number will be the (-) of first two numbers from the largest number
		printf("%d %d %d\n", b[0], b[1], b[6] - (b[0] + b[1]));
	}
	return 0;
}


