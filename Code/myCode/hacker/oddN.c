#include<stdio.h>
#include <stdlib.h>

void oddN(int l, int r) {
    int arr[100] = {0};
    int ind=0,i,first;

    if(l%2 !=0) {
	arr[ind++] = l;
	first = l;
    } else {
	arr[ind++] = l+1;
	first = l+1;
    }
    for(i=first+2; i<r; i=i+2) {
	arr[ind++] = i;
    }
    if(r%2 !=0)
	arr[ind++] = r;

    for(i=0; i<ind; i++)
	printf("%d ", arr[i]);
    printf("\n");
    return;
}


int main()
{
    int l,r;
    oddN(2,110);;
    return 0;
}
