#include <stdio.h>
#include <string.h>

#include "s_gets.h"

#define SIZE 80
#define LINE 10

void menu();
void display(char *str[], int line);
void sort_by_ascii(char *str[], int line);
void sort_by_length(char *str[], int line);
int get_first_word_length(char *str);
void sort_by_first_word_length(char *str[], int line);
void exchange_str(char *str1, char *str2, int n);

int main(void)
{
	int check;

	char str[LINE][SIZE];
	char *strings[SIZE];
	int ct = 0;
	printf("Please input strings with space line to end\n");
	while (ct < LINE && s_gets(str[ct], SIZE) && str[ct][0] != '\0')
	{
		strings[ct] = str[ct];
		ct ++;
	}
	menu();
	while (scanf("%d", &check) == 1)
	{
		if (check == 0)
			break;
		if (check < 0 || check > 4)
		{
			menu();
			continue;
		}
		while (getchar() != '\n')
			continue;
		switch (check)
		{
			case 1:
				printf("You input string is:\n");
				display(strings, ct);
				break;
			case 2:
				sort_by_ascii(strings, ct);
				printf("Sort by ACSII,string is:\n");
				display(strings, ct);
				break;
			case 3:
				sort_by_length(strings, ct);
				printf("Sort by string's length,string is:\n");
				display(strings, ct);
				break;
			case 4:
				sort_by_first_word_length(strings, ct);
				printf("Sort by string's first word length,string is:\n");
				display(strings, ct);
				break;
		}
		menu();	
	}
	return 0;
}

void menu()
{
	printf("The menu is below:\n");
	printf("*********************************************\n");
	printf("1 -- 打印源字符串列表\t2 -- 以ASCII中的顺序打印字符串\n");
	printf("3 -- 按长度递增顺序打印字符串\t4 -- 按字符串中第1个单词的长度打印字符串\n");
	printf("0 -- 退出\n");
	printf("*********************************************\n");
}

void display(char *str[], int line)
{
	int i = 0;
	for (i = 0; i < line; i ++)
		printf("%s\n", str[i]);
}

void sort_by_ascii(char *str[], int line)
{
	int i = 0, j;
	char *temp;
	for (i = 0; i < line; i ++)
		for (j = i + 1; j < line; j ++)
			if (strcmp(str[i], str[j]) > 0)
				exchange_str(str[i], str[j], strlen(str[i]) > strlen(str[j]) ? strlen(str[i]) : strlen(str[j]));
}

void sort_by_length(char *str[], int line)
{
	int i = 0, j;
	char *temp;
	for (i = 0; i < line; i ++)
		for (j = i + 1; j < line; j ++)
			if (strlen(str[i]) > strlen(str[j]))
				exchange_str(str[i], str[j], strlen(str[i]) > strlen(str[j]) ? strlen(str[i]) : strlen(str[j]));
}

int get_first_word_length(char *str)
{
	int word_length = 0;
	int i = 0;
	while (*str)
	{
		if (!isspace(*str))
		{
			word_length ++;
			i ++;
		}
		if (i > 0 && isspace(*str))
			break;
		str ++;
	}

	return word_length;
}

void sort_by_first_word_length(char *str[], int line)
{
	int i = 0, j;
	char *temp;
	for (i = 0; i < line; i ++)
		for (j = i + 1; j < line; j ++)
			if (get_first_word_length(str[i]) > get_first_word_length(str[j]))
				exchange_str(str[i], str[j], strlen(str[i]) > strlen(str[j]) ? strlen(str[i]) : strlen(str[j]));
}

void exchange_str(char *str1, char *str2, int n)
{
	char temp[n];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}
