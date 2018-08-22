#include <stdio.h>
#include <string.h>

#include "s_gets.h"

#define NAME_MAX 40
#define GROUP_NUM 3
#define CSIZE 4

typedef struct name {
	char last[NAME_MAX];
	char first[NAME_MAX];
} s_name;

typedef struct student {
	s_name name;
	float group[GROUP_NUM];
	float avg;
} s_student;

void get_score(s_student students[], int n);
float get_student_avg(s_student students[], int n);
void display(const s_student students[], int n);

void get_score(s_student students[], int n)
{
	int i = 0, j = 0;
	printf("Please Input student's name and score:\n");
	for (i = 0; i < n; i ++)
	{
		printf("Please input %d student info:\n", i + 1);
		printf("first name:");
		s_gets(students[i].name.first, NAME_MAX);
		printf("last name:");
		s_gets(students[i].name.last, NAME_MAX);
		for (j = 0; j < GROUP_NUM; j ++)
		{
			printf("the %d score:", j + 1);
			scanf("%f", &students[i].group[j]);
			while (getchar() != '\n')
				continue;
		}
	}
}

float get_student_avg(s_student students[], int n)
{
	int i = 0;
	float sum = 0;
	int j = 0;
	float class_sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < GROUP_NUM; j ++)
			sum += students[i].group[j];
		students[i].avg = sum / GROUP_NUM;
		class_sum += sum;
	}
	return class_sum;
}

void display(const s_student students[], int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i ++)
	{
		printf("%s %s,", students[i].name.first, students[i].name.last);
		printf("Score:");
		for (j = 0; j < GROUP_NUM; j ++)
			printf("%.2f ", students[i].group[j]);
		printf("avg:%.2f\n", students[i].avg);
	}
}

int main(void)
{
	s_student students[CSIZE] = {
		{.name = {"san", "zhang"}},
		{.name = {"si", "li"}},
		{.name = {"wu", "wang"}},
		{.name = {"liu", "sun"}}
	};
	printf("students name is:\n");
	display(students, CSIZE);
	float class_sum = 0;
	get_score(students, CSIZE);
	class_sum = get_student_avg(students, CSIZE);
	display(students, CSIZE);
	printf("The class's avg is %.2f\n", class_sum / CSIZE);
	return 0;
}
