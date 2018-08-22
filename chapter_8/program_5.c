#include <stdio.h>

int main(void)
{
	int height = 100;
	int low = 1;
	int guess = (low + height) / 2;
	printf("Pick an integer from 1 to 100.I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\na l if my guess is larger, a s if my guess is smaller.\n");
	printf("Uh...is your number %d?\n", guess);
	int ch;
	while ((ch = getchar()) != 'y')
	{
		if (ch == '\n')
		{
			continue;
		}
		if (ch != 'l' && ch != 's')
		{
			printf("I donot know what are you saying\n");
			continue;
		}
		if (ch == 'l')
		{
			height = guess - 1;
		}
		else if (ch == 's')
		{
			low = guess + 1;
		}
		guess = (low + height) / 2;
		printf("Well,then,it is %d?\n", guess);
	}
	printf("I know I could do it!\n");
	return 0;
}
