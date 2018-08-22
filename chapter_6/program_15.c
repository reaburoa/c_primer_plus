#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[255];
	printf("Please input a string with max length 255:\n");
	scanf("%s", str);
	int i = 0, length = strlen(str);
	for (i = length; i >= 0; i --)
	{
		printf("%c", str[i]);
	}

	printf("\n");
	return 0;
}
