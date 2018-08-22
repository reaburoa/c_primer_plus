#include <stdio.h>

#define EACH_HOUR_SALARY 1000
#define PRE_THREE_HOURS 300
#define NEXT_150_HOURS 150
#define HOUR_RATE 1.5
#define RATE_15 0.15
#define RATE_20 0.2
#define RATE_25 0.25
#define BASE_HOUR 40

#define action_1 8.75
#define action_2 9.33
#define action_3 10.00
#define action_4 11.20

int display_menu();

int main(void)
{
	display_menu();
	float work_hours = 0;
	float salary = 0;
	float tax = 0;
	int action;
	while (scanf("%d", &action) == 1) 
	{
		if (action < 1 || action > 5)
		{
			printf("Please input action again:");
			continue;
		}
		if (action == 5)
		{
			break;
		}

		float salary_rate = 0;
		switch (action)
		{
			case 1:
				salary_rate = action_1;
				break;
			case 2:
				salary_rate = action_2;
				break;
			case 3:
				salary_rate = action_3;
				break;
			case 4:
				salary_rate = action_4;
				break;
		}
		printf("Please input work hours in this week:");
		scanf("%f", &work_hours);
		if (work_hours > BASE_HOUR)
		{
			work_hours = BASE_HOUR + (work_hours - BASE_HOUR) * HOUR_RATE;
		}
		salary = work_hours * salary_rate * 1.0;
		printf("salary_rate=%.2f hour=%.2f salary=%.2f\n", salary_rate, work_hours, salary);
		if (salary > PRE_THREE_HOURS)
		{
			tax = PRE_THREE_HOURS * RATE_15;
			if (salary < (PRE_THREE_HOURS + NEXT_150_HOURS))
			{
				tax += (salary - PRE_THREE_HOURS) * RATE_20;			
			}
			else if (salary > (PRE_THREE_HOURS + NEXT_150_HOURS))
			{
				tax += NEXT_150_HOURS * RATE_20 + (salary - PRE_THREE_HOURS - NEXT_150_HOURS) * RATE_25;
			}
		}
		else
		{
			tax = salary * RATE_15;
		}
		printf("Your work hours is %.2f\n", work_hours);
		printf("Your salary total is $%.2f, tax is $%.2f and left salary is $%.2f\n", salary, tax, salary - tax);
		display_menu();
	}
	return 0;
}

int display_menu()
{
	printf("*********************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1 $8.75/hr\t2 $9.33/hr\n");
	printf("3 $10.00/hr\t4 $11.20/hr\n");
	printf("5 quit\n");
	printf("*********************************************************************\n");
	return 0;
}
