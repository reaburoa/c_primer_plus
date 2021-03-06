#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "s_gets.h"

#define MAXNAME 40
#define MAXSEATS 12
#define MAXNO 20
#define CHOICE 6
#define DATA_FILE "./file/program_8.data"

typedef struct member {
	int seat_no;
	int status;
	char last[MAXNAME];
	char first[MAXNAME];
} s_member;

char menu(void);
int get_empty_totals(const s_member members[], int n);
int show_empty_list(const s_member members[], int n);
void sort_by_last(s_member members[], int n);
void show_assigned_seats(const s_member members[], int n);
void assign_seat(s_member members[], int n);
void delete_assigned_seat(s_member members[], int n);

void sort_by_last(s_member members[], int n)
{
	int i = 0, j = 0;
	s_member temp;
	for (i = 0; i < n; i ++)
		for (j = i; j < n; j ++)
		{
			if (members[j].status != 1)
				continue;
			if (strcmp(members[i].last, members[j].last) > 0)
			{
				temp = members[i];
				members[i] = members[j];
				members[j] = temp;
			}
		}
}

void show_assigned_seats(const s_member members[], int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
		if (members[i].status == 1)
			printf("%d seat is assigned to %s %s\n", members[i].seat_no, members[i].last, members[i].first);
}

void delete_assigned_seat(s_member members[], int n)
{
	int empty_totals = get_empty_totals(members, n);
	if (empty_totals == n)
		printf("There is no assigned seats.\n");
	else
	{
		show_assigned_seats(members, n);
		printf("Please enter which seat do you want to delete assigned:");
		int number;
		while (scanf("%d", &number) == 1)
		{
			while (getchar() != '\n')
				continue;
			if (number < 1 || number > 12)
			{
				printf("please enter a number between 1-12:");
				continue;
			}
			else
				break;
		}
		printf("Do you really want to delete(y/n)?");
		char check;
		while (scanf("%c", &check) == 1)
		{
			while (getchar() != '\n')
				continue;
			check = tolower(check);
			if (check != 'y' && check != 'n')
			{
				printf("Please enter a char y or n:");
				continue;
			}
			else
				break;
		}
		if (check == 'y')
		{
			members[number - 1].status = 0;
			printf("delete %d seat success.\n", number);
		}
		else
			printf("Don't delete anything.\n");
	}
}

void assign_seat(s_member members[], int n)
{
	int empty_total = show_empty_list(members, n);
	if (empty_total == 0)
		printf("I'm sorry, there is no empty seats.\n");
	else
	{
		int seat = 0;
		printf("Please input which seat do you want:");
		while (scanf("%d", &seat) == 1)
		{
			if (seat < 0 || seat > 12)
			{
				printf("Please enter a number between 1-12:");
				continue;
			}
			else
				break;
		}
		while (getchar() != '\n')
			continue;
		printf("Please enter your last name:");
		s_gets(members[seat - 1].last, MAXNAME);
		printf("Please enter your first name:");
		s_gets(members[seat - 1].first, MAXNAME);
		printf("%s %s will be assigned to seat %d\n", members[seat - 1].last, members[seat - 1].first, seat);
		printf("Please check this is ok(y/n):");
		char check;
		while (scanf("%c", &check))
		{
			while (getchar() != '\n')
				continue;
			check = tolower(check);
			if (check != 'y' && check != 'n')
			{
				printf("Please enter y or n:");
				continue;
			}
			else
			{
				members[seat - 1].status = 1;
				printf("%d seat has assigned to %s %s\n", seat, members[seat - 1].last, members[seat - 1].first);
				break;
			}
		}
	}
}

int get_empty_totals(const s_member members[], int n)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < n; i ++)
		if (!members[i].status)
			sum ++;
	return sum;
}

int show_empty_list(const s_member members[], int n)
{
	int i = 0;
	int empty_total = get_empty_totals(members, n);
	if (empty_total == 0)
		printf("There is no empty seats.\n");
	else
	{
		for (i = 0; i < n; i ++)
			if (members[i].status != 1)
				printf("%d ", members[i].seat_no);
		printf("\n");
	}
	return empty_total;
}

char menu(void)
{
	char *menu[CHOICE] = {
		"Show number of empty seats",
		"Show list of empty seats",
		"Show alphabetical list of seats",
		"Assign a customer to a seat assginment",
		"Delete a seat assginment",
		"Quit"
	};
	const char *label = "abcdef";
	printf("To choose a function, enter its letter label:\n");
	int i = 0;
	for (i = 0; i < CHOICE; i ++)
	{
		printf("%c) %s\n", *(label + i), menu[i]);
	}
	printf("****************************************************\n");
	printf("Please enter your choice:");
	char choice;
	while (scanf("%c", &choice))
	{
		while (getchar() != '\n')
			continue;
		choice = tolower(choice);
		if (strchr(label, choice) == NULL)
		{
			printf("Please enter your choice again:");
			continue;
		}
		else
			break;
	}
	return choice;
}

int main(void)
{
	s_member members[MAXSEATS];
	FILE *fp;
	int i = 0;
	int size = sizeof(s_member);
	if ((fp = fopen(DATA_FILE, "rb")) == NULL)
	{
		for (i = 0; i < MAXSEATS; i ++)
			members[i].seat_no = i + 1;
	}
	else
	{
		fread(members, size, MAXSEATS, fp);
		fclose(fp);
	}
	char choice;
	while (choice = menu())
	{
		if (choice == 'f')
			break;
		switch (choice)
		{
			case 'a':
				printf("empty seats is %d\n", get_empty_totals(members, MAXSEATS));
				break;
			case 'b':
				printf("Empty seats is:\n");
				show_empty_list(members, MAXSEATS);
				break;
			case 'c':
				sort_by_last(members, MAXSEATS);
				show_assigned_seats(members, MAXSEATS);
				break;
			case 'd':
				assign_seat(members, MAXSEATS);
				break;
			case 'e':
				delete_assigned_seat(members, MAXSEATS);
				break;
		}
	}
	if ((fp = fopen(DATA_FILE, "wb")) == NULL)
	{
		printf("Open %s file failed.\n", DATA_FILE);
	}
	else
	{
		fwrite(members, size, MAXSEATS, fp);
		close(fp);
	}
	printf("Bye.\n");
	return 0;
}
