CC = gcc
CFLAGS = -g -c 

all: my_program

my_program: main.o other_func.o
	$(CC) main.o other_func.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

other_func.o: other_func.c
	$(CC) $(CFLAGS) other_func.c

clean:
	rm -rf *.o my_program