#include<stdio.h>

int binarySearch(int *A, int n, int x, int search)
{
    int low, high, mid, result=-1;
    low = 0 ;
    high = n -1;

    while(low<=high) {
	mid = low + (high-low)/2;
	if(A[mid] == x) {
	    result = mid;
	    if(search) { //Right
		low = mid+1;
	    } else { //Left
		high = mid-1;
	    }

	} else if(A[mid] > x) {
	    high = mid-1;
	} else if (A[mid] < x) {
	    low = mid+1;
	}
    }
    return result;
}

int countN(int *A, int n1, int B)
{
    int a1, a2;

    a1 = binarySearch(A, n1, B, 0);
    if(a1!=-1) {
	a2 = binarySearch(A, n1, B, 1);
        return a2-a1+1;
    }
    return 0;
}

int main()
{
    //int A[] = {5,7,7,8,8,10};
    int A[] = {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10 };

    int n, B;

    printf("Input number: ");
    scanf("%d", &B);

    n = countN(A, sizeof(A)/sizeof(int), B);
    printf("Number: %d\n", n);

    return 0;
}
