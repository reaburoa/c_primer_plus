#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int get_month_no(const struct month_info *ss_month, char *month);
void uc_word(char *word);
int get_all_days(const struct month_info *ss_month, int month_no);

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
	char month[MAX];
	printf("Please input a month name:\n");
	if (s_gets(month, MAX) == NULL)
	{
		fprintf(stderr, "Please enter a string for month name!");
		exit(EXIT_FAILURE);
	}
	int days = get_all_days(months, get_month_no(months, month));
	printf("You input month name is %s\n", month);
	printf("Until Month %s has %d days in a year\n", month, days);
	return 0;
}

int get_month_no(const struct month_info *ss_month, char *month)
{
	int i = 0;
	uc_word(month);
	int month_no = 0;
	for (i = 0; i < MONTH_TOTALS; i ++)
		if (strcmp(ss_month[i].month_name, month) == 0)
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

int get_all_days(const struct month_info *ss_month, int month_no)
{
	int all_days = 0;
	int i = 0;
	for (i = 0; i < month_no; i ++)
		all_days += ss_month[i].days;
	return all_days;
}

