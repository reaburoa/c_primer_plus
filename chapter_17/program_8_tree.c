#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "program_8_tree.h"

typedef struct pair {
	Trnode *parent;
	Trnode *child;
} Pair;

static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static bool ToLeftWithName(const Item *i1, const Item *i2);
static bool ToRightWithName(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void(*pf)(Item item));
static void InOrderWithName(const Trnode *root, const Item *item, void(*pf)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static Pair SeekItemWithName(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

void InitializeTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
	return ptree->root == NULL ? true : false;
}

bool TreeIsFull(const Tree *ptree)
{
	return ptree->size == MAXITEMS ? true : false;
}

int TreeItemCount(const Tree *ptree)
{
	return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
	Trnode *new_node;
	Pair seek;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full!\n");
		return false;
	}
	seek = SeekItem(pi, ptree);
	if (seek.child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node!\n");
		return false;
	}

	ptree->size ++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size --;
	return true;
}

void Traverse(const Tree *ptree, void(*pf)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pf);
}

void TraverseWithName(const Tree *pt, const Item *item, void(*pf)(Item item))
{
	if (pt != NULL)
		InOrderWithName(pt->root, item, pf);
}

void DeleteAll(Tree *ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);

	ptree->root = NULL;
	ptree->size = 0;
}

static Trnode *MakeNode(const Item *pi)
{
	Trnode *new_node;
	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static bool ToLeftWithName(const Item *i1, const Item *i2)
{
	if (strcmp(i1->petname, i2->petname) < 0)
		return true;
	else
		return false;
}

static bool ToRightWithName(const Item *i1, const Item *i2)
{
	if (strcmp(i1->petname, i2->petname) > 0)
		return true;
	else
		return false;
}

static void AddNode(Trnode *new_node, Trnode *root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left ==NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "Location error in AddNode()!\n");
		exit(EXIT_FAILURE);
	}
}

static void InOrder(const Trnode *root, void(*pf)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pf);
		(*pf)(root->item);
		InOrder(root->right, pf);
	}
}

static void InOrderWithName(const Trnode *root, const Item *item, void(*pf)(Item item))
{
	if (root != NULL)
	{
		InOrderWithName(root->left, item, pf);
		if (strcmp(root->item.petname, item->petname) == 0)
			(*pf)(root->item);
		InOrderWithName(root->right, item, pf);
	}
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	if (ptree->root == NULL)
	{
		look.child = NULL;
		return look;
	}
	else
		look.child = ptree->root;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}

	return look;
}

static Pair SeekItemWithName(const Item *pi, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	if (ptree->root == NULL)
	{
		look.child = NULL;
		return look;
	}
	else
		look.child = ptree->root;
	while (look.child != NULL)
	{
		if (ToLeftWithName(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRightWithName(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}

	return look;
}

static void DeleteNode(Trnode **ptr)
{
	Trnode *temp;
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void DeleteAllNodes(Trnode *root)
{
	Trnode *pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

