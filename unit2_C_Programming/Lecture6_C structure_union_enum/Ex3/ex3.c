/*
 * ex3.c
 *
 *  Created on: Jan 7, 2022
 *      Author: mohamed
 */

#include <stdio.h>

struct complex
{
	float m_real;
	float m_imaginary;
};
struct complex addTwoComplex(struct complex a, struct complex b)
{
	struct complex temp;
	temp.m_real= a.m_real + b.m_real;
	temp.m_imaginary = a.m_imaginary + b.m_imaginary;
	return temp;
}
struct complex readData(char text[])
{
	struct complex a;
	printf("%s\n", text);
	printf("Enter real and imaginary respectively:");
	scanf("%f %f", &a.m_real, &a.m_imaginary);
	return a;
}

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	struct complex complex1, complex2, result;
	complex1 = readData("for 1st complex number: ");
	complex2 = readData("for 2nd complex number: ");
	result = addTwoComplex(complex1, complex2);
	printf("sum = %g + %gi", result.m_real, result.m_imaginary);
	return 0;
}

