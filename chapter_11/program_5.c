#include <stdio.h>
#include <string.h>

char *find(char *str, char ch);

int main(void)
{
	char str[] = "hgqwed";
	char ch = 'z';
	printf("str=\"%s\" char=\"%c\"\n", str, ch);
	char *ptr;
	ptr = find(str, ch);
	if (ptr == NULL)
		printf("not find\n");
	else
		printf("ch ptr is %u and next is %c\n", ptr, *(ptr + 1));
	return 0;
}

char *find(char *str, char ch)
{
	char *pos;
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == ch)
		{
			pos = str + i;
			break;
		}
		i ++;
	}
	if (*(str + strlen(str)) == *(str + i))
		return NULL;
	return pos;
}
