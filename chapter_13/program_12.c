#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ROW 20
#define LOW 31
#define DATA_FILE "./file/program_12.data"
#define IMG_FILE "./file/program_12.data.img"
#define MAX 40
#define IMG " .':~*=@%#"

void init_data(char arr[][LOW], FILE *fp);
void display_arr(char (*arr)[LOW], int row);
void render_img(FILE *fp, char (*arr)[LOW], int row);
void display_file(FILE *fp);

int main(void)
{
	char arr_file[ROW][LOW];
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
	FILE *fp_img;
	if ((fp_img = fopen(IMG_FILE, "w+")) == NULL)
	{
		fprintf(stderr, "Open img file failed\n");
		exit(EXIT_FAILURE);
	}
	render_img(fp_img, arr_file, 20);
	printf("Done\n");
	fclose(fp_img);
	return 0;
}

void render_img(FILE *fp, char (*arr)[LOW], int row)
{
	int i = 0, j = 0;
	for (i = 0; i < 20; i ++)
	{
		for (j = 0; j < LOW; j ++)
		{
			char ch;
			if (arr[i][j] != '\0') 
			{
				char str[2] = {arr[i][j], '\0'};
				int k = atoi(str);
				ch = IMG[k];
			}
			else 
			{
				ch = '\n';
			}
			putc(ch, fp);
		}
	}
}

void init_data(char arr[][LOW], FILE *fp)
{
	char ch;
	int i = 0, j = 0;
	while ((ch = getc(fp)) != EOF)
	{
		if (ch == ' ') 
			continue;
		if (ch == '\n')
		{
			i ++;
			continue;
		}
		arr[i][j] = ch;
		j ++;
		if (j == 30) 
		{
			arr[i][j] = '\0';
			j = 0;
			continue;
		}
	}
}

void display_arr(char (*arr)[LOW], int row)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i ++)
	{
		for (j = 0; j < LOW; j ++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}
