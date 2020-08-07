#include <stdio.h>
#include <stdlib.h>

// declearing the functions
int abs_value(int x);
int manhattanDistance(int x1, int x2, int y1, int y2);

/*
main function allows our other functions, loops and our variables to work together
*/
int main()
{
	// variables that we use to calculate
	int size, cars;
	int opt_x = 0;
	int opt_y = 0;
	int check = 0;
	int alpha = 0;

	// checking if the size is valid or not
	do
	{
		printf("Size: ");
		scanf("%d", &size);
		if(size < 51 && size >0)
		{
			check = 1;
		}
		else
		{
			printf("Size must be between 50 and 1\n");
		}
	}
	while(check !=1);
	
	printf("Cars: ");
	scanf("%d", &cars);
	// zero car situation check
	if(cars == 0)
	{
		printf("Best Slot Found In: 1 1\n");
		return EXIT_SUCCESS;
	}
	// full slot situation
	else if(cars >= size * size)
	{
		printf("Best Slot Found In: 0 0\n");
		return EXIT_SUCCESS;
	}
	//creating parking lot array
	int slot[size][size];
	int w;
	for(w = 0; w<size;w++) 
	{
		int o;
		for(o=0; o<size; o++)
		{
			slot[w][o]=0;       // clearing the array
		}
	}
	int nearest_array [size][size];
	int q,t;
	for(q=0; q<size; q++)
	{
		for(t=0;t<size;t++)
		{
			nearest_array [q][t]= 1000;   // making arrays elements big enough
		}								  // because we need to find small values
	}    
	int x;
	for(x= 0; x<cars; x++)
	{
		printf("Locations: ");		  // entering the cars cordinates
		int x_cor, y_cor;
		scanf("%d %d", &x_cor, &y_cor);
		if(x_cor <= size && y_cor <= size && y_cor > 0 && x_cor > 0) // car cordinate validity check
		{
			slot[x_cor-1][y_cor-1] = 1;
			nearest_array[x_cor-1][y_cor-1] = 1;
		}

	}
	/* first two fors goes through arrays zeros, second for loops goes through arrays cars and finds manhattan distances
	*/
	int i;
	for(i = 0; i<size;i++)   
	{
		int j;
		for(j=0; j<size; j++)
		{
			if(slot[i][j] == 0)
			{
				
				int a;	
				for(a = 0; a<size; a++)
				{
					int b;
					for(b=0; b<size; b++)
					{
						if(slot[a][b] == 1)
						{
							alpha = manhattanDistance(i, a, j, b);
							
							if(nearest_array[i][j] > alpha)  // en kisa mesafeyi nearest array icine atiyoruz //
							{
								nearest_array[i][j] = alpha;
							}
						
						}

					}
				}
				
			}
			
		}
	}
	/*
	finding the optimal values for x and y with nearest value formula
	*/
	int max = 0;
	int c;
	for( c = 0; c<size; c++)  // x
	{
		int d;
		for(d=0; d<size; d++)   // y
		{
			if(nearest_array[c][d]>max)
			{
				max = nearest_array[c][d];
				opt_x = c;
				opt_y = d;
			}
			else if(nearest_array[c][d] == max)
			{
				if(c < opt_x)
				{
					opt_x = c;
					opt_y = d;
				}
				else if(c == opt_x && d < opt_y)
				{
				opt_x = c;
				opt_y = d;
					
				}
			}
		} 
	}
	
	printf("Best Slot Found In: %d %d\n", opt_x + 1, opt_y + 1);
	return EXIT_SUCCESS;
}

/*
1-purpose of this function is distance check
2-Function manhattanDistance calculates the distance between two cordinates 
by using the manhattan distance algorythm
3-@param x_1 is first slots  x value
4-@param x_2 is second slots  x value
5-@param y_1 is first slots  y value
6-@param y_2 is second slots  y value
*/
int manhattanDistance(int x_1, int x_2, int y_1, int y_2)
{
	int x_fark, y_fark;
	x_fark = abs_value(x_1 - x_2);
	y_fark = abs_value(y_1 - y_2);

	return x_fark + y_fark;
}

/*
1-Purpose of this fuction is calculating the absolute value without a library
2-Function abs_value, calculates the absolute value of the entered value
3-@param int x is the parameter of the function whose, absolute value is to be calculated
*/
int abs_value(int x)
{
	if(x < 0)
	{
		x = x * -1;
	}
	return x;
}


