CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o reader_process.o generate_numbers.o semaphore_func.o writer_process.o
	$(CC) main.o reader_process.o generate_numbers.o semaphore_func.o writer_process.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate_numbers.o: generate_numbers.c
	$(CC) $(CFLAGS) generate_numbers.c

reader_process.o: reader_process.c
	$(CC) $(CFLAGS) reader_process.c

semaphore_func.o: semaphore_func.c
	$(CC) $(CFLAGS) semaphore_func.c

writer_process.o: writer_process.c
	$(CC) $(CFLAGS) writer_process.c

clean:
	rm -rf *.o my_program numbers.txt
