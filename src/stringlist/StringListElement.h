#ifndef STRINGLISTELEMENT_H
#define STRINGLISTELEMENT_H

typedef struct StringListElement
{
	char Value[100];
} StringListElement;

void printStringListElement (StringListElement);
int isStringListElementEqual (const char *, StringListElement *);
#endif
