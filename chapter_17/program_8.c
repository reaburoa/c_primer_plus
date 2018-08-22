#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "program_8_tree.h"
#include "s_gets.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(Tree *pt);
void findAllpet(Tree *pt);
void printitem(Item item);
void uppercase(char *str);

int main(void)
{
	Tree pets;
	char choice;
	InitializeTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a':
				addpet(&pets);
				break;
			case 'l':
				showpets(&pets);
				break;
			case 'f':
				findAllpet(&pets);
				break;
			case 'g':
				findpet(&pets);
				break;
			case 'n':
				printf("%d pets in club\n", TreeItemCount(&pets));
				break;
			case 'd':
				droppet(&pets);
				break;
			default:
				break;
		}
	}
	DeleteAll(&pets);
	printf("Bye.\n");

	return 0;
}

char menu(void)
{
	int ch;
	printf("**************************************************\n");
	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a) add a pet   l) show list of pets");
	puts("n) number of pets   f) find pets with pet name");
	puts("g) find pet with name and kind");
	puts("d) delete a pet   q) quit");
	printf("**************************************************\n");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("alfgndq", ch) == NULL)
			puts("Please enter an a, l, f, n, d, or q:");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';

	return ch;
}

void addpet(Tree *pt)
{
	Item temp;
	if (TreeIsFull(pt))
		puts("No room in the club!");
	else
	{
		puts("Please enter the name of pet:");
		s_gets(temp.petname, SLEN);
		puts("Please enter pet kind:");
		s_gets(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, pt);
	}
}

void showpets(const Tree *pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		Traverse(pt, printitem);
}

void printitem(Item item)
{
	printf("pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(Tree *pt)
{
	Item temp;
	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find:");
	s_gets(temp.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);
	if (InTree(&temp, pt))
		printf("is a member.\n");
	else
		printf("is not a member.\n");
}

void droppet(Tree *pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No Entries!");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	s_gets(temp.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);
	if (DeleteItem(&temp, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

void uppercase(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str ++;
	}
}

void findAllpet(Tree *pt)
{
	Item temp;
	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find:");
	s_gets(temp.petname, SLEN);
	uppercase(temp.petname);
	printf("name %s all pets:\n", temp.petname);
	TraverseWithName(pt, &temp, printitem);
}
