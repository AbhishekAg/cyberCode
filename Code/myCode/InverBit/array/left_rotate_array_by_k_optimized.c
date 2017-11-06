#include <stdio.h>

/* function to print an array */
void printArray(int arr[], int size);

/*Fuction to get gcd of a and b*/
int gcd(int a,int b);

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    int i, j, k, temp;
    for (i = 0; i < gcd(n, d); i++)
    {
	/* move i-th values of blocks */
	temp = arr[i];
	j = i;
	while(1)
	{
	    k = j + d;
	    if (k >= n)
		k = k - n;
	    if (k == i)
		break;
	    arr[j] = arr[k];
	    j = k;
	}
	arr[j] = temp;
    }
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
	printf("%d ", arr[i]);
    printf("\n");
}

/*Fuction to get gcd of a and b*/
int gcd(int a,int b)
{
    if(b==0)
	return a;
    else
	return gcd(b, a%b);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printArray(arr, 7);
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}