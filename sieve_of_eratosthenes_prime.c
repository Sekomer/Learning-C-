#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieve(int, int*, int**);

int main()
{
	int size, input; 
	int *a;

	printf("Enter sieve limit (inclusive): ");
	scanf("%d", &input);
	
	sieve(input, &size, &a);
	for(int i = 0; i < size; i++)
		printf("%d\n", a[i]);

return 0;
}

void sieve(int range, int* size, int** primes)
{

	bool array[range + 1];
	for(int i = 3; i <= range; i += 2)
		array[i] = true;
	
	int counter = 1;
	for(int j = 3; j <= range; j +=2)
		if(array[j]){
			counter++;
			for(int k = 2*j; k <= range; k += j)
				array[k] = false;
		}

	*size = counter;
	int* p = malloc((counter) * sizeof(int));
	int counter_2 = 0;
	p[counter_2++] = 2;
	for(int i = 3;i <= range; i += 2)
		if(array[i])
			p[counter_2++] = i;

	*primes = p;
}


