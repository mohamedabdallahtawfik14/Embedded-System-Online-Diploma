/*
 * ex3.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfRows, noOfCols, matrix[10][10], transpose[10][10];
	printf("Enter rows and column of matrix : ");
	scanf("%d %d", &noOfRows, &noOfCols);
	printf("Enter elements of matrix: \n");
	int row, col;
	// take matrix of user
	for (row = 0; row < noOfRows; ++row) {
		for (col = 0; col < noOfCols; ++col) {
			printf("Enter element a%d%d: ", row + 1, col + 1);
			scanf("%d", &matrix[row][col]);
			// getting the transpose in the same loop
			transpose[col][row] = matrix[row][col];
		}
	}
	// view the matrix
	printf("Entered Matrix: \n");
	for (row = 0; row < noOfRows; ++row) {
		for (col = 0; col < noOfCols; ++col) {
			printf("%d	", matrix[row][col]);
		}
		printf("\n");
	}
	// view the transpose of the matrix
	printf("Transpose of Matrix: \n");
	for (row = 0; row < noOfCols; ++row) {
		for (col = 0; col < noOfRows; ++col) {
			printf("%d	", transpose[row][col]);
		}
		printf("\n");
	}
	return 0;
}

