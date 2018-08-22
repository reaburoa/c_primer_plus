#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "s_gets.h"

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

#define BOOK_DATA "./file/program_7.data"

typedef struct book_data {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} s_book;

void menu();
void insert(FILE *fp);
void edit(FILE *fp, int n);
void delete(FILE *fp, int n);
int display(FILE *fp, s_book book);
int get_books(FILE *fp, s_book book);

void delete(FILE *fp, int n)
{
	s_book book;
	char *temp_file = "./file/program_7.data.tmp";
	FILE *tmp_fp;
	tmp_fp = fopen(temp_file, "wb");
	int size = sizeof(s_book);
	if (n > 1)
	{
		s_book lib[n - 1];
		fseek(fp, 0L, SEEK_SET);
		fread(&lib[0], size, n - 1, fp);
		fwrite(&lib[0], size, n - 1, tmp_fp);
	}
	long size_l = size * n;
	fseek(fp, size_l - size, SEEK_SET);
	fread(&book, size, 1, fp);
	printf("Old data is:\n");
	printf("%s by %s: $%.2f\n", book.title, book.author, book.value);
	char check;
	char low_check;
	printf("Do you want to delete this book(y/n)?");
	while (scanf("%c", &check) == 1)
	{
		while (getchar() != '\n')
			continue;
		low_check = tolower(check);
		if (low_check != 'y' && low_check != 'n')
		{
			printf("Please input y or n\n");
			continue;
		}
		else
			break;
	}
	if (low_check == 'y')
	{
		while (fread(&book, size, 1, fp) == 1)
		{
			fwrite(&book, size, 1, tmp_fp);
		}
		rename(temp_file, BOOK_DATA);
		fp = tmp_fp;
		//fclose(tmp_fp);
		//fclose(fp);

	}
	else
	{
		printf("Dont delete anything\n");
	}
}

void edit(FILE *fp, int n)
{
	s_book book;
	int size = sizeof(s_book);
	long size_l = size * n;
	fseek(fp, size_l - size, SEEK_SET);
	fread(&book, size, 1, fp);
	printf("Old data is:\n");
	printf("%s by %s: $%.2f\n", book.title, book.author, book.value);
	printf("Please enter title:");
	while (s_gets(book.title, MAXTITL) == NULL)
	{
		printf("get book title failed\n");
		printf("Please enter title:");
		continue;
	}
	printf("Please enter author:");
	while (s_gets(book.author, MAXAUTL) == NULL)
	{
		printf("get book author failed\n");
		printf("Please enter author:");
		continue;
	}
	printf("Please input the value:");
	scanf("%f", &book.value);
	while (getchar() != '\n')
		continue;
	fseek(fp, size_l - size, SEEK_SET);
	if (fwrite(&book, size, 1, fp) == 1)
		printf("edit book success.\n");
}

int get_books(FILE *fp, s_book book)
{
	int books = 0;
	rewind(fp);
	while (fread(&book, sizeof(book), 1, fp) == 1)
		books ++;
	return books;
}

void insert(FILE *fp)
{
	s_book book;
	s_book library[MAXBKS];
	int i = get_books(fp, book);
	int filecount = i, index = 0;
	puts("Please ad new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (i < MAXBKS && s_gets(library[i].title, MAXTITL) != NULL && library[i].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[i].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[i++].value);
        while (getchar() != '\n')
            continue;
        if (i < MAXBKS)
            puts("Enter the next title.");
    }
    if (i > 0)
    {
        puts("Here is the list of your books:");
        for (index = filecount; index < i; index ++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		fseek(fp, 0L, SEEK_END);
        fwrite(&library[filecount], sizeof(book), i - filecount, fp);
    }
}

int display(FILE *fp, s_book book)
{
	rewind(fp);
	int books = 0;
	printf("Current is:\n");
	while (fread(&book, sizeof(book), 1, fp) == 1)
	{
		printf("%d %s by %s: $%.2f\n", books + 1, book.title, book.author, book.value);
		books ++;
	}

	return books;
}

void menu()
{
	printf("**********************************\n");
	printf("This is manager platform.\n");
	printf("a) add books\tb) edit book\n");
	printf("c) delete book\td) show file data\n");
	printf("q) quit\n");
	printf("**********************************\n");
	printf("Please Choice a menu(a,b,c,d,q):");
}

int main(void)
{
	s_book library[MAXBKS];
	char choice;
	int count = 0;
	int index, filecount;
	FILE *pbook;
	int size = sizeof(s_book);
	int edit_book_no;
	s_book book;
	if ((pbook = fopen(BOOK_DATA, "r+b")) == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", BOOK_DATA);
		exit(EXIT_FAILURE);
	}
	menu();
	while (scanf("%c", &choice) == 1)
	{
		while (getchar() != '\n')
			continue;
		if (choice > 'd' || choice < 'a')
			break;
		switch (choice)
		{
			case 'a':
				insert(pbook);
				break;
			case 'b':
				printf("please input a book number to edit:");
				while (scanf("%d", &edit_book_no) == 1)
				{
					if (edit_book_no < 0 || edit_book_no > MAXBKS)
					{
						printf("Please enter a number between 1 to %d\n", MAXBKS);
						continue;
					}
					else
					{
						while (getchar() != '\n')
							continue;
						break;
					}
				}
				if (edit_book_no < 0 || edit_book_no > MAXBKS)
				{
					printf("Please choice a menu.\n");
				}
				else
				{
					edit(pbook, edit_book_no);
				}
				break;
			case 'c':
				printf("please input a book number to delete:");
				while (scanf("%d", &edit_book_no) == 1)
				{
					if (edit_book_no < 0 || edit_book_no > MAXBKS)
					{
						printf("Please enter a number between 1 to %d\n", MAXBKS);
						continue;
					}
					else
					{
						while (getchar() != '\n')
							continue;
						break;
					}
				}
				if (edit_book_no < 0 || edit_book_no > MAXBKS)
				{
					printf("Please choice a menu.\n");
				}
				else
				{
					delete(pbook, edit_book_no);
				}
				break;
			case 'd':
				printf("There %d books in %s\n", display(pbook, book), BOOK_DATA);
				break;
		}
		menu();
	}
	puts("Bye.");
	fclose(pbook);

	return 0;
}
