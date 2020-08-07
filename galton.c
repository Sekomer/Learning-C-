
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void galton(int size, int shots);
int main()
{
	srand(time(NULL));
	galton(10,1000);


	return 0;
}

void galton(int size, int shots)
{

	int* array[size];
	
	for(int i= 0; i<size; i++)
	{
		int mem = (i+1) * sizeof(int);
		array[i] = malloc(mem);
	}

	for(int n = 0; n < shots; n++)
	{
		array[0][0]++;
		int j = 0;
		for(int i = 1; i < size; i++)
		{
			if(rand() % 2) 
				j++;
			
			array[i][j]++;
		}
	}

	for(int i=0; i < size; i++)
	{
		for(int j=0; j<=i; j++)
			printf("%5d", array[i][j]);
		
		printf("\n");
	}
}


























































