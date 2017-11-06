#include <stdio.h>
#include <math.h>

int floorx(float fn)
{
    int n;

    n = (int)(fn+0.5);

    return n;
}

long long int Xsqrt(long long int A)
{
    long long int low, high, mid, ans=0;

    if(A == 0 || A == 1)
	return A;

    low = 0;
    high = A/2;

    while(low<=high) {
        mid = low + (high-low)/2;
	if(mid*mid == A)
            return mid;
	else if(mid*mid < A) {
	    low = mid+1;
	    ans = mid;
	}
	else if(mid*mid > A)
	    high = mid-1;
    }
    return ans;
}

int main()
{
    float fn;
    long long int n, A;
#if 0
    printf("Input float number: ");
    scanf("%f", &fn);
    n = floorx(fn);
    printf("Floor of %f is %d\n", fn, n);
#endif

    printf("Input number: ");
    scanf("%lld", &A);
    n = Xsqrt(A);
    printf("Sqrt of %lld is %lld\n", A, n);
    return 0;
}
