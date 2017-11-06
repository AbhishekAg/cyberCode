#include <stdio.h>
#include "header.h"

int main()
{
    double v1, v2, m, s;
    v1 = 5.2;
    v2 = 7.9;
    int i = 0;

    m  = mean(v1, v2);
    s = sum(v1, v2);

    printf("The mean of %3.2f and %3.2f is %3.2f\n", v1, v2, m);
    printf("The sum of %3.2f and %3.2f is %3.2f\n", v1, v2, s);

    /*while(1) {
	i = i+1;
    }
    i = i + 100;
    printf("i value=%d\n", i);*/

    return 0;
}
