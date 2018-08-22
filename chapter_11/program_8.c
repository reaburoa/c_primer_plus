#include <stdio.h>
#include <string.h>

#define SIZE 80
#define SUB_STR_SIZE 10
int find_sub_str(char *source, char *find);
char *s_gets(char *st, int n);

int main(void)
{
	char source[SIZE];
	char find[SUB_STR_SIZE];
	printf("Please input a string:\n");
	while (s_gets(source, SIZE) && source[0] != '\0')
	{
		printf("Please input sub string to find:\n");
		s_gets(find, SUB_STR_SIZE);
		int pos = find_sub_str(source, find);
		printf("source string is %s and find string is %s and pos is %d\n", source, find, pos >= 0 ? pos + 1 : pos);
		printf("test again\n");
	}
	return 0;
}

int find_sub_str(char *source, char *find)
{
	int i = 0;
	int length = strlen(find);
	char *first_pos;
	first_pos = strchr(source, *find);
	if (first_pos) {
		while (*find) {
			if (*find != *(first_pos ++))
				return -1;
			find ++;
			i ++;
		}
	}
	else
		return -1;
	return (first_pos - source - i) / sizeof(char);
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
