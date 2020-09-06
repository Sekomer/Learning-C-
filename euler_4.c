#include <stdio.h>
#include <stdbool.h>

bool ispalindrome(int );

int main() 
{
	int max = 0;
	for(int i = 999; i>100; i--)
	{
		for(int j = 999; j>100; j--)
		{
			bool check = ispalindrome(i * j);
			if(check && ((i * j) > max))
			{
				max = i * j;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}


bool ispalindrome(int num)
{
	int remainder, original = num, reversed = 0;
	while(num!=0)
	{
		remainder = num % 10;
		reversed = reversed*10 + remainder;
		num /= 10;
	}
	
	if(original == reversed)
	{
		return 1;
	}

	return 0;
}