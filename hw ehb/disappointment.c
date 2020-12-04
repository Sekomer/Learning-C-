# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/* Forward declaration of functions*/ 
static void roll_dice(int* , int , int);
static void fill_plotter_array(int* , int* ,int );
static void console_plot(int*, int);
static int array_max(int*, int );

/* Preprocessors */
#define ONE_DICE 6
#define TWO_DICES 11


int 
main(int argc, char** argv)
{
    /* Some variables for easy coding */
    int one_dice_num_out = 6;
    int two_dice_num_out = 11;
    int num_rolls = 100000;

    /* Random seed for different outputs */
    srand( time(0) );

    /* Initializing our rough arrays */
    int first_outcome[6];
    int second_outcome[11];

    /* Initializing our probabilty plot arrays */
    int first_plotter[6];
    int second_plotter[11];

    /*  rolling dices and calculating number of occurence */
    roll_dice(first_outcome, one_dice_num_out, num_rolls);
    roll_dice(second_outcome, two_dice_num_out, num_rolls);
    
    /* filling probability arrays */
    fill_plotter_array(first_outcome, first_plotter, one_dice_num_out);
    fill_plotter_array(second_outcome, second_plotter, two_dice_num_out);

    /* stdout plots */
    console_plot(first_plotter, one_dice_num_out);
    console_plot(second_plotter, two_dice_num_out);


return EXIT_SUCCESS;
}

/*
    Function that returns maximum element from given array
    @param array : array that we choose its maximum
    @param size : sizeof "array"
*/
static int 
array_max(int* array, int size)
{
    int max = 0;
    
    for (int i = 0; i < size; ++i)
    {
        max = (array[i] > max ? array[i] : max); 
    }

    return max;
}


/* reference link:
https://stackoverflow.com/a/44426234/12688015

    Function to print the graphs of CLT states to the terminal
    @param plt_arr : array that will be printed
    @param size : sizeof "array"
*/
static void 
console_plot(int* plt_arr, int size) {

	int edge = array_max(plt_arr, size);

    char* dice_number = (size == ONE_DICE ? "One" : "Two");
    char* plural = (size == ONE_DICE ? "" : "s");

    printf("\nCLT Results with %s Dice%s: \n\n", dice_number, plural);

      /* iterating over rows */
	for (int i = edge - 1; i >= 0; i--) 
    { 
        /* iterating over columns */
		for (int j = 0; j < size; j++) 
        { 
            /* two digit numbers alligns more space, so we should fix their output */
            char* assigner = (j >= 8 ? " " : "");

			if (plt_arr[j] >= i) 
                printf("*%s ", assigner); 
            
			else 
                printf("  ");
		}    
            printf("\n");
		
        /* after data rows, print out the dice states */
        if (i == 0) 
        { 
            /*  switch statement to choose output formation */
            switch (size)
            {
                case 6:
                    for (int x = 0; x < size; x++)
                        printf("%d ", x + 1);
                    break;
                
                case 11:
                    for (int x = 2; x <= size +1; x++)
                        printf("%d ", x);
                    break;
            }
			printf("\n\n");
        }
	}
}


/*
    Function that rolls dices, it's array / size / rolls dependent, reusable in different situations with it's easy API
    @param arr : array that we fill with rough data
    @param size : array's size
    @int rolls : number of, rolls / iterations
*/
static void 
roll_dice(int* arr, int size, int rolls)
{
    int total = 0;

    /* first clear array */
    for (int i = 0; i < size; i++)
        arr[i] = 0;
   
    /*  roll dice, incresing corresponding value in the array */
    for (int i = 0 ; i < rolls; i++)
    {
        total = 0;

    /* result of one dice  */
        if (size == ONE_DICE)
            total = (rand() % 6);

    /* result of two dices  */
        else if (size == TWO_DICES)
            total = (rand() % 6) + (rand() % 6);

        arr[total]++;
    }
}


/*
    Function that fills plot arrays, it's array / plot_array / size dependent, reusable in different situations with it's easy API
    @param arr : array that we are reading
    @param plt_arr : array that we are going to fill
    @param sides : size of array
*/
static void 
fill_plotter_array(int* arr, int* plt_arr, int sides)
{   
    /*  for making one dice plot smaller */
    int divider = (sides == ONE_DICE ? 3000 : 1000);

    /* scaling our data */
    for (int i = 0; i < sides; ++i)
        plt_arr[i] = arr[i] / divider;
}