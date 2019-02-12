CC = gcc
CFLAGS = -Wall -std=c99

all : fleschIndex.o
	$(CC) fleschIndex.c -o fleschIndex -lm

fleschIndex.o : fleschIndex.c
	$(CC) -c $(CFLAGS) fleschIndex.c -o fleschIndex.o -lm

clean :
	rm fleschIndex fleschIndex.o
