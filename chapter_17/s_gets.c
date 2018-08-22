#include <stdio.h>
#include <string.h>

#include "s_gets.h"

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
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
