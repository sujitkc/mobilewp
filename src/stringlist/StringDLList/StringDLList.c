#include <stdio.h>
#include <stdlib.h>
#include "StringDLList.h"

void initStringDLList (StringDLList * aL)
{
	aL->Head = aL->Tail = NULL;
	aL->Size = 0;
}

unsigned int getStringDLListSize (StringDLList * aL)
{
	return aL->Size;
}

void pushBackStringDLList (StringDLList * aL, StringListElement aE)
{
	StringDLListNode* TempNode;
	TempNode = (StringDLListNode *) malloc (sizeof (StringDLListNode));
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

void pushFrontStringDLList (StringDLList * aL, StringListElement aE)
{
}

StringListElement popBackStringDLList (StringDLList * aL)
{
	StringListElement LE;
	StringDLListNode * TempNode;
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

StringListElement popFrontStringDLList (StringDLList * aL)
{
}

StringListElement lastStringDLList (StringDLList * aL)
{
	StringListElement LE;
	if (aL->Tail)
	{
		LE = aL->Tail->Item;
	}
	return LE;
}

StringListElement * getStringListElement (StringDLList * aL, const unsigned int aIndex)
{
	unsigned int i = 0;
	StringDLListNode* TempNode;
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

void printStringDLList (StringDLList * aL)
{
	int i;
	StringDLListNode* TempNode;
	if (aL->Head == NULL)
	{
		printf ("List not there. Can't print!\n");
		return;
	}
	TempNode = aL->Head;
	while (TempNode != NULL)
	{
		printStringListElement (TempNode->Item);
		TempNode = TempNode->Next;
	}
	return;
}

void printReverseStringDLList (StringDLList * aL)
{
	int i;
	StringDLListNode* TempNode = aL->Tail;
	while (TempNode != NULL)
	{
		printStringListElement (TempNode->Item);
		TempNode = TempNode->Prev;
	}
	return;

}

/* Returns pointer to the DLList element if its content (node-pointer) is found the same as the one passed as argument (aValue).
 * On failure, it returns 0
*/
StringDLListNode * searchDLList (StringDLList* aL, const char * aValue)
{
	unsigned int i;
	StringDLListNode* TempNode = aL->Head;
	while (TempNode != NULL)
	{
		if (isStringListElementEqual (aValue, &(TempNode->Item)))
		{
			return TempNode;
		}
		TempNode = TempNode->Next;
	}
	return 0;
}
