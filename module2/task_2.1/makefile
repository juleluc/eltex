CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o contacts.o menu.o
	$(CC) main.o contacts.o menu.o -o my_program

test: test.o contacts.o menu.o
	$(CC) test.o contacts.o menu.o -o test

main.o: main.c
	$(CC) $(CFLAGS) main.c

menu.o: menu.c
	$(CC) $(CFLAGS) menu.c

contacts.o: contacts.c
	$(CC) $(CFLAGS) contacts.c

test.o: test.c
	$(CC) $(CFLAGS) test.c
clean:
	rm -rf *.o my_program test
