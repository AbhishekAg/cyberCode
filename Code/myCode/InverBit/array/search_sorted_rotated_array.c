/* Search an element in a sorted and rotated array */

#include <stdio.h>


int search(int *arr, int n, int key)
{
    int pivot = find_pivot(arr, n);

}

int main()
{
    int arr[] = {4,5,6,7,8,9,1,2,3}

    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    search(arr, n, key);


    return 0;

}
