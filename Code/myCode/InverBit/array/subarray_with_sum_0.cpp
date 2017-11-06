/*
 * Find the largest subarray with 0 sum
 * Given an array of integers, find length of the largest subarray with sum equals to 0.
 */

/*
 * This algorithm will find all subarrays with sum 0 and it can be easily modified to find the minimal one or to keep track of the start and end indexes. This algorithm is O(n).
 *
 * Given an int[] input array, you can create an int[] tmp array where tmp[i] = tmp[i - 1] + input[i]; Each element of tmp will store the sum of the input up to that element(prefix sum of array).
 *
 * Now if you check tmp, you'll notice that there might be values that are equal to each other. Let's say that this values are at indexes j an k with j < k, then the sum of the input till j is equal to the sum till k and this means that the sum of the portion of the array between j and k is 0! Specifically the 0 sum subarray will be from index j + 1 to k.
 *
 * NOTE: if j + 1 == k, then k is 0 and that's it! ;)
 * NOTE: The algorithm should consider a virtual tmp[-1] = 0;
 * NOTE: An empty array has sum 0 and it's minimal and this special case should be brought up as well in an interview. Then the interviewer will say that doesn't count but that's another problem! ;)
 * The implementation can be done in different ways including using a HashMap with pairs but be careful with the special case in the NOTE section above.
 *
 * Example:
 *
 * int[] input = {4,  6,  3, -9, -5, 1, 3, 0, 2}
 * int[] tmp =   {4, 10, 13,  4, -1, 0, 3, 3, 5}
 * Value 4 in tmp at index 0 and 3 ==> sum tmp 1 to 3 = 0, length (3 - 1) + 1 = 3
 * Value 0 in tmp at index 5 ==> sum tmp 0 to 5 = 0, length (5 - 0) + 1 = 6
 * Value 3 in tmp at index 6 and 7 ==> sum tmp 7 to 7 = 0, length (7 - 7) + 1 = 1
 * ****UPDATE****
 *
 * Assuming that in our tmp array we end up with multiple element with the same value then you have to consider every identical pair in it! Example (keep in mind the virtual '0' at index '-1'):
 *
 * int[] array = {0, 1, -1, 0}
 * int[] tmp = {0, 1, 0, 0}
 * By applying the same algorithm described above the 0-sum subarrays are delimited by the following indexes (included):
 *
 * [0] [0-2] [0-3] [1-2] [1-3] [3]
 *
 * Although the presence of multiple entries with the same value might impact the complexity of the algorithm depending on the implementation, I believe that by using an inverted index on tmp (mapping a value to the indexes where it appears) we can keep the running time at O(n).
 */

/* C++ program to find the length of largest subarray with 0 sum */
#include <bits/stdc++.h>
using namespace std;

/* Returns Length of the required subarray */
int maxLen(int arr[], int n)
{
    /* Map to store the previous sums */
    map<int, int> presum;

    int sum = 0;        // Initialise the sum of elements
    int max_len = 0;    // Initialise result

    /* Traverse through the given array */
    for(int i=0; i<n; i++)
    {
	/* Add current element to sum */
	sum += arr[i];

	if (arr[i]==0 && max_len==0)
	    max_len = 1;
	if (sum == 0)
	    max_len = i+1;

	/* Look for this sum in Hash table */
	if(presum.find(sum) != presum.end())
	{
	    /* If this sum is seen before, then update max_len */
	    max_len = max(max_len, i-presum[sum]);
	}
	else
	{
	    /* Else insert this sum with index in hash table */
	    presum[sum] = i;
	}
    }

    return max_len;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Length of the longest 0 sum subarray is "<< maxLen(arr, n) << "\n";

    return 0;
}
