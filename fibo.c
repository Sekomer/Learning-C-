#include <stdio.h>

int main(){
	
	int a, b = 1;
	int element = 1; 
	int i;
	int sum = 0;

	printf("kacinci fibonacci sayisina ulasmaya calisiyorsunuz ?\n");
	scanf("%d", &element);
	
	for(i = 1; i < element; i++){
		sum = a + b;
		a = b;
		b = sum;
		
	}	
		if(element == 1 || element == 2){

		printf("%d. sayi %d dir\n",element , 1);

	}
		else{
	
		printf("%d. element %d'dir'\n", element, sum);

    }
	return 0;
}
	


