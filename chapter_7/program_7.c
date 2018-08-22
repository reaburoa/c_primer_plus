#include <stdio.h>

#define EACH_HOUR_SALARY 1000
#define PRE_THREE_HOURS 300
#define NEXT_150_HOURS 150
#define HOUR_RATE 1.5
#define RATE_15 0.15
#define RATE_20 0.2
#define RATE_25 0.25
#define BASE_HOUR 40

int main(void)
{
	float work_hours = 0;
	float salary = 0;
	float tax = 0;
	printf("Please input work hours in this week:");
	scanf("%f", &work_hours);
	if (work_hours > BASE_HOUR)
	{
		work_hours = BASE_HOUR + (work_hours - BASE_HOUR) * HOUR_RATE;
	}
	salary = work_hours * EACH_HOUR_SALARY * 1.0;
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
		tax = salary * HOUR_RATE;
	}
	printf("Your work hours is %.2f\n", work_hours);
	printf("Your salary total is %.2f, tax is %.2f and left salary is %.2f\n", salary, tax, salary - tax);
	return 0;
}
