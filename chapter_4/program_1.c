#include <stdio.h>

int main()
{
	char name[100];
	char last[100];

	printf("Please input your name:");
	scanf("%s", name);
	printf("Please input your last name:");
	scanf("%s", last);
	printf("Your name is %s,%s\n", name, last);

	return 0;
}
