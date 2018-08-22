#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "program_3_list.h"

static void CopyToNode(Item item, Node *pNode);

void InitializeList(List *plist)
{
	plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
	return (plist->items == 0) ? true : false;
}

bool ListIsFull(const List *plist)
{
	return plist->items == MAXSIZE;
}

unsigned int ListItemCount(const List *plist)
{
	return plist->items;
}

bool AddItem(List *plist, Item item)
{
	if (ListIsFull(plist))
		return false;
	plist->entries[plist->items++] = item;

	return true;
}

void Traverse(const List *plist, void(*pf)(Item item))
{
	int i = 0;
	for (i = 0; i < plist->items; i ++)
		(*pf)(plist->entries[i]);
}

void EmptyTheList(List *plist)
{
	plist->items = 0;
}

