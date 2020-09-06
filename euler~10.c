#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

bool sieve[2000000];

int main ()
{
	const size_t lenght =  2000000;
	size_t counter = 3;
	uint64_t sum = 2;  // speeding up with ignoring even numbers, adding two seperately

	for(size_t i = 0; i<lenght; i++) 
		sieve[i]= true;  //  __init__ 1 for every value

	while(counter <= lenght)
	{
		if(sieve[counter])
		{	
			sum += counter;
			for(size_t i = 2; counter * i < lenght; i++)
			{
				sieve[counter*i]= false;			//  if the number is prime, then multiples of it will be prime too	
			}									//  assignin FALSE to it's multiples 
		}
	counter+=2;		// iterating over odd's
	}
	printf("%" PRIu64 "\n", sum);
	return 0;
}

//0,0257706 sec