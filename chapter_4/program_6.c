#include <stdio.h>
#include <string.h>

int main()
{
	char name[100];
	char last[100];

	printf("Please input your name:");
	scanf("%s", name);
	printf("Please input your last name:");
	scanf("%s", last);
	int name_leng = strlen(name);
	int last_leng = strlen(last);
	printf("%*s %*s\n", name_leng, name, last_leng, last);
	printf("%*d %*d\n", name_leng, name_leng, last_leng, last_leng);
	
	printf("%-*s %-*s\n", name_leng, name, last_leng, last);
	printf("%-*d %-*d\n", name_leng, name_leng, last_leng, last_leng);
	return 0;
}
