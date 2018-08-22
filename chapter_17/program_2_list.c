#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "program_2_list.h"

static void CopyToNode(Item item, Node *pNode);

void InitializeList(List *plist)
{
	plist->head = plist->end = NULL;
}

bool ListIsEmpty(const List *plist)
{
	return (plist->head == plist->end) ? true : false;
}

bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	full = (pt == NULL) ? true : false;
	free(pt);
	return full;
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pt = plist->head;
	while (pt != NULL)
	{
		count ++;
		pt = pt->next;
	}

	return count;
}

bool AddItem(List *plist, Item item)
{
	Node *pnew;
	Node *end = plist->end;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (end == NULL)
	{
		plist->head = plist->end = pnew;
	}
	else
	{
		end->next = pnew;
		plist->end = pnew;
	}

	return true;
}

void Traverse(const List *plist, void(*pf)(Item item))
{
	Node *pNode = plist->head;
	while (pNode != NULL)
	{
		(*pf)(pNode->item);
		pNode = pNode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *pNode = plist->head;
	while (plist->head != NULL)
	{
		pNode = plist->head;
		plist->head = pNode->next;
		free(pNode);
	}
	/*Node *pNode = (*plist)->next;
	(*plist)->next = NULL;
	while (pNode != NULL)
	{
		free(pNode);
		pNode = pNode->next;
	}*/
}

static void CopyToNode(Item item, Node *pNode)
{
	pNode->item = item;
}
