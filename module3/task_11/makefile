CC = gcc
CFLAGS = -g -c -pthread

all: my_program

my_program: main.o child_process.o generate_numbers.o parent_process.o semaphore_func.o
	$(CC) main.o child_process.o generate_numbers.o parent_process.o semaphore_func.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate_numbers.o: generate_numbers.c
	$(CC) $(CFLAGS) generate_numbers.c

child_process.o: child_process.c
	$(CC) $(CFLAGS) child_process.c

semaphore_func.o: semaphore_func.c
	$(CC) $(CFLAGS) semaphore_func.c

parent_process.o: parent_process.c
	$(CC) $(CFLAGS) parent_process.c

clean:
	rm -rf *.o my_program numbers.txt
