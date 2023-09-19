INCPATH = -I./ -Inodelist/ -Inodelist/NodeDLList/

BIN = ../../bin

all :
	make -C nodelist; \
	make Dictionary.o;

Dictionary.o : Dictionary.c Dictionary.h
	gcc -c Dictionary.c $(INCPATH) -o $(BIN)/Dictionary.o
