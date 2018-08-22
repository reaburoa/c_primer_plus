#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ROW 20
#define LOW 31
#define DATA_FILE "./file/program_12.data"
#define IMG_FILE "./file/program_13.data.img"
#define MAX 40
#define IMG " .':~*=@%#"

void init_data(int row, int low, char arr[row][low], FILE *fp);
void display_arr(int row, int low, char arr[row][low]);
void render_img(FILE *fp, int row, int low, char arr[row][low]);

int main(void)
{
	int row, low;
	printf("Please input row and low:\n");
	scanf("%d %d", &row, &low);
	char arr_file[row][low];
	FILE *fp;
	if ((fp = fopen(DATA_FILE, "r")) == NULL) 
	{
		fprintf(stderr, "Open %s file failed\n", DATA_FILE);
		exit(EXIT_FAILURE);
	}
	init_data(row, low, arr_file, fp);
	fclose(fp);
	printf("Old file info is:\n");
	display_arr(row, low, arr_file);
	FILE *fp_img;
	if ((fp_img = fopen(IMG_FILE, "w+")) == NULL)
	{
		fprintf(stderr, "Open img file failed\n");
		exit(EXIT_FAILURE);
	}
	render_img(fp_img, row, low, arr_file);
	printf("Done\n");
	fclose(fp_img);
	return 0;
}

void render_img(FILE *fp, int row, int low, char arr[row][low])
{
	int i = 0, j = 0;
	for (i = 0; i < row; i ++)
	{
		for (j = 0; j < low; j ++)
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
		putc('\n', fp);
	}
}

void init_data(int row, int low, char arr[row][low], FILE *fp)
{
	char ch;
	int i = 0, j = 0;
	while ((ch = getc(fp)) != EOF)
	{
		if (i >= row)
			break;
		if (ch == ' ') 
			continue;
		arr[i][j] = ch;
		j ++;
		if (j == low) 
		{
			arr[i][j] = '\0';
			if (ch != '\n')
			{
				char temp;
				while ((temp = getc(fp)) != '\n')
					continue;
			}
			j = 0;
			i ++;
			continue;
		}
	}
}

void display_arr(int row, int low, char arr[row][low])
{
	int i = 0, j = 0;
	for (i = 0; i < row; i ++)
	{
		for (j = 0; j < low; j ++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}
