/*
 * Given an array of positive and negative integers, 
 * re-arrange it so that you have positive integers on one end and negative integers on other
 * but retain their order of appearance in the original array.
 */

#include <stdio.h>

#define SWAP(a, b, type) { \
    type tmp; \
    tmp = a; \
    a = b; \
    b = tmp; \
}

void rearrange(int *arr, int k)
{
    int i,n,p,count_n=0;

    for(i=0; i<k; i++) {
	if(arr[i] < 0)
	    count_n++;
    }

    if(count_n == 0|| count_n == k)
	return;

    //n=0; p=count_n;
    n=0; p=1;

    for(i=0; i<k; i++) {
	if(arr[n] < 0) {
	    n++;
	    continue;
	}

	if(n >= count_n || p > k)
	    return;

	SWAP(arr[n], arr[p], int);

	if(arr[n] >= 0 && arr[p] >= 0)
	    p++;

	if(arr[n]<0 || arr[n] < 0) {
	    n++;
	    p++;
	}
    }
}

int main()
{
    int arr[] = {1,7,-5,9,-12,15};
    //int arr[] = {-5,7,1,9,-12,15};
    //int arr[] = {-5,7,-6,9,-12,15};
    //int arr[] = {8,7,1,9,-12,15};
    //int arr[] = {-8,-7,-1,-9,-12,-15};
    //int arr[] = {8,7,1,9,12,15};
    //int arr[] = {5,-7,-6,9,-12,15};
    int i;

    for (i=0; i<sizeof(arr)/sizeof(int); i++)
	printf("%d ", arr[i]);
    printf("\n");

    rearrange(arr, sizeof(arr)/sizeof(int));

    for (i=0; i<sizeof(arr)/sizeof(int); i++)
	printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
