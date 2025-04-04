CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o queue_func.o 
	$(CC) main.o queue_func.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

queue_func.o: queue_func.c
	$(CC) $(CFLAGS) queue_func.c

clean:
	rm -rf *.o my_program
