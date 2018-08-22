#include <stdio.h>

char *ss_gets(char *st, int n);

int main(void)
{
	char test[10];
	printf("Please input a string:\n");
	ss_gets(test, 10);
	printf("test string is:%s\n", test);
	return 0;
}

char *ss_gets(char *st, int n)
{
	char *ret_val;
	ret_val = fgets(st, n, stdin);
	char *pos;
	if (ret_val) 
	{
		pos = strchr(st, '\n');
		if (pos)
			*pos = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
