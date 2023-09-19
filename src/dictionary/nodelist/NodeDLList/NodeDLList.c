#include <stdio.h>
#include <stdlib.h>

#include "NodeDLList.h"

void initNodeDLList (NodeDLList * aL)
{
	aL->Head = aL->Tail = NULL;
	aL->Size = 0;
}

unsigned int getNodeListSize (NodeDLList * aL)
{
	return aL->Size;
}

void pushBackNodeDLList (NodeDLList * aL, NodeListElement aE)
{
	NodeDLListNode* TempNode;
	TempNode = (NodeDLListNode *) malloc (sizeof (NodeDLListNode));
	TempNode->Item = aE;
	TempNode->Next = NULL;
	TempNode->Prev = aL->Tail;
	
	if (aL->Head == NULL)	/* empty list	*/
	{
		aL->Head = TempNode;
		aL->Tail = TempNode;
	}
	else if (aL->Head != NULL)
	{
		aL->Tail->Next = TempNode;
		aL->Tail = TempNode;
	}
	aL->Size++;
	return;
}

void pushFrontNodeDLList (NodeDLList * aL, NodeListElement aE)
{
}

NodeListElement popBackNodeDLList (NodeDLList * aL)
{
	NodeListElement LE;
	NodeDLListNode * TempNode;
	if (aL->Head == NULL)
	{
		printf ("Trying to pop from empty list! Exiting...\n");
		exit (1);
	}
	else if (aL->Size == 1)
	{
		TempNode = aL->Tail;
		LE = aL->Tail->Item;
		aL->Head = aL->Tail = NULL;
		aL->Size = 0;
		free (TempNode);
		return LE;
	}
	else
	{
		LE = aL->Tail->Item;
		aL->Tail = aL->Tail->Prev;
		free (aL->Tail->Next);
		aL->Tail->Next = NULL;
		aL->Size--;
	
		return LE;
	}
}

NodeListElement popFrontNodeDLList (NodeDLList * aL)
{
}

NodeListElement lastNodeDLList (NodeDLList * aL)
{
	NodeListElement LE;
	if (aL->Tail)
	{
		LE = aL->Tail->Item;
	}
	return LE;
}

NodeListElement * getNodeListElement (NodeDLList * aL, const unsigned int aIndex)
{
	unsigned int i = 0;
	NodeDLListNode* TempNode;
	if (aL->Head == NULL)
	{
		printf ("Empty List! Can't access element!\n");
		return 0;
	}
	TempNode = aL->Head;
	while (TempNode != NULL)
	{
		if (i == aIndex)
		{
			return &(TempNode->Item);
		}
		TempNode = TempNode->Next;
		i++;
	}
	return 0;
}

void printNodeDLList (NodeDLList * aL)
{
	int i;
	NodeDLListNode* TempNode;
	if (aL->Head == NULL)
	{
		printf ("List not there. Can't print!\n");
		return;
	}
	TempNode = aL->Head;
	while (TempNode != NULL)
	{
		printNodeListElement (TempNode->Item);
		TempNode = TempNode->Next;
	}
	return;
}

void printReverseNodeDLList (NodeDLList * aL)
{
	int i;
	NodeDLListNode* TempNode = aL->Tail;
	while (TempNode != NULL)
	{
		printNodeListElement (TempNode->Item);
		TempNode = TempNode->Prev;
	}
	return;

}

/* Returns pointer to the DLList element if its content (node-pointer) is found the same as the one passed as argument (aValue).
 * On failure, it returns 0
*/
NodeDLListNode * search (NodeDLList* aL, struct Node * aValue)
{
	unsigned int i;
	NodeDLListNode* TempNode = aL->Head;
	while (TempNode != NULL)
	{
		if (isNodeListElementEqual (aValue, &(TempNode->Item)))
		{
			return TempNode;
		}
		TempNode = TempNode->Next;
	}
	return 0;
}
