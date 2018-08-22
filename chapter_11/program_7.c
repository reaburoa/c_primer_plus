#include <stdio.h>
#include <string.h>

#define LENGTH 8

char *mystrncpy(char *s1, char *s2, int n);
char *s_gets(char *st, int n);

int main(void)
{
	char dest[LENGTH] = "";
	char src[20];
	printf("Please input source string:\n");
	while (s_gets(src, 20) && src[0] != '\0')
	{
		mystrncpy(dest, src, LENGTH);
		printf("copy string,dest string is:%s\n", dest);
		printf("Please input source string again:\n");
	}
	return 0;
}

char *mystrncpy(char *s1, char *s2, int n)
{
	int i = 0;
	if (strlen(s2) >= n)
		return s1;

	for (i = 0; i < n; i ++)
		*(s1 + i) = *(s2 + i);
	if (*(s1 + i) != '\0')
		*(s1 + i) = '\0';

	return s1;
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
