/*
 * ex1.c
 *
 *  Created on: Dec 13, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float firstMatrix[2][2], secondMatrix[2][2];
	// scan first matrix values from user
	printf("Enter the elements of 1st matrix\n");
	int row, col;
	for (row = 0; row < 2; ++row) {
		for (col = 0; col < 2; ++col) {
			printf("Enter a%d%d: ", row + 1, col + 1);
			scanf("%f", &firstMatrix[row][col]);
		}
	}
	// scan second matrix values from user
	printf("Enter the elements of 2nd matrix\n");
	for (row = 0; row < 2; ++row) {
		for (col = 0; col < 2; ++col) {
			printf("Enter b%d%d: ", row + 1, col + 1);
			scanf("%f", &secondMatrix[row][col]);
		}
	}
	// add two matrix and print the result in same for loop
	printf("Sum Of Matrix: \n");
	for (row = 0; row < 2; ++row) {
		for (col = 0; col < 2; ++col) {
			printf("%.1f\t", firstMatrix[row][col] + secondMatrix[row][col]);
		}
		printf("\n");
	}

	return 0;
}


