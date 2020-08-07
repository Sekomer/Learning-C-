#include <stdio.h>

int points_calculator(int num, char chr);
int count_down(char chr, int num, int target, int score, int first);

int main()
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
	return 0;
}
int count_down(char chr, int num, int target, int score, int first)
{	
	if(chr == 'D' && (target == first) )
	{
		target = target - score;
	}
	else if(target != first && score <= target)
	{
		switch(chr)
		{
			case 'O':
				target = target - 25;
				break;
			case 'I':
				target =  target - 50;
				break;
			case 'D':
				target = target -num*2;
				break;
			case 'T':
				target = target - num*3;
				break;
			case 'S':
				target = target - num;
				break;
		}		
	}
	return target;
}
int points_calculator(int num, char chr)
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
