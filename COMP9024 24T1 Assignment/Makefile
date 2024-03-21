# CC      = gcc
# CFLAGS  = -Wall -Wextra -Wpedantic -Werror -O0 -g
# LIBS	= -lm -lxml2 -lcurl -I/usr/include/libxml2

# # If dcc is available, use it
# ifneq ($(shell which dcc),)
# 	CC = dcc
# endif

# .PHONY: all clean

# all: crawler 

# crawler: crawler.c graph.c list.c
# 	$(CC) $(CFLAGS) $(POSIX) -o $@ $^ $(LIBS)

# clean:
# 	rm -f crawler
# 	rm -rf *.dSYM


##################### Test Make #####################


CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11

testFile : testFile.o list.o
	$(CC) $(CFLAGS) -o testFile testFile.o list.o

testFile.o : testFile.c list.h
	$(CC) $(CFLAGS) -c testFile.c

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c


clean:
	rm -f *.o, testFile

