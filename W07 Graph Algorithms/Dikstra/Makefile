CC      = gcc
CFLAGS  = -Wall -Werror -std=c11

dijkstra : dijkstra.o PQueue.o WGraph.o
	$(CC) $(CFLAGS) -o dijkstra dijkstra.o PQueue.o WGraph.o

dijkstra.o : dijkstra.c PQueue.h 
	$(CC) $(CFLAGS) -c dijkstra.c

WGraph.o : WGraph.c WGraph.h
	$(CC) $(CFLAGS) -c WGraph.c

PQueue.o : PQueue.c PQueue.h
	$(CC) $(CFLAGS) -c PQueue.c

clean : 
	rm -f *.o dijkstra