/*
 Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
 If such an integer is found return 1 else return -1.
 */

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) { \
        int tmp = a; \
	a = b; \
	b = tmp; \
}

int partition(int *A, int start, int end)
{
    int pivot = A[end];
    int pIndex = start;
    int i;
    for(i=start; i<end; i++) {
	if(A[i] <= pivot) {
	    SWAP(A[i], A[pIndex]);
	    pIndex++;
	}
    }
    SWAP(A[pIndex], A[end]);
    return pIndex;
}

void
quickSort(int *A, int start, int end)
{
    int pIndex;
    if(start < end) {
	pIndex = partition(A, start, end);
	quickSort(A, start, pIndex-1);
	quickSort(A, pIndex+1, end);
    }
}

int findingP(int *A, int n)
{
    int i;

    quickSort(A, 0, n-1);
    for(i=0; i<n; i++)
	printf("%d ", A[i]);
    printf("\n");

    for(i=0; i<n-1; i++) {
	if((A[i] < A[i+1]) && ((A[i]) == (n-1)-i)) {
	    return 1;
	}
    }
    if(A[i] == 0)
	return 1;
    return -1;
}

int main()
{
    //int A[] = {7,2,1,6,8,5,3,4};
    int A[] = {-4,-2,0,-1,-6};
    //int A[] = {-6,-1,4};
    //int A[] = {-4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5};

    printf("num: %d Found: %d\n", sizeof(A)/sizeof(int), findingP(A, sizeof(A)/sizeof(int)));
    
    return 0;
}
