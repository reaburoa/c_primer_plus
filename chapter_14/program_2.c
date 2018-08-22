#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "s_gets.h"

#define MAX 30
#define MIN 3
#define MONTH_TOTALS 12

struct month_info {
	char month_name[MAX];
	char short_name[MIN];
	int days;
	int month_no;
};

struct input {
	int year;
	int day;
	char month[];
};

int get_month_no(const struct month_info *ss_month, char *month);
void uc_word(char *word);
int get_all_days(const struct month_info *ss_month, int month_no);
struct input *get_input(void);
bool check_leap_year(int year);

bool check_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? true : false;
}

struct input *get_input(void)
{
	struct input *data;
	data = malloc(sizeof(struct input) + MAX * sizeof(char));
	printf("Please input year:");
	if (scanf("%d", &data->year) != 1)
	{
		printf("Please input a number for year!\n");
		exit(EXIT_FAILURE);
	}
	while (getchar() != '\n')
		continue;
	printf("Please input month:");
	if (s_gets(data->month, MAX) == NULL)
	{
		printf("Get month info failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Please input day:");
	while (scanf("%d", &data->day) == 1)
	{
		if (data->day < 1 || data->day > 31) 
		{
			printf("Please input a number for day");
			continue;
		}
		else
			break;
	}
	while (getchar() != '\n')
		continue;
	if (data->day > 31 || data->day < 1)
	{
		printf("Please input a number for day!\n");
		exit(EXIT_FAILURE);
	}
	return data;
}

int get_all_days(const struct month_info *ss_month, int month_no)
{
	int all_days = 0;
	int i = 0;
	for (i = 0; i < month_no; i ++)
		all_days += ss_month[i].days;
	return all_days;
}

int get_month_no(const struct month_info *ss_month, char *month)
{
	int i = 0;
	uc_word(month);
	int month_no = 0;
	for (i = 0; i < MONTH_TOTALS; i ++)
		if (strcmp(ss_month[i].month_name, month) == 0 || strcmp(ss_month[i].short_name, month) == 0)
		{
			month_no = ss_month[i].month_no;
			break;
		}
	return month_no;
}

void uc_word(char *word)
{
	int length = strlen(word);
	int i = 0;
	*word = toupper(*word);
	for (i = 1; i < length; i ++)
		*(word + i) = tolower(*(word + i));
}

int main(void)
{
	struct month_info months[12] = {
		{"January", "Jan", 31, 1},
		{"Februray", "Feb", 28, 2},
		{"March", "Mar", 31, 3},
		{"April", "Apr", 30, 4},
		{"May", "May", 31, 5},
		{"June", "Jun", 30, 6},
		{"July", "Jul", 31, 7},
		{"August", "Aug", 31, 8},
		{"September", "Sep", 30, 9},
		{"October", "Oct", 31, 10},
		{"November", "Nov", 30, 11},
		{"December", "Dec", 31, 12},
	};

	struct input *data;
	data = get_input();
	if (check_leap_year(data->year))
		months[1].days = 29;
	int month_no;
	if ((month_no = atoi(data->month)) == 0)
		month_no = get_month_no(months, data->month);
	if (month_no < 0 || month_no > 12)
	{
		printf("Please input correct month info for month!\n");
		exit(EXIT_FAILURE);
	}
	printf("You input is %d-%s-%d\n", data->year, data->month, data->day);
	int days = get_all_days(months, month_no  - 1);
	printf("Until %d-%s-%d is %d days in a year\n",data->year, data->month, data->day, days + data->day);
	free(data);
	return 0;
}

