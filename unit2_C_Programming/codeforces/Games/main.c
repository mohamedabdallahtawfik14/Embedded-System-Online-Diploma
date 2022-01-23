/*
 * main.c
 *
 *  Created on: Jan 23, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfTeams, count, internalCount, teams[30][2], sum = 0;
	scanf("%d", &numOfTeams);
	for (count = 0; count < numOfTeams; ++count) {
		for (internalCount = 0; internalCount < 2; ++internalCount) {
			scanf("%d", &teams[count][internalCount]);
		}
	}
	for (count = 0; count < numOfTeams; ++count)
	{
		for (internalCount = count + 1; internalCount < numOfTeams; ++internalCount)
		{
			if((teams[count][0] == teams[internalCount][1]) && (teams[count][1] == teams[internalCount][0]))
			{
				sum += 2;
			}
			else if((teams[count][0] == teams[internalCount][1]) || (teams[count][1] == teams[internalCount][0]))
			{
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}

