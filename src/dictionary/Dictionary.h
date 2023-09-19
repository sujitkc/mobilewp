#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "NodeDLList.h"

typedef struct Node
{
	int isMarked;
	char Value;
	struct NodeDLList ChildList;
	unsigned int Number;
} Node;

static void createNode (const char *, Node *, const unsigned int);
static unsigned int getNoOfChildren (Node *);
static Node * getChildByIndex (const unsigned int, Node *);
static Node * newNode (const char);
static void printNode (Node *, int);

typedef struct Dictionary
{
	Node * Root;
} Dictionary;

void loadDictionary (const char *, Dictionary *);
void deleteDictionary (Dictionary *);
static int checkPrefix (const char *, Node *);
int isValidPrefix (const char *, Dictionary *);

static void printDictionary (Dictionary *);
#endif
