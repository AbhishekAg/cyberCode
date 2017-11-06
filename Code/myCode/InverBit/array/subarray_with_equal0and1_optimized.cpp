/*
 * Largest subarray with equal number of 0s and 1s
 * Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
 */
/*
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) (a)>(b)?(a):(b)
#define N 100


int subarray(int *arr, int n)
{
    int i;
    int sum=0, max_len=0;

    map<int,int> presum;

    for(i=0; i<n; i++) {
	if(arr[i] == 0)
	    sum += -1;
	else
	    sum += 1;

	if(sum == 0)
	    max_len = i+1;

	/* If hash is present then update the length */
	if(presum.find(sum) != presum.end()) {
	    max_len = MAX(max_len, i-presum[sum]);
	} else {
	    presum[sum] = i;
	}
    }

    return max_len;
}

int main()
{
    /* consider 0 as -1*/
    int arr[] = {1, 0, 1, 1, 1, 0,1,1};
    int n = sizeof(arr)/sizeof(int);

    cout << "Max: " << subarray(arr, n) << "\n";

    return 0;
}
