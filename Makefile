CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

all: edit

gap.o: gap.c gap.h
	$(CC) $(CFLAGS) -c gap.c

display.o: display.c display.h
	$(CC) $(CFLAGS) -c display.c

gap_test: tests/gap_test.c gap.o
	$(CC) $(CFLAGS) tests/gap_test.c gap.o -o tests/gap_test

edit: edit.c gap.o display.o config.h
	$(CC) $(CFLAGS) edit.c gap.o display.o $(LDFLAGS) -o edit

test: gap_test 
	./tests/gap_test

clean:
	rm gap.o display.o  tests/gap_test edit
