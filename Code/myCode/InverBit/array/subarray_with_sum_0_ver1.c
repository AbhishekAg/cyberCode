/* A simple C program to find largest subarray with 0 sum */
#include <stdio.h>

int MAX(a,b) {
    return ((a) > (b) ? (a) : (b));
}

int maxLen(int arr[], int n)
{
    int max_len = 0; // Initialize result
    int i,j,curr_sum;

    for (i = 0; i < n; i++)
    {
	curr_sum = 0;
	for (j = i; j < n; j++)
	{
	    curr_sum += arr[j];
	    if (curr_sum == 0) {
		max_len = MAX(max_len, j-i+1);
	    }
	}
    }
    return max_len;
}

int main()
{
    //int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    //int arr[] = {1,7,-5,9,-12,15};
    int arr[] = {4,6,3,-9,-5,1,3,0,2};

    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of the longest 0 sum subarray is %d\n", maxLen(arr, n));

    return 0;

}
