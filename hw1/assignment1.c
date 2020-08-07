#include <stdio.h>
#include<stdlib.h>

int main()
{
	int year, month, day, end_year, check, i, y;
	int q, m, j, k, zeller_con;
	int temp = 0;
	
	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &month, &day);
	
	switch(month){ //checking first date
		case 1:
		case 2:
			q = day;
			k = (year-1)%100;
			j = ((year-1) - k)/100;
			m = month + 12;
			break;
		default:
			q = day;
			k = year%100;
			j = (year - k)/100;
			m = month;     
	}
	check = ((q+((13*(m+1))/5)+k+(k/4)+(j/4)+5*j)%7);

	if(month>12 || day>31 || day<1 || month<1 || (month==2 && day>28) || ((day==31) && (month==2|| month==4||month==6||month==9||month==11))){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("Enter end year: ");
		scanf("%d", &end_year);
		if(end_year < year)
		{
			printf("Invalid date.\n");
			return EXIT_FAILURE;
		}
		
		for(i= year; i<= end_year; i++){ //checking every year
		y = i;
		switch(month)
		{
			case 1:
			case 2:
				y--;
				q = day;
				k = y%100;
				j = (y - k)/100;
				m = month + 12;
				break;
			default:
				q = day;
				k = y%100;
				j = (y - k)/100;
				m = month;
		}
		zeller_con = ((q+((13*(m+1))/5)+k+(k/4)+(j/4)+5*j)%7);
		
			if(zeller_con==check)
			{
				temp++;
			}	
		}
		switch(check)
		{
			case 0:
				printf("It's a Saturday.\n");
				break;
			case 1:
				printf("It's a Sunday.\n");
				break;
			case 2:
				printf("It's a Monday.\n");
				break;
			case 3:
				printf("It's a Tuesday.\n");
				break;
			case 4:
				printf("It's a Wednesday.\n");
				break;
			case 5:
				printf("It's a Thursday.\n");
				break;
			case 6:
				printf("It's a Friday.\n");
				break;
		}
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n", year+1, end_year, temp-1);
	return EXIT_SUCCESS;
}
