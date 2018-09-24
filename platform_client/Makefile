#compiler
CC = gcc

#include
CSAPP_INC = ./csapp
CSAPP_SRC = ./csapp

# compiler flag
CFLAGS = -Wall -I $(CSAPP_INC)
LDLIBS = -lpthread

LOG = ../logger/logger.cpp
PROGS = system_a_client\
	system_server\

all: $(CSAPP_SRC)/csapp.o $(PROG) $(LOG) $(PROGS)
$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

clean:
	rm -f $(PROGS) *.o *~

