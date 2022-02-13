#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
	int low = 0;
	int high = numsSize - 1;
	int mid;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if(target == nums[mid])
		{
			return mid;
		}
		else if(target < nums[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	/* code */
	int arr[9] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
	int arrSize = (sizeof(arr) / sizeof(int));
	printf("%d", search(arr, arrSize, 40));
	return 0;
}