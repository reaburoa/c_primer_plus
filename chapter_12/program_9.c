#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define EACH_WORD_SIZE 80

int main(void)
{
	int word_num;
	printf("How many words do you wish to enter(q to quit)?\n");
	while (scanf("%d", &word_num) == 1)
	{
		while (getchar() != '\n')
			continue;
		char *words[word_num];
		
		printf("Enter %d words now:\n", word_num);
		char ch;
		int j = 0;
		int i = 0;
		char temp[EACH_WORD_SIZE];
		while ((ch = getchar()))
		{
			if (!isspace(ch) && i < EACH_WORD_SIZE)
			{
				temp[i] = ch;
				i ++;
			}
			if (isspace(ch) && i > 0)
			{
				temp[i] = '\0';
				words[j] = (char *)malloc(i * sizeof(char));
				for (int k = 0; k < i; k ++)
					words[j][k] = temp[k];
				i = 0;
				j ++;
			}

			if (ch == '\n')
				break;
			if (j >= word_num)
				continue;
		}
		for (i = 0; i < word_num; i ++)
			printf("%s\n",  words[i]);
		printf("How many words do you wish to enter(q to quit)?\n");
		for (i = 0; i < word_num; i ++)
			free(words[i]);
	}
	return 0;
}
