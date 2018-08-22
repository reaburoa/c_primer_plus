#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program_2_list.h"

void showMovies(Item item);
char *s_gets(char *pt, int n);

char *s_gets(char *pt, int n)
{
	char *ret;
	char *find;
	ret = fgets(pt, n, stdin);
	if (ret)
	{
		find = strchr(pt, '\n');
		if (find)
			*find = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}

	return ret;
}

void showMovies(Item item)
{
	printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

int main(void)
{
	List movie;
	Item temp;

	InitializeList(&movie);
	if (ListIsFull(&movie)) 
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(EXIT_FAILURE);
	}

	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating<0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(&movie, temp) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movie))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title (empty line to stop):");
	}

	if (ListIsEmpty(&movie)) 
		printf("No data entered.");
	else
	{
		printf("Here is the movie list:\n");
		Traverse(&movie, showMovies);
	}

	printf("You enterd %d movie.\n", ListItemCount(&movie));

	EmptyTheList(&movie);

	return 0;
}
