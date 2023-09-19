INCPATH = -I./ -Idictionary/ -Idictionary/nodelist/ -Idictionary/nodelist/NodeDLList -I./wp/ -Istringlist/ -Istringlist/StringDLList/

BIN = ../bin

$(BIN)/mobilewp : \
	$(BIN)/main.o \
	$(BIN)/Dictionary.o \
	$(BIN)/NodeDLList.o \
	$(BIN)/NodeListElement.o \
	$(BIN)/StringDLList.o \
	$(BIN)/StringListElement.o \
	$(BIN)/Wp.o \
	$(BIN)/main.o
	gcc $(BIN)/Dictionary.o \
	$(BIN)/NodeDLList.o \
	$(BIN)/NodeListElement.o \
	$(BIN)/StringDLList.o \
	$(BIN)/StringListElement.o \
	$(BIN)/Wp.o \
	$(BIN)/main.o \
	-o $(BIN)/mobilewp;

$(BIN)/Dictionary.o : dictionary/Dictionary.c dictionary/Dictionary.h dictionary/nodelist/NodeListElement.h
	gcc -c dictionary/Dictionary.c $(INCPATH) -o $(BIN)/Dictionary.o

$(BIN)/NodeListElement.o : dictionary/nodelist/NodeListElement.c dictionary/nodelist/NodeListElement.h
	gcc -c dictionary/nodelist/NodeListElement.c $(INCPATH) -o $(BIN)/NodeListElement.o

$(BIN)/NodeDLList.o : dictionary/nodelist/NodeDLList/NodeDLList.c dictionary/nodelist/NodeDLList/NodeDLList.h
	gcc -c dictionary/nodelist/NodeDLList/NodeDLList.c $(INCPATH) -o $(BIN)/NodeDLList.o

dictionary/nodelist/NodeDLList/NodeDLList.h : dictionary/nodelist/NodeListElement.h
	touch dictionary/nodelist/NodeDLList/NodeDLList.h

$(BIN)/StringListElement.o : stringlist/StringListElement.c stringlist/StringListElement.h
	gcc -c stringlist/StringListElement.c $(INCPATH) -o $(BIN)/StringListElement.o

$(BIN)/StringDLList.o : stringlist/StringDLList/StringDLList.c stringlist/StringDLList/StringDLList.h
	gcc -c stringlist/StringDLList/StringDLList.c $(INCPATH) -o $(BIN)/StringDLList.o;

stringlist/StringDLList/StringDLList.h : stringlist/StringListElement.h
	touch stringlist/StringDLList/StringDLList.h

$(BIN)/Wp.o : wp/Wp.c wp/Wp.h dictionary/Dictionary.h
	gcc -c wp/Wp.c $(INCPATH) -o $(BIN)/Wp.o

$(BIN)/main.o : main.c dictionary/Dictionary.h stringlist/StringDLList/StringDLList.h wp/Wp.h
	gcc -c main.c $(INCPATH) -o $(BIN)/main.o

clean : 
	rm $(BIN)/mobilewp; \
	rm $(BIN)/*.o; \
	rm *~

