INCPATH = -I../

BIN = ../../../bin

all :
	make -C NodeDLList; \
	make NodeListElement.o;

NodeListElement.o : NodeListElement.c NodeListElement.h
	gcc -c NodeListElement.c $(INCPATH) -o $(BIN)/NodeListElement.o
