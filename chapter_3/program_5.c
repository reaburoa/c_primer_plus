#include <stdio.h>

int main(void)
{
	int age;
	long seconds = 3.156e7;
	long long all_seconds = 0;
	printf("Enter your age:");
	scanf("%d", &age);
	printf("all seconds is:%lld\n", seconds * age);
	return 0;	
}
