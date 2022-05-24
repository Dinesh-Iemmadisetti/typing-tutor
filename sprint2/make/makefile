CC=g++
CFLAGS = -g -Wall -c
INCLUDEPATH = ./../include
SRCPATH=./../src
OBJPATH=./../obj
BINPATH=./../bin


$(BINPATH)/APP: $(OBJPATH)/main.o $(OBJPATH)/NewUser.o $(OBJPATH)/ExistingUser.o $(OBJPATH)/TypeWriter.o $(OBJPATH)/asterisk.o $(OBJPATH)/First.o
	$(CC) -Wall -g -o APP $(OBJPATH)/main.o $(OBJPATH)/NewUser.o $(OBJPATH)/ExistingUser.o $(OBJPATH)/TypeWriter.o $(OBJPATH)/asterisk.o $(OBJPATH)/First.o
	@mv APP $(BINPATH)/

$(OBJPATH)/main.o: $(SRCPATH)/main.cpp $(INCLUDEPATH)/NewUser.h $(INCLUDEPATH)/ExistingUser.h $(INCLUDEPATH)/TypeWriter.h
	$(CC) $(CFLAGS) $(SRCPATH)/main.cpp -I $(INCLUDEPATH)/
	@mv main.o $(OBJPATH)/

$(OBJPATH)/NewUser.o: $(SRCPATH)/NewUser.cpp $(INCLUDEPATH)/NewUser.h $(INCLUDEPATH)/ExistingUser.h $(INCLUDEPATH)/First.h
	$(CC) $(CFLAGS) $(SRCPATH)/NewUser.cpp -I $(INCLUDEPATH)/
	@mv NewUser.o $(OBJPATH)/

$(OBJPATH)/ExistingUser.o: $(SRCPATH)/ExistingUser.cpp $(INCLUDEPATH)/NewUser.h $(INCLUDEPATH)/ExistingUser.h $(INCLUDEPATH)/TypeWriter.h $(INCLUDEPATH)/First.h
	$(CC) $(CFLAGS) $(SRCPATH)/ExistingUser.cpp -I $(INCLUDEPATH)/
	@mv ExistingUser.o $(OBJPATH)/

$(OBJPATH)/TypeWriter.o: $(SRCPATH)/TypeWriter.cpp $(INCLUDEPATH)/NewUser.h $(INCLUDEPATH)/ExistingUser.h $(INCLUDEPATH)/TypeWriter.h
	$(CC) $(CFLAGS) $(SRCPATH)/TypeWriter.cpp -I $(INCLUDEPATH)/
	@mv TypeWriter.o $(OBJPATH)/

$(OBJPATH)/asterisk.o: $(SRCPATH)/asterisk.cpp $(INCLUDEPATH)/Password.h
	$(CC) $(CFLAGS) $(SRCPATH)/asterisk.cpp -I $(INCLUDEPATH)/
	@mv asterisk.o $(OBJPATH)/

$(OBJPATH)/First.o: $(SRCPATH)/First.cpp $(INCLUDEPATH)/First.h
	$(CC) $(CFLAGS) $(SRCPATH)/First.cpp -I $(INCLUDEPATH)/
	@mv First.o $(OBJPATH)/

clear:
	rm $(BINPATH)/APP $(OBJPATH)/main.o $(OBJPATH)/NewUser.o $(OBJPATH)/ExistingUser.o $(OBJPATH)/TypeWriter.o $(OBJPATH)/asterisk.o $(OBJPATH)/First.o
	

 
