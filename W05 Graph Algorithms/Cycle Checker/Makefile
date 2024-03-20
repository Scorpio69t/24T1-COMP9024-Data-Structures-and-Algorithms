CC      = gcc
CFLAGS  = -Wall -Werror -std=c11

graphAnalyser : cycleCheck.o Graph.o
	$(CC) $(CFLAGS) -o cycleCheck cycleCheck.o Graph.o

graphAnalyser.o : cycleCheck.c Graph.h
	$(CC) $(CFLAGS) -c cycleCheck.c

Graph.o : Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c

clean : 
	rm -f *.o cycleCheck