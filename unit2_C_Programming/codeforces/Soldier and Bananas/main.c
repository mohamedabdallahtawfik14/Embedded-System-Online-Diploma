/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int costFirstBanana, soliderMoney, quantatiy, count, sum = 0;
	scanf("%d %d %d", &costFirstBanana, &soliderMoney, &quantatiy);
	for (count = 1; count <= quantatiy; ++count)
	{
		sum += (count * costFirstBanana);
	}
	printf("%d", ((sum > soliderMoney)? (sum - soliderMoney) : 0));
	return 0;
}

