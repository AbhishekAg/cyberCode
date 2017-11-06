/*
 * Program for array rotation
 * Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
 */

#include <stdio.h>

void left_rotate(int *arr, int n, int k)
{
    int tmp,i,j;

    for(i=0; i<k; i++) {
        tmp = arr[0];
	for(j=0;j<n-1;j++) {
	    arr[j] = arr[j+1];
	}
	arr[j] = tmp;
    }
}

int main()
{
    //int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    //int arr[] = {1,7,-5,9,-12,15};
    int arr[] = {4,6,3,-9,-5,1,3,0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, k=5;

    printf("Before rotation: \n");
    for(i=0;  i<n; i++)
	printf("%d ", arr[i]);
    printf("\n");

    left_rotate(arr, n, k);

    printf("After rotation: \n");
    for(i=0;  i<n; i++)
	printf("%d ", arr[i]);
    printf("\n");

    return 0;

}
