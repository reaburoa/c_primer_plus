#include <stdio.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
float get_float(void);

int main(void)
{
	int choice;
	float first_number;
	float second_number;
	float result;
	while ((choice = get_choice()) != 'q')
	{
		printf("Enter first number:");
		first_number = get_float();
		printf("Enter second number:");
		second_number = get_float();
		switch (choice)
		{
			case 'a':
				printf("%.2f + %.2f = %.2f\n", first_number, second_number, first_number + second_number);
				break;
			case 's':
				printf("%.2f - %.2f = %.2f\n", first_number, second_number, first_number - second_number);
				break;
			case 'm':
				printf("%.2f * %.2f = %.2f\n", first_number, second_number, first_number * second_number);
				break;
			case 'd':
				if (second_number == 0)
				{
					printf("divide number cannot be 0, Please enter second_number:\n");
					second_number = get_float();
				}
				printf("%.2f / %.2f = %.2f\n", first_number, second_number, first_number / second_number);
				break;
			default:
				break;
		}
	}
	printf("Bye.\n");
	return 0;
}

char get_choice(void)
{
	int ch;
	printf("Enter the operation of your choice:\n");
	printf("a.add\ts.subtract\n");
	printf("m.multiply\td.divide\n");
	printf("q.quit\n");
	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("Please respond with a,s,m,d, or q.\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	int ch;
	int tmp;
	ch = getchar();
	while (isspace(ch))
		ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

float get_float(void)
{
	float input;
	char ch;
	while (scanf("%f", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\nPlease enter a ");
		printf("number, such as 2.5, -1, or 3:");
	}
	return input;
}
