#ifndef STRINGDLLIST_h
#define STRINGDLLIST_h

#include "StringListElement.h"

typedef struct StringDLListNode
{
	StringListElement Item;
	struct StringDLListNode* Next;
	struct StringDLListNode* Prev;
} StringDLListNode;

typedef struct StringDLList
{
	StringDLListNode * Head;
	StringDLListNode * Tail;
	unsigned int Size;
} StringDLList;

void initStringDLList (StringDLList *);
void pushBackStringDLList (StringDLList *, StringListElement);
void pushFrontStringDLList (StringDLList *, StringListElement);
StringListElement popBackStringDLList (StringDLList *);
StringListElement popFrontStringDLList (StringDLList *);
int insertStringDLList (StringDLList *, StringListElement, const unsigned int);
StringListElement * getStringListElement (StringDLList *, const unsigned int);
StringListElement lastStringDLList (StringDLList *);
unsigned int getStringDLListSize (StringDLList *);

#endif
