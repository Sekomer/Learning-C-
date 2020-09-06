#include <stdio.h>

// a^2 + b^2 = c^2
// we can easily see 'a' and 'b' cant be over 'c/2'

int main ()
{	
	for (int i = 1; i < 1000/2; i++)  // interating over a
	{
		for (int j = i; j < 1000/2; j++)	// interating over b
		{
			int c = 1000 - (i + j); 
			// checking Pythagorean theorem
			(i*i + j*j == c*c) ? printf ("%d\n", i*j*c) : 1;
		}
	}
	return 0;
}
