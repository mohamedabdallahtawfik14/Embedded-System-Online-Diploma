/*
 * main.c
 *
 *  Created on: Feb 3, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int n, k, k2, count = 0;

	char pass[101] = "", index =97;
	scanf("%d %d", &n, &k);
	k2 =k;
	while(k--)
	{
		pass[count] = index++;
		count++;
	}
	index = 97;
	for (; count < n; ++count, index++)
	{
		if(index >= 122)
		{
			index = 97 + k2;
		}
		if(index == 97 + k2)
		{
			index = 97;
		}
		pass[count] = index;


	}

	printf("%s", pass);
	return 0;
}
