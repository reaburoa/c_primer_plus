#include <stdio.h>
#include <string.h>

#include "s_gets.h"

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

typedef struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} s_book;

void display_books(const s_book *books, int n);
void sort_by_title(s_book *books, int n);
void sort_by_value(s_book *books, int n);

void display_books(const s_book *books, int n)
{
	int index = 0;
	for (index = 0; index < n; index ++)
		printf("%s by %s: $%.2f\n", books[index].title, books[index].author, books[index].value);
}

void sort_by_title(s_book *books, int n)
{
	int i = 0;
	int j = 0;
	s_book temp;
	for (i = 0; i < n; i ++)
		for (j = i; j < n; j ++)
		{
			if (books[i].title[0] > books[j].title[0])
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
}

void sort_by_value(s_book *books, int n)
{
	int i = 0;
	int j = 0;
	s_book temp;
	for (i = 0; i < n; i ++)
		for (j = i; j < n; j ++)
		{
			if (books[i].value > books[j].value)
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
}

int main(void)
{
	s_book library[MAXBKS];
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Please enter the value.\n");
		scanf("%f", &library[count ++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		display_books(library, count);
		printf("Sort by title:\n");
		sort_by_title(library, count);
		display_books(library, count);
		printf("Sort by value:\n");
		sort_by_value(library, count);
		display_books(library, count);
	}
	else
		printf("No books? Too bad.\n");
	return 0;
}
