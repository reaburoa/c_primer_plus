#include <stdio.h>
#include <string.h>

#include "program_5_stack.h"

char *s_gets(char *str, int n);

char *s_gets(char *str, int n)
{
	char *ret_val, *find;
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

int main(void)
{
	Stack stack;

	Item temp;
	char input[MAXSTRING];
	
	InitializeStack(&stack);
	printf("Please enter a string what push to stack:\n");
	while (s_gets(input, MAXSTRING) != NULL && input[0] != '\0')
	{
		if (StackIsFull(&stack))
		{
			printf("Stack is full!\n");
			break;
		}
		strcpy(temp.str, input);
		push(temp, &stack);

		printf("%d items in stack\n", StackItemCount(&stack));
		printf("Please enter a string what push to stack:\n");
	}
	printf("You push to stack info is:\n");
	while (!StackIsEmpty(&stack)) 
	{
		pop(&temp, &stack);
		printf("Stack info is %s\n", temp.str);
	}

	EmptyTheStack(&stack);
	puts("Bye!");

	return 0;
}
