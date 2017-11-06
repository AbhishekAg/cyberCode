#include <stdio.h>

void func(int var)
{
    if(var>30)
	return;

    int local = 20;
    printf("Var: %d, address: %p\n", var, &local);
    func(var+10);
    return;
}

int main()
{
    func(10);
    printf("In main\n");
    return 0;
}
