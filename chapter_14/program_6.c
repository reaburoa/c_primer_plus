#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_MAX 40
#define SPORTOR_NUMS 19

typedef struct sportor {
	char first[NAME_MAX];
	char last[NAME_MAX];
	int in_nums;
	int hit_nums;
	int run_nums;
	int dot_nums;
	float hit_rate;
} s_sportor;

#define DATA_FILE "./file/program_6.data"

int get_data(FILE *fp, s_sportor sportor[], int *ar_no);
void get_hit_rate(s_sportor s[], int *ar, int n);
void display(s_sportor s[], int *ar, int n);
bool in_arr(int n, int *ar);

bool in_arr(int n, int *ar)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		if (*(ar + i) == n) 
			return true;
	}
	return false;
}

int get_data(FILE *fp, s_sportor sportor[], int *ar_no)
{
	int i = 0;
	while (!feof(fp))
	{
		bool in_array = false;
		int no = -1;
		char last[NAME_MAX], first[NAME_MAX];
		int in_num, hit_num, lei_num, dot_num;
		fscanf(fp, "%d %40s %40s %d %d %d %d", &no, last, first, &in_num, &hit_num, &lei_num, &dot_num);
		if (no >= 0) 
		{
			strcpy(sportor[no].last, last);
			strcpy(sportor[no].first, first);
			if (in_arr(no, ar_no) == false) 
			{
				sportor[no].in_nums = in_num;
				sportor[no].hit_nums = hit_num;
				sportor[no].run_nums = lei_num;
				sportor[no].dot_nums = dot_num;
			}
			else 
			{
				sportor[no].in_nums += in_num;
				sportor[no].hit_nums += hit_num;
				sportor[no].run_nums += lei_num;
				sportor[no].dot_nums += dot_num;
			}
			if (in_arr(no, ar_no) == false)
			{
				ar_no[i] = no;
				i ++;
			}
		}
	}
	return i;
}

void get_hit_rate(s_sportor s[], int *ar, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		int no = *(ar + i);
		if (s[no].in_nums != 0)
			s[no].hit_rate = 1.0 * s[no].hit_nums / s[no].in_nums;
	}
}

void display(s_sportor s[], int *ar, int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		int no = *(ar + i);
		printf("%d %s %s %d %d %d %d %d%\n", no, s[no].last, s[no].first, s[no].in_nums, s[no].hit_nums, s[no].run_nums, s[no].dot_nums, (int)(s[no].hit_rate*100));
	}
}

int main(void)
{
	FILE *fp;
	if ((fp = fopen(DATA_FILE, "r")) == NULL)
	{
		printf("Open file %s failed\n", DATA_FILE);
		exit(EXIT_FAILURE);
	}
	int sportor_nos[SPORTOR_NUMS], sportor_nums;
	s_sportor sportor[SPORTOR_NUMS];
	sportor_nums = get_data(fp, sportor, sportor_nos);
	fclose(fp);
	get_hit_rate(sportor, sportor_nos, sportor_nums);
	printf("no\tlast\tfirst\tin_nums\thit_nums\trun_nums\tdot_nums\thit_rate\n");
	display(sportor, sportor_nos, sportor_nums);
	return 0;
}
