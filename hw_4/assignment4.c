#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE 10000
#define LIMIT 200

int glob_index = 0;	//global index

struct instruction_s
{
    int step;
    int index;
};

char* get_word(char* s, int n)
{
	char* words = strtok(s," ");
	int i = 1;
	while (words != NULL)	//this loop split strings by empty as n times
	{
        if(i != n)
        {
        	words = strtok(NULL, " ");
        	i++;
		}
		else
		{
			break;
		}
    }
    
	i = 0;
	int j = 0;
	char c;
	while ((c = words[i++]) != '\0')	//this loop checks is char alphabetic character and if it is, makes lower and assign to string agian
    {
        if (isalpha(c))
        {
            words[j++] = tolower(c);
        }
    }
    words[j] = '\0';

	return words;
}

void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence)
{
	glob_index += instructions[n_instructions].index;	// add-substract index of current nth instruction in struct
	sentence = lines[glob_index - 1];	//assign glob_index-1th line of book to sentence
	printf("%s ",get_word(sentence,instructions[n_instructions].step));	//send get_word function sentence and step
}

int main (int argc, char *argv[])
{
    char** book = malloc(LINE * sizeof(char*));	//allocate space for book
    int i;
	for(i = 0; i < LINE; i++)
	{
		book[i] = malloc(LIMIT * sizeof(char));	//allocate space for each line
	}
    FILE *ptr;
    ptr = fopen(argv[1],"r");
    char c;
    if(!ptr)
    {
        printf("ERROR!");
        return 1;
    }
    else
    {
      int ch = 0;	//keeps char index in a line
      int ln = 0;	//keeps line index in book
      do
      {
          c = fgetc(ptr);
          if(feof(ptr))
          {
             break ;
          }

		   if(c == '\n')
           {
                ln++;
                ch = 0;
           }
           else
           {
                book[ln][ch] = c;
                ch++;
           }
       }
       while(1);
    }
    fclose(ptr);
    FILE *fptr;
    fptr = fopen(argv[2],"r");
    int number_of_line = 0;
    char x;
    if(!fptr)
    {
        printf("ERROR!");
        return 1;
    }
    else
    {
        do	//this do while finds how many line this file has
        {
           x = fgetc(fptr);
	       if(x == '\n')
	       {
	            number_of_line++;
	       }
	       if(feof(fptr))
	       {
	       		break;
		   }

        }while(1);
        
        rewind(fptr);	//bring index of file pointer to beginning
        
        struct instruction_s* ins = malloc(number_of_line * sizeof(struct instruction_s));	//allocate space for struct pointer(array)
		int k;
		for(k = 0; k < number_of_line;k++)
		{
			fscanf(fptr,"%d %d",&ins[k].index, &ins[k].step);	//read file and assign 2 integer to struct's index and struct's step
		}

   		int lnn;
	    char* sentence = " ";

	    printf("\n");
	    for(lnn = 0; lnn < number_of_line; lnn++)	//send function book,struct, a number in for loop and a string(sentence)
	    {
	    	get_sentence(book,ins,lnn,sentence);
		}
		printf("\n");
    }
    fclose(fptr);
    free(book);

    return 0;
}
