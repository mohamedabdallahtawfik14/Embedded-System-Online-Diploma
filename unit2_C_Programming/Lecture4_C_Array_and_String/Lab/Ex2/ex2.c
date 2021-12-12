/*
 * ex2.c
 *
 *  Created on: Dec 12, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	float x[5] = {5, 16, 22, 3.5, 15};
	int count;
	for (count = 0; count < 5; ++count) {
		printf("y(%f) = %f\n", x[count], (5 * x[count] * x[count] + 3 * x[count] + 2));
	}
	return 0;
}

