/*
 * Given a number n, find all factors of number n
 */

#include<stdio.h>
#include<math.h>

#define NUM 100
#if 0
int factors(int n, int *A)
{
    int i, j=0;

    A[j++] = 1;

    if(n==1) {
	return j;
    }
    for(i=2; i<=n/2; i++) {
	if(n%i == 0) {
	    A[j++] = i;
	}
    }
    A[j++] = n;
    return j;
}
#endif
int factors(int n, int *A)
{
    int i, j=0,k=0;
    int B[NUM];

    for(i=1; i<=sqrt(n); i++) {
	if(n%i == 0) {
	    A[j++] = i;
	    if(i != sqrt(n))
		B[k++] = n/i;
	}
    }
    for(i=j;i<j+k;i++) {
	A[j++] = B[--k];
    }
    return j;
}

int main()
{
    int n, i, j;
    int A[NUM];
    printf("Input number: ");
    scanf("%d", &n);
    j = factors(n, A);
    printf("Factors of Number %d are: ", n);
    for(i=0;i<j; i++)
	printf("%d ", A[i]);
    printf("\n");

    return 0;
}
