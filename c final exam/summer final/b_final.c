#include <stdio.h>
#include <stdlib.h>

typedef struct sizedstr_s sizedstr_t;

struct sizedstr_s{
    char *content;
    int length;
};


sizedstr_t new_sizedstr(char s[])
{
	int len = 0;
	for(int i = 0 ; s[i] != '\0';i++)
	{
		len++;
	}
	char *sized_string = (char*) malloc(len * sizeof(char));
	for(int j = 0; s[j] != '\0'; j++)
	{
		sized_string[j] =s[j];
	}

    sizedstr_t x = { sized_string, len};
    return x;
}

void print_sizedstr(const sizedstr_t x)
{
	printf("%s",x.content);
}

int sizedstr_len(const sizedstr_t x)
{
	
    return x.length;
}

sizedstr_t sizedstr_cat(const sizedstr_t x1, const sizedstr_t x2)
{
	char *str =  (char*) malloc((x1.length + x2.length)* sizeof(char));
	for(int i=0; i < x1.length ; i++){
    str[i] = x1.content[i];
	}
	for(int j=x1.length ; j < x1.length + x2.length ; j++){
    str[j] = x2.content[ j - x1.length];
	}
    sizedstr_t x = { str, x1.length + x2.length};
    return x;
}

int sizedstr_cmp(const sizedstr_t x1, const sizedstr_t x2)
{
	for(int i = 0; i < x1.length;i++)
	{
		if(x1.content[i] != x2.content[i]){
			if(x1.content[i] < x2.content[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
    return 0;
}

void delete_sizedstr(sizedstr_t x)
{
	free(x.content);
}

int main(int argc, char *argv[])
{
    if (argv[1][0] == 'p') {
        sizedstr_t x = new_sizedstr(argv[2]);
        print_sizedstr(x);
        printf("\n");
        delete_sizedstr(x);
    } else if (argv[1][0] == 'l') {
        sizedstr_t x = new_sizedstr(argv[2]);
        printf("%d\n", sizedstr_len(x));
        delete_sizedstr(x);
    } else if (argv[1][0] == 'c') {
        sizedstr_t x1 = new_sizedstr(argv[2]);
        sizedstr_t x2 = new_sizedstr(argv[3]);
        sizedstr_t x3 = sizedstr_cat(x1, x2);
        print_sizedstr(x3);
        printf("\n");
        printf("%d\n", sizedstr_len(x3));
        delete_sizedstr(x1);
        delete_sizedstr(x2);
        delete_sizedstr(x3);
    } else if (argv[1][0] == 'o') {
        sizedstr_t x1 = new_sizedstr(argv[2]);
        sizedstr_t x2 = new_sizedstr(argv[3]);
        int cmp = sizedstr_cmp(x1, x2);
        printf("%d\n", cmp);
        delete_sizedstr(x1);
        delete_sizedstr(x2);
    }

    return EXIT_SUCCESS;
}
