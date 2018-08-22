#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define ID_MAX 0xFF
#define SIZE_MAX 0x7F
#define LEFT 0
#define CENTER 1
#define RIGHT 2

const char *alignment[3] = {"left", "center", "right"};
const char *switch_btn[2] = {"off", "on"};

typedef struct font {
	unsigned int id : 8;
	unsigned int size :7;
	unsigned int : 1;
	unsigned int alignment : 2;
	bool bord : 1;
	bool italic : 1;
	bool underline : 1;
	unsigned int : 3;
} s_font;

char getChoice();
bool inArr(char *arr, char ch);
void setSize(s_font *font);
void setId(s_font *font);
void setAlignment(s_font *font);
void toggleBord(s_font *font);
void toggleItalic(s_font *font);
void toggleUnderline(s_font *font);

void toggleUnderline(s_font *font)
{
	font->underline = font->underline == 1 ? 0 : 1;
}

void toggleItalic(s_font *font)
{
	font->italic = font->italic == 1 ? 0 : 1;
}

void toggleBord(s_font *font)
{
	font->bord = font->bord == 1 ? 0 : 1;
}

void setAlignment(s_font *font)
{
	char choose;
	printf("Select alignment:\n");
	printf("l) left\tc) center\tr) right\n");
	while (scanf("%c", &choose) == 1)
	{
		while (getchar() != '\n')
			continue;
		choose = tolower(choose);
		if (choose != 'l' && choose != 'c' && choose != 'r')
		{
			printf("Enter char l or c or r:");
			continue;
		}
		else
		{
			switch (choose)
			{
				case 'l':
					font->alignment = LEFT;
					break;
				case 'c':
					font->alignment = CENTER;
					break;
				case 'r':
					font->alignment = RIGHT;
					break;
			}
			break;
		}
	}
}

void setId(s_font *font)
{
	int id;
	printf("Enter font id (0-255):");
	while (scanf("%d", &id) == 1)
	{
		while (getchar() != '\n')
			continue;
		if (id > 255 || id < 0)
		{
			printf("Please enter 0-255:");
			continue;
		}
		else
		{
			font->id = id & ID_MAX;
			break;
		}
	}
}

void setSize(s_font *font)
{
	int size;
	printf("Enter font size (0-127):");
	while (scanf("%d", &size) == 1)
	{
		if (size > 127 || size < 0)
		{
			printf("Please enter size 0-127:");
			continue;
		}
		else
		{
			font->size = size & SIZE_MAX;
			break;
		}
	}
}

bool inArr(char *arr, char ch)
{
	int length = strlen(arr);
	int i = 0;
	for (i = 0; i < length; i ++)
		if (arr[i] == ch)
			return true;
	return false;
}

char getChoice()
{
	char choice;
	printf("*******************Menu Below*****************************\n");
	printf("f) change font\ts) change size\ta) change alignment\n");
	printf("b) toggle bold\ti) toggle italic\tu) toggle underline\n");
	printf("q) quit\n");
	printf("**********************************************************\n");
	printf("Please Choice below:\n");
	char chooses[8] = "fsabiuq";
	while (scanf("%c", &choice) == 1)
	{
		while (getchar() != '\n')
			continue;
		choice = tolower(choice);
		if (!inArr(chooses, choice))
		{
			printf("Please choose from the Menu:");
			continue;
		}
		else
			break;
	}
	return choice;
}

int main(void)
{
	s_font ff = {
		.id = 0,
		.size = 0,
		.alignment = 0,
		.bord = 0,
		.italic = 0,
		.underline = 0
	};
	char choice = getChoice();
	while (choice && choice != 'q')
	{
		switch (choice)
		{
			case 'f':
				setId(&ff);
				break;
			case 's':
				setSize(&ff);
				break;
			case 'a':
				setAlignment(&ff);
				break;
			case 'b':
				toggleBord(&ff);
				break;
			case 'i':
				toggleItalic(&ff);
				break;
			case 'u':
				toggleUnderline(&ff);
				break;
		}
		printf("\n%-4s %-4s %-9s %-3s %-3s %-3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
		printf("%-4d %-4d %-9s %-3s %-3s %-3s\n", ff.id, ff.size, alignment[ff.alignment], switch_btn[ff.bord], switch_btn[ff.italic], switch_btn[ff.underline]);
		choice = getChoice();
	}
	return 0;
}
