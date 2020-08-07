#include <stdio.h>
//You cannot use the string library 

#define MAX_STRING_SIZE 20


void append(char* a, char* b)
{
  //fill the function body. Do not change the arguments and the return parameter
 	int count = 0;
  	char c[21];
  	int c_ptr = 0;
  	char* ptr = a;
 	while(*ptr != '\0'){
		c[c_ptr++] = *ptr++;
		if (++count == 20)
		{
			printf("Error");
		return;  
		}
  	}
  	c[c_ptr++] =' ';
	if (++count == 20)
	{
		printf("Error");
		return;  
	}

	ptr = b;
	while(*ptr != '\0')
  	{
	c[c_ptr++] = *ptr++;
		if (++count == 20)
		{
		printf("Error");
		return;  
		}
  	}
  	c[c_ptr++] ='\0';
  	a = c;


  	printf("%s\n", a);

  return;
}

int main()
{
	char a[MAX_STRING_SIZE];
	char b[MAX_STRING_SIZE];
	scanf("%s",a);
	scanf("%s",b);
	append(a,b);
	return 0;
}
