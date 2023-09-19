INCPATH = -I../ -I../../

BIN = ../../../../bin


all : NodeDLList.o

NodeDLList.o : NodeDLList.c NodeDLList.h
	gcc -c NodeDLList.c $(INCPATH) -o $(BIN)/NodeDLList.o;

NodeDLList.h : ../NodeListElement.h
	touch NodeDLList.h;
