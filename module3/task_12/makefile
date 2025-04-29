CC = gcc
CFLAGS = -g -c -pthread

all: my_program

my_program: main.o shared_semaphore.o 
	$(CC) main.o shared_semaphore.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c


shared_semaphore.o: shared_semaphore.c
	$(CC) $(CFLAGS) shared_semaphore.c


clean:
	rm -rf *.o my_program 
