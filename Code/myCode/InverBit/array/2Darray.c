#include <stdio.h>
#include <stdlib.h>

#if 0
int ** allocateArray(int r, int c)
{
    int i;
    int **arr = (int **)malloc(r *sizeof(int *));

    for(i=0; i<r; i++) {
	arr[i] = (int *)malloc(c *sizeof(int));
    }

    return arr;
}

void fillArray(int **arr, int r, int c)
{
    int i,j;

    for(i=0; i<r; i++) {
	for(j=0; j<c; j++) {
	    arr[i][j] = i;
	}
    }
}
#endif
void printArray(int **arr, int r, int c)
{
    int i,j;

    for(i=0; i<r; i++) {
	for(j=0; j<c; j++) {
	    printf("%d ", arr[i][j]);
	}
	printf("\n");
    }
}

void deleteArray(int **arr, int r, int c)
{
    int i;
    for(i=0; i<r; i++) {
	free(arr[i]);
    }
    free(arr);
}

int **prettyPrint(int A, int *numR, int *numC)
{
    int i,j,dir,r,c;
    int **arr;
    int T,R, L,B;

    if(!A) {
	*numR=0; *numC=0;
	return NULL;
    }

    if(A==1) {
	r = c =1;
    } else {
        r = c = A+(A-1);
    }
    *numR = r; *numC = c;

    arr = (int **)malloc(r *sizeof(int *));
    for(i=0; i<r; i++) {
	arr[i] = (int *)malloc(c *sizeof(int));
    }

    dir=0;
    T=0; B=r-1; L=0; R=c-1;

    while(T<=B && L<=R) {
	if(dir==0) {
	    for(i=L; i<=R; i++)
		arr[T][i] = A;
	    dir=1;T++;
	} else if(dir==1) {
	    for(i=T; i<=B; i++)
		arr[i][R] = A;
	    dir=2; R--;
	} else if(dir==2) {
	    for(i=R; i>=L; i--)
		arr[B][i] = A;
	    dir=3; B--;
	} else if(dir==3) {
	    for(i=B; i>=T; i--)
		arr[i][L] = A;
	    dir=0; L++; A = A-1;
	}
    }
    return arr;
}


int main()
{
    //int r,c;
    int **arr;
    int A, numR=0, numC=0;
    int i,j;

#if 0
    printf("Input rows and columns: ");
    scanf("%d %d", &r, &c);

    arr = allocateArray(r, c);
    fillArray(arr, r, c);
    printArray(arr, r, c);
    deleteArray(arr, r, c);
#endif
    printf("Input number: ");
    scanf("%d", &A);
    arr = prettyPrint(A, &numR, &numC);
    printArray(arr, numR, numC);
    deleteArray(arr, numR, numC);

    return 0;
}
