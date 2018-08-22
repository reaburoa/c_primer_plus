#include <stdio.h>
#include <string.h>

#define LEN 80

char find(const char *str, char ch);
char *s_gets(char *str, int n);

int main(void)
{
	char str[LEN];
	printf("Please input string(press twice enter to quit):\n");
	char ch;
	int found;
	while (s_gets(str, LEN) && str[0] != '\0')
	{
		printf("Please input a char:");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		found = find(str, ch);
		printf("found ret is %d \n", found ? 1 : 0);
		printf("Please input string:\n");
	}
	return 0;
}

char find(const char *str, char ch)
{
	while (*str != ch && *str != '\0')
		str ++;
	return *str;
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (*str != '\n' && *str != '\0')
			str ++;
		if (*str == '\n')
			*str = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
