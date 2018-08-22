#include <stdio.h>

#define SINGLE_TAX_BEGIN 17850
#define HOME_OWNER_TAX_BEGIN 23900
#define MARRIED_SHARE_TAX_BEGIN 29750
#define MARRIED_DIVORCED_TAX_BEGIN 14875
#define BASE_TAX_RATE 0.15
#define OTHER_TAX_RATE 0.28

int display_menu();

int main(void)
{
	display_menu();
	int menu;
	double income = 0;
	double tax = 0;
	while (scanf("%d", &menu) == 1)
	{
		if (menu == 5) break;
		if (menu < 1 || menu > 5) continue;
		printf("Please input your income:");
		scanf("%lf", &income);
		printf("Your income is $%.2lf\n", income);
		double base_income = 0;
		switch (menu)
		{
			case 1:
				base_income = SINGLE_TAX_BEGIN;
				break;
			case 2:
				base_income = HOME_OWNER_TAX_BEGIN;
				break;
			case 3:
				base_income = MARRIED_SHARE_TAX_BEGIN;
				break;
			case 4:
				base_income = MARRIED_DIVORCED_TAX_BEGIN;
				break;
		}
		if (income > base_income) 
		{
			tax = base_income * BASE_TAX_RATE + (income - base_income) * OTHER_TAX_RATE;
		}
		else
		{
			tax = income * BASE_TAX_RATE;
		}

		printf("Your tax is $%.2lf and real income is $%.2lf\n", tax, income - tax);
		display_menu();	
	}
	return 0;
}

int display_menu()
{
	printf("***********************************\n");
	printf("1 single\t2 home_onwer\n");
	printf("3 married with togethor\t4 married divorced\n");
	printf("5 quit\n");
	printf("***********************************\n");
	printf("Please input a menu:");
	return 0;
}
