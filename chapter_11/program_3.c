#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 80

char *get_word(char *word);

int main(void)
{
	char word[WORD_SIZE];
	printf("Please input a string\n");
	get_word(word);
	printf("Word is %s\n", word);
	return 0;
}

char *get_word(char *word)
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		if (!isspace(ch))
		{
			*(word + i) = ch;
			i ++;
		}
		if ((i > 0 && isspace(ch)) || ch == '\n')
			break;
	}
	*(word + i) = '\0';
	if (ch == EOF)
		return NULL;	
	return word;
}
