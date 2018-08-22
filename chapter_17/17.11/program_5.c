#include <stdio.h>

#include "stack.h"

int main(void)
{
	Stack stack;

	Item temp;
	char ch;
	
	InitializeStack(&stack);
	puts("Testing the Stack interface.Type a to add a value,");
	puts("type d to delete a value, and type q to quit.");
	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a' && ch != 'd')
			continue;
		switch (ch)
		{
			case 'a':
				printf("Integer to add:");
				scanf("%d", &temp);
				if (!StackIsFull(&stack))
				{
					printf("Putting %d into stack\n", temp);
					push(temp, &stack);
				}
				else
					puts("Stack is full");
				break;
			default:
				if (StackIsEmpty(&stack))
					puts("Nothing to delete!");
				else
				{
					pop(&temp, &stack);
					printf("Removing %d from stack\n", temp);
				}
				break;
		}

		printf("%d items in stack\n", StackItemCount(&stack));
		puts("Type a to add, d to delete, q to quit:");
	}

	EmptyTheStack(&stack);
	puts("Bye!");

	return 0;
}
