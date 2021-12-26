/*
 * main.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	int row, col, matrix[5][5], targetRow, targetCol, moves = 0;
	for (row = 0; row < 5; ++row)
	{
		for (col = 0; col < 5; ++col)
		{
			scanf("%d", &matrix[row][col]);
			if(matrix[row][col] == 1)
			{
				targetRow = row;
				targetCol = col;
			}
		}
	}
	moves = (targetRow >= 2)? targetRow - 2 : 2 - targetRow;
	moves += ((targetCol >= 2)? targetCol - 2 : 2 - targetCol);
	printf("%d", moves);

	return 0;
}

