#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MOVIES 10
#define MAX_TITLE 100
int counter = 2; 

//add your functions and struct definition here.

typedef struct 
{
    char* title;
    int purchases;
    double rating;
}Movie;

int add_movie(Movie movies[], char* name, double rat);
 
int get_purchases(Movie movies[], char* name){

    for(int i=0; i<N_MOVIES; i++)
        if (strcmp(name, movies[i].title) == 0)
            return movies[i].purchases;

    return -1;
}

int compute_rating(Movie movies[], char* name, double n_rating)
{

    for(int i=0; i<counter; i++)
        if (strcmp(name, movies[i].title) == 0)
            {
                double r = movies[i].rating * movies[i].purchases;
                movies[i].purchases++; 
                r += n_rating;
                movies[i].rating = r/(movies[i].purchases);
                return movies[i].rating;
                printf("The movie %s is updated. The number of purchases is %d. The rating is updated to %.2f.\n", movies[i].title, movies[i].purchases, movies[i].rating);
            }

    return 0;


}

int add_movie(Movie movies[], char* name, double rat)
{
    if (counter > N_MOVIES)
        return 0;
    Movie m;
    m.rating = rat;
    m.title = name;
    m.purchases = 1;
    movies[counter++] = m;
    return 1; 

}



int main()
{
	//there are initially two elements in the array. 
    Movie movies[N_MOVIES] = { {"Spartacus", 9, 4.0}, {"Ben Hur", 5, 1.8}};
    
	char movie_title[MAX_TITLE];
    int movie_rating, menu_selection, result;
    char input;

    for (int i = 2; i < N_MOVIES; i++)
        movies[i].purchases = -1;

    printf("Welcome to the movie database.\n");
    do {
        printf("Enter your request (1 for getting the purchases of a movie, 2 for updating the rating of a movie, 3 for exit):");
        scanf("%d", &menu_selection);

        if (menu_selection == 1) {
            printf("Enter the movie title:");
            scanf(" %[^\n]s", movie_title);

            result = get_purchases(movies, movie_title);
            if (result != -1) {
                printf("The movie %s has been purchased %d times.\n", movie_title, result);
            } else {
                printf("The movie %s could not be found in the database.\n", movie_title);
            }
        }

        else if (menu_selection == 2) {
            printf("Enter the movie title:");
            scanf(" %[^\n]s", movie_title);

            printf("Enter the movie rating (out of 5):");
            scanf("%d", &movie_rating);

            while (movie_rating < 0 || movie_rating > 5) {
                printf("Enter the movie rating (out of 5):");
                scanf("%d", &movie_rating);
            }

            result = compute_rating(movies, movie_title, movie_rating);
            if (result == 0) {
                printf("The movie %s could not be found in the database. Would you like to add this movie (Y/N):", movie_title);
                scanf(" %c", &input);

                while (input != 'Y' && input != 'N') {
                    printf("Please enter a valid input (Y/N):");
                    scanf(" %c", &input);
                }

                if (input == 'Y') {
                    result = add_movie(movies, movie_title, movie_rating);
                    if (result == 1) {
                        printf("The movie %s is added to the database with a rating of %d.\n", movie_title, movie_rating);
                    } else {
                        printf("The movie %s could not be added to the database.\n", movie_title);
                    }
                }
            }
        }
    } while (menu_selection != 3);

    return EXIT_SUCCESS;
}
