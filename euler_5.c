#include <stdio.h>

long common_divisor(long , long);   // declaring function

// I used long numbers to prevent Integer Overflow
int main()
{	
	long num = 1, divide;

	for(int i = 2; i <= 20; i++)  
		{
			divide =  common_divisor(num, i);  // finding common divisors of the numbers, 
			num *= (i/divide); 				   // if there is, divide i to the common part then mulitply with num 
		}

	printf("%ld\n", num);
	// 232792560
	return 0;
}

long common_divisor(long num, long num2)
{
	long com = 1;
	
	for(int x = 2; x <= num2; x++)
	{
		while(num%x==0 && num2%x==0)  // while there are common divisors, continue dividing
		{
			num/= x; num2/=x;		// don't forget to divide numbers cuz we don't want to divide twice some numbers
			com *= x;				//( and also it will crush cuz there will be endless loop )
		} 							// exp = (28 ==> 2,2,7) otherwise (2,4,14,28 )
	}
	
	return com;						// returning common part
}