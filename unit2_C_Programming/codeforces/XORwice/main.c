/*
 * main.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int firstNum, secondNum, noOfTestCases;
	scanf("%d", &noOfTestCases);
	int count;
	// explanation : bcz we try to make  (a⊕x) + (b⊕x) small, we try to cancel one term of them so if we put x with a or b
	// the result will be a⊕b
	for (count = 0; count < noOfTestCases; ++count) {
		scanf("%d %d", &firstNum, &secondNum);
		printf("%d\n", firstNum ^ secondNum);
	}
	return 0;
}

