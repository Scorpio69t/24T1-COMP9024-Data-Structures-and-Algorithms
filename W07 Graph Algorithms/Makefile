CC      = gcc
CFLAGS  = -Wall -Werror -std=c11

popularityRank : popularityRank.o WGraph.o
	$(CC) $(CFLAGS) -o popularityRank popularityRank.o WGraph.o

popularityRank.o : popularityRank.c WGraph.h
	$(CC) $(CFLAGS) -c popularityRank.c

WGraph.o : WGraph.c WGraph.h
	$(CC) $(CFLAGS) -c WGraph.c

clean : 
	rm -f *.o popularityRank