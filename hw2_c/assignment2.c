#include <stdio.h>
#include <stdlib.h>

int points_calculator(int num, char chr);  //declearing our functions
int count_down(char chr, int num, int target, int score, int first); // chr is segment value, num is area value, target is our remaining points
                                                                     // score is value of our shot, first is our starting point for comparing the first shot
int main() // main function that manages other functions
{
    int target, score, num, first; 
    char chr;
    printf("Target: ");
    scanf("%d", &target);
    first = target;
    while (target > 0)
    {
        printf("Throw: ");
        scanf("%d %c", &num, &chr); 
        score = points_calculator(num, chr);
        target = count_down(chr, num, target, score, first);
        printf("Points: %d\n", target);
    }
    return EXIT_SUCCESS;
}
int count_down(char chr, int num, int target, int score, int first)  // countdown function that takes parameters and evaluates remaining points
{   
    if(chr == 'D' && (target == first) )
    {
        target = target - score;
    }
    else if(target != first)
    {
        if(target - score >=2)
        {
            target = target - score;    
        }
        else if(target - score == 0 && chr == 'D')
        {
            target = target - score;
        }   
    }
    return target;
}
int points_calculator(int num, char chr) // calculating the shot value for every shot
{
    int temp;
    switch(chr)
    {
        case 'O':
            temp = 25;
            break;
        case 'I':
            temp = 50;
            break;
        case 'D':
            temp = num*2;
            break;
        case 'T':
            temp = num*3;
            break;
        case 'S':
            temp = num;
            break;  
    }
    return temp;
}
