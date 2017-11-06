#include <stdio.h>

void printSpiral(int m, int n, int A[][n])
{
    int T,B,L,R,dir;
    T=0; B=m-1; L=0; R=n-1;
    dir=0;
    int i=0;
    while(T<=B && L<=R) {
	if(dir == 0) {
	    for(i=L;i<=R;i++)
		printf("%d ", A[T][i]);
	    T++; dir=1;
	} else if(dir==1) {
	    for(i=T;i<=B;i++)
		printf("%d ", A[i][R]);
	    R--; dir=2;
	} else if(dir==2) {
	    for(i=R;i>=L;i--)
		printf("%d ", A[B][i]);
	    B--; dir=3;
	} else if(dir==3) {
	    for(i=B;i>=T;i--)
		printf("%d ", A[i][L]);
	    L++; dir=0;
	}
    }
}

int main()
{
    /*int A[][3] = {{1,2,3},
                 {4,5,6},
		 {7,8,9}};*/
    int A[][4] = {{1,2,3,4},
                  {5,6,7,8},
		  {9,10,11,12},
		  {13,14,15,16}};
    printSpiral(4, 4, A);
    printf("\n");
    return 0;
}

#if 0
int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
    *length_of_array = n11 * n12; // length of result array
    int *result = (int *) malloc(*length_of_array * sizeof(int));
    int T,B,L,R,dir;
    T=0; B=n11-1; L=0; R=n12-1;
    dir=0;
    int i=0, j=0;
    while(T<=B && L<=R) {
	if(dir == 0) {
	    for(i=L;i<=R;i++)
		result[j++] = A[T][i];
	    T++; dir=1;
	} else if(dir==1) {
	    for(i=T;i<=B;i++)
		result[j++] = A[i][R];
	    R--; dir=2;
	} else if(dir==2) {
	    for(i=R;i>=L;i--)
		result[j++] = A[B][i];
	    B--; dir=3;
	} else if(dir==3) {
	    for(i=B;i>=T;i--)
		result[j++] = A[i][L];
	    L++; dir=0;
	}
    }   

    return result;
}
#endif
