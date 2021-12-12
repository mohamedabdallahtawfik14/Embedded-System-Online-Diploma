/*
 * ex3.c
 *
 *  Created on: Dec 12, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float matrix[3][3];
	int row, col;
//	 scan matrix values from user
	for (row = 0; row < 3; ++row) {
		for (col = 0; col < 3; ++col) {
			printf("Enter the item(%d, %d) : ", row, col);
			scanf("%f", &matrix[row][col]);
		}
	}
	// view matrix values
	printf("the matrix is\n");
	for (row = 0; row < 3; ++row) {
		for (col = 0; col < 3; ++col) {
			printf("%.2f\t", matrix[row][col]);
		}
		printf("\n");
	}
	// transpose without temp
	for (row = 0; row < 3; ++row) {
		for (col = row; col < 3; ++col) {
			if(row != col)
			{
				matrix[row][col] = matrix[row][col] + matrix[col][row];
				matrix[col][row] = matrix[row][col] - matrix[col][row];
				matrix[row][col] = matrix[row][col] - matrix[col][row];
			}
		}
	}
	// transpose
	printf("the Transpose matrix is \n");
	for (row = 0; row < 3; ++row) {
		for (col = 0; col < 3; ++col) {
			printf("%.2f\t", matrix[row][col]);
		}
		printf("\n");
	}
	return 0;
}

