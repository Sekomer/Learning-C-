
#include <stdio.h>

int main()
{
	long sum_square = 0;
	long square_sum = 0;
	int i = 1;
	for( ; i <= 100; )
	{	
		sum_square += i*i;		// sum of squares
		square_sum += i;		// sum of numbers that we are gonna square
		i++;
	}
	long result = square_sum * square_sum - sum_square;    // square of sum of nums minus sum of all numbers square

	printf("%ld\n", result);
	// 25164150
	return 0;
}