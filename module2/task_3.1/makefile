CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o rights_access_func.o menu.o
	$(CC) main.o rights_access_func.o menu.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

rights_access_func.o: rights_access_func.c
	$(CC) $(CFLAGS) rights_access_func.c

menu.o: menu.c
	$(CC) $(CFLAGS) menu.c
clean:
	rm -f *.o my_program test
