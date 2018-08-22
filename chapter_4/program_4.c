#include <stdio.h>

int main(void)
{
	char name[100];
	float height;
	printf("Please input your name:");
	scanf("%s", name);
	printf("Please input your height:");
	scanf("%f", &height);
	printf("%s, you are %.3f feet tall\n", name, height / 12);

	return 0;
}
