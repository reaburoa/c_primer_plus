#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TSIZE 45

typedef struct film {
	char title[TSIZE];
	int rating;
	struct film *next;
	struct film *front;
} s_film;

char *s_gets(char *st, int n);

char *s_gets(char *st, int n)
{
	char *ptr, *find;
	ptr = fgets(st, n, stdin);
	if (ptr)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ptr;
}

int main(void)
{
	s_film *head = NULL;
	s_film *rear = NULL;
	s_film *prev, *current;

	char input[TSIZE];
	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(s_film));
		if (head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
			current->front = prev;
		}
		rear = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop)");
		prev = current;
	}
	if (head == NULL)
		printf("No data entered.\n");
	else
		printf("Here is the movie list:\n");
	printf("Show list from head:\n");
	current = head;
	while (current != NULL)
	{
		printf("Movie:%s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}
	printf("Show list from rear:\n");
	current = rear;
	while (current != NULL)
	{
		printf("Movie:%s Rating: %d\n", current->title, current->rating);
		current = current->front;
	}

	current = head;
	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}

	printf("Bye!\n");
	return 0;
}
