#include <stdio.h>

int main(void)
{
	char letters[26];
	int i = 0, j = 0;
	for (i = 0; i < 26; i ++) 
	{
		letters[i] = 'a' + i;
	}
	printf("26 letters is:");
	for (j = 0; j < 26; j ++) 
	{
		printf("%c ", letters[j]);
	}

	printf("\n");
	return 0;
}
