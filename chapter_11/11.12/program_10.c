#include <stdio.h>

int s_strlen(char *st);

int main(void)
{
	char str[] = "asdsadadqweqsacfewrq";

	printf("string %s length is %d\n", str, s_strlen(str));

	return 0;
}

int s_strlen(char *st)
{
	int count = 0;
	while (*st) 
	{
		count ++;
		st ++;
	} 

	return count;
}
