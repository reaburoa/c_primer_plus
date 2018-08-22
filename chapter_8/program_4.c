#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int word_nums = 0;
	int word_letters = 0;
	char word[100] = {0};
	while ((ch = getchar()) != EOF)
	{
		if (isalnum(ch)) 
		{
			word[word_letters] = ch;
			word_letters ++;
		}
		else
		{
			word_nums ++;
			printf("word '%s' has letters %d\n", word, word_letters);

			int i = 0;
			for (i = 0; i < word_letters; i ++)
			{
				word[i] = 0;
			}
			word_letters = 0;
		}
	}
	printf("There is %d words\n", word_nums);

	return 0;
}

