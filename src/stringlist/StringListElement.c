#include <stdio.h>
#include <string.h>

#include "StringListElement.h"

void printStringListElement (StringListElement aE)
{
	printf ("Not printable!\n");
	return;
}

int isStringListElementEqual (const char * aValue, StringListElement * aE)
{
	if (strcmp (aValue, aE->Value) == 0)
	{
		return 1;
	}
	return 0;
}
