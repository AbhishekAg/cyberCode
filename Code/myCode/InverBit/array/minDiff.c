/*
Given three sorted arrays A, B and C of not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

*/
#include <stdio.h>

int MAX(int a, int b, int c)
{
    if(a>=b && a>=c)
	return a;
    if(b>=a && b>=c)
	return b;
    if(c>=a && c>=b)
	return c;
}

int MIN(int a, int b, int c)
{
    if(a<=b && a<=c)
	return a;
    if(b<=a && b<=c)
	return b;
    if(c<=a && c<=b)
	return c;
}

int solve(int* A, int n1, int* B, int n2, int* C, int n3)
{
    int a = A[n1-1]; //Storing the highest element
    int b = B[n2-1];
    int c = C[n3-1];

    int i,j,k;
    int result = 0;
    int minR = 0;

    i = n1-2;
    j = n2-2;
    k = n3-2;

    minR = result = abs(MAX(a,b,c) - MIN(a,b,c));
    while(1) {
	if(a>=b && a>=c && i>=0) {
	    a = A[i--];
	    result = abs(MAX(a,b,c) - MIN(a,b,c));
	    minR = result<minR?result:minR;
	    continue;
	}
	else if(b>=a && b>=c && j>=0) {
	    b = B[j--];
	    result = abs(MAX(a,b,c) - MIN(a,b,c));
	    minR = result<minR?result:minR;
	    continue;
	}
	else if(c>=a && c>=b && k>=0) {
	    c = C[k--];
	    result = abs(MAX(a,b,c) - MIN(a,b,c));
	    minR = result<minR?result:minR;
	    continue;
	}
	return minR;
    }
}

int main()
{
    int A[] = {1, 4, 5, 8, 10};
    int B[] = {6, 9, 15};
    int C[] = {2, 3, 6, 6};

    int result = solve(A, sizeof(A)/sizeof(int),
          B, sizeof(B)/sizeof(int),
	  C, sizeof(C)/sizeof(int));

    printf("Diff: %d\n", result);
    return 0;
}
