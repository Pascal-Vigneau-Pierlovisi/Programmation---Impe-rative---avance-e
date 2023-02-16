CC=gcc
CFLAGS=-Wall -pedantic -g

all: pierlovisiExo1

listesTPExo1MainCodeDepart.o: listesTPExo1MainCodeDepart.h listesTPExo1MainCodeDepart.c
	$(CC) -c listesTPExo1MainCodeDepart.c -o listesTPExo1MainCodeDepart.o

pierlovisiExo1:pierlovisiExo1.c listesTPExo1MainCodeDepart.o
	$(CC) $(CFLAGS) -o pierlovisiExo1 pierlovisiExo1.c listesTPExo1MainCodeDepart.o

clean:
	rm *.o pierlovisiExo1
