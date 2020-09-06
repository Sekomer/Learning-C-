#include <stdio.h>

int main()
{
	int a = 1;
	int b = 1;
	int temp;
	long sum = 0;
	
	while(a < 4000000)
	{
		temp = a;
		a = a + b;
		b = temp;
		
		if(!(a & 1))
		{
			sum += a;
			printf("%d\n", a);
		}
		
	}		

	printf("%ld", sum);
	return 0;
}

