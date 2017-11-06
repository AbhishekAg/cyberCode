#include <stdio.h>

#define NUM 8

#define SWAP(a, b) { \
        int tmp = a; \
	a = b; \
	b = tmp; \
}

#define PRINT_ARR(A) {\
    for(i=0; i<NUM; i++) \
	printf("%d ", A[i]); \
    printf("\n");\
}

#define COPY_ARR(A, B) {\
    for(i=0; i<NUM; i++) \
	B[i] = A[i];\
}

void
selectionSort(int *A, int n)
{
    int i,j,imin;
    printf("Selection Sort: ");

    for(i=0; i<n-1; i++) {
	imin = i;
	for(j=i+1; j<n; j++) {
	    if(A[j] < A[imin])
		imin = j;
	}
	SWAP(A[i], A[imin]);
    }
}

void
bubbleSort(int *A, int n)
{
    int i,j,flag;
    printf("Bubble Sort: ");

    for(i=1; i<n; i++) {
	flag = 0;
	for(j=0; j<n-i; j++) {
	    if(A[j] > A[j+1]) {
		SWAP(A[j], A[j+1]);
		flag=1;
	    }
	}
	if(flag == 0)
	    break;
    }
}

void
insertionSort(int *A, int n)
{
    int i,hole,value;
    printf("Insertion Sort: ");

    for(i=1; i<n; i++) {
	value = A[i];
	hole = i;
	while(hole > 0 && A[hole-1] > value) {
	    A[hole] = A[hole-1];
	    hole = hole-1;
	}
	A[hole] = value;
    }
}
void merge(int *A, int start, int mid, int end)
{
    int p=start; int q=mid+1; int i;
    int Arr[end - start + 1];
    int k=0;
    for(i=start; i<=end; i++) {
	if(p>mid)
	    Arr[k++] = A[q++];
	else if(q>end)
	    Arr[k++] = A[p++];
	else if(A[p] < A[q])
	    Arr[k++] = A[p++];
	else
	    Arr[k++] = A[q++];
    }
    for(p=0; p<k; p++)
	A[start++] = Arr[p];
    return;
}

void
mergeSort(int *A, int start, int end)
{
    if(start < end) {
	int mid = (start+end)/2;
	mergeSort(A, start, mid);
	mergeSort(A, mid+1, end);
	merge(A, start, mid, end);
    }
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

int binarySearch(int *A, int n, int x)
{
    int low, high, mid;
    low = 0 ;
    high = n -1;
    mid = low + (high-low)/2;

    if(A[mid] == x) {
	return mid;
    } else if(A[mid] > x) {
	high = mid-1;
    } else if (A[mid] < x) {
	low = mid+1;
    }
}

int main()
{
    //int A[] = {2,7,4,1,5,3};
    int A[] = {7,2,1,6,8,5,3,4};
    int B[NUM];
    int i;

    COPY_ARR(A, B); //Make a backup

    PRINT_ARR(A);
    selectionSort(A, NUM);
    PRINT_ARR(A);

    COPY_ARR(B, A); //Restore 

    PRINT_ARR(A);
    bubbleSort(A, NUM);
    PRINT_ARR(A);

    COPY_ARR(B, A); //Restore 

    PRINT_ARR(A);
    insertionSort(A, NUM);
    PRINT_ARR(A);

    COPY_ARR(B, A); //Restore 

    PRINT_ARR(A);
    printf("Merge Sort: ");
    mergeSort(A, 0, NUM-1);
    PRINT_ARR(A);

    COPY_ARR(B, A); //Restore 

    PRINT_ARR(A);
    printf("Quick Sort: ");
    quickSort(A, 0, NUM-1);
    PRINT_ARR(A);

    i = binarySearch(A, NUM, 5);
    printf("Element 5 is at index %d\n", i);
    return 0;
}
