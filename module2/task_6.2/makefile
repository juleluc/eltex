CC = gcc
CFLAGS = -g -fPIC

all: my_program

my_program: main.o menu.o liblist.so
	$(CC) main.o menu.o -ldl -o my_program

liblist.so: list.o
	$(CC) -shared -o liblist.so list.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

menu.o: menu.c 
	$(CC) $(CFLAGS) -c menu.c

list.o: list.c 
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -rf *.o my_program liblist.so