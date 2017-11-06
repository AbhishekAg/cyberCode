#include <stdio.h>
#include <stdlib.h>


#define INT_MIN  -21782959
#define INT_MAX  21782959

int heap_size = 0;
int capacity;
int harr[100] = {0};

void SWAP(int *x, int *y)
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

int getMin()
{
    return harr[0];
}

void insertKey(int a)
{
    if(heap_size == capacity) {
	printf("FULL\n");
    }
    int i = heap_size;
    heap_size++;
    harr[i] = a;

    while(i!=0 && harr[parent(i)] > harr[i]) {
	SWAP(&harr[parent(i)], &harr[i]);
	i = parent(i);
    }
}

void changeKey(int i, int a)
{
    harr[i] = a;
    while(i!=0 && harr[parent(i)] > harr[i]) {
	SWAP(&harr[parent(i)], &harr[i]);
	i = parent(i);
    }
}

void minHeapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if(l<heap_size && harr[smallest] > harr[l])
	smallest = l;
    if(r<heap_size && harr[smallest] > harr[r])
	smallest = r;

    if(smallest != i) {
	SWAP(&harr[i], &harr[smallest]);
	minHeapify(smallest);
    }
}

/* Remove the min(root) and adjust the heap */
int extractMin()
{
    if(heap_size <=0) //No elements
	return INT_MAX;
    if(heap_size == 1) {
	heap_size--;
	return harr[0];
    }

    int root = harr[0]; //Min element
    harr[0] = harr[heap_size-1]; //Copy last element to first
    heap_size--;
    minHeapify(0); //Adjust the heap from 0 location to retain the min heap property
    return root;
}

int deleteKey(int i)
{
    int val = harr[i]; //Value to be deleted
    changeKey(i, INT_MIN); //Will update the value with MIN value
    extractMin();
}

int main()
{
    //int A[] = {10,2,5,7,0,18,31,8,16,69};
    int A[] = {10,2,5,7,0,4,31,8,16,69};
    int i;

    printf("Min Heap implementation\n");
    capacity = 100;

    for(i=0; i<sizeof(A)/sizeof(int); i++) {
	insertKey(A[i]);
    }
    for(i=0; i<sizeof(A)/sizeof(int); i++) {
	printf("ExtractMin: %d\n", extractMin());
    }
    return 0;

}
