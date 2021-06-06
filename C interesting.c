#include <stdio.h>

int add(x, y)
    int x, y;
{
	return x + y;
}

int main()
{
	int wow = add(3,9,6);
	printf("%d\n", wow);
}