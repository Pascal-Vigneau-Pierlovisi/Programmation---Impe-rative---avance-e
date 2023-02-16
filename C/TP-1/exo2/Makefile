CC=gcc
CFLAGS=-Wall -pedantic -g

all: main

pile.o: pile.h pile.c
	$(CC) -c pile.c -o pile.o

main:main.c pile.o
	$(CC) $(CFLAGS) -o main main.c pile.o

clean:
	rm *.o pile
