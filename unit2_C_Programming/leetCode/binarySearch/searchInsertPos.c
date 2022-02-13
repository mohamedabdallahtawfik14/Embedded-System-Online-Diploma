#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int low = 0;
	int high = numsSize - 1;
	int mid;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if((target == nums[mid])||(low==high && target < nums[mid]))
		{
			return mid;
		}
		else if(target < nums[mid])
		{
			high = mid - 1;
            high = (high < 0)? 0:high;
		}
		else
		{
			low = mid + 1;
		}
	}
    if(target < nums[mid])
    {
        return mid;
    }
	return mid + 1;
}
int main(int argc, char const *argv[])
{
	/* code */
	int arr[9] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
	printf("%d\n", searchInsert(arr, 9, 2));
	printf("%d\n", searchInsert(arr, 9, 45));
	printf("%d\n", searchInsert(arr, 9, 50));
	printf("%d\n", searchInsert(arr, 9, 5));

	return 0;
}