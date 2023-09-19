#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"
#include "NodeListElement.h"
#include "NodeDLList.h"

Node * newNode (const char c)
{
	Node * node = (Node *)malloc (sizeof (Node));
	node->Value = c;
	node->isMarked = 0;
	initNodeDLList (&(node->ChildList));
	return node;
}

unsigned int getNoOfChildren (Node * aNode)
{
	return getNodeListSize (&(aNode->ChildList));
}

Node * getChildByIndex (const unsigned int aIndex, Node * aNode)
{
	NodeListElement * element = getNodeListElement (&(aNode->ChildList), aIndex);
	if (element)
	{
		return element->Value;
	}
	return 0;
}

void addChild (Node * aChild, Node * aNode)
{
	NodeListElement element;
	element.Value = aChild;
	pushBackNodeDLList (&(aNode->ChildList), element);
}

void createNode (const char * aWord, Node * aNode, const unsigned int aNoOfWords)
{
	if (strlen (aWord) == 1)
	{
		Node * child;
		unsigned int i;
		for (i = 0; i < getNoOfChildren (aNode); i++)
		{
			child = getChildByIndex (i, aNode);
			if (child->Value == aWord[0])
			{
				child->isMarked = 1;
				child->Number = aNoOfWords;
				return;
			}
		}	
		child = newNode (aWord[0]);
		addChild (child, aNode);
		child->isMarked = 1;
		child->Number = aNoOfWords;
		return;
	}
	else
	{
		Node * child;
		unsigned int i;
		for (i = 0; i < getNoOfChildren (aNode); i++)
		{
			child = getChildByIndex (i, aNode);
			if (child->Value == aWord[0])
			{
				createNode (aWord + 1, child, aNoOfWords);
				return;
			}
		}	
		child = newNode (aWord[0]);
		addChild (child, aNode);
		createNode (aWord + 1, child, aNoOfWords);
		return;
	}
}
static unsigned int deleted = 0;
void deleteNode (Node * aNode)
{
	unsigned int i;
	unsigned int NoOfChildren = getNoOfChildren (aNode);
	deleted++;
	for (i = 0; i < NoOfChildren; i++)
	{
		deleteNode ((((aNode->ChildList).Tail)->Item).Value);
		popBackNodeDLList (&(aNode->ChildList));
	}
	free (aNode);
}

int checkPrefix (const char * aPrefix, Node * CurrentNode)
{
	unsigned int i;
	if (strlen (aPrefix) == 1 && CurrentNode->Value == aPrefix[0])
	{
		return 1;
	}
	else if (getNoOfChildren (CurrentNode) == 0 || CurrentNode->Value != aPrefix[0])
	{
		return 0;
	}
	for (i = 0; i < getNoOfChildren (CurrentNode); i++)
	{
		if (checkPrefix (aPrefix + 1, getChildByIndex (i, CurrentNode)))
		{
			return 1;
		}
	}
	return 0;
}

int isValidPrefix (const char * aPrefix, Dictionary * aDictionary)
{
	char Prefix [100];
	memset (Prefix, 0, 100);
	strcpy (Prefix + 1, aPrefix);
	Prefix[0] = ' ';
	return checkPrefix (Prefix, aDictionary->Root);
}

void loadDictionary (const char * aFileName, Dictionary * aDictionary)
{
	FILE * fin;
	unsigned int NoOfWords = 0;
	aDictionary->Root = newNode (' ');
	fin = fopen (aFileName, "r");
	
	while (!feof (fin))
	{
		char NextWord[100];
		memset (NextWord, 0, 100);
		fscanf (fin, " %s", NextWord);
		if (strcmp (NextWord, " ") == 0)
		{
			break;
		}
		createNode (NextWord, aDictionary->Root, NoOfWords);
		NoOfWords++;
	}
}

void deleteDictionary (Dictionary * aDictionary)
{
	deleteNode (aDictionary->Root);
	free (aDictionary);
}

void printNode (Node * aNode, int aLevel)
{
	int i;
	printf ("level %d", aLevel);
	for (i = 0; i < aLevel; i++)
	{
		printf (" ");
	}
	printf ("%c\n", aNode->Value);
	if (aNode->isMarked == 1)
	{
		printf (" S. No. %d\n", aNode->Number);
	}
	for (i = 0; i < getNoOfChildren (aNode); i++)
	{
		Node * node = getChildByIndex (i, aNode);
		printNode (node, aLevel + 1);
	}
}

void printDictionary (Dictionary * aD)
{
	printNode (aD->Root, 0);
}

