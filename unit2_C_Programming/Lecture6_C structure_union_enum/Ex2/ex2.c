/*
 * ex2.c
 *
 *  Created on: Jan 7, 2022
 *      Author: mohamed
 */

#include <stdio.h>

struct distance
{
	int feet;
	float inch;
};
struct distance readData(char text[])
{
	struct distance a;
	printf("%s\n", text);
	printf("Enter feet: ");
	scanf("%d", &a.feet);
	printf("Enter inch: ");
	scanf("%f", &a.inch);
	return a;
}
struct distance addTwoDistance(struct distance a, struct distance b)
{
	struct distance temp;
	temp.feet = a.feet + b.feet;
	temp.inch = a.inch + b.inch;
	if(temp.inch >= 12)
	{
		temp.feet++;
		temp.inch = temp.inch - 12;
	}
	return temp;
}
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	struct distance x, y, result;
	x = readData("Enter information for 1st distance");
	y = readData("Enter information for 2nd distance");
	result = addTwoDistance(x, y);
	printf("Sum of distances= %d\'-%g\"", result.feet, result.inch);
	return 0;
}

