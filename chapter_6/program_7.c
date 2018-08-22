#include<stdio.h>
#include<string.h>

int main(void)
{
	char character[40];
	printf("Please enter a word:");
	scanf("%s", character);
	int i;
	for (i = strlen(character) - 1; i >= 0; i --) 
	{
		printf("%c", character[i]);
	}
	printf("\n");
	return 0;
}
