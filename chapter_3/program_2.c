#include <stdio.h>

int main(void)
{
	unsigned char ch;
	printf("Please input an int number:");
	scanf("%d", &ch);

	printf("%d number to char is %c\n", ch, ch);

	return 0;
}
