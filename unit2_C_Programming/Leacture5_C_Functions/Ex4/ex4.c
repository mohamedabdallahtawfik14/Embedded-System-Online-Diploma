/*
 * ex4.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int pw(int base, int power)
{
	if(power >= 1)
	{
		return base * pw(base, power - 1);
	}
	// any number power of zero equal to 1
	return 1;
}

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int base, power;
	printf("Enter base number: ");
	scanf("%d", &base);
	printf("Enter power number(positive number): ");
	scanf("%d", &power);
	printf("%d^%d = %d", base, power, pw(base, power));
	return 0;
}

