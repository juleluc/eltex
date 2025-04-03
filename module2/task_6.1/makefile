CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o menu.o liblist.a
	$(CC) main.o  menu.o  -L. -llist -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

menu.o: menu.c
	$(CC) $(CFLAGS) menu.c

list.o: list.c
	$(CC) $(CFLAGS) list.c

liblist.a: list.o
	ar rc liblist.a list.o

clean:
	rm -rf *.o my_program liblist.a