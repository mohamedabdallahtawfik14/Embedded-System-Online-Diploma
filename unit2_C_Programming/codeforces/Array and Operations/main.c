/*
 * main.c
 *
 *  Created on: Dec 22, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
/* C program for Merge Sort */
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfTwstCases, noOfArrayElements, noOfOperations, data[120], count = 0, startOfOperation, endOfOperation;
	long long score = 0;
	scanf("%d", &noOfTwstCases);
	while(noOfTwstCases--)
	{

		scanf("%d %d", &noOfArrayElements, &noOfOperations);
		for (count = 0; count < noOfArrayElements; ++count)
		{
			scanf("%d", &data[count]);
		}
		//sorting array asc
		mergeSort(data, 0, noOfArrayElements - 1);
		startOfOperation = noOfArrayElements - (2 * noOfOperations);
		endOfOperation = noOfArrayElements - noOfOperations ;
		for (count = startOfOperation; ((count < endOfOperation) && (noOfOperations > 0)); ++count)
		{
			// time limit bcz division take long time
			//score += (data[count] / data[noOfOperations + count]);

			// never data[count] will larger than data[count + noOfOperations] array sorted!!!
			// there are another soln with xor too instead of ==
			if(data[count] == data[noOfOperations + count])
			{
				score++;
			}
		}
		for (count = 0; count < startOfOperation; ++count)
		{
			score += data[count];
		}
		printf("%lld\n", score);
		score = 0;
	}
	return 0;
}


