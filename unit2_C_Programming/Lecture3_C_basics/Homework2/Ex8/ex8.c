/*
 * ex8.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char op;
	float num1, num2;
	printf("Enter operator either + or - or * or divide : ");
	scanf("%c", &op);
	printf("Enter two operands: ");
	scanf("%f %f", &num1, &num2);
	switch(op)
	{
		case '+' :
		{
			printf("%.1f + %.1f = %.1f", num1, num2, num1 + num2);
		}
		break;

		case '-' :
		{
			printf("%.1f - %.1f = %.1f", num1, num2, num1 - num2);
		}
		break;

		case '*' :
		{
			printf("%.1f * %.1f = %.1f", num1, num2, num1 * num2);
		}
		break;

		case '/' :
		{
			printf("%.1f / %.1f = %.1f", num1, num2, num1 / num2);
		}
		break;

		default :
		{
			printf("Error!!! Wrong operation!!!");
		}
	}
	return 0;
}

