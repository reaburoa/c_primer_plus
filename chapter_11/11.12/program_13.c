#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ANSWER "grant"
#define SIZE 40
char *s_gets(char *st, int n);
void to_lower(char *st);

int main(void)
{
	char try[SIZE];
	puts("Who is buried in Grants's tomb?");
	s_gets(try, SIZE);
	to_lower(try);
	while (strcmp(try, ANSWER)) 
	{
		puts("No, that's wrong.Try again.");
		s_gets(try, SIZE);
		to_lower(try);
	}

	puts("That's right!");

	return 0;
}

void to_lower(char *st)
{
	while (*st != '\0')
	{
		*st = tolower(*st);
		st ++;
	}
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val) 
	{
		while (*st != '\n' && *st != '\0')
			st ++;
		if (*st == '\n')
			*st = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
