// What is the 10 001st prime number?
// 104743
// it took 0,0127824 seconds to calculate   ==> powershell>> Measure-Command{.\exe7.exe}

#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

bool is_prime(long);    // function decleration

long i = 6;
int prime_counter = 2; // including 2 and 3

int main()
{
	for( ; prime_counter < 10001; ) 
	{
		if(is_prime(i-1)) 
		{	
			prime_counter++;  
			if(prime_counter == 10001){printf("%d\n", i-1);}
		}

		if(is_prime(i+1)) 
		{	
			prime_counter++;
			if(prime_counter == 10001){printf("%d\n", i+1);}		
		}
		i+=6;
	}
	return 0;
}

bool is_prime(long num)
{
	for(int x = 3; (x*x) <= num; x+=2)  // we don't have to check even numbers because we are using 6*k (+-)1 method
	{
		if(num % x == 0)
		{
			return FALSE;
		}
	}

	return TRUE;   // if it is not returning false, then its prime
}