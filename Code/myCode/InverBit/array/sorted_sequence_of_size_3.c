/*
 * Find a sorted subsequence of size 3 in linear time
 * Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.
 *
 * Examples:
 *
 * Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
 * Output: 5, 6, 30
 *
 * Input:  arr[] = {1, 2, 3, 4}
 * Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4
 *
 * Input:  arr[] = {4, 3, 2, 1}
 * Output: No such triplet
 */

/* Solution:
 * 1) Create an auxiliary array smaller[0..n-1]. smaller[i] should store the index of a number which is smaller than arr[i] and is on left side of arr[i]. smaller[i] should contain -1 if there is no such element.
 * 2) Create another auxiliary array greater[0..n-1]. greater[i] should store the index of a number which is greater than arr[i] and is on right side of arr[i]. greater[i] should contain -1 if there is no such element.
 * 3) Finally traverse both smaller[] and greater[] and find the index i for which both smaller[i] and greater[i] are not -1.
 */
/* C/C++ program to find a sorted subsequence of size 3 */
#include<stdio.h>
#include<stdlib.h>

/* A function to fund a sorted subsequence of size 3 */
void find3Numbers(int arr[], int n)
{
    int max = n-1; /*Index of maximum element from right side */
    int min = 0; /*Index of minimum element from left side */
    int i;

    /* Create an array that will store index of a smaller
     * element on left side. If there is no smaller element
     * on left side, then smaller[i] will be -1. */
    int *smaller = (int *)malloc(sizeof(int)*n);
    smaller[0] = -1;  /* first entry will always be -1 */
    for (i = 1; i < n; i++)
    {
	if (arr[i] <= arr[min])
	{
	    min = i;
	    smaller[i] = -1;
	}
	else
	    smaller[i] = min;
    }

    /* Create another array that will store index of a
     * greater element on right side. If there is no greater
     * element on right side, then greater[i] will be -1. */
    int *greater = (int *)malloc(sizeof(int)*n);
    greater[n-1] = -1;  /* last entry will always be -1 */
    for (i = n-2; i >= 0; i--)
    {
	if (arr[i] >= arr[max])
	{
	    max = i;
	    greater[i] = -1;
	}
	else
	    greater[i] = max;
    }

    /* Now find a number which has both a greater number on
     * right side and smaller number on left side */
    for (i = 0; i < n; i++)
    {
	if (smaller[i] != -1 && greater[i] != -1)
	{
	    printf("%d %d %d\n", arr[smaller[i]],
		    arr[i], arr[greater[i]]);
	    return;
	}
    }

    /* If we reach number, then there are no such 3 numbers */
    printf("No such triplet found\n");

    /* Free the dynamically alloced memory to avoid memory leak */
    free(smaller);
    free(greater);

    return;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}
