#ifndef NODEDLLIST_H
#define NODEDLLIST_H

#include "NodeListElement.h"

typedef struct NodeDLListNode
{
	NodeListElement Item;
	struct NodeDLListNode* Next;
	struct NodeDLListNode* Prev;
} NodeDLListNode;

typedef struct NodeDLList
{
	NodeDLListNode * Head;
	NodeDLListNode * Tail;
	unsigned int Size;
} NodeDLList;

void initNodeDLList (NodeDLList *);
void pushBackNodeDLList (NodeDLList *, NodeListElement);
void pushFrontNodeDLList (NodeDLList *, NodeListElement);
NodeListElement popBackNodeDLList (NodeDLList *);
NodeListElement popFrontNodeDLList (NodeDLList *);
int insert (NodeDLList *, NodeListElement, const unsigned int);
//int remove (NodeDLList *, const unsigned int);
unsigned int getNodeListSize (NodeDLList *);
NodeListElement * getNodeListElement (NodeDLList *, const unsigned int);
NodeListElement lastNodeDLList (NodeDLList *);

#endif
