/*
 * main.c
 *
 *  Created on: Dec 21, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	int noOfTestCases, a, b, count = 0, internalCount = 0, sum = 0, data[300000];
	scanf("%d", &noOfTestCases);
	for (count = 0; count < noOfTestCases; ++count)
	{
//		// tiiiiime limtit
//		sum = 0;
		scanf("%d %d", &a, &b);
//		for (internalCount = 0; internalCount < a; ++internalCount)
//		{
//			data[internalCount] = internalCount;
//			sum ^= internalCount;
//		}
//
//		while(sum != b)
//		{
//			if((sum ^ b) != a)
//			{
//				data[internalCount] = sum ^ b;
//				sum ^= data[internalCount];
//			}
//			else
//			{
//				data[internalCount] = internalCount  + 1;
//				sum ^= data[internalCount];
//			}
//			internalCount++;
//		}
//		printf("%d\n", internalCount);
		//xor will be n = a - 1
		int xor;
		if((a - 1) % 4 == 0)
		{
			xor = a - 1;
		}
		//xor will be 1
		else if((a - 1) % 4 == 1)
		{
			xor = 1;
		}
		//xor will be n = a
		else if((a - 1) % 4 == 2)
		{
			xor = a;
		}
		//xor will be n = 0
		else
		{
			xor = 0;
		}
		// if xor equal to (b) we don't need to add any elements to the array
		if(xor == b)
		{
			printf("%d\n", a);
		}
		// if the result of (xor ^ b) not equal to a we need to add one element
		// bcs (not forget this rule) a^b=c ==> a^c=b
		else if((xor ^ b) != a)
		{
			printf("%d\n", a + 1);
		}
		// if the result of (xor ^ b) equal to a we need to add one element but this element equal to a
		// and we need array without of a so we will add two elements not one element
		// ex if we need to add 3 and a equal to 3 so we will add 1 and two so its xor will be 3
		else
		{
			printf("%d\n", a + 2);
		}
	}
	return 0;
}

