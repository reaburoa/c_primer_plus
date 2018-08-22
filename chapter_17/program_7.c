#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "program_7_tree.h"

#define FILE_NAME "./file/program_7.data"

char menu(void);
char *s_gets(char *ptr, int n);
void initData(Tree *ptee);
void showWord(Item item);
void showWords(Tree *ptree);
void findWord(Tree *ptree);

void findWord(Tree *ptree)
{
	char s_word[SLEN];
	Item item;
	const Item *pi;

	if (TreeIsEmpty(ptree))
	{
		printf("There is no data!\n");
		return ;
	}

	printf("Please enter a word:");
	s_gets(s_word, SLEN);
	strcpy(item.word, s_word);
	pi = WhereInTree(&item, ptree);
	if (pi == NULL)
		printf("%s is not in word tree!\n", s_word);
	else
		printf("%s in word tree apear times %d!\n", pi->word, pi->nums);
}

void showWords(Tree *ptree)
{
	if (TreeIsEmpty(ptree))
		printf("No words!\n");
	else
		Traverse(ptree, showWord);
}

void showWord(Item item)
{
	printf("%s: %d\n", item.word, item.nums);
}

void initData(Tree *ptree)
{
	FILE *pf;
	if ((pf = fopen(FILE_NAME, "r")) == NULL)
	{
		fprintf(stderr, "Open file fialed!\n");
		exit(EXIT_FAILURE);
	}

	Item item;
	char s_word[SLEN];
	while (fscanf(pf, "%s", s_word) == 1 && !TreeIsFull(ptree)) {
		strcpy(item.word, s_word);
		AddItem(&item, ptree);
	}
	fclose(pf);
}

char *s_gets(char *ptr, int n)
{
	char *ret_val, *find;
	ret_val = fgets(ptr, n, stdin);
	if (ret_val)
	{
		find = strchr(ptr, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() == '\n')
				continue;
	}

	return ret_val;
}

char menu(void)
{
	char ch;

	printf("**************************************************\n");
	printf("Word Program\n");
	printf("Enter the lette corresponding to your Choice:\n");
	printf("a) show word and apear times\tb) seek a word\n");
	printf("q) quit\n");
	printf("**************************************************\n");
	printf("Please choose:");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("abq", ch) == NULL)
			printf("Please enter an a, b, or q:");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	return ch;
}

int main(void)
{
	Tree word;
	InitializeTree(&word);
	printf("Init word data ...\n");
	initData(&word);
	char ch;
	while ((ch = menu()) != 'q')
	{
		switch (ch)
		{
			case 'a':
				printf("All words is below:\n");
				showWords(&word);
				break;
			case 'b':
				printf("Find a word in Words Tree\n");
				findWord(&word);
				break;
			default:
				break;
		}
	}
	DeleteAll(&word);
	printf("Bye!\n");
	return 0;
}
