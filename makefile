CC=gcc
CFLAGS=-c -Wall -g

all: main

main: utils.o main.o
	$(CC) utils.o main.o -o main

utils.o: utils.c
	$(CC) $(CFLAGS) utils.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	/bin/rm -f main *.o *.tar.gz
