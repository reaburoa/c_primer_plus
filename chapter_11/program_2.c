#include <stdio.h>
#include <ctype.h>

int set_arr(char *dest, char *str, int n);
char *s_gets(char *st, int num);

int main(void)
{
	int num;
	printf("Please input array members:");
	scanf("%d", &num);
	char ar[num];
	printf("Please input source string:\n");
	while (getchar() != '\n')
		continue;
	char str[100];
	s_gets(str, 100);
	printf("You input string is:%s\n", str);
	int arr_real_nums = num;
	arr_real_nums = set_arr(ar, str, num);
	int i = 0;
	printf("Array is:\n");
	for (i = 0; i < arr_real_nums; i ++) 
		printf("%c ", *(ar + i));
	printf("\n");
	return 0;
}

int set_arr(char *dest, char *str, int n)
{
	int i = 0;
	while (*str && i < n)
	{
		if (isspace(*str)) {
			break;
		}
		*(dest + i) = *str;
		i ++;
		str ++;
	}

	return i;
}

char *s_gets(char *st, int num)
{
	char *ret_val;
	ret_val = fgets(st, num, stdin);
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
