CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o operations.o
	$(CC) main.o operations.o -o my_program

test: test.o operations.o
	$(CC) test.o operations.o -o test

main.o: main.c
	$(CC) $(CFLAGS) main.c

operations.o: operations.c
	$(CC) $(CFLAGS) operations.c

test.o: test.c
	$(CC) $(CFLAGS) test.c

clean:
	rm -f *.o my_program test
