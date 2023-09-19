#include <stdio.h>

#include "NodeListElement.h"

void printNodeListElement (NodeListElement aE)
{
	printf ("Not printable!\n");
	return;
}

int isNodeListElementEqual (struct Node * aValue, NodeListElement * aE)
{
	if (aValue == aE->Value)
	{
		return 1;
	}
	return 0;
}
