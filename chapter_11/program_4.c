#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 80

char *get_word(char *word, int n);

int main(void)
{
	int num;
	printf("Please input string length:");
	scanf("%d", &num);
	char word[num];
	printf("Please input a string\n");
	get_word(word, num);
	printf("Word is %s\n", word);
	return 0;
}

char *get_word(char *word, int n)
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != EOF && i < n)
	{
		if (ch == '\n') 
			continue;
		if (!isspace(ch))
		{
			*(word + i) = ch;
			i ++;
		}
		if ((i > 0 && isspace(ch)))
			break;
	}
	*(word + i) = '\0';
	if (ch == EOF)
		return NULL;	
	return word;
}
