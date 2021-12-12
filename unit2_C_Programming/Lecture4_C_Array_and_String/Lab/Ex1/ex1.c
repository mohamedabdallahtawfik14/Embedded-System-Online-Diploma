/*
 * ex1.c
 *
 *  Created on: Dec 12, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float degrees[10];
	int count;
	// scan 10 degrees from user
	for (count = 0; count < (sizeof(degrees) / sizeof(float)); ++count) {
		printf("Enter student %d degree : ", count + 1);
		scanf("%f", &degrees[count]);
	}
	// print all array
	for (count = 0; count < (sizeof(degrees) / sizeof(float)); ++count) {
		printf("Student %d degree is %f\n", count + 1, degrees[count]);
	}
	return 0;
}


