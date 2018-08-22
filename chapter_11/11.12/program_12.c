#include <stdio.h>
#include <ctype.h>

char *get_ptr(const char *st);

int main(void)
{
	char *str1 = "asda qer";
	char *str2 = "asd";
	char *str1_ptr = get_ptr(str1);
	char *str2_ptr = get_ptr(str2);
	printf("str1=\"%s\" and space ptr is %u and space next char is %c\n", str1, str1_ptr, *(str1_ptr + 1));
	printf("str2=\"%s\" and space ptr is %u and space next char is %c\n", str2, str2_ptr, *(str2_ptr + 1));

	return 0;
}

char *get_ptr(const char *st)
{
	while (*st) 
	{
		if (*st == ' ')
			break;
		if (*st == '\0') 
			return NULL;
		st ++;
	}

	return st;
}

