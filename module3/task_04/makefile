CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o 
	$(CC) main.o  -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o my_program numbers.txt
