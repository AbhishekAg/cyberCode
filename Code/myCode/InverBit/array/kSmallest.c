#include <stdio.h>
#include <stdlib.h>

int *harr;
int heap_size=0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*i + 2;
}

int getMax()
{
    return harr[0];
}

/* A recursive method to heapify a subtree with root at given index
   This method assumes that the subtrees are already heapified
*/
void maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
	largest = l;
    if (r < heap_size && harr[r] > harr[largest])
	largest = r;
    if (largest != i)
    {
	swap(&harr[i], &harr[largest]);
	maxHeapify(largest);
    }
}

maxHeapOfK(int *A, int size)
{
    heap_size = size;
    harr = A;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
	maxHeapify(i);
	i--;
    }
}

void replaceMax(int x) 
{
    harr[0] = x;
    maxHeapify(0);
}

/* Create MAX heap of k elements */
int kthSmallestElement(int *A, int n, int k)
{
    int i;
    maxHeapOfK(A, k);

    for (i=k; i<n; i++)
	if (A[i] < getMax())
	    replaceMax(A[i]);

    return getMax();
}

int main()
{
    int A[] = {10,1,0,9,8,6,2,7,20};
    int k=0, val;

    printf("Input kth: ");
    scanf("%d", &k);

    if(k==0 || k>(sizeof(A)/sizeof(int))) {
	printf("Error\n");
	return 0;
    }

    val = kthSmallestElement(A, sizeof(A)/sizeof(int), k);
    printf("Kth Smallest element is: %d\n", val);
    return 0;
}
