#compiler
CC 	=	gcc


#include
CSAPP_INC= 	./csapp
CSAPP_SRC= 	./csapp
CSAPP    =	./csapp/csapp.o

# compiler flag
CFLAGS 	= 	-Wall -I $(CSAPP_INC)

#C++ Compiler flags
CXXFLAGS=	-g -std=c++11 -Wall -pedantic
LDLIBS 	= 	-lpthread

TRANS_INC=	./translation
TRANS_SRC=	./translation
TRANS	=	./translation/translation-engine.o

LOG	= 	../logger/logger.cpp
PUGI	= 	./dependencies/pugixml/pugixml.o
PUGIXML	= 	./dependencies/pugixml/pugixml.cpp \
		./dependencies/pugixml/pugixml.hpp \
		./dependencies/pugixml/pugiconfig.hpp

MSG	=	./message_elements/*

JSON	=	./dependencies/json.hpp

PROGS 	=	system_a_client\
		system_b_client\
		system_server\

all:	        $(CSAPP_O) $(TRAN_O) $(LOG) $(PROGS)

$(CSAPP_O):     $(shell g++ -c $(CSAPP))
$(TRAN_O):	$(shell g++ -c $(TRANS))
$(PROGS): 	$(CSAPP) $(PUGI) $(JSON) $(TRANS) $(MSG)
$(PUGI): 	$(PUGIXML)
$(TRANS):	$(TRANS_SRC)/translation-engine.cpp $(TRANS_INC)/translation-engine.h
$(CSAPP): 	$(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

clean:
		rm -rf $(PROGS) *.o $(PUGI) *.dSYM

