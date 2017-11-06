#include <stdio.h>

#define MAX_PFE 4

int main()
{
    int i=0;
    int arr[MAX_PFE] = {0};
    int arr2[MAX_PFE] = {[0 ... MAX_PFE-3] = 0,2,3};

    for(i=0; i<MAX_PFE; i++) {
	printf("arr[%d]=%d\n",i,arr[i]);
	printf("arr2[%d]=%d\n",i,arr2[i]);
    }
    return 0;
}
