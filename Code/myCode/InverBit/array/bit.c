#include <stdio.h>

int main()
{
    int x;
    while(1) {
	printf("Input X: ");
	scanf("%d", &x);

	printf("Value: %d", x & (x-1));
    }

}
