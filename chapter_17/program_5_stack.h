#ifndef _STACK_H
#define _STACK_H
#include <stdbool.h>

#define MAXSTACK 10
#define MAXSTRING 100

typedef struct item {
	char str[MAXSTRING];
} Item;

typedef struct node {
	Item item;
	struct node *next;
	struct node *front;
} Node;

typedef struct stack
{
	Node *top;
	Node *rear;
	int items;
} Stack;

void InitializeStack(Stack *st);
bool StackIsEmpty(const Stack *st);
bool StackIsFull(const Stack *st);
int StackItemCount(const Stack *st);
bool push(Item item, Stack *st);
bool pop(Item *item, Stack *st);
void EmptyTheStack(Stack *st);

#endif
