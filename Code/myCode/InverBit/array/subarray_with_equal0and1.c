/*
 * Largest subarray with equal number of 0s and 1s
 * Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
 */
/*
 * Complexity O(n2)
 */

#include <stdio.h>

#define MAX(a,b) (a)>(b)?(a):(b)

int subarray(int *arr, int n)
{
    int i,j;
    int sum, max_len=0;

    for(i=0;i<n-1;i++) {
	sum = (arr[i] == 0)? -1 : 1;
	for(j=i+1;j<n;j++) {
	    if(arr[j] == 0)
		sum += -1;
	    else
		sum += 1;
	    if(sum == 0) {
		max_len = MAX(max_len, j-i+1);
	    }
	}
    }
    return max_len;
}

int main()
{
    /* consider 0 as -1*/
    int arr[] = {1, 0, 1, 1, 1, 0,0,0};
    int n = sizeof(arr)/sizeof(int);

    printf("Max %d\n", subarray(arr, n));

    return 0;
}
