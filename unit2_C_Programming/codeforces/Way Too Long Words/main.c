/*
 * main.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int noOfWords, count, internalCount, sum;
	char word[100], out[3];
	scanf("%d ", &noOfWords);
	for (count = 0; count < noOfWords; ++count)
	{
		sum = 0;
		gets(word);
		if(strlen(word) <= 10)
		{
			printf("%s\n", word);
		}
		else
		{
			out[0] = word[0];
			out[2] = word[strlen(word) - 1];
			internalCount = 1;
			while((word[internalCount] != '\0') && (internalCount != (strlen(word) - 1)))
			{
				sum++;
				internalCount++;
			}
			out[1] = sum;
			printf("%c%d%c\n", out[0], out[1], out[2]);
		}

	}
	return 0;
}

