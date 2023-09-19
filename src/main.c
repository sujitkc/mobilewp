#include <stdio.h>
#include <stdlib.h>
#include "Dictionary.h"
#include "Wp.h"
#include "StringDLList.h"

int main ()
{
	Dictionary * dictionary = (Dictionary *)malloc (sizeof (Dictionary));
	WordProcessor Wp;
	loadDictionary ("linux.words.txt", dictionary);
	initStringDLList (&(Wp.PrefixList));
	processWord (&Wp, dictionary);
	deleteDictionary (dictionary);
	return 0;
}
