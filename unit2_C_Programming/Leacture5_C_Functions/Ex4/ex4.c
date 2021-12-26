/*
 * ex4.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

double pw(float base, float power)
{
	int posPower;
	float orBase;
	if(base == 0 && power < 0)
	{
		return -1;
	}
	// in general we have 4 cases
	// case1: power is positive and base is integer
	// case2: power is negative and base is float
	// case3: power is positive and base is float
	// case4: power is negative and base is integer
	//////// but mathematically we can reduce them to two cases only ///////////
	// case1 and case2 have same result, case3 and case4 too have same result!
	if((((int)base == base) && (power >= 0)) || (((int)base != base) && (power <= 0)))
	{
		posPower = (power < 0) ? -1*power : power;
		orBase = ((int)base != base)? (int)(1 / base) : base;
		if(posPower >= 1)
		{
			return orBase * pw(orBase, posPower - 1);
		}
	}
	else
	{
		//will reached here if float and pos or int and neg
		// if float and pos the steps will be normal as we know but it reached here with
		// int and neg the power will be positive and we will get 1 / value (int)
		posPower = (power < 0) ? -1*power : power;
		orBase = ((int)base == base)? (1 / base) : base;
		if(posPower >= 1)
		{
			return orBase * pw(orBase, posPower - 1);
		}
	}
	// any number power of zero equal to 1
	return 1;
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	float base, power;
	double result;
	printf("Enter base number: ");
	scanf("%f", &base);
	printf("Enter power number(positive number): ");
	scanf("%f", &power);
	result = pw(base, power);
	result != -1 ? printf("%g^%g = %g", base, power, result) : printf("Invalid Input!!!");;
	return 0;
}

