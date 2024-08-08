CC = gcc
CFLAGS = -Wall -g

gap.o: gap.c
	$(CC) $(CFLAGS) -c gap.c

all: gap.o

gap_test: tests/gap_test.c gap.o
	$(CC) $(CFLAGS) tests/gap_test.c gap.o -o tests/gap_test

test: gap_test 
	./tests/gap_test

clean:
	rm gap.o tests/gap_test
