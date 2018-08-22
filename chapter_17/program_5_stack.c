#include <stdio.h>
#include <stdlib.h>

#include "program_5_stack.h"

static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *item);

void InitializeStack(Stack *st)
{
	st->top = st->rear = NULL;
	st->items = 0;
}

bool StackIsEmpty(const Stack *st)
{
	return st->items == 0;
}

bool StackIsFull(const Stack *st)
{
	return st->items == MAXSTACK;
}

int StackItemCount(const Stack *st)
{
	return st->items;
}

bool push(Item item, Stack *st)
{
	Node *pnew;
	if (StackIsFull(st))
		return false;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (StackIsEmpty(st))
	{
		pnew->front = NULL;
		st->top = pnew;
		st->rear = pnew;
	}
	else
	{
		st->top->next = pnew;
		pnew->front = st->top;
	}
	st->top = pnew;
	st->items ++;
	return true;
}

bool pop(Item *item, Stack *st)
{
	Node *pt;
	if (StackIsEmpty(st))
		return false;
	pt = st->top;
	CopyToItem(pt, item);
	st->top->next = NULL;
	st->top = pt->front;
	free(pt);
	st->items --;
	if (st->items == 0)
		st->rear = NULL;
	return true;
}

void EmptyTheStack(Stack *st)
{
	Item dummy;
	while (!StackIsEmpty(st))
		pop(&dummy, st);
}

static void CopyToNode(Item item, Node *pn)
{
	pn->item = item;
}

static void CopyToItem(Node *pn, Item *item)
{
	*item = pn->item;
}
