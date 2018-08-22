#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ROW 20
#define LOW 30
#define DATA_FILE "./file/program_14.data"
#define IMG_FILE "./file/program_14.data.img"
#define MAX 40
#define IMG " .':~*=@%#"

void init_data(int arr[][LOW], FILE *fp);
void display_arr(int (*arr)[LOW], int row);
void render_img(FILE *fp, int (*arr)[LOW], int row);
void fix_data(int (*arr)[LOW]);

int main(void)
{
	int arr_file[ROW][LOW];
	FILE *fp;
	if ((fp = fopen(DATA_FILE, "r")) == NULL) 
	{
		fprintf(stderr, "Open %s file failed\n", DATA_FILE);
		exit(EXIT_FAILURE);
	}
	init_data(arr_file, fp);
	fclose(fp);
	printf("Old file info is:\n");
	display_arr(arr_file, 20);
	printf("Fix data is:\n");
	fix_data(arr_file);
	display_arr(arr_file, 20);
	FILE *fp_img;
	if ((fp_img = fopen(IMG_FILE, "w+")) == NULL)
	{
		fprintf(stderr, "Open img file failed\n");
		exit(EXIT_FAILURE);
	}
	render_img(fp_img, arr_file, 20);
	fclose(fp_img);
	printf("Done\n");
	return 0;
}

void render_img(FILE *fp, int (*arr)[LOW], int row)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i ++)
	{
		for (j = 0; j < LOW; j ++)
		{
			char ch = IMG[arr[i][j]];
			putc(ch, fp);
		}
		putc('\n', fp);
	}
}

void init_data(int arr[][LOW], FILE *fp)
{
	char ch;
	int i = 0, j = 0;
	for (i = 0; i <	ROW; i ++)
		for (j = 0; j < LOW; j ++)
			fscanf(fp, "%d", &arr[i][j]);
}

void fix_data(int (*arr)[LOW])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i ++)
	{
		for (j = 0; j < LOW; j ++)
		{
			int cur = arr[i][j];
			int up = 0, left = 0, right = 0, low = 0;
			int k = 0;
			if (i - 1 >= 0)
			{
				up = arr[i - 1][j];
				k ++;
			}
			if (j - 1 >= 0)
			{
				left = arr[i][j - 1];
				k ++; 
			}
			if (i + 1 < ROW)
			{
				low = arr[i + 1][j];
				k ++;
			}
			if (j + 1 < LOW)
			{
				right = arr[i][j + 1];
				k ++;
			}
			if (cur - up > 1 && cur - left > 1 && cur - right > 1 && cur - low > 1)
			{
				float avg = (left + right + up + low) / k;
				arr[i][j] = (int)avg;
			}
		}
	}
}

void display_arr(int (*arr)[LOW], int row)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i ++)
	{
		for (j = 0; j < LOW; j ++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
