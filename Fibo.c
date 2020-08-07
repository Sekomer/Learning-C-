#include <stdio.h>

int main()
{
	int i, n, t1 = 0, t2 = 1, nextTerm;
	printf("Enter the number of terms you want to calculate: ");
	scanf("%d", &n);
	printf("Fibonacci Series:\n");
	for (i = 1; i <= n; ++i)
	{
		nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;
		printf("%dth Fibonacci Number is %d \n", i, t1);
	}
	return 0;
}