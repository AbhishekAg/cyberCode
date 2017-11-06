#include <stdio.h>

int gcd(int a, int b)
{
    if(b==0)
	return a;
    else
	return gcd(b, a%b);
}

int main()
{
    int a,b,n;

    while(1) {
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
        n = gcd(a,b);
        printf("GCD of %d and %d is = %d\n", a, b, n);
    }
    return 0;
}
