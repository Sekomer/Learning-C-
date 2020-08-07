#include<stdio.h>
# define TRUE 1
# define FALSE 0

#define LIMIT 2000000

int prime(int num);

int main()
{
	int i;
	long sum = 2;
	for(i = 3; i < LIMIT; i += 2)
		sum += prime(i);
	
	printf("%ld\n", sum);
}

int prime(int num){
	int i; 
	for(i = 3; i*i <= num; i += 2)
		if(num % i == 0)
			return FALSE; // checking number is prime or not

	return num;
}
