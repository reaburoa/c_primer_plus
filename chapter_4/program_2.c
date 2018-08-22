#include <stdio.h>

int main()
{
	char name[100];
	char last[100];

	printf("Please input your name:");
	scanf("%s", name);
	printf("Please input your last name:");
	scanf("%s", last);
	printf("Your name is \"%s\", last name is \"%s\"\n", name, last);
	printf("Your name is \"%20s\", last name is \"%20s\"\n", name, last);
	printf("Your name is \"%-20s\", last name is \"%-20s\"\n", name, last);
	printf("Your name is \"%3s\", last name is \"%3s\"\n", name, last);

	return 0;
}
