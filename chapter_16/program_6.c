#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENG 40

typedef struct name {
	char last[NAME_LENG];
	char first[NAME_LENG];
} s_name;

#define NUM 40
void fillarray(s_name name[], int n);
void showarray(const s_name name[], int n);
int mycomp(const void *name1, const void *name2);
char rrand();

char rrand()
{
	int next;
	next = next * 1103515245 + 12345;
	return (next /65535) % 25 + 65;
}

void fillarray(s_name name[], int n)
{
	int i = 0, j = 0;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i ++)
		for (j = 0; j < NUM / 2; j ++)
		{
			name[i].last[j] = rrand();
			name[i].first[j] = rrand();
			if (j == 19)
			{
				name[i].last[j] = '\0';
				name[i].first[j] = '\0';
			}
		}
}

void showarray(const s_name name[], int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
		printf("%d name is %s %s\n", i + 1, name[i].last, name[i].first);

	printf("\n");
}

int mycomp(const void *name1, const void *name2)
{
	const s_name *name_s1 = (const s_name *)name1;
	const s_name *name_s2 = (const s_name *)name2;
	int res;
	res = strcmp(name_s1->last, name_s2->last);
	return res == 0 ? strcmp(name_s1->first, name_s2->first) : res;
}

#define NUMS 15

int main(void)
{
	s_name names[NUMS];
	fillarray(names, NUMS);
	printf("Origin data is:\n");
	showarray(names, NUMS);
	qsort(names, NUMS, sizeof(s_name), mycomp);
	printf("sort data is:\n");
	showarray(names, NUMS);
	return 0;
}
