#include <stdio.h>

int main()
{
	long long number = 600851475143;

	for(int i=3; i*i<600851475143; i+=2)
	{
		if(number == i)
		{
			printf("%lld\n", number);
			break;
		}

		if(number % i == 0)
		{
			number /= i;
		}
	}
	return 0;
}

