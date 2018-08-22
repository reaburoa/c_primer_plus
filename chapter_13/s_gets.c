#include <stdio.h>
#include <string.h>

char *s_gets(char *ft, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(ft, n, stdin);
	if (ret_val)
	{
		find = strchr(ret_val, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
