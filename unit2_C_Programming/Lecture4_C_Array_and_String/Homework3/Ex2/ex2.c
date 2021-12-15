/*
 * ex2.c
 *
 *  Created on: Dec 13, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfData;
	float values[100], sum = 0;
	printf("Enter the numbers of data: ");
	scanf("%d", &noOfData);
	int index;
	// scan data from user and get the sum
	for (index = 0; index < noOfData; ++index) {
		printf("%d. Enter number: ", (index + 1));
		scanf("%f", &values[index]);
		sum += values[index];
	}
	printf("Average = %.2f", sum / noOfData);
	return 0;
}


