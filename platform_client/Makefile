#compiler
CC 	=	gcc


#include
CSAPP_INC= 	./csapp
CSAPP_SRC= 	./csapp
CSAPP 	= 	$(CSAPP_SRC)/csapp.o

# compiler flag
CFLAGS 	= 	-Wall -I $(CSAPP_INC)

#C++ Compiler flags
CXXFLAGS=	-g -std=c++11 -Wall -pedantic
LDLIBS 	= 	-lpthread

LOG	= 	../logger/logger.cpp
PUGI	= 	./dependencies/pugixml/pugixml.o
PUGIXML	= 	./dependencies/pugixml/pugixml.cpp \
		./dependencies/pugixml/pugixml.hpp \
		./dependencies/pugixml/pugiconfig.hpp

PROGS 	=	system_a_client\
		system_b_client\
		system_server\

all:
	$(CSAPP_SRC)/csapp.o $(LOG) $(PROGS)

$(PROGS): $(CSAPP) $(PUGI)
$(PUGI): $(PUGIXML)
$(CSAPP): $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

clean:
	rm -rf $(PROGS) *.o $(PUGI) *.dSYM

