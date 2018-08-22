#include <stdio.h>
#include <string.h>

char *s_gets(char *ptr, int n)
{
	char *ret, *find;
	ret = fgets(ptr, n, stdin);
	if (ret)
	{
		find = strchr(ptr, '\n');
		if (find)
			*find = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}

	return ret;
}
