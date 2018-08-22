#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
};
typedef struct film Item;

typedef struct node {
	Item item;
	struct node *next;
} Node;

typedef struct list {
	Node *head;
	Node *end;
} List;
//typedef Node * List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(List *plist, Item item);
void Traverse(const List *plist, void(*pf)(Item item));
void EmptyTheList(List *plist);

#endif
