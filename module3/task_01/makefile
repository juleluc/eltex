CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o calculate_area.o
	$(CC) main.o calculate_area.o -o my_program


main.o: main.c
	$(CC) $(CFLAGS) main.c

calculate_area.o: calculate_area.c
	$(CC) $(CFLAGS) calculate_area.c


clean:
	rm -f *.o my_program test
