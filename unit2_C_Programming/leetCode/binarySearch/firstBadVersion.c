// The API isBadVersion is defined for you.
#include <stdio.h>
#include <stdbool.h>

bool isBadVersion(int version);

int firstBadVersion(long long n) 
{
   long long low = 1;
	long long high = n;
	long long mid;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if(isBadVersion(mid) == true && isBadVersion(mid - 1) != true)
		{
			return mid;
		}
		else if(isBadVersion(mid) == false)
		{
			low = mid + 1;
		}
        else
        {
            high = mid - 1;
        }
	}
	return -1;
}
bool isBadVersion(int version)
{
	char arr[5]={false, false, false, true, true};
	return arr[version - 1];
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("%d", firstBadVersion(5));
	return 0;
}