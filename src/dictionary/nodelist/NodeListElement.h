#ifndef NODELISTELEMENT_H
#define NODELISTELEMENT_H

struct Node;

typedef struct NodeListElement
{
	struct Node * Value;
} NodeListElement;

void printNodeListElement (NodeListElement);
int isNodeListElementEqual (struct Node *, NodeListElement *);
#endif
