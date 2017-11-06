#include <stdio.h>

static int bar = 0;

int func_a()
{
    static int var;
    printf("In function A. var=%d, bar=%d\n", var, bar);
    var+=5;
    printf("%d\n", var);
    return 0;
}

int func_b()
{
    static int var = 30;
    printf("In function B. var=%d, bar=%d\n", var, bar);
    var+=5;
    printf("%d\n", var);
    return 0;
}

int main()
{
    printf("In main\n");
    func_a();
    func_b();
    return 0;
}
