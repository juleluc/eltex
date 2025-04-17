CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o child_process.o generate_numbers.o signal_handler.o parent_process.o
	$(CC) main.o child_process.o generate_numbers.o signal_handler.o parent_process.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate_numbers.o: generate_numbers.c
	$(CC) $(CFLAGS) generate_numbers.c

child_process.o: child_process.c
	$(CC) $(CFLAGS) child_process.c

signal_handler.o: signal_handler.c
	$(CC) $(CFLAGS) signal_handler.c

parent_process.o: parent_process.c
	$(CC) $(CFLAGS) parent_process.c

clean:
	rm -rf *.o my_program numbers.txt
